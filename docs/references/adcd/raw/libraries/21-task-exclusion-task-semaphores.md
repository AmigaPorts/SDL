# 21 / Task Exclusion / Task Semaphores


Semaphores can be used for the purposes of mutual exclusion.  With this
method of locking, all tasks agree on a locking convention before
accessing shared data structures.  Tasks that do not require access are
not affected and will run normally, so this type of exclusion is
considered preferable to forbidding and disabling.  This form of exclusion
is explained in more detail in the "[Exec Semaphores](../Libraries_Manual_guide/node02FA.html)" chapter.

