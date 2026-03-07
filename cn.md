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