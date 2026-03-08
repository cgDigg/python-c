import os
import platform
import json
import shutil
import subprocess
from .tools.system import system
def project(name):
    if os.path.exists(name):
        print("Error: Directory already exists")
        return
    os.mkdir(name)
    os.chdir(name)
    with open("cbuildtxt.txt",'w')as f:
        f.write("")
    os.mkdir("src")
    os.chdir("src")
    with open(f"{name}.c",'w') as f:
        f.write("""
#include <stdio.h>
int main(){
    printf("hallo");
    return 0;
}""")
def compile(name):
    # 检查项目目录是否存在
    if not os.path.exists(name):
        return 1
    
    # 保存当前工作目录，以便最后恢复
    original_cwd = os.getcwd()
    os.chdir(name)
    
    try:
        # 检查配置文件是否存在
        config_file = "cbuildtxt.txt"
        if not os.path.exists(config_file):
            return 2
        
        # 解析配置文件
        lib = []
        src = ""
        path_hr = ""
        cmd = []
        compiler = ""
        line_num = 0  # 修复：初始化行号计数器
        
        with open(config_file, 'r', encoding='utf-8') as f:
            for line in f:
                line_num += 1
                line = line.strip()
                
                if line.startswith("src,"):
                    src = line[4:].strip()
                elif line.startswith("lib,"):
                    lib.append(line[4:].strip())
                elif line.startswith("header,"):
                    path_hr = line[7:].strip()
                elif line.startswith("@windows"):
                    cmd.append("!win")
                elif line.startswith("@mac"):
                    cmd.append("!mac")
                elif line.startswith("@asm"):
                    cmd.append("cl*asm")
                elif line.startswith("@obj"):
                    cmd.append("cl*obj")
                elif line.startswith("cl,"):
                    compiler = line[3:].strip()
                elif line=="lib*":
                    cmd.append("lib")
                elif line and not line.startswith('#'): continue
        
        # 构建配置字典
        config = {
            "src": src,
            "lib": lib,
            "header": path_hr,
            "cmd": cmd,
            "compiler": compiler
        }
        # 检查源文件是否存在
        if not os.path.exists(config["src"]):
            return 3
        
        # 检查头文件路径是否存在
        if not os.path.exists(config["header"]):
            return 4
        
        # 检查编译器环境变量
        if not shutil.which("cl")or not shutil.which("gcc"):
            return 5
        
        # 验证编译器版本（修复：decode bytes 并简化版本检查）
        # 检查平台兼容性
        current_system = platform.system()
        for i in config["cmd"]:
            if i == "!win" and current_system != "Windows":
                return 7
            if i == "!mac" and current_system not in ("Darwin", "MacOS"):  # 修复：macOS实际返回"Darwin"
                return 7
        # 构建编译命令选项
        # 构建库文件链接参数
        lib_args = ' '.join(config["lib"])
        cl_cmd=[]
        if len(config["cmd"])<1:
            cl_cmd = []
        else:
            for i in config["cmd"]:
                if i == "cl*asm":
                    cl_cmd.append("asm")
                elif i == "cl*obj":
                    cl_cmd.append("obj")
                elif i == "lib":
                    cl_cmd.append("lib")
                else:
                    return 6
        # 执行编译

# ============ 修改后的编译逻辑 ============

        if config["compiler"] == "cl":
            # 构建基础参数列表
            base_args = []
            if config['header']:
                base_args.extend([f"/I{config['header']}",config['src']])
              # lib_args 应该是列表
            
            if not cl_cmd:
                cmd = ["cl"] + base_args+[lib_args]
                print(" ".join(cmd))
                system(cmd)
            elif cl_cmd[0] == "asm":
                cmd = ["cl", "/s", config['src']]
                print(" ".join(cmd))
                system(cmd)
            elif cl_cmd[0] == "obj":
                cmd = ["cl", "/c", config['src']]
                print(" ".join(cmd))
                system(cmd)
            elif cl_cmd[0] == "lib":
                cmd = ["cl", "/LD"] + base_args
                print(" ".join(cmd))
                system("".join(cmd))
                system(["link", "*.obj", "/DLL", f"/OUT:{name}.dll",'libcmt.lib'])
                print(f"link /DLL {name}.dll *.obj libcmt.lib {lib_args}")
            else:
                cmd = ["cl"] + base_args
                print(" ".join(cmd))
                system(cmd)
            print(" ".join(cmd))
            return 0

        elif config["compiler"] == "gcc":
            # 构建基础参数列表
            base_args = []
            if config['header']:
                base_args.extend([f"-I{config['header']}"])
            base_args.append(config['src'])
            base_args.append(f"-o {name}")
            
            if not cl_cmd:
                cmd = ["gcc"] + base_args+[lib_args]
                print(" ".join(cmd))
                system(cmd)
            elif cl_cmd[0] == "asm":
                cmd = ["gcc", "-S", config['src']]  # 注意：gcc 生成汇编是 -S 不是 -s
                print(" ".join(cmd))
                system(cmd)
            elif cl_cmd[0] == "obj":
                cmd = ["gcc", "-c", config['src']]
                print(" ".join(cmd))
                system(cmd)
            elif cl_cmd[0] == "lib":
                cmd = ["gcc", "-c"] + base_args
                print(" ".join(cmd))
                system(cmd)
                if platform.system() == "Windows":
                    system(["gcc", "-shared", "-o", f"{name}.dll", "*.o"])
                    print(" ".join(["gcc", "-shared", "-o", f"{name}.dll", "*.o"]))
                elif platform.system() == "Darwin":
                    system(["gcc", "-dynamiclib", "-o", f"{name}.dylib", "*.o"])
                    print(" ".join(["gcc", "-dynamiclib", "-o", f"{name}.dylib", "*.o"]))
                else:
                    system(["gcc", "-shared", "-o", f"{name}.so", "*.o"])

            else:
                cmd = ["gcc"] + base_args
                print(" ".join(cmd))
                system(cmd)
            print(" ".join(cmd))
            if not cl_cmd or cl_cmd[0] != "lib":
                return 0
            else:
                if not os.path.exists(f"{name}.def"):
                    if platform.system() == "Windows":
                        return 10
                    else:
                        return 0
                elif shutil.which("lib")!=None:
                    system(["lib","/DEF:{name}.def","/OUT:{name}.lib","/MACHINE:x64"])
                    return 0
                else:
                    return 0
            return 0
        else:
            return 9
    finally:
        # 恢复原始工作目录
        os.chdir(original_cwd)