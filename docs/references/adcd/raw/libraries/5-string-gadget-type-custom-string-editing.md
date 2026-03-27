# 5 / String Gadget Type / Custom String Editing


The application may choose to control the editing features provided in
[string](../Libraries_Manual_guide/node0164.html) gadgets used within the application.  To locally install the custom
string editing features, the application provides a hook in the
[StringExtend](../Libraries_Manual_guide/node016D.html) structure [EditHook](../Libraries_Manual_guide/node016D.html#line89) field.

A hook is a well defined calling interface for a user provided subroutine
or function.  Hooks are more fully described in the "[Utility Library](../Libraries_Manual_guide/node04A2.html)"
chapter.  A [string](../Libraries_Manual_guide/node0164.html) gadget hook is called in the standard way, where the
hook object is a pointer to a [SGWork](../Libraries_Manual_guide/node016F.html) structure, and the hook message is a
pointer to a command block.  However, unlike a function callback hook, a
string gadget editing hook is called on Intuition's task context, not on
the application's own context.  Therefore, a string gadget editing hook
must not use dos.library, and may not [Wait()](../Libraries_Manual_guide/node02D4.html) on application signals or
message ports, and may not call any Intuition function which might wait
for Intuition.

The command block starts with either (longword) [SGH_KEY](../Libraries_Manual_guide/node0172.html) or [SGH_CLICK](../Libraries_Manual_guide/node0174.html).
There may be new commands added in the future, so the application should
not assume that these are the only possible commands. The hook should
return zero if it doesn't understand the command and non-zero if the
command is supported.

The [SGWork](../Libraries_Manual_guide/node016F.html) structure, defined in <intuition/[sghooks.h](../Includes_and_Autodocs_2._guide/node00E5.html#line32)>, is listed on the
next page.  Use this structure as the hook object for custom string
editing hooks.

 [SGWork Structure](../Libraries_Manual_guide/node016F.html)       [Actions with SGH_KEY](../Libraries_Manual_guide/node0173.html) 
 [EditOp Definitions](../Libraries_Manual_guide/node0170.html)     [The SGH_CLICK Command](../Libraries_Manual_guide/node0174.html) 
 [Actions Definitions](../Libraries_Manual_guide/node0171.html)    [Actions with SGH_CLICK](../Libraries_Manual_guide/node0175.html) 
 [The SGH_KEY Command](../Libraries_Manual_guide/node0172.html)    [Example String Gadget Editing Hook](../Libraries_Manual_guide/node0596.html) 

