from . import Messagebox
def box(title,text,icon,button):
    return MessageBox.MessageBox.Py_MessageBox(title,text,icon,button)

mb_ok=0x00000000
mb_yesno=0x00000004
mb_yesnocentrel=0x00000003
mb_iconquestion=0x00000020
mb_iconerror=0x00000010
mb_iconimformation=0x00000040
mb_iconwarning=0x00000030