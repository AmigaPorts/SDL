# Using the Amiga 3000

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

We recommend working through the following exercises step by step. 

While providing a  quick overview of the use and capabilities of the
3000, a  lot of important information is included that everyone will find 

useful.

## 2.1 The Workbench

Since the SCSI hard disk comes factory-installed, a  few seconds after switching on the computer the graphical user interface, called the
Workbench, appears. If you're already familiar with previous versions of 

the Amiga, you'll immediately notice some changes. The Workbench window is no longer just a  background screen. It has acquired a  border with which it can be moved around, brought into the foreground or reduced in size. There is even a  close gadget (which should be used carefully). Professional color selection and the appearance of
3-dimension are impressive enhancements that dress up the Workbench 

window. There is now just a  single gadget for superimposing windows: the back/front gadget. Click on it once and the screen or window is brought into the foreground. A  second click restores the object to the background. Next to the back/front gadget, a  window has a  new gadget, by which it can be toggled between two alternate sizes and positions. This is referred to as the alternate gadget.

### 2.1.1 Starting AmigaOS 2.x

At this point some suggestions concerning the startup of the Workbench may be helpful. Let's begin with the Startup-sequence script file in the S directory. This file contains all the commands and parameters necessary to start the system. Configuring the system to one's own wishes used to require making various changes. Remember if a  command results in output to the InitialCLI window, the Workbench screen is opened and the CLI window appears on it. This is not desired, since there is the opening of windows on the Workbench screen before the screen itself is activated. Here's why. When the LoadWB command wants to open the Workbench, the
"workbench.library" attempts to use the stored display mode for the 

Workbench screen. If the screen is not yet present, there is no problem. If 

it is, an attempt is made to close it and open a  new one in the desired mode. This fails when the screen to be closed contains a  CLI or user window. The result is a  system requester requesting that all windows be closed.
Let's assume a  user is working with the A2024 monitor, which requires a 

special driver. Suddenly nothing can be seen on the screen, and without an understanding of the system, nothing can be done to solve this problem.

Several things could be done to prevent this situation from occurring. 

First of all, only those commands that must be executed before the 

activation of the Workbench should precede the LoadWB command.
Secondly, the "Command >NIL: parameter" format should be used to null 

their output.

Another possibility is offered through the directory WbStartup. All 

programs (i.e., icons that are located here) are started after activation of the Workbench, just as if they were selected with a  double-click of the left mouse button. For example, if you will be working for an extended amount of time with a  particular word processing task, you can simply place the icon of the word processor, or the text itself, in this directory.
Startup-sequence complications with autostarting programs can be 

avoided by simply modifying the placement of icons.

### 2.1.2 The Workbench Menus

Your acquaintance with the Amiga will require you to be familiar with 

the Workbench menu functions. Even CLI enthusiasts should make thorough use of them, since now the CLI can be entirely replaced by the graphical user interface. Before we proceed with the individual items, we should mention one more innovation regarding the selection of icons. If you press the left mouse button and hold it down while moving the mouse, a  rectangular box appears on the Workbench or in a  Workbench window. When the left mouse button is released, all the icons within the box are selected, a  better procedure than multiple selections using the

The "Workbench" menu contains items that are independent of file or directory selections:

Backdrop This item is used to manipulate the Workbench window. 

Selecting it removes the border, enlarges the window to 

the full screen size and places it behind all other windows. The former condition is restored when the item is selected again.

Execute Command 

Causes a  CLI/Shell command to be executed. A 

requester appears in which a  command can be entered the same as in the Shell. A  new window is opened for resulting output and can again be closed with the use of a close gadget.

Redraw All If programs have cluttered or disrupted the workbench 

screen, you can use this item to restore all windows and icons to their original condition.

Update All If you are working with the Workbench and the Shell, 

you can use this item to show changes you have made to directories with the Shell. It updates Workbench memory and redraws the screen to reflect the current status.

Last Message 

About 

Quit 

The last message to appear on the title bar is redisplayed.

Displays a  requester showing the version numbers of 

the operating system and Workbench you are using. This also shows the copyright notice. This is the same as clicking on the close gadget of the
Workbench. If the Workbench is not blocked by any 

program windows, you can close it after confirming your decision in a  requester. This frees up memory for processes such as graphics programs that may have large memory requirements. The "Window" menu contains items that refer to directories and drives. They affect only the active window:

New Drawer Makes a  new directory and provides an icon for it. The 

name of the directory can be entered in a  requester.

Open Parent When one directory is located within another directory, 

which in turn is located within a  third, it may be advisable to close the respective parent directories.
Selecting this item will again open the directory in 

which the current window's directory is located.

Close Closes the current window (directory). 

Update In earlier versions, directory changes that were not 

applied to the Workbench had to be remade with each close and subsequent reopen of the directory in order to be reflected on the screen. This item provides a  simple way of keeping a  window's information current.

Select Contents If you want to work with all entries of a  directory, the 

entire contents can be selected with this item.

