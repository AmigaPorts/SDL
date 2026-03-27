# D / Errors / Memory Loss--During Execution


A continuing memory loss during execution can be caused by failure to keep
up with voluminous IDCMP messages such as [MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23) messages. Intuition
cannot re-use IDCMP message blocks until you [ReplyMsg()](../Libraries_Manual_guide/node02F3.html) them.  If your
window's allotted message blocks are all in use, new sets will be
allocated and not freed till the window is closed.  Continuing memory
losses can also be caused by a program loop containing an allocation-type
call without a corresponding free.

