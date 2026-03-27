# 21 Exec Tasks / Task Exclusion


From time to time the advanced system program may find it necessary to
access global system data structures.  Because these structures are shared
by the system and by other tasks that execute asynchronously to your task,
a task must prevent other tasks from using these structures while it is
reading from or writing to them.  This can be accomplished by preventing
the operating system from switching tasks by forbidding or disabling.  A
section of code that requires the use of either of these mechanisms to
lock out access by others is termed a critical section.  Use of these
methods is discouraged.  For arbitrating access to data between your
tasks, semaphores are a superior solution.  (See the "[Exec Semaphores](../Libraries_Manual_guide/node02F5.html)"
chapter)

 [Forbidding Task Switching](../Libraries_Manual_guide/node02C2.html)    [Disabling Tasks](../Libraries_Manual_guide/node02C3.html)    [Task Semaphores](../Libraries_Manual_guide/node02C4.html) 

