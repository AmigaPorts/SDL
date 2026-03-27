# 6 Intuition Menus / Setting Up Menus


The application does not have to worry about handling the menu display.
The menus are simply submitted to Intuition and the application waits for
Intuition to send messages about the selection of menu items.  These
messages, along with the data in the menu structures, give the application
all the information required for the processing of the user actions.

Menus can be set up with the GadTools library on systems running Release 2
or a later version of the OS.  Since GadTools makes menu set up easier and
handles much of the detail work of menu processing (including adjusting to
the current font selection), it should be used whenever possible.

Under 1.3 (V34) and older versions of the OS, GadTools is not available.
To set up menus that work with these older systems, you use the [Menu](../Libraries_Manual_guide/node0199.html) and
[MenuItem](../Libraries_Manual_guide/node019A.html) structures.  In general, for each menu in the menu bar, you
declare one instance of the Menu structure.  For each item or sub-item
within a menu, you declare one instance of the MenuItem structure.
Text-based menus like the kind used in this chapter require an additional
[IntuiText](../Libraries_Manual_guide/node01C7.html) structure for each menu, menu item and sub-item.  All these
structures are defined in <intuition/[intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html)>.

The data structures used for menus are linked together to form a list
known as a menu strip.  For all the details of how the structures are
linked and for listings of [Menu](../Libraries_Manual_guide/node0199.html) and [MenuItem](../Libraries_Manual_guide/node019A.html), see the [Menu Data Structures](../Libraries_Manual_guide/node0198.html)"
section later in this chapter.

 [Submitting and Removing Menu Strips](../Libraries_Manual_guide/node0181.html) 
 [Simple Menu Example](../Libraries_Manual_guide/node0182.html) 
 [Disabling Menu Operations](../Libraries_Manual_guide/node0183.html) 
 [Changing Menu Strips](../Libraries_Manual_guide/node0184.html) 
 [Sharing Menu Strips](../Libraries_Manual_guide/node0185.html) 
 [Menu Selection Messages](../Libraries_Manual_guide/node0186.html) 
 [Menu Numbers](../Libraries_Manual_guide/node0188.html) 
 [Help Key Processing in Menus](../Libraries_Manual_guide/node018A.html) 
 [Menu Layout](../Libraries_Manual_guide/node018B.html) 
 [About Menu Item Boxes](../Libraries_Manual_guide/node018C.html) 
 [Attribute Items and the Checkmark](../Libraries_Manual_guide/node018D.html) 
 [Toggle Selection](../Libraries_Manual_guide/node018E.html) 
 [Mutual Exclusion](../Libraries_Manual_guide/node018F.html) 
 [Managing the State of Checkmarks](../Libraries_Manual_guide/node0190.html) 
 [Command Key Sequences](../Libraries_Manual_guide/node0191.html) 
 [Enabling and Disabling Menus and Menu Items](../Libraries_Manual_guide/node0192.html) 
 [Intercepting Normal Menu Operations](../Libraries_Manual_guide/node0193.html) 

