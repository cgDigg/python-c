from .argv import argv,argv_index
from .cbuild import compile,project
from .run import run,cl_run,clean,compile
from .builds import builds
def main():
    if len(argv())<2:
        print("没有足够的参数")
        return 1
    if argv_index(1)=="project":
        if len(argv())<3:
            print("没有足够的参数")
            return 1
        project(argv_index(2))
    if argv_index(1)=="cl":
        if len(argv())<3:
            print("没有足够的参数")
            return 1
        compile(argv_index(2))
    if argv_index(1)=="clean":
        if len(argv())<3:
            print("没有足够的参数")
            return 1
        clean(argv_index(2))
    if argv_index(1)=="builds":
        if len(argv())<3:
            print("没有足够的参数")
            return 1
        builds(argv_index(2))
if __name__=="__main__":
    main()

