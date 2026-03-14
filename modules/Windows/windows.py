import tkinter as tk# need to import tkinter
class Windows():
    def __main__(self):
        self.root=tk.Tk()
        return self.root
    def title(self,root,title):
        title=str(root,title)
        root.title(title)
        return 0
    def size(root,hight,width):
        
        hight=str(hight)
        width=str(width)
        root.geometry(f"{hight}x{width}")
        return 0
    def show(self,root):
        root.mainloop()
        return 0