# builds.py

import os
import sys

# 颜色定义
red = '\033[91m'
green = '\033[92m'
yellow = '\033[93m'
blue = '\033[94m'
white = '\033[97m'
chuti = '\033[96m'
back = '\033[0m'

# 从 cbuild 导入 compile
from .run import cl_run

def builds():
    or_path = os.path.abspath(os.getcwd())
    print(blue + "一个类似于 cmake 的文本式编译器，version 0.0.0 开发版" + back)
    
    if not os.path.exists("build.txt"):
        print(red + "错误：" + back + "未找到 build.txt" + back)
        return 1
    
    try:
        with open("build.txt", 'r', encoding='utf-8') as f:
            lines = f.readlines()
        
        projects = []
        _pro=[]
        for line in lines:
            path = line.strip()
            if path:
                abs_path = os.path.join(or_path, path)
                projects.append(abs_path)
                _pro.append(path)
        num1 = len(projects)
        num = 0
        
        if num1 == 0:
            print(yellow + "警告：" + back + "build.txt 为空" + back)
            return 0
        
        print(f"\n发现 {num1} 个项目，开始编译...\n")
        mum2=0
        for abs_path in projects:
            mum2+=1
            if not os.path.exists(abs_path):
                print(red + "错误：" + back + f"不存在项目 '{abs_path}'" + back)
                continue
            
            print(blue + "正在编译：" + back + f"{os.path.basename(abs_path)}")
            
                # ← 修复：只传递一个参数
            result = cl_run(os.path.basename(abs_path))
                
            print(yellow + "返回值：" + back + f"{result}\n")
            os.chdir(or_path)
            if result == 0:
                num += 1
                print(green + "成功：" + back + f"{os.path.basename(abs_path)}\n" + back)
            elif result>0 and result<10:
                print(red + "失败：" + back + f"{os.path.basename(abs_path)} (错误码：{result})\n" + back)
        
        percentage = (num / num1 * 100) if num1 > 0 else 0.0
        print(f"\n{blue}编译完成，共{num1}个目录，已完成{num}个({percentage:.1f}%){back}")
        
    except Exception as e:
        print(red + f"错误：{e}" + back)
        import traceback
        traceback.print_exc()
        return 1
    finally:
        os.chdir(or_path)
    
    return 0