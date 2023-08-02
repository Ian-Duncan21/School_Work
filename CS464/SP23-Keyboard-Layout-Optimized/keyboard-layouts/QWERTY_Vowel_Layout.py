import tkinter as tk
from tkinter import *
from tkinter import ttk

key = tk.Tk()
key.title('On Screen Keyboard - Colemak Layout - Vowel')

# key.resizable(True,True)
# sizegrip = ttk.Sizegrip(key)
# sizegrip.grid(row=4, sticky= tk.SE)

#ADJUST THESE TO MATCH SPECS OF SCREEN WE GET LOANED
key.geometry('1600x900')  # Window size
# key.maxsize(width=1385, height=320) 
# key.minsize(width=1385, height=320)

key.resizable(True,True)
sizegrip = ttk.Sizegrip(key)
sizegrip.grid(row=4, sticky= tk.SE)

#Style
style = ttk.Style()
key.configure(bg='gray27')
style.configure('TButton', background='gray21')
style.configure('TButton', foreground='white')
theme = "light"
# style.map('TButton', background=[('active','red')])

# my code
# style.configure('.', font=('Helvetica', 12, 'bold'), background='blue', foreground='white')
# style.configure('JS.TButton', font=('Helvetica', 12), background='blue', foreground='black')

#Entry Box
equation = tk.StringVar()
Dis_entry = ttk.Entry(key, state='readonly', textvariable=equation)
Dis_entry.grid(rowspan=1, columnspan=100, ipadx=999, ipady=20, row = 0, column = 0)

exp = " " #Store the text currently typed into the entry box
is_shift = False #Is shift key being pressed?
is_caps = False

def CapsLock():
    global is_caps
    is_caps = not is_caps
    display()

def press(num):
    global exp
    exp = exp + str(num)
    equation.set(exp)


def Backspace():
    global exp
    exp = exp[:-1]
    equation.set(exp)


def Shift():
    global is_shift
    is_shift = not is_shift
    display()


def Clear():
    global exp
    exp = " "
    equation.set(exp)

def Theme():
    global theme
    if theme == "dark":
        key.configure(bg= theme)
        style.configure('TButton', bg =theme, fg ="white")
        style.configure('TButton', foreground='white')
        theme = "light"
    elif theme == "light":
        key.configure(bg='gray99')
        style.configure('TButton', background='azure')
        style.configure('TButton', foreground='black')
        theme = "dark"

