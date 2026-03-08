import subprocess
def system(command_list):
    """安全地执行系统命令，使用列表形式防止注入"""
    
    try:
        result = subprocess.run(command_list, check=True, capture_output=True, text=True)
        print(result.stdout)
        return 0
    except subprocess.CalledProcessError as e:
        print(e.stderr)
        return e.returncode
    except FileNotFoundError as e:
        return -1