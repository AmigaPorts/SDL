# A Register Summary / COPJMP1, COPJMP2


                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
COPJMP1    088      S       A     Copper restart at first location
COPJMP2    08A      S       A     Copper restart at second location


                 These addresses are strobe addresses.  When written
                 to, they cause the Copper to jump indirect using
                 the address contained in the first or second
                 location registers described below. The Copper
                 itself can write to these addresses, causing its
                 own jump indirect.
