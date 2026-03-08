# python-c
[Chinese version](cn.md)
 
Thanks for using python-c! 
It is written for use c in python. 
## modules
### MessageBox
This module is a wrapper for MessageBox.
example:
```python
from MessageBox import *
MessageBox("hallo","hallo world",mb_iconerror_,mb_ok)#mb_ok = MB_OK in C
```
### byte
This module is a wrapper for byte.
example:
```python
from byte import byte_int_to_binary,byte_binary_to_int
print(byte_int_to_binary(255))#int to binary
print(byte_binary_to_int("11111111"))#binary to int
```
## package
### cbuild
This package is a language package for c. 

you need cmd to run it. 

grammar:
```grammar
cbuild project [name] normal/unconsole		create a new project named [name](normal or without console)
cbuild build [name]		build the project named [name]
cbuild clean [name]		clean the project named [name]
cbuild help				show the help message
```
#### write build file
build file is named "cbuildtxt.txt"
```grammer
src,		set the source file
header,		set the include file
lib,		set the library file
cl,			set the compiler
@windows/@mac		set compile platform
@asm/@obj	set other compile type
```
## license
MIT License 

Copyright (c) 2026 cgDigg
```license
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