# 14 / The Workbench Library / Workbench Library Functions


[AppWindows](../Libraries_Manual_guide/node0245.html#line5), [AppIcons](../Libraries_Manual_guide/node0245.html#line11) and [AppMenuItems](../Libraries_Manual_guide/node0245.html#line17) extend the user's ability to perform
operations with the Workbench iconic interface.  They all provide
graphical methods for passing arguments to a running application. In order
to manage AppWindows, AppIcons and AppMenuItems, the Amiga OS includes
these Workbench library functions:


struct AppIcon     *AddAppIconA( ULONG, ULONG, char *, struct MsgPort *,
```c
                                 struct FileLock *, struct DiskObject *,
                                 struct *TagItem );
```
struct AppMenuItem *AddAppMenuItemA( ULONG, ULONG, char *,
```c
                                     struct MsgPort *, struct *TagItem);
```
struct AppWindow   *AddAppWindowA( ULONG, ULONG, struct Window *,

```c
                                   struct MsgPort *, struct *TagItem);
```
BOOL                RemoveAppIcon(struct AppIcon *);
BOOL                RemoveAppMenuItem(struct AppMenuItem *);
BOOL                RemoveAppWindow(struct AppWindow  *);


The functions [AddAppMenuItemA()](../Includes_and_Autodocs_2._guide/node0408.html), [AddAppWindowA()](../Includes_and_Autodocs_2._guide/node0409.html) and [AddAppIconA()](../Includes_and_Autodocs_2._guide/node0407.html) have
alternate entry points using the same function name without the trailing
A.  The alternate functions accept any [TagItem](../Libraries_Manual_guide/node0497.html) arguments on the stack
instead of from an array. See the listings below for examples.

