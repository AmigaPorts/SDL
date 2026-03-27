# 6 / / Intercepting Menu Operations / A Warning on the MENUSTATE Flag


The MENUSTATE flag is set by Intuition in [Window](../Libraries_Manual_guide/node0121.html).Flags when the menus of
that window are in use.  Beware: in typical event driven programming, such
a state variable is not on the same timetable as the application's input
message handling, and should not be used to draw profound conclusions in
any program.  Use [IDCMP_MENUVERIFY](../Libraries_Manual_guide/node01DE.html#line6) to synchronize with the menu handling.

