import sys
def argv():
    return sys.argv
def argv_index(index):
    try:
        return sys.argv[index]
    except Exception:
        return ""