# 8 / The Keyboard / Type of Data Received


The keyboard data is not received in the form of ASCII characters.
Instead, for maximum versatility, it is received in the form of keycodes.
These codes include both the down and up transitions of the keys. This
allows your software to use both sets of information to determine exactly
what is happening on the keyboard.

Here is a list of the hexadecimal values that are assigned to the
keyboard. A downstroke of the key transmits the value shown here. An
upstroke of the key transmits this value plus $80. The picture of the
keyboard shows the positions that correspond to the description in the
sections below.

Note that raw keycodes provide positional information only, the legend
which is printed on top of the keys changes from country to country.

 [RAW Keycodes -> 00-3F hex](../Hardware_Manual_guide/node019A.html) 
 [RAW Keycodes -> 40-5F hex  (Codes common to all keyboards)](../Hardware_Manual_guide/node019B.html) 
 [RAW Keycodes -> 60-67 hex  (Key codes for qualifier keys)](../Hardware_Manual_guide/node019C.html) 
 [F0-FF hex](../Hardware_Manual_guide/node019D.html) 

