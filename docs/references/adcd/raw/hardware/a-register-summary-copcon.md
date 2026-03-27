# A Register Summary / COPCON


                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
COPCON     02E      W      A( [E](../Hardware_Manual_guide/node00AC.html#line17) ) Copper control register


                 This is a 1-bit register that when set true, allows
                 the Copper to access the blitter hardware. This
                 bit is cleared by power-on reset, so that the Copper
                 cannot access the blitter hardware. See Appendix C
                 for ECS operation.

                 BIT#    NAME      FUNCTION
                 ----    -------   ------------------
                  01     CDANG     Copper danger mode. Allows Copper
                                   access to blitter if true.
