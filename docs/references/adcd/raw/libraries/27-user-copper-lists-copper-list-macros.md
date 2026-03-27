# 27 / User Copper Lists / Copper List Macros


Once this pointer to a user Copper list is available, you can use it with
system macros (<graphics/[gfxmacros.h](../Includes_and_Autodocs_2._guide/node00B6.html#line22)>) to instruct the system what to add
to its own list of things for the Copper to do within a specific [ViewPort](../Libraries_Manual_guide/node032B.html#line59).
The file <graphics/[gfxmacros.h](../Includes_and_Autodocs_2._guide/node00B6.html#line37)> provides the following five macro
functions that implement user Copper instructions.

[CINIT](../Includes_and_Autodocs_2._guide/node0428.html) initializes the Copper list buffer. It is used to specify how many
instructions are going to be placed in the Copper list.  It is called as
follows.


```c
    CINIT(uCopList, num_entries);
```
The uCopList argument is a pointer tot he user Copper list and num_entries
is the number of entries in the list.

[CWAIT](../Includes_and_Autodocs_2._guide/node0432.html) waits for the video beam to reach a particular horizontal and
vertical position.  Its format is:


```c
    CWAIT(uCopList, v, h)
```
Again, uCopList is the pointer to the Copper list.  The v argument is the
vertical position for which to wait, specified relative to the top of the
[ViewPort](../Libraries_Manual_guide/node032B.html#line59).  The legal range of values (for both NTSC and PAL) is from 0 to
255; h is the horizontal position for which to wait.  The legal range of
values (for both NTSC and PAL) is from 0 to 226.

[CMOVE](../Includes_and_Autodocs_2._guide/node0430.html) installs a particular value into a specified system register. Its
format is:


```c
    CMOVE(uCopList, reg, value)
```
Again, uCopList is the pointer to the Copper list.  The reg argument is
the register to be affected, specified in this form:  custom.register-name
where the register-name is one of the registers listed in the Custom
structure in <hardware/[custom.h](../Includes_and_Autodocs_2._guide/node00CD.html#line25)>.  The value argument to [CMOVE](../Includes_and_Autodocs_2._guide/node0430.html) is the
value to place in the register.

[CBump()](../Includes_and_Autodocs_2._guide/node0425.html) increments the user Copper list pointer to the next position in
thelist.  It is usually invoked for the programmer as part of the macro
definitions [CWAIT](../Includes_and_Autodocs_2._guide/node0432.html) or [CMOVE](../Includes_and_Autodocs_2._guide/node0430.html).  Its format is:


```c
    CBump(uCopList)
```
where uCopList is the pointer to the user Copper list.

[CEND](../Includes_and_Autodocs_2._guide/node0426.html) terminates the user Copper list.  Its format is:


```c
    CEND(uCopList)
```
where uCopList is the pointer to the user Copper list.

Executing any of the user Copper list macros causes the system to
dynamically allocate special data structures called intermediate Copper
lists that are linked into your user Copper list (the list to which
uCopList points) describing the operation. When you call the function
[MrgCop](../Libraries_Manual_guide/node0332.html#line27)(&view) as shown in the section called "[Forming A Basic Display](../Libraries_Manual_guide/node0332.html),"
the system uses all of its intermediate Copper lists to sort and merge
together the real Copper lists for the system ([LOFCprList and SHFCprList](../Includes_and_Autodocs_2._guide/node00B8.html#line57)).

When your program exits, you must return to the system all of the memory
that you allocated or caused to be allocated.  This means that you must
return the intermediate Copper lists, as well as the user Copper list data
structure.  Here are two different methods for returning this memory to
the system.


```c
    /* Returning memory to the system if you have NOT
     * obtained the ViewPort from Intuition.  */
    FreeVPortCopLists(viewPort);

    /* Returning memory to the system if you HAVE
     * obtained the ViewPort from Intuition.  */
    CloseScreen(screen);    /* Intuition only */
```
User Copper lists may be clipped, under Release 2 and later, to [ViewPort](../Libraries_Manual_guide/node032B.html#line59)
boundaries if the appropriate tag (VTAG_USERCLIP_SET) is passed to
[VideoControl()](../Libraries_Manual_guide/node0339.html#line15).  Under earlier releases, the user Copper list would "leak"
through to lower ViewPorts.

