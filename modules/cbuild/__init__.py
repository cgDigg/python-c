"""cbuild - 一个类似于 cmake 的文本式编译器"""

__version__ = "0.0.1"

from .argv import argv, argv_index
from .cbuild import compile, project
from .run import run, cl_run, clean
from .builds import builds
from .more_projects import no_console, MessageBox

__all__ = [
    'argv',
    'argv_index',
    'compile',
    'project',
    'run',
    'cl_run',
    'clean',
    'builds',
    'no_console',
    'MessageBox',
]