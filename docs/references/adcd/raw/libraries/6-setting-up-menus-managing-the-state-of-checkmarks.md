# 6 / Setting Up Menus / Managing the State of Checkmarks


To correctly handle checkmarked menu items, from time to time the
application will need to read the [CHECKED](../Libraries_Manual_guide/node019B.html#line7) bit of its [CHECKIT](../Libraries_Manual_guide/node019B.html#line3) [MenuItem](../Libraries_Manual_guide/node019A.html)s.
It is not adequate to infer which items are checked by tracking what their
state must have become.  There are several reasons for this (although it's
not important to understand the details; just the implication):

  * Using multi-selection of menus, the user can toggle the state of a

```c
    [MENUTOGGLE](../Libraries_Manual_guide/node019B.html#line24) item several times, yet the application will receive only
    a single [IDCMP_MENUPICK](../Libraries_Manual_guide/node01DE.html) event, and that item will only appear once
    one the [NextSelect](../Libraries_Manual_guide/node019A.html#line93) chain.
```
  * When the user selects a mutually exclusive menu item, the

```c
    [IDCMP_MENUPICK](../Libraries_Manual_guide/node01DE.html) event refers to that item, but Intuition doesn't
    notify your application of other items that may have been deselected
    through mutual exclusion.
```
  * Prior to V36, unusually complex multi-selection operations could

```c
    orphan menu selections.  That is to say, some items that were
    selected may not even appear on the [NextSelect](../Libraries_Manual_guide/node019A.html#line93) chain.  If such an
    item had a checkmark, the state of that checkmark could nevertheless
    have changed.
```
  * For complex multi-selection operations, the [NextSelect](../Libraries_Manual_guide/node019A.html#line93) chain will not

```c
    be in select-order (a side-effect of the fact that the same [MenuItem](../Libraries_Manual_guide/node019A.html)
    cannot appear twice in the same NextSelect chain combined with the
    fix to the orphaning problems mentioned above).  With certain mutual
    exclusion arrangements, it is impossible to predict the state of the
    checkmarks.
```
  * If the user begins multi-selection in the menus and hits several

```c
    checkmarked items, but then presses the help key, the application
    will receive an [IDCMP_MENUHELP](../Libraries_Manual_guide/node01DE.html#line21) message.  No [IDCMP_MENUPICK](../Libraries_Manual_guide/node01DE.html) message
    will have been sent.  Thus, some checkmark changes could have gone
    unnoticed by the application.
```
It is legal to examine the [CHECKED](../Libraries_Manual_guide/node019B.html#line7) state of a [MenuItem](../Libraries_Manual_guide/node019A.html) while that MenuItem
is still attached to a window.  It is unnecessary to first call
[ClearMenuStrip()](../Libraries_Manual_guide/node0181.html#line11).

