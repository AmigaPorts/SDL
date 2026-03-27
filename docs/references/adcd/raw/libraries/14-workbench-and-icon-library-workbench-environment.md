# 14 Workbench and Icon Library / Workbench Environment


On the Amiga there are at least two ways to start a program running:

  * By activating a tool or project icon in Workbench (an icon is

```c
    activated by pointing to it with the mouse and double-clicking
    the mouse select button.)
```
  * By typing the name of an executable file at the Shell (also

```c
    known as the CLI or Command Line Interface)
```
In the Workbench environment, a program is run as a separate process.  A
process is simply a task with additional information needed to use DOS
library.

By default, a Workbench program does not have a window to which its output
will go.  Therefore, stdin and stdout do not point to legal file handles.
This means you cannot use stdio functions such as [printf()](../Includes_and_Autodocs_2._guide/node0162.html) if your program
is started from Workbench unless you first set up a stdio window.

Some compilers have options or defaults to provide a stdio window for
programs started from Workbench.  In Release 2, applications can use an
auto console window for stdio when started from Workbench by opening
"CON:0/0/640/200/auto/close/wait" as a file.  An auto console window will
only open if stdio input or output occurs.  This can also be handled in
the startup code module that comes with your compiler.

 [Argument Passing In Workbench](../Libraries_Manual_guide/node023A.html) 
 [WBStartup Message](../Libraries_Manual_guide/node023E.html) 
 [Example of Parsing Workbench Arguments](../Libraries_Manual_guide/node05C4.html) 

