# python-c
感谢使用python-c!
## 模块
### MessageBox
这是用以显示消息框的模块 

example:
```python
from MessageBox import *
MessageBox("hallo","hallo world",mb_iconerror_,mb_ok)#mb_ok同等于C语言的MB_OK
```
### byte
这是一个字节模块
example:
```python
from byte import byte_int_to_binary,byte_binary_to_int
print(byte_int_to_binary(255))#把非符号整数转换成二进制
print(byte_binary_to_int("11111111"))#把二进制转换成非符号整数
```
## 包
### cbuild
这是一个用于构建C语言文件的模块
你需要使用cmd来运行它
运行方法：
```语法
cbuild project [项目名] normal/unconsole		创建一个新的项目，项目名为[项目名]，normal为有控制台，unconsole为无控制台
cbuild build [项目名]
cbuild clean [项目名]
cbuild help 
```
#### 编写构建文件
构建文件是cbuild的配置文件，你可以使用cbuild来生成一个构建文件。
构建文件名为"cbuildtxt.txt"
```语法
src,		设置源文件
header,		设置头文件
lib,		设置库文件
cl,			设置编译器
@windows/@mac	设置编译平台
@asm/@obj	设置其他编译类型
```

## 许可证
python-c使用MIT许可证
全文: 
```MIT License
Copyright (c) 2026 cgDigg
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```