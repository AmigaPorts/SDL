# 22 Exec Signals


Tasks often need to coordinate with other concurrent system activities
(like other tasks and interrupts).  This coordination is handled by Exec
through the synchronized exchange of specific event indicators called
signals.

This is the primary mechanism responsible for all intertask communication
and synchronization on the Amiga.  This signal mechanism operates at a low
level and is designed for high performance.  Signals are used extensively
by the Exec message system as a way to indicate the arrival of an
inter-task message.  The message system is described in more detail in the
"[Exec Messages and Ports](../Libraries_Manual_guide/node02EF.html)" chapter.


```c
    Not for Beginners.
    ------------------
    This chapter concentrates on details about signals that most
    applications do not need to understand for general Amiga programming.
    For a general overview of signals, see the "[Introduction to Exec](../Libraries_Manual_guide/node0289.html)"
    chapter of this manual.
```
 [The Signal System](../Libraries_Manual_guide/node02D2.html)    [Function Reference](../Libraries_Manual_guide/node02D6.html) 

