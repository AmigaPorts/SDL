# 26 Exec Interrupts / Disabling Interrupts


As mentioned in the "[Exec Tasks](../Libraries_Manual_guide/node02C3.html)" chapter, it is sometimes necessary to
disable interrupts when examining or modifying certain shared system data
structures.  However, for proper system operation, interrupts should never
be disabled unless absolutely necessary, and never for more than 250
microseconds.  Interrupt disabling is controlled with the [Disable()](../Libraries_Manual_guide/node02C3.html#line6) and
[Enable()](../Libraries_Manual_guide/node02C3.html#line6) functions. Although assembler DISABLE and ENABLE macros are
provided, we strongly suggest that you use the system functions rather
than the macros for upwards compatibility and smaller code size.

In some system code, there are nested disabled sections.  Such code
requires that interrupts be disabled with the first [Disable()](../Libraries_Manual_guide/node02C3.html#line6) and not
re-enabled until the last [Enable()](../Libraries_Manual_guide/node02C3.html#line6).  The system Enable() and Disable()
functions are designed to permit this sort of nesting.

[Disable()](../Libraries_Manual_guide/node02C3.html#line6) increments a counter to track how many levels of disable have
been issued.  Only 126 levels of nesting are permitted. [Enable()](../Libraries_Manual_guide/node02C3.html#line6)
decrements the counter, and reenables interrupts when the last disable
level has been exited.

