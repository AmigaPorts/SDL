# 15 GadTools Library / Function Reference


The following are brief descriptions of the Intuition functions discussed
in this chapter.  See the "Amiga ROM Kernel Reference Manual: Includes and
Autodocs" for details on each function call.  All of these functions
require Release 2 or a later version of the operating system.


               Table 15-2: GadTools Library Functions
  ______________________________________________________________________
 |                                                                      |
 |          Function                  Description                       |
 |======================================================================|
 |       [CreateGadgetA()](../Includes_and_Autodocs_2._guide/node03E8.html)  Allocate GadTools gadget, tag array form.     |
 |        [CreateGadget()](../Includes_and_Autodocs_2._guide/node03E8.html)  Allocate GadTools gadget, varargs form.       |
 |         [FreeGadgets()](../Includes_and_Autodocs_2._guide/node03EB.html)  Free all GadTools gadgets.                    |
 |  [GT_SetGadgetAttrsA()](../Includes_and_Autodocs_2._guide/node03F6.html)  Update gadget, tag array form.                |
 |   [GT_SetGadgetAttrs()](../Includes_and_Autodocs_2._guide/node03F6.html)  Update gadget, varargs form.                  |
 |       [CreateContext()](../Includes_and_Autodocs_2._guide/node03E7.html)  Create a base for adding GadTools gadgets.    |
 |----------------------------------------------------------------------|
 |        [CreateMenusA()](../Includes_and_Autodocs_2._guide/node03E9.html)  Allocate GadTools menu structures, tag array  |
 |                        form.                                         |
 |         [CreateMenus()](../Includes_and_Autodocs_2._guide/node03E9.html)  Allocate GadTools menu structures, varargs    |
 |                        form.                                         |
 |           [FreeMenus()](../Includes_and_Autodocs_2._guide/node03EC.html)  Free menus allocated with CreateMenus().      |
 |    [LayoutMenuItemsA()](../Includes_and_Autodocs_2._guide/node03F7.html)  Format GadTools menu items, tag array form.   |
 |     [LayoutMenuItems()](../Includes_and_Autodocs_2._guide/node03F7.html)  Format GadTools menu items, varargs form.     |
 |        [LayoutMenusA()](../Includes_and_Autodocs_2._guide/node03F8.html)  Format GadTools menus, tag array form.        |
 |         [LayoutMenus()](../Includes_and_Autodocs_2._guide/node03F8.html)  Format GadTools menus, varargs form.          |
 |----------------------------------------------------------------------|
 |          [GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html)  GadTools gadget compatible version of         |
 |                        [GetMsg()](../Libraries_Manual_guide/node02F2.html).                                     |
 |        [GT_ReplyIMsg()](../Includes_and_Autodocs_2._guide/node03F5.html)  GadTools gadget compatible version of         |
 |                        [ReplyMsg()](../Libraries_Manual_guide/node02F3.html).                                   |
 |       [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html)  Process GadTools gadgets with                 |
 |                        GetMsg()/ReplyMsg().                          |
 |   [GT_PostFilterIMsg()](../Includes_and_Autodocs_2._guide/node03F3.html)  Process GadTools gadgets with                 |
 |                        GetMsg()/ReplyMsg().                          |
 |----------------------------------------------------------------------|
 |    [GT_RefreshWindow()](../Includes_and_Autodocs_2._guide/node03F4.html)  Display GadTools gadget imagery after         |
 |                        creation.                                     |
 |     [GT_BeginRefresh()](../Includes_and_Autodocs_2._guide/node03EF.html)  GadTools gadget compatible version of         |
 |                        [BeginRefresh()](../Libraries_Manual_guide/node011E.html).                               |
 |       [GT_EndRefresh()](../Includes_and_Autodocs_2._guide/node03F0.html)  GadTools gadget compatible version of         |
 |                        [EndRefresh()](../Libraries_Manual_guide/node011E.html#line25).                                 |
 |----------------------------------------------------------------------|
 |       [DrawBevelBoxA()](../Includes_and_Autodocs_2._guide/node03EA.html)  Draw a 3D box, tag array form.                |
 |        [DrawBevelBox()](../Includes_and_Autodocs_2._guide/node03EA.html)  Draw a 3D box, varargs form.                  |
 |----------------------------------------------------------------------|
 |      [GetVisualInfoA()](../Includes_and_Autodocs_2._guide/node03EE.html)  Get drawing information for GadTools, tag     |
 |                        array form.                                   |
 |       [GetVisualInfo()](../Includes_and_Autodocs_2._guide/node03EE.html)  Get drawing information for GadTools, varargs |
 |                        form.                                         |
 |      [FreeVisualInfo()](../Includes_and_Autodocs_2._guide/node03ED.html)  Free drawing information for GadTools.        |
 |______________________________________________________________________|

