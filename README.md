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
## dll
I make dll for c.

have many types.
### cmd
a dll named cmd
#### functions
```functions
int free_sth(void* ptr);
int cmd(char* command);
int copy(const char* src, const char* des);
int move(const char* src, const char* des);
int Rename(const char* src, const char* des);
int rmfile(const char* path);
int rmdir(const char* path);
int mkdir(const char* path);
int input(const char* question, char* buffer, int buffer_size);
```

### function
a dll named function
#### functions
```functions
int __stdcall error_(const char* error_information);
int __stdcall error_w(const char* error_information, const char* error_title);
BOOL __stdcall hide_question(const char* question,char* output_buffer,size_t buffer_size);
int __stdcall hide_and_with(const char* question,char* output_buffer,size_t buffer_size,char hide_char);
int __stdcall get_argc(void);
BOOL __stdcall get_argv(int index, char* buffer, int buffer_size);
int __stdcall wait_for_key(void);
int __stdcall keybord_getch();
int Error_windows(const char* Error);
const char* string_add(const char* string1, const char* string2, int butter_size);
void free_string(char* address);
typedef char* (*CallbackFunc)(void);
typedef char* (*DllFunction)(CallbackFunc);
int run_dll_no_header(const char* dll_name, const char* function_name);
int show_hide_cursor(int mode);
int show_message(char* title, char* imformation, long enter);
int check(const char* string1, const char* string2);
```

### int_str
a c++ dll named int_str
#### functions
```functions
char* change_int_to_str(int string);
int free_str(char* str);
```

### math
a dll named math
#### functions
```functions
double gamma(double value);
double factorial(double value);
double absolute_value(double value);
double power(double base, double exponent);
double square_root(double value);
```

### python
a dll named python 
you need python header and python dll
#### functions
```functions
int init_python(void);
int exit_python(void);
int run_python(char* file);
int run_python_string(char* code);
void cmd_python();
```

### python_function
a dll named python_function
#### functions
```functions
int add_(int number1, int number2);
int cmd_run(const char* cmd);
int python_in_path_test(void);
int print_str(const char* string);
int time_down(int time_ms);
int start_python(void);
int multiply(int a, int b);
int strings_equal(char* string1, char* string2);
int python_run_module(char* module_);
int dll_run_int(char* dll, char* function_, char* argv);
int error(HWND hwnd, char* title, char* massege_);
```

### random
a dll named random
#### functions
```functions
int radom(int small_number, int large_number);
char radon_str(char* string, int index);
```

### strings
a dll named strings
#### functions
```functions
int string_length(const char* str);
int strings_check(char* string1, char* string2);
const char* string_add(char* string1, char* string2, int butter_size);
void string_free(const char* str);
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