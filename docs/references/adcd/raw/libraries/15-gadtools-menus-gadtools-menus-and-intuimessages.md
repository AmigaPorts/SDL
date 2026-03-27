# 15 / GadTools Menus / GadTools Menus and IntuiMessages


If the window uses GadTools menus and GadTools gadgets, then use the
[GT_GetIMsg()](../Libraries_Manual_guide/node025B.html) and [GT_ReplyIMsg()](../Libraries_Manual_guide/node025B.html) functions described below (or
[GT_FilterIMsg()](../Libraries_Manual_guide/node0271.html) and [GT_PostFilterIMsg()](../Libraries_Manual_guide/node0271.html), if applicable).  However, if the
window has GadTools menus, but no GadTools gadgets, it is acceptable to
use [GetMsg()](../Libraries_Manual_guide/node02F2.html) and [ReplyMsg()](../Libraries_Manual_guide/node02F3.html) in the usual manner.

Additionally, no context need be created with [CreateContext()](../Libraries_Manual_guide/node026D.html) if no
GadTools gadgets are used.  For more about these functions, see the
section on "[Other GadTools Functions](../Libraries_Manual_guide/node0270.html)" later in this chapter.