Clean Up Tidies up a  window by reorganizing its icons according 

to the window's size.

Snapshot Stores the size and position of the current window 

(submenu item "Window") and the order of all the icons 

it contains (submenu item "All").

Show Determines what will be shown in the current window. 

The submenu item "Only Icons" is the default. This shows only those objects that have an icon file (".info file). All other entries are also shown when you select the "All Files" submenu item. For example, this enables you to display CLI commands and double-click to start them, whereby a  requester appears permitting the input of parameters.

View By The preset submenu item "Icon" shows the directory 

contents by icons and, underneath them, the

corresponding filenames. All other options produce a scrollable list of entries without icons. The entries that appear in this list are determined by the "Show" criteria. Their sequence is determined by the three remaining
"View By" submenu items. Entries can be sorted by 

"Name" of file, by "Size", or by "Date" created. Files can 

be selected from these lists as they can from the display of icons. The "Icon" menu contains functions relating to icons. The upper portion consists of general activities and the lower portion consists of special icons only.

Open Opens the selected icon, which is the same as double- 

clicking on the icon with the mouse.

Copy Makes a  copy of a  file, directory or diskette. 

Rename Changes the name of an object. 

Information Opens a  large requester in which all data about an icon 

can be displayed and manipulated.

Snapshot Saves the position of the selected icon. 

Unsnapshot Deletes position information of icons saved in 

"Snapshot". 

Leave Out One of the most convenient features of the new 

Workbench. Selected icons are saved in the main 

Workbench window. This makes it possible to select the 

icon again without reopening its directory. The Leave
Out configuration is saved and remains in effect even 

after resetting or turning off the computer.

Put Away Removes icons placed in the Workbench window by 

Leave Out and displays them again with their respective 

directories.

Delete 

Deletes all selected icons and their files or directories 

after confirmation using a  requester. Format Disk Formats a  diskette. The disk is initialized and given the name "Empty". The diskette icon is then displayed.

Empty Trash Deletes the contents of the Trashcan directory. 

The "Tools" menu normally contains only the "ResetWB" function, which returns the entire Workbench to its initial status. This menu was intended for user-defined items. Unfortunately, no utility for incorporating programs into menus is supplied, although the public- domain "ToolManager" (Fish 476) can be used to accomplish this.

### 2.1.3 The Workbench Programs

Now let's look at the programs that Workbench Version 37 Revision 64 contains. We begin with the "Prefs" directory, since you will find all the programs needed to tailor the system to your needs:

Input This program establishes all the time constants for 

interrogating the keyboard and the mouse. With the
"Mouse Speed" slider, you control how much the mouse 

must be moved to cause a  corresponding movement of the mouse pointer. A  low value indicates that a  small movement of the mouse will change the position of the pointer. If this is not adequate, you can click on the
"Acceleration" box. A  check mark appears in the box 

when Acceleration is selected. Now the slightest movement of the mouse will cause a  large displacement of the pointer. You may have to go back and adjust the
Mouse Speed after selecting Acceleration. 

The "Double-Click" slider sets the maximum time span that can separate two clicks before they will be recognized separately rather than as a  double-click.
You can try this out with the "Test" button. If a  double- 

click is recognized, this is indicated in the "Show" box.

"Key Repeat Delay" sets the time after which a  key that 

is struck and not released will be considered struck again.

"Key Repeat Rate" is the speed at which a  letter will 

appear on the screen as repeated input once the Key
Repeat Delay is reached and the key continues to be 

held down. This can be checked in the Key Repeat Test field.

IControl IControl establishes keyboard commands that take the 

place of complicated mouse operations. "Verify
Timeout" is the timespan that keys must be pressed to 

activate the corresponding action. "Command Keys" are letter keys that are pressed in combination with the left
<Amiga> key to perform certain actions. For example, to 

move the Workbench into the foreground and the front screen into the background, or to substitute for the
"OK" and "Cancel" gadgets of some system requesters. 

IControl allows you to specify the letters to be used for 

these actions.

"Mouse Screen Drag" keys are used with the mouse to 

drag the screen both horizontally and vertically. With
IControl you can specify the keys (I Shift |. fctril ,(AJt) 

and/or <Amiga>) that must be held down along with the left mouse button for this operation. When such keys are paired on the keyboard, the left one should be used.

"Avoid flicker" provides for flicker-free text in special 

display modes. "Preserve colors" ensures stability and fidelity of color. With "Screen menu snap", menus will always be shown in the visible area of the screen, and with "Text gadget filter", control characters are filtered out of text.

Palette 

This allows the colors of the Workbench to be changed. The currently selected color appears in a  box to the left of the palette. Below it the red, green and blue intensity of the selected color can be adjusted.

WBpattern The main Workbench window and its directory 

windows are displayed with a  background pattern. The editor WBpattern lets you choose these patterns from eight preset selections.

Font 

Pointer 

ScreenMode 

OverScan 

Allows selection of the character sets to be used for the text underneath icons, for that displayed in the title bars of screens and windows, and for the default text of the system. You can also specify whether or not the background field behind text characters should be colored. Color selections for text and field are made separately. With this preference you can change the appearance of the mouse pointer and adjust the "hot spot" (i.e., the portion of the pointer capable of activating an object). Here the resolution and display mode of the Workbench is established. The Workbench can be made larger than the visible area of the screen. You can specify whether or not the screen display should "Autoscroll" when the selected "Width" and "Height" values exceed the visible screen dimensions. The number of possible colors can also be determined according to screen mode. If you have a  monitor on which the border area around the Workbench is visible, then you can also enlarge the
Workbench. With "Edit Text Overscan" and "Edit 

Standard Overscan" you can inform the system of the 

normal visible area of your monitor and the desired overscan display size. A  program can then open a screen that extends beyond the normal text area, so that no border is visible.

Printer 

PrinterGfx 

This program allows you to tell the system what type of printer is connected to your computer, through which port it is connected, what kind of paper you are using, and various preferences regarding text output. Here you can define several specifications for the output of graphics to the printer. Next to the "Color
Correct" area, you can choose the "Smoothing" option 

to round sharp edges and offset or centering options.
Other specifications include "Dithering," "Scaling,
"Image," "Aspect" and "Shade". 

Serial This program sets the data transfer parameters for a 

modem connected to the serial port. The maximum rate supported is 31250 baud.

Time This program establishes the date and time and sets the 

accubuffered truetime clock accordingly. The "System" directory contains programs that are used primarily by the operating system. The exceptions to this rule are "SetMap," by which you can change the assigned keyboard layout, "NoFastMem," which disables the Fast RAM area, and "FixFonts," which should always be run following changes in the Fonts directory. In the "Utilities" directory there are a  few small programs that perform helpful tasks:

Clock Displays the time in analog or digital format and has an 

alarm function.

More This is a  program for reading text files. You can scan 

through the text within a  window one page or line at a time.

Display Graphics in IFF format and even slideshows can be 

displayed with this program.

Say A  simple program to convert typed text into computer- 

synthesized speech.

Exchange and Commodities 

This is the main program of an assortment of small utilities. It controls the following programs: "Autopoint automatically activates the window over which the mouse pointer is located, "Blanker" blanks out the screen when no input has been received for a  specified period of time, "FKey" assigns function keys, "IHelp allows keyboard commands to replace many mouse operations, and "NoCapsLock" forces software disabling of the leaps Lock \  key.

## 2.2 The Command Line Interpreter

The Shell is a  window in which you can enter command lines to control the Amiga. A  command line consists of a  program name and, in some cases, additional parameters.

2.2.1 

AmigaOS 2.x Resident Commands 

Unlike in previous versions of the Amiga operating system, under 

AmigaOS 2.x many programs are stored in ROM. This allows faster 

processing and trouble-free manipulation of system directories. Some programs stored in ROM are also kept in the current system directory, because programs written for earlier versions expect them there and require them for execution. The following commands are implemented in ROM:

2.2.2 

Alias 

Get 

Set 

Ask 

Getenv 

Setenv 

CD 

If 

Skip 

Echo 

Lab 

Stack 

Else 

NewCLI 

Unalias 

EndCLI 

NewShell 

Unset 

Endlf 

Path 

Unsetenv 

EndShell 

Prompt 

Why 

EndSkip 

Quit 

.bra 

Failat 

Resident 

.ket 

Fault 

Run 

.key 

Using the CLI 

The Shell or CLI provides many features to help you edit the current command line: The left and right cursor control keys move the cursor one character position in the indicated direction. When used in conjunction with the lst1i"l key, they move the cursor to the beginning or end of the line respectively.

The I  Backspace \  key erases the character to the left of the cursor. The fDefl key erases the character at the cursor position.

[Ctrl l+fm This corresponds to I  Backspace). [ctrH+fM> to [Enter! , and 

(ctrQ+Q} to Help. 

[ctn |+fw) This erases the previous word. 

[ctril+fT) This erases the entire window (works only in 

combination with (Enter)).

( ctn >+Txl This erases the entire command line. 

Ictrit+Jui This erases the line from the beginning up to the cursor 

position.

[Ctrl I+TkI This erases the line from the cursor position to the end. 

This aborts an executing program, command file, etc.

Previously entered commands are stored. You can scan up or down 

through this list with the cursor control keys. There is a  search function for quickly locating a  particular command within a  list. Simply type the first few characters of the command you wish to locate. Then press the up or down cursor control key together with the I  Shin) key to begin searching in the desired direction for the first line that begins with the typed sequence. In the Shell window, blocks of text can be marked with the mouse and with <rt-Amiga> +  (c) as in a  word processor. The block can be copied to another window by pressing <rt-Amiga>+(v) after activating the window that is to receive the text. If you enter a  command in a  Shell window that is too small to hold the entire output, the initial lines will scroll off the top of the window and disappear from view. Enlarging the window will cause them to reappear.

## 3.1 The Libraries and their Functions

