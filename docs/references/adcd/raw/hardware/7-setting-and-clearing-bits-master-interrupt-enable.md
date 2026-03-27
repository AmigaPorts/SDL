# 7 / / Setting and Clearing Bits / Master Interrupt Enable


Bit 14 of the  [interrupt registers](../Hardware_Manual_guide/node0164.html)  (INTEN) is for interrupt enable. This
is the master interrupt enable bit. If this bit is a 0, it disables all
other interrupts. You may wish to clear this bit to temporarily disable
all interrupts to do some critical processing task.

   Warning:
   --------
   This bit is used for enable/disable only. It creates no interrupt
   request.