def display():
    #Add the capitalized letters if the shift key is being pressed.
    if (not is_caps and not is_shift):
        tick = ttk.Button(key, text='`', width=6, command=lambda: press('`'))
        tick.grid(row=1, column=0, ipadx=6, ipady=10)

        num1 = ttk.Button(key, text='1', width=6, command=lambda: press('1'))
        num1.grid(row=1, column=1, ipadx=6, ipady=10)

        num2 = ttk.Button(key, text='2', width=6, command=lambda: press('2'))
        num2.grid(row=1, column=2, ipadx=6, ipady=10)

        num3 = ttk.Button(key, text='3', width=6, command=lambda: press('3'))
        num3.grid(row=1, column=3, ipadx=6, ipady=10)

        num4 = ttk.Button(key, text='4', width=6, command=lambda: press('4'))
        num4.grid(row=1, column=4, ipadx=6, ipady=10)

        num5 = ttk.Button(key, text='5', width=6, command=lambda: press('5'))
        num5.grid(row=1, column=5, ipadx=6, ipady=10)

        num6 = ttk.Button(key, text='6', width=6, command=lambda: press('6'))
        num6.grid(row=1, column=6, ipadx=6, ipady=10)

        num7 = ttk.Button(key, text='7', width=6, command=lambda: press('7'))
        num7.grid(row=1, column=7, ipadx=6, ipady=10)

        num8 = ttk.Button(key, text='8', width=6, command=lambda: press('8'))
        num8.grid(row=1, column=8, ipadx=6, ipady=10)

        num9 = ttk.Button(key, text='9', width=6, command=lambda: press('9'))
        num9.grid(row=1, column=9, ipadx=6, ipady=10)

        num0 = ttk.Button(key, text='0', width=6, command=lambda: press('0'))
        num0.grid(row=1, column=10, ipadx=6, ipady=10)

        square_brackets_open = ttk.Button(key, text='[', width=6, command=lambda: press('['))
        square_brackets_open.grid(row=1, column=11, ipadx=6, ipady=10)

        square_brackets_closed = ttk.Button(key, text=']', width=6, command=lambda: press(']'))
        square_brackets_closed.grid(row=1, column=12, ipadx=6, ipady=10)
        
        backspace = ttk.Button(
                key, text='<--', width=6, command=Backspace)
        backspace.grid(row=1, column=13, ipadx=6, ipady=10)

            # Second Row Buttons

        tab_button = ttk.Button(key, text='Tab', width=6,
                                    command=lambda: press('\t'))
        tab_button.grid(row=2, column=0,  ipadx=6, ipady=10)
        
        single_quote = ttk.Button(key, text ="'", width = 6, command = lambda: press("'"))
        single_quote.grid(row = 2, column=1, ipadx = 6, ipady= 10)
        
        comma = ttk.Button(key, text =",", width = 6, command = lambda: press(","))
        comma.grid(row = 2, column=2, ipadx = 6, ipady= 10)
        
        period = ttk.Button(key, text =".", width = 6, command = lambda: press("."))
        period.grid(row = 2, column=3, ipadx = 6, ipady= 10)
        
        P = ttk.Button(key, text='p', width=6, command=lambda: press('p'))
        P.grid(row=2, column=4, ipadx = 6, ipady=10)

        Y = ttk.Button(key, text='y', width=6, command=lambda: press('y'))
        Y.grid(row=2, column=5, ipadx=6, ipady=10)

        F = ttk.Button(key, text='f', width=6, command=lambda: press('f'))
        F.grid(row=2, column=6, ipadx=6, ipady=10)

        G = ttk.Button(key, text='g', width=6, command=lambda: press('g'))
        G.grid(row=2, column=7, ipadx=6, ipady=10)

        C = ttk.Button(key, text='c', width=6, command=lambda: press('c'))
        C.grid(row=2, column=8, ipadx=6, ipady=10)

        R = ttk.Button(key, text='r', width=6, command=lambda: press('r'))
        R.grid(row=2, column=9, ipadx=6, ipady=10)

        L = ttk.Button(key, text='l', width=6, command=lambda: press('l'))
        L.grid(row=2, column=10, ipadx=6, ipady=10)

        backslash = ttk.Button(
                key, text='/', width=6, command=lambda: press('/'))
        backslash.grid(row=2, column=11, ipadx=6, ipady=10)

        equal = ttk.Button(key, text='=', width=6,
                                command=lambda: press('='))
        equal.grid(row=2, column=12, ipadx=6, ipady=10)
            
        frontslash = ttk.Button(key, text='\\', width=6,
                                command=lambda: press('\\'))
        frontslash.grid(row=2, column=13, ipadx=6, ipady=10)

            # Third Row Buttons
        caps = ttk.Button(key, text ='Caps', width = 6, command = CapsLock)
        caps.grid(row=3, column=0, ipadx=6, ipady=10)


        A = ttk.Button(key, text='a', width=6, command=lambda: press('a'), style= 'JS.TButton')
        A.grid(row=3, column=1, ipadx=6, ipady=10)

        O = ttk.Button(key, text='o', width=6, command=lambda: press('o'))
        O.grid(row=3, column=2, ipadx=6, ipady=10)

        E = ttk.Button(key, text='e', width=6, command=lambda: press('e'))
        E.grid(row=3, column=3, ipadx=6, ipady=10)

        U = ttk.Button(key, text='u', width=6, command=lambda: press('u'))
        U.grid(row=3, column=4, ipadx=6, ipady=10)

        I = ttk.Button(key, text='i', width=6, command=lambda: press('i'))
        I.grid(row=3, column=5, ipadx=6, ipady=10)

        D = ttk.Button(key, text='d', width=6, command=lambda: press('d'))
        D.grid(row=3, column=6, ipadx=6, ipady=10)

        H = ttk.Button(key, text='h', width=6, command=lambda: press('h'))
        H.grid(row=3, column=7, ipadx=6, ipady=10)

        T = ttk.Button(key, text='t', width=6, command=lambda: press('t'))
        T.grid(row=3, column=8, ipadx=6, ipady=10)

        N = ttk.Button(key, text='n', width=6, command=lambda: press('n'))
        N.grid(row=3, column=9, ipadx=6, ipady=10)

        S = ttk.Button(key, text='s', width=6,
                            command=lambda: press('s'))
        S.grid(row=3, column=10, ipadx=6, ipady=10)

        minus = ttk.Button(key, text='-', width=6,
                                command=lambda: press('-'))
        minus.grid(row=3, column=11, ipadx=6, ipady=10)

        enter = ttk.Button(key, text='Enter', width=6,
                            command=lambda: press('\n'))
        enter.grid(row=3, column=12, columnspan= 2, ipadx=55, ipady=10)

            # Fourth Row Buttons

        shift = ttk.Button(key, text='Shift', width=6, command=Shift)
        shift.grid(row=4, column=0, columnspan=2, ipadx=55, ipady=10)

        Semi_Colon = ttk.Button(key, text=';', width=6, command=lambda: press(';'))
        Semi_Colon.grid(row=4, column=2, ipadx=6, ipady=10)

        Q = ttk.Button(key, text='q', width=6, command=lambda: press('q'))
        Q.grid(row=4, column=3, ipadx=6, ipady=10)

        J = ttk.Button(key, text='j', width=6, command=lambda: press('j'))
        J.grid(row=4, column=4, ipadx=6, ipady=10)

        K = ttk.Button(key, text='k', width=6, command=lambda: press('k'))
        K.grid(row=4, column=5, ipadx=6, ipady=10)

        X = ttk.Button(key, text='x', width=6, command=lambda: press('x'))
        X.grid(row=4, column=6, ipadx=6, ipady=10)

        B = ttk.Button(key, text='b', width=6, command=lambda: press('b'))
        B.grid(row=4, column=7, ipadx=6, ipady=10)

        M = ttk.Button(key, text='m', width=6, command=lambda: press('m'))
        M.grid(row=4, column=8, ipadx=6, ipady=10)

        W = ttk.Button(key, text='w', width=6, command=lambda: press('w'))
        W.grid(row=4, column=9, ipadx=6, ipady=10)

        V = ttk.Button(key, text='v', width=6, command=lambda: press('v'))
        V.grid(row=4, column=10, ipadx=6, ipady=10)

        Z = ttk.Button(key, text='z', width=6,
                                command=lambda: press('z'))
        Z.grid(row=4, column=11, ipadx=6, ipady=10)

        clear = ttk.Button(key, text='Clear', width=6, command=Clear)
        clear.grid(row=4, column=12, columnspan=2, ipadx=55, ipady=10)

            # Fifth Row Buttons
            
        # ctrol = ttk.Button(key, text='Space', width=6,
        #                     command=lambda: press(' Ctrl'))
        # ctrol.grid(row=5, column=0, columnspan=8, ipadx=350, ipady=10)
            
        # win = ttk.Button(key, text='Space', width=6,
        #                     command=lambda: press(' '))
        # win.grid(row=5, column=1, columnspan=8, ipadx=350, ipady=10)
        # altt = ttk.Button(key, text='Space', width=6,
        #                     command=lambda: press(' '))
        # altt.grid(row=5, column=2, columnspan=8, ipadx=350, ipady=10)

        space = ttk.Button(key, text='Space', width=6,
                            command=lambda: press(' '))
        space.grid(row=5, column=0, columnspan=12, ipadx=350, ipady=10)

        theme = ttk.Button(key, text='Theme', width=6, command=Theme)
        theme.grid(row=5, column=13, columnspan=2, ipadx=55, ipady=10)

        key.mainloop()
    elif (not is_caps and is_shift):
        tilda = ttk.Button(key, text='~', width=6, command=lambda: press('~'))
        tilda.grid(row=1, column=0, ipadx=6, ipady=10)

        num1 = ttk.Button(key, text='!', width=6, command=lambda: press('!'))
        num1.grid(row=1, column=1, ipadx=6, ipady=10)

        num2 = ttk.Button(key, text='@', width=6, command=lambda: press('@'))
        num2.grid(row=1, column=2, ipadx=6, ipady=10)
        
        num3 = ttk.Button(key, text='#', width=6, command=lambda: press('#'))
        num3.grid(row=1, column=3, ipadx=6, ipady=10)

        num4 = ttk.Button(key, text='$', width=6, command=lambda: press('$'))
        num4.grid(row=1, column=4, ipadx=6, ipady=10)

        num5 = ttk.Button(key, text='%', width=6, command=lambda: press('%'))
        num5.grid(row=1, column=5, ipadx=6, ipady=10)

        num6 = ttk.Button(key, text='^', width=6, command=lambda: press('^'))
        num6.grid(row=1, column=6, ipadx=6, ipady=10)

        num7 = ttk.Button(key, text='&', width=6, command=lambda: press('&'))
        num7.grid(row=1, column=7, ipadx=6, ipady=10)

        num8 = ttk.Button(key, text='*', width=6, command=lambda: press('*'))
        num8.grid(row=1, column=8, ipadx=6, ipady=10)

        num9 = ttk.Button(key, text='(', width=6, command=lambda: press('('))
        num9.grid(row=1, column=9, ipadx=6, ipady=10)

        num0 = ttk.Button(key, text=')', width=6, command=lambda: press(')'))
        num0.grid(row=1, column=10, ipadx=6, ipady=10)

        curlyO = ttk.Button(key, text='{', width=6, command=lambda: press('{'))
        curlyO.grid(row=1, column=11, ipadx=6, ipady=10)

        curlyC= ttk.Button(key, text='}', width=6, command=lambda: press('}'), )
        curlyC.grid(row=1, column=12, ipadx=6, ipady=10)

        backspace = ttk.Button(
                key, text='<---', width=6, command=Backspace)
        backspace.grid(row=1, column=13, ipadx=6, ipady=10)

            # Second Row Buttons

        tab_button = ttk.Button(key, text='Tab', width=6,
                                    command=lambda: press('\t'))
        tab_button.grid(row=2, column=0, ipadx=6, ipady=10)
        
        quote = ttk.Button(key, text='"', width=6, command=lambda: press('"'))
        quote.grid(row=2, column=1, ipadx=6, ipady=10)

        lArrow = ttk.Button(key, text='<', width=6, command=lambda: press('<'))
        lArrow.grid(row=2, column=2, ipadx=6, ipady=10)

        rArrow = ttk.Button(key, text='>', width=6, command=lambda: press('>')) #, style = 'red'
        rArrow.grid(row=2, column=3, ipadx=6, ipady=10)

        P = ttk.Button(key, text='P', width=6, command=lambda: press('P'))
        P.grid(row=2, column=4, ipadx = 6, ipady=10)

        Y = ttk.Button(key, text='Y', width=6, command=lambda: press('Y'))
        Y.grid(row=2, column=5, ipadx=6, ipady=10)

        F = ttk.Button(key, text='F', width=6, command=lambda: press('F'))
        F.grid(row=2, column=6, ipadx=6, ipady=10)

        G = ttk.Button(key, text='G', width=6, command=lambda: press('G'))
        G.grid(row=2, column=7, ipadx=6, ipady=10)

        C = ttk.Button(key, text='C', width=6, command=lambda: press('C'))
        C.grid(row=2, column=8, ipadx=6, ipady=10)

        R = ttk.Button(key, text='R', width=6, command=lambda: press('R'))
        R.grid(row=2, column=9, ipadx=6, ipady=10)

        L = ttk.Button(key, text='L', width=6, command=lambda: press('L'))
        L.grid(row=2, column=10, ipadx=6, ipady=10)

        question = ttk.Button(
                key, text='?', width=6, command=lambda: press('?'))
        question.grid(row=2, column=11, ipadx=6, ipady=10)

        plus= ttk.Button(key, text='+', width=6,
                                command=lambda: press('+'))
        plus.grid(row=2, column=12, ipadx=6, ipady=10)
            
        verticleslash = ttk.Button(key, text='|', width=6,
                                command=lambda: press('|'))
        verticleslash.grid(row=2, column=13, ipadx=6, ipady=10)
            # Third Row Buttons.
            
        caps = ttk.Button(key, text ='Caps', width = 6, command = CapsLock)
        caps.grid(row=3, column=0, ipadx=6, ipady=10)


        A = ttk.Button(key, text='A', width=6, command=lambda: press('A'))
        A.grid(row=3, column=1, ipadx=6, ipady=10)

        O = ttk.Button(key, text='O', width=6, command=lambda: press('O'))
        O.grid(row=3, column=2, ipadx=6, ipady=10)

        E = ttk.Button(key, text='E', width=6, command=lambda: press('E'))
        E.grid(row=3, column=3, ipadx=6, ipady=10)

        U = ttk.Button(key, text='U', width=6, command=lambda: press('U'))
        U.grid(row=3, column=4, ipadx=6, ipady=10)

        I = ttk.Button(key, text='I', width=6, command=lambda: press('I'))
        I.grid(row=3, column=5, ipadx=6, ipady=10)

        D = ttk.Button(key, text='D', width=6, command=lambda: press('D'))
        D.grid(row=3, column=6, ipadx=6, ipady=10)

        H = ttk.Button(key, text='H', width=6, command=lambda: press('H'))
        H.grid(row=3, column=7, ipadx=6, ipady=10)

        T = ttk.Button(key, text='T', width=6, command=lambda: press('T'))
        T.grid(row=3, column=8, ipadx=6, ipady=10)

        N = ttk.Button(key, text='N', width=6, command=lambda: press('N'))
        N.grid(row=3, column=9, ipadx=6, ipady=10)

        S = ttk.Button(key, text='S', width=6,
                            command=lambda: press('S'))
        S.grid(row=3, column=10, ipadx=6, ipady=10)

        underscore = ttk.Button(key, text='_', width=6,
                                command=lambda: press('_'))
        underscore.grid(row=3, column=11, ipadx=6, ipady=10)

        enter = ttk.Button(key, text='Enter', width=6,
                            command=lambda: press('\n'))
        enter.grid(row=3, column=12, columnspan= 2, ipadx=55, ipady=10)

            # Fourth Row Buttons

        shift = ttk.Button(key, text='Shift', width=6, command=Shift)
        shift.grid(row=4, column=0, columnspan=2, ipadx=55, ipady=10)

        Colon = ttk.Button(key, text=':', width=6, command=lambda: press(':'))
        Colon.grid(row=4, column=2, ipadx=6, ipady=10)

        Q = ttk.Button(key, text='Q', width=6, command=lambda: press('Q'))
        Q.grid(row=4, column=3, ipadx=6, ipady=10)

        J = ttk.Button(key, text='J', width=6, command=lambda: press('J'))
        J.grid(row=4, column=4, ipadx=6, ipady=10)

        K = ttk.Button(key, text='K', width=6, command=lambda: press('K'))
        K.grid(row=4, column=5, ipadx=6, ipady=10)

        X = ttk.Button(key, text='X', width=6, command=lambda: press('X'))
        X.grid(row=4, column=6, ipadx=6, ipady=10)

        B = ttk.Button(key, text='B', width=6, command=lambda: press('B'))
        B.grid(row=4, column=7, ipadx=6, ipady=10)

        M = ttk.Button(key, text='M', width=6, command=lambda: press('M'))
        M.grid(row=4, column=8, ipadx=6, ipady=10)

        W = ttk.Button(key, text='W', width=6, command=lambda: press('W'))
        W.grid(row=4, column=9, ipadx=6, ipady=10)

        V = ttk.Button(key, text='V', width=6, command=lambda: press('V'))
        V.grid(row=4, column=10, ipadx=6, ipady=10)

        Z = ttk.Button(key, text='Z', width=6,
                                command=lambda: press('Z'))
        Z.grid(row=4, column=11, ipadx=6, ipady=10)

        clear = ttk.Button(key, text='Clear', width=6, command=Clear)
        clear.grid(row=4, column=12, columnspan=2, ipadx=55, ipady=10)

            # Fifth Row Buttons

        # ctrol = ttk.Button(key, text='Space', width=6,
        #                     command=lambda: press(' Ctrl'))
        # ctrol.grid(row=5, column=0, columnspan=8, ipadx=6, ipady=10)
            
        # win = ttk.Button(key, text='Win', width=6,
        #                     command=lambda: press('Win'))
        # win.grid(row=5, column=1, columnspan=8, ipadx=6, ipady=10)
        
        # altt = ttk.Button(key, text='ALT', width=6,
        #                     command=lambda: press(' Alt'))
        # altt.grid(row=5, column=2, columnspan=8, ipadx=6, ipady=10)

        space = ttk.Button(key, text='Space', width=6,
                            command=lambda: press(' '))
        space.grid(row=5, column=0, columnspan=12, ipadx=350, ipady=10)

        theme = ttk.Button(key, text='Theme', width=6, command=Theme)
        theme.grid(row=5, column=13, columnspan=2, ipadx=55, ipady=10)
        key.mainloop()
    elif (is_caps and not is_shift):
        tick = ttk.Button(key, text='`', width=6, command=lambda: press('`'))
        tick.grid(row=1, column=0, ipadx=6, ipady=10)

        num1 = ttk.Button(key, text='1', width=6, command=lambda: press('1'))
        num1.grid(row=1, column=1, ipadx=6, ipady=10)

        num2 = ttk.Button(key, text='2', width=6, command=lambda: press('2'))
        num2.grid(row=1, column=2, ipadx=6, ipady=10)

        num3 = ttk.Button(key, text='3', width=6, command=lambda: press('3'))
        num3.grid(row=1, column=3, ipadx=6, ipady=10)

        num4 = ttk.Button(key, text='4', width=6, command=lambda: press('4'))
        num4.grid(row=1, column=4, ipadx=6, ipady=10)

        num5 = ttk.Button(key, text='5', width=6, command=lambda: press('5'))
        num5.grid(row=1, column=5, ipadx=6, ipady=10)

        num6 = ttk.Button(key, text='6', width=6, command=lambda: press('6'))
        num6.grid(row=1, column=6, ipadx=6, ipady=10)

        num7 = ttk.Button(key, text='7', width=6, command=lambda: press('7'))
        num7.grid(row=1, column=7, ipadx=6, ipady=10)

        num8 = ttk.Button(key, text='8', width=6, command=lambda: press('8'))
        num8.grid(row=1, column=8, ipadx=6, ipady=10)

        num9 = ttk.Button(key, text='9', width=6, command=lambda: press('9'))
        num9.grid(row=1, column=9, ipadx=6, ipady=10)

        num0 = ttk.Button(key, text='0', width=6, command=lambda: press('0'))
        num0.grid(row=1, column=10, ipadx=6, ipady=10)

        square_brackets_open = ttk.Button(key, text='[', width=6, command=lambda: press('['))
        square_brackets_open.grid(row=1, column=11, ipadx=6, ipady=10)

        square_brackets_closed = ttk.Button(key, text=']', width=6, command=lambda: press(']'))
        square_brackets_closed.grid(row=1, column=12, ipadx=6, ipady=10)
        
        backspace = ttk.Button(
                key, text='<--', width=6, command=Backspace)
        backspace.grid(row=1, column=13, ipadx=6, ipady=10)
            # Second Row Buttons

        tab_button = ttk.Button(key, text='Tab', width=6,
                                    command=lambda: press('\t'))
        tab_button.grid(row=2, column=0,  ipadx=6, ipady=10)
        
        single_quote = ttk.Button(key, text ="'", width = 6, command = lambda: press("'"))
        single_quote.grid(row = 2, column=1, ipadx = 6, ipady= 10)
        
        comma = ttk.Button(key, text =",", width = 6, command = lambda: press(","))
        comma.grid(row = 2, column=2, ipadx = 6, ipady= 10)
        
        period = ttk.Button(key, text =".", width = 6, command = lambda: press("."))
        period.grid(row = 2, column=3, ipadx = 6, ipady= 10)
        
        P = ttk.Button(key, text='P', width=6, command=lambda: press('P'))
        P.grid(row=2, column=4, ipadx = 6, ipady=10)

        Y = ttk.Button(key, text='Y', width=6, command=lambda: press('Y'))
        Y.grid(row=2, column=5, ipadx=6, ipady=10)

        F = ttk.Button(key, text='F', width=6, command=lambda: press('F'))
        F.grid(row=2, column=6, ipadx=6, ipady=10)

        G = ttk.Button(key, text='G', width=6, command=lambda: press('G'))
        G.grid(row=2, column=7, ipadx=6, ipady=10)

        C = ttk.Button(key, text='C', width=6, command=lambda: press('C'))
        C.grid(row=2, column=8, ipadx=6, ipady=10)

        R = ttk.Button(key, text='R', width=6, command=lambda: press('R'))
        R.grid(row=2, column=9, ipadx=6, ipady=10)

        L = ttk.Button(key, text='L', width=6, command=lambda: press('L'))
        L.grid(row=2, column=10, ipadx=6, ipady=10)
        
        backslash = ttk.Button(
                key, text='/', width=6, command=lambda: press('/'))
        backslash.grid(row=2, column=11, ipadx=6, ipady=10)

        equal = ttk.Button(key, text='=', width=6,
                                command=lambda: press('='))
        equal.grid(row=2, column=12, ipadx=6, ipady=10)
            
        frontslash = ttk.Button(key, text='\\', width=6,
                                command=lambda: press('\\'))
        frontslash.grid(row=2, column=13, ipadx=6, ipady=10)

            # Third Row Buttons
        caps = ttk.Button(key, text ='Caps', width = 6, command = CapsLock)
        caps.grid(row=3, column=0, ipadx=6, ipady=10)
        
        A = ttk.Button(key, text='A', width=6, command=lambda: press('A'))
        A.grid(row=3, column=1, ipadx=6, ipady=10)

        O = ttk.Button(key, text='O', width=6, command=lambda: press('O'))
        O.grid(row=3, column=2, ipadx=6, ipady=10)

        E = ttk.Button(key, text='E', width=6, command=lambda: press('E'))
        E.grid(row=3, column=3, ipadx=6, ipady=10)

        U = ttk.Button(key, text='U', width=6, command=lambda: press('U'))
        U.grid(row=3, column=4, ipadx=6, ipady=10)

        I = ttk.Button(key, text='I', width=6, command=lambda: press('I'))
        I.grid(row=3, column=5, ipadx=6, ipady=10)

        D = ttk.Button(key, text='D', width=6, command=lambda: press('D'))
        D.grid(row=3, column=6, ipadx=6, ipady=10)

        H = ttk.Button(key, text='H', width=6, command=lambda: press('H'))
        H.grid(row=3, column=7, ipadx=6, ipady=10)

        T = ttk.Button(key, text='T', width=6, command=lambda: press('T'))
        T.grid(row=3, column=8, ipadx=6, ipady=10)

        N = ttk.Button(key, text='N', width=6, command=lambda: press('N'))
        N.grid(row=3, column=9, ipadx=6, ipady=10)

        S = ttk.Button(key, text='S', width=6,
                            command=lambda: press('S'))
        S.grid(row=3, column=10, ipadx=6, ipady=10)
        
        minus = ttk.Button(key, text='-', width=6,
                                command=lambda: press('-'))
        minus.grid(row=3, column=11, ipadx=6, ipady=10)

        enter = ttk.Button(key, text='Enter', width=6,
                            command=lambda: press('\n'))
        enter.grid(row=3, column=12, columnspan= 2, ipadx=55, ipady=10)

            # Fourth Row Buttons

        shift = ttk.Button(key, text='Shift', width=6, command=Shift)
        shift.grid(row=4, column=0, columnspan=2, ipadx=55, ipady=10)

        Semi_Colon = ttk.Button(key, text=';', width=6, command=lambda: press(';'))
        Semi_Colon.grid(row=4, column=2, ipadx=6, ipady=10)
        
        Q = ttk.Button(key, text='Q', width=6, command=lambda: press('Q'))
        Q.grid(row=4, column=3, ipadx=6, ipady=10)

        J = ttk.Button(key, text='J', width=6, command=lambda: press('J'))
        J.grid(row=4, column=4, ipadx=6, ipady=10)

        K = ttk.Button(key, text='K', width=6, command=lambda: press('K'))
        K.grid(row=4, column=5, ipadx=6, ipady=10)

        X = ttk.Button(key, text='X', width=6, command=lambda: press('X'))
        X.grid(row=4, column=6, ipadx=6, ipady=10)

        B = ttk.Button(key, text='B', width=6, command=lambda: press('B'))
        B.grid(row=4, column=7, ipadx=6, ipady=10)

        M = ttk.Button(key, text='M', width=6, command=lambda: press('M'))
        M.grid(row=4, column=8, ipadx=6, ipady=10)

        W = ttk.Button(key, text='W', width=6, command=lambda: press('W'))
        W.grid(row=4, column=9, ipadx=6, ipady=10)

        V = ttk.Button(key, text='V', width=6, command=lambda: press('V'))
        V.grid(row=4, column=10, ipadx=6, ipady=10)

        Z = ttk.Button(key, text='Z', width=6,
                                command=lambda: press('Z'))
        Z.grid(row=4, column=11, ipadx=6, ipady=10)
        clear = ttk.Button(key, text='Clear', width=6, command=Clear)
        clear.grid(row=4, column=12, columnspan=2, ipadx=55, ipady=10)

            # Fifth Row Buttons
            
        # ctrol = ttk.Button(key, text='Space', width=6,
        #                     command=lambda: press(' Ctrl'))
        # ctrol.grid(row=5, column=0, columnspan=8, ipadx=350, ipady=10)
            
        # win = ttk.Button(key, text='Space', width=6,
        #                     command=lambda: press(' '))
        # win.grid(row=5, column=1, columnspan=8, ipadx=350, ipady=10)
        # altt = ttk.Button(key, text='Space', width=6,
        #                     command=lambda: press(' '))
        # altt.grid(row=5, column=2, columnspan=8, ipadx=350, ipady=10)

        space = ttk.Button(key, text='Space', width=6,
                            command=lambda: press(' '))
        space.grid(row=5, column=0, columnspan=12, ipadx=350, ipady=10)

        theme = ttk.Button(key, text='Theme', width=6, command=Theme)
        theme.grid(row=5, column=13, columnspan=2, ipadx=55, ipady=10)
        key.mainloop()
    else:
        tilda = ttk.Button(key, text='~', width=6, command=lambda: press('~'))
        tilda.grid(row=1, column=0, ipadx=6, ipady=10)

        num1 = ttk.Button(key, text='!', width=6, command=lambda: press('!'))
        num1.grid(row=1, column=1, ipadx=6, ipady=10)

        num2 = ttk.Button(key, text='@', width=6, command=lambda: press('@'))
        num2.grid(row=1, column=2, ipadx=6, ipady=10)
        
        num3 = ttk.Button(key, text='#', width=6, command=lambda: press('#'))
        num3.grid(row=1, column=3, ipadx=6, ipady=10)

        num4 = ttk.Button(key, text='$', width=6, command=lambda: press('$'))
        num4.grid(row=1, column=4, ipadx=6, ipady=10)

        num5 = ttk.Button(key, text='%', width=6, command=lambda: press('%'))
        num5.grid(row=1, column=5, ipadx=6, ipady=10)

        num6 = ttk.Button(key, text='^', width=6, command=lambda: press('^'))
        num6.grid(row=1, column=6, ipadx=6, ipady=10)

        num7 = ttk.Button(key, text='&', width=6, command=lambda: press('&'))
        num7.grid(row=1, column=7, ipadx=6, ipady=10)

        num8 = ttk.Button(key, text='*', width=6, command=lambda: press('*'))
        num8.grid(row=1, column=8, ipadx=6, ipady=10)

        num9 = ttk.Button(key, text='(', width=6, command=lambda: press('('))
        num9.grid(row=1, column=9, ipadx=6, ipady=10)

        num0 = ttk.Button(key, text=')', width=6, command=lambda: press(')'))
        num0.grid(row=1, column=10, ipadx=6, ipady=10)

        curlyO = ttk.Button(key, text='{', width=6, command=lambda: press('{'))
        curlyO.grid(row=1, column=11, ipadx=6, ipady=10)

        curlyC= ttk.Button(key, text='}', width=6, command=lambda: press('}'), )
        curlyC.grid(row=1, column=12, ipadx=6, ipady=10)

        backspace = ttk.Button(
                key, text='<---', width=6, command=Backspace)
        backspace.grid(row=1, column=13, ipadx=6, ipady=10)

            # Second Row Buttons

        tab_button = ttk.Button(key, text='Tab', width=6,
                                    command=lambda: press('\t'))
        tab_button.grid(row=2, column=0, ipadx=6, ipady=10)
        
        quote = ttk.Button(key, text='"', width=6, command=lambda: press('"'))
        quote.grid(row=2, column=1, ipadx=6, ipady=10)

        lArrow = ttk.Button(key, text='<', width=6, command=lambda: press('<'))
        lArrow.grid(row=2, column=2, ipadx=6, ipady=10)

        rArrow = ttk.Button(key, text='>', width=6, command=lambda: press('>')) #, style = 'red'
        rArrow.grid(row=2, column=3, ipadx=6, ipady=10)
        
        P = ttk.Button(key, text='p', width=6, command=lambda: press('p'))
        P.grid(row=2, column=4, ipadx = 6, ipady=10)

        Y = ttk.Button(key, text='y', width=6, command=lambda: press('y'))
        Y.grid(row=2, column=5, ipadx=6, ipady=10)

        F = ttk.Button(key, text='f', width=6, command=lambda: press('f'))
        F.grid(row=2, column=6, ipadx=6, ipady=10)

        G = ttk.Button(key, text='g', width=6, command=lambda: press('g'))
        G.grid(row=2, column=7, ipadx=6, ipady=10)

        C = ttk.Button(key, text='c', width=6, command=lambda: press('c'))
        C.grid(row=2, column=8, ipadx=6, ipady=10)

        R = ttk.Button(key, text='r', width=6, command=lambda: press('r'))
        R.grid(row=2, column=9, ipadx=6, ipady=10)

        L = ttk.Button(key, text='l', width=6, command=lambda: press('l'))
        L.grid(row=2, column=10, ipadx=6, ipady=10)
        
        question = ttk.Button(
                key, text='?', width=6, command=lambda: press('?'))
        question.grid(row=2, column=11, ipadx=6, ipady=10)

        plus= ttk.Button(key, text='+', width=6,
                                command=lambda: press('+'))
        plus.grid(row=2, column=12, ipadx=6, ipady=10)
            
        verticleslash = ttk.Button(key, text='|', width=6,
                                command=lambda: press('|'))
        verticleslash.grid(row=2, column=13, ipadx=6, ipady=10)
            # Third Row Buttons.
            
        caps = ttk.Button(key, text ='Caps', width = 6, command = CapsLock)
        caps.grid(row=3, column=0, ipadx=6, ipady=10)
        
        A = ttk.Button(key, text='a', width=6, command=lambda: press('a'), style= 'JS.TButton')
        A.grid(row=3, column=1, ipadx=6, ipady=10)

        O = ttk.Button(key, text='o', width=6, command=lambda: press('o'))
        O.grid(row=3, column=2, ipadx=6, ipady=10)

        E = ttk.Button(key, text='e', width=6, command=lambda: press('e'))
        E.grid(row=3, column=3, ipadx=6, ipady=10)

        U = ttk.Button(key, text='u', width=6, command=lambda: press('u'))
        U.grid(row=3, column=4, ipadx=6, ipady=10)

        I = ttk.Button(key, text='i', width=6, command=lambda: press('i'))
        I.grid(row=3, column=5, ipadx=6, ipady=10)

        D = ttk.Button(key, text='d', width=6, command=lambda: press('d'))
        D.grid(row=3, column=6, ipadx=6, ipady=10)

        H = ttk.Button(key, text='h', width=6, command=lambda: press('h'))
        H.grid(row=3, column=7, ipadx=6, ipady=10)

        T = ttk.Button(key, text='t', width=6, command=lambda: press('t'))
        T.grid(row=3, column=8, ipadx=6, ipady=10)

        N = ttk.Button(key, text='n', width=6, command=lambda: press('n'))
        N.grid(row=3, column=9, ipadx=6, ipady=10)

        S = ttk.Button(key, text='s', width=6,
                            command=lambda: press('s'))
        S.grid(row=3, column=10, ipadx=6, ipady=10)
        
        underscore = ttk.Button(key, text='_', width=6,
                                command=lambda: press('_'))
        underscore.grid(row=3, column=11, ipadx=6, ipady=10)

        enter = ttk.Button(key, text='Enter', width=6,
                            command=lambda: press('\n'))
        enter.grid(row=3, column=12, columnspan= 2, ipadx=55, ipady=10)

            # Fourth Row Buttons

        shift = ttk.Button(key, text='Shift', width=6, command=Shift)
        shift.grid(row=4, column=0, columnspan=2, ipadx=55, ipady=10)
        
        Q = ttk.Button(key, text='q', width=6, command=lambda: press('q'))
        Q.grid(row=4, column=3, ipadx=6, ipady=10)

        J = ttk.Button(key, text='j', width=6, command=lambda: press('j'))
        J.grid(row=4, column=4, ipadx=6, ipady=10)

        K = ttk.Button(key, text='k', width=6, command=lambda: press('k'))
        K.grid(row=4, column=5, ipadx=6, ipady=10)

        X = ttk.Button(key, text='x', width=6, command=lambda: press('x'))
        X.grid(row=4, column=6, ipadx=6, ipady=10)

        B = ttk.Button(key, text='b', width=6, command=lambda: press('b'))
        B.grid(row=4, column=7, ipadx=6, ipady=10)

        M = ttk.Button(key, text='m', width=6, command=lambda: press('m'))
        M.grid(row=4, column=8, ipadx=6, ipady=10)

        W = ttk.Button(key, text='w', width=6, command=lambda: press('w'))
        W.grid(row=4, column=9, ipadx=6, ipady=10)

        V = ttk.Button(key, text='v', width=6, command=lambda: press('v'))
        V.grid(row=4, column=10, ipadx=6, ipady=10)

        Z = ttk.Button(key, text='z', width=6,
                                command=lambda: press('z'))
        Z.grid(row=4, column=11, ipadx=6, ipady=10)

        clear = ttk.Button(key, text='Clear', width=6, command=Clear)
        clear.grid(row=4, column=12, columnspan=2, ipadx=55, ipady=10)

            # Fifth Row Buttons
            
        # ctrol = ttk.Button(key, text='Space', width=6,
        #                     command=lambda: press(' Ctrl'))
        # ctrol.grid(row=5, column=0, columnspan=8, ipadx=350, ipady=10)
            
        # win = ttk.Button(key, text='Space', width=6,
        #                     command=lambda: press(' '))
        # win.grid(row=5, column=1, columnspan=8, ipadx=350, ipady=10)
        # altt = ttk.Button(key, text='Space', width=6,
        #                     command=lambda: press(' '))
        # altt.grid(row=5, column=2, columnspan=8, ipadx=350, ipady=10)

        space = ttk.Button(key, text='Space', width=6,
                            command=lambda: press(' '))
        space.grid(row=5, column=0, columnspan=12, ipadx=350, ipady=10)

        theme = ttk.Button(key, text='Theme', width=6, command=Theme)
        theme.grid(row=5, column=13, columnspan=2, ipadx=55, ipady=10)

        key.mainloop()

        
#run the keyboard
display()