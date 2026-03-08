from .argv import argv,argv_index
from .cbuild import compile,project
from .run import run,cl_run,clean
from .builds import builds
from .more_projects import no_console,MessageBox
def main():
    if len(argv())<2:
        print("没有足够的参数")
        return 1
    elif argv_index(1)=="project":
        if len(argv())<4:
            print("没有足够的参数")
            return 1
        if argv_index(3)=="normal":
            project(argv_index(2))
        elif argv_index(3)=="conloseness":
            no_console(argv_index(2))
        elif argv_index(3)=="MessageBox":
            MessageBox(argv_index(2))
        else:
            print("参数错误")
    elif argv_index(1)=="build":
        run()
    elif argv_index(1)=="clean":
        if len(argv())<3:
            print("没有足够的参数")
            return 1
        clean(argv_index(2))
    elif argv_index(1)=="builds":
        if len(argv())<2:
            print("没有足够的参数")
            return 1
        builds()
    else:
        return run()
    return 0
if __name__=="__main__":
    exit(main())

