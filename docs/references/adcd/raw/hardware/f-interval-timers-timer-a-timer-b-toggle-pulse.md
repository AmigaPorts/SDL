# F / / Interval Timers (Timer A, Timer B) / Toggle/pulse


A control bit (CRx2) selects the output applied to  [port B](../Hardware_Manual_guide/node0131.html)  while the PB
on/off bit is ON.  On every timer underflow, the output can either toggle
or generate a single positive pulse of one cycle duration.  The toggle
output is set high whenever the timer is started, and set low by  [RES](../Hardware_Manual_guide/node0153.html) .

