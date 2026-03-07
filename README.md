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