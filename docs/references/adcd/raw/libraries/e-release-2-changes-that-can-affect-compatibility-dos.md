# E / Release 2 Changes That Can Affect Compatibility / DOS


  * DOS is now written in C and assembler, not BCPL.  The BCPL compiler

    artifact which caused D0 function results to also be in D1 is gone.
    System patches in Release 2 that return some DOS function results in
    both D0 and D1 are not guaranteed to remain in the next release. Fix
    your programs!  Use Scratch to find these problems in your code.
  * DOS now has a real library base with normal [LVO](../Libraries_Manual_guide/node028F.html) vectors.

  * Stack usage has all changed (variables, direction).

  * New packet and lock types.  Make sure you are not passing stack

```c
    garbage for the second argument to [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html).
```
  * [Process](../Libraries_Manual_guide/node0287.html#line51) structure is bigger.  "Rolling your own" Process structure

```c
    from a [Task](../Libraries_Manual_guide/node02BB.html) fails.  Use dos.library [System() or CreateNewProc()](../Libraries_Manual_guide/node0023.html).
```
  * Unless documented otherwise, you must be a process to call DOS

    functions. DOS function dependence on special process structures can
    change with OS revisions.
