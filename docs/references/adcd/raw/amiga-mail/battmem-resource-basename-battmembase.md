# battmem.resource (basename: _BattMemBase)


ObtainBattSemaphore()()                 - Obtain access to nonvolatile
```c
                                          ram. (V36)
```
ReadBattMem(buffer,offset,length)(a0,d0/d1)
```c
                                        - Read a bitstring from
                                          nonvolatile ram.  (V36)
```
ReleaseBattSemaphore()()                - Allow nonvolatile ram to others.
```c
                                           (V36)
```
WriteBattMem(buffer,offset,length)(a0,d0/d1)

```c
                                        - Write a bitstring to nonvolatile
                                          ram.  (V36)
```
