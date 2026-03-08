import os
def no_console(name):
    if os.path.exists(name):
        print("Error: Directory already exists")
        return
    os.mkdir(name)
    os.chdir(name)
    with open("cbuildtxt.txt",'w') as f:
        f.write(f"""
src,src/{name}.c
header,include
cl,cl""")
    os.mkdir("include")
    os.mkdir("src")
    os.chdir("src")
    with open(f"{name}.c",'w') as f:
        f.write("""
#include <stdio.h>

int main() {
    FreeConsole();
    printf("Hello World!");
    return 0;
}""")
def MessageBox(name):
    if os.path.exists(name):
        print("Error: Directory already exists")
        return
    os.mkdir(name)
    os.chdir(name)
    with open("cbuildtxt.txt",'w') as f:
        f.write(f"""
src,src/{name}.c
header,include
cl,cl
lib,user32.lib
/windows""")
    os.mkdir("include")
    os.mkdir("src")
    os.chdir("src")
    with open(f"{name}.c",'w') as f:
        f.write("""
#include <stdio.h>
#include <Windows.h>
int MessageBox(char* title,char* message){
                return MessageBoxW(NULL,title,message, MB_OK);}
int main() {
                MessageBox("Hello World!","Hello World!");
    return 0;
}""")
