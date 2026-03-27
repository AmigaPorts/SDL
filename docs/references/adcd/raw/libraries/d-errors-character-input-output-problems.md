# D / Errors / Character Input/Output Problems


[RAWKEY](../Libraries_Manual_guide/node01E1.html#line19) users must be aware that RAWKEY codes can be different letters or
symbols on national keyboards.  If you need to use RAWKEY, run the codes
through [RawKeyConvert()](../Includes_and_Autodocs_2._guide/node050A.html) (see the "[Intuition Input and Output Methods](../Libraries_Manual_guide/node01E1.html#line19)"
chapter) to get proper translation to correct ASCII codes. Improper
display or processing of high-ASCII international characters can be caused
by incorrect tolower()/toupper(), or by sign extension of character values
when switched on or assigned into larger size variables. Use unsigned
variables such as UBYTE (not char) for strings and characters whenever
possible. [Internationally correct string functions](../Libraries_Manual_guide/node04A6.html) are provided in the 2.0
utility.library.

