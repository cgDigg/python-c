from .cbuild import compile, project
from .argv import argv, argv_index
import os
green = "\033[32m"
red = "\033[31m"
blue = "\033[34m"
chuti = "\033[1m"
back = "\033[0m"
yellow = "\033[33m"
def run():
    print(blue + "一个类似于 cmake 的文本式编译器，version 0.0.0 开发版" + back)
    
    # 检查是否有足够的参数（至少需要命令）
    if len(argv()) < 1:
        print(red + "错误：" + back + "缺乏" + chuti + "足够的" + back + "参数")
        print("用法：cbuild <command> [arguments]")
        print("可用命令：project, build, clean, help")
        return 1
    
    command = argv_index(1)
    
    # project 命令
    if command == "project":
        if len(argv()) < 2:
            print(red + "错误" + back + "：缺乏" + chuti + "项目名称" + back + "参数")
            print("用法：cbuild project <项目名称>")
            return 1
        else:
            project_name = argv_index(1)
            result = project(project_name)
            if result:
                print(green + "成功" + back + "：已经搭建项目 '" + project_name + "'")
                return 0
            else:
                print(red + "错误" + back + "：项目创建失败")
                return 1
    
    # build 命令
    elif command == "build":
        if len(argv()) < 2:
            print(red + "错误" + back + "：缺乏" + chuti + "项目名称" + back + "参数")
            print("用法：cbuild build <项目名称>")
            return 1
        else:
            project_name = argv_index(2)
            result = compile(project_name)
            
            if result == 0:
                print(green + "成功" + back + "：编译完成")
                return 0
            elif result == 1:
                print(red + "错误" + back + "：不存在项目 '" + project_name + "'")
                return 1
            elif result == 2:
                print(red + "错误" + back + "：无法找到构建脚本 (cbuildtxt.txt)")
                return 1
            elif result == 3:
                print(red + "错误" + back + "：无法找到源文件")
                return 1
            elif result == 4:
                print(red + "错误" + back + "：无法找到头文件路径")
                return 1
            elif result == 5:
                print(red + "错误" + back + "：未找到编译器 (cl)")
                return 1
            elif result == 7:
                print(red + "错误" + back + "：平台不兼容")
                return 1
            elif result == 8:
                print(red + "错误" + back + "：编译选项错误")
                return 1
            elif result == 9:
                print(red + "错误" + back + "：不支持的编译器")
                return 1
            elif result == 10:
                print(yellow + "警告" + back + "：将不会生成导入库")
                return 2
            else:
                print(red + "错误" + back + "：未知错误 (代码：" + str(result) + ")")
                return 1
    
    # clean 命令（新增）
    elif command == "clean":
        if len(argv()) < 2:
            print(red + "错误" + back + "：缺乏" + chuti + "项目名称" + back + "参数")
            print("用法：cbuild clean <项目名称>")
            return 1
        else:
            project_name = argv_index(1)
            result = clean(project_name)
            if result:
                print(green + "成功" + back + "：清理完成")
                return 0
            else:
                print(red + "错误" + back + "：清理失败")
                return 1
    
    # help 命令（新增）
    elif command == "help":
        print("""
用法：cbuild <命令> [选项]

可用命令：
  project <name>    创建新项目
  build <name>      编译项目
  clean <name>      清理构建文件
  help              显示此帮助信息

示例：
  cbuild project myapp    创建名为 myapp 的项目
  cbuild build myapp      编译 myapp 项目
  cbuild clean myapp      清理 myapp 构建文件

配置文件 (cbuildtxt.txt) 说明：
  src,<文件>          指定源文件
  lib,<库>            指定链接库
  path_header,<路径>  指定头文件路径
  cl,<编译器>         指定编译器 (cl 或 gcc)
  @windows/@mac       平台限制
  @asm/@obj           生成汇编/目标文件
""")
        return 0
    
    # version 命令（新增）
    elif command == "version":
        print("cbuild version 0.0.0 开发版")
        return 0
    
    # 未知命令
    else:
        print(red + "错误" + back + "：未知命令 '" + command + "'")
        print("使用 'cbuild help' 查看可用命令")
        return 1


# 新增 clean 函数（如果 cbuild.py 中没有）
def clean(name):
    """清理构建文件"""
    import os
    import shutil
    
    if not os.path.exists(name):
        return False
    
    original_cwd = os.getcwd()
    os.chdir(name)
    
    try:
        # 要删除的文件扩展名
        extensions = ['.o', '.obj', '.s', '.asm', '.exe', '.out', '.ilk', '.pdb', '.lib', '.dll']
        
        count = 0
        for file in os.listdir('.'):
            for ext in extensions:
                if file.endswith(ext):
                    os.remove(file)
                    count += 1
                    break
        
        # 删除构建目录
        for dir_name in ['build', 'Debug', 'Release']:
            if os.path.exists(dir_name):
                shutil.rmtree(dir_name)
                count += 1
        
        return True
        
    except Exception:
        return False
        
    finally:
        os.chdir(original_cwd)
def cl_run(name):
    original_cwd=os.getcwd()
    result = compile(name)
    if result == 0:
        print(green + "成功" + back + "：编译完成")
        return 0
    elif result == 1:
        print(red + "错误" + back + "：不存在项目 '" + name + "'")
        return 1
    elif result == 2:
        print(red + "错误" + back + "：无法找到构建脚本 (cbuildtxt.txt)")
        return 1
    elif result == 3:
        print(red + "错误" + back + "：无法找到源文件")
        return 1
    elif result == 4:
        print(red + "错误" + back + "：无法找到头文件路径")
        return 1
    elif result == 5:
        print(red + "错误" + back + "：未找到编译器 (cl)")
        return 1
    elif result == 6:
        print(red + "错误" + back + "：编译器验证失败")
        return 1
    elif result == 7:
        print(red + "错误" + back + "：平台不兼容")
        return 1
    elif result == 8:
        print(red + "错误" + back + "：编译选项错误")
        return 1
    elif result == 9:
        print(red + "错误" + back + "：不支持的编译器")
        return 1
    elif result == 10:
        print(yellow + "警告" + back + "：将不会生成导入库")
        return 2
    else:
        print(red + "错误" + back + "：未知错误 (代码：" + str(result) + ")")
        return 1
