---
title: 34 Keymap Library / Keyboard Layout
manual: libraries
chapter: libraries
section: 34-keymap-library-keyboard-layout
functions: []
libraries: []
---

# 34 Keymap Library / Keyboard Layout

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The keys with key codes $2B and $30 in the following keyboard diagrams are
keys which are present on some national Amiga keyboards.


```c
     [Figure 34-1: Amiga 1000 Keyboard Showing Key Codes in Hex](hardware/hard-pics-8-10-pic.md) 

     [Figure 34-2: Amiga 500/2000/3000 Keyboard Showing Key Codes in Hex](devices/hard-pics-8-11-pic.md) 
```
The default values given above correspond to the values the console device
will return when these keys are pressed with the keycaps as shipped with
the standard American keyboard.


  Table 34-6: ROM Default (USA0) and USA1 Console Key Mapping


   Raw                    Unshifted          Shifted
   Key       Keycap        Default           Default
  Number     Legend         Value             Value
  ------     ------         -----             -----


```c
    00        ` ~             ` (Accent grave)  ~ (tilde)
    01        1 !             1                 !
    02        2 @             2                 @
    03        3 #             3                 #
    04        4 $             4                 $
    05        5 %             5                 %
    06        6 ^             6                 ^
    07        7 &             7                 &
    08        8 *             8                 *
    09        9 (             9                 (
    0A        0 )             0                 )
    0B        - _             - (Hyphen)        _ (Underscore)
    0C        = +             =                 +
    0D        |                                 |
    0E                        (undefined)
    0F        0               0                 0 (Numeric pad)
    10        Q               q                 Q
    11        W               w                 W
    12        E               e                 E
    13        R               r                 R
    14        T               t                 T
    15        Y               y                 Y
    16        U               u                 U
    17        I               i                 I
    18        O               o                 O
    19        P               p                 P
    1A        [ {             [                 {
    1B        ] }             ]                 }
    1C                        (undefined)
    1D        1               1                 1 (Numeric pad)
    1E        2               2                 2 (Numeric pad)
    1F        3               3                 3 (Numeric pad)
    20        A               a                 A
    21        S               s                 S
    22        D               d                 D
    23        F               f                 F
    24        G               g                 G
    25        H               h                 H
    26        J               j                 J
    27        K               k                 K
    28        L               l                 L
    29        ; :             ;                 :
    2A        ' "             ' (single quote)  "
    2B                        (not on most
                               US keyboards)
    2C                        (undefined)
    2D        4               4                 4 (Numeric pad)
    2E        5               5                 5 (Numeric pad)
    2F        6               6                 6 (Numeric pad)
    30                        (not on most
                               US keyboards)
    31        Z               z                 Z
    32        X               x                 X
    33        C               c                 C
    34        V               v                 V
    35        B               b                 B
    36        N               n                 N
    37        M               m                 M
    38        , <             , (comma)         <
    39        . >             . (period)        >
    3A        / ?             /       ?
    3B                        (undefined)
    3C        .               .                 . (Numeric pad)
    3D        7               7                 7 (Numeric pad)
    3E        8               8                 8 (Numeric pad)
    3F        9               9                 9 (Numeric pad)
    40        (Space bar)     20                20
    41        Back Space      08                08
    42        Tab             09                09
    43        Enter           0D                0D (Numeric pad)
    44        Return          0D                0D
    45        Esc             1B                1B
    46        Del             7F                7F
    47                        (undefined)
    48                        (undefined)
    49                        (undefined)
    4A        -               -                 - (Numeric Pad)
    4B                        (undefined)
    4C        Up arrow        <CSI>A            <CSI>T
    4D        Down arrow      <CSI>B            <CSI>S
    4E        Forward arrow   <CSI>C            <CSI> A (note blank space
                                                           after <CSI>)
    4F        Backward arrow  <CSI>D            <CSI> @ (note blank space
                                                           after <CSI>)
    50        F1              <CSI>0~           <CSI>10~
    51        F2              <CSI>1~           <CSI>11~
    52        F3              <CSI>2~           <CSI>12~
    53        F4              <CSI>3~           <CSI>13~
    54        F5              <CSI>4~           <CSI>14~
    55        F6              <CSI>5~           <CSI>15~
    56        F7              <CSI>6~           <CSI>16~
    57        F8              <CSI>7~           <CSI>17~
    58        F9              <CSI>8~           <CSI>18~
    59        F10             <CSI>9~           <CSI>19~
    5A        (               (                 ( (usa1 Numeric pad)
    5B        )               )                 ) (usa1 Numeric pad)
    5C        /               /                 / (usa1 Numeric pad)
    5D        *               *                 * (usa1 Numeric pad)
    5E        +               +                 + (usa1 Numeric pad)
    5F        HELP            <CSI>?~           <CSI>?~
```
   Raw        Function
   Key        or Keycap
  Number      Legend
  ------      ---------
```c
    60        Shift (left of space bar)
    61        Shift (right of space bar)
    62        Caps Lock
    63        Ctrl
    64        (Left) Alt
    65        (Right) Alt
    66        Amiga (left of space bar)            Left Amiga
    67        Amiga (right of space bar)           Right Amiga
    68        Left mouse button (not converted)    Inputs are only for the
    69        Right mouse button (not converted)   mouse connected to
    6A        Middle mouse button (not converted)  Intuition, (currently
    6B        (undefined)                          gameport one).
    6C        (undefined)
    6D        (undefined)
    6E        (undefined)
    6F        (undefined)
    70-7F     (undefined)
    80-F8     Up transition (release or unpress key of one
              of the above keys) (80 for 00, F8 for 7F)
    F9        Last key code was bad
              (was sent in order to resynchronize)
    FA        Keyboard buffer overflow
    FB        (undefined, reserved for
              keyboard processor catastrophe)
    FC        Keyboard selftest failed
    FD        Power-up key stream start.
              Keys pressed or stuck at power-up
              will be sent between FD and FE.
    FE        Power-up key stream end
    FF        (undefined, reserved)
    FF        Mouse event, movement only,
              no button change (not converted)


    Notes about the preceding table:

    1) "<CSI>" is the Control Sequence Introducer, value hex 9B.

    2) "(undefined)" indicates that the current keyboard design should not
       generate this number.  If you are using [SetKeyMap()](libraries/34-keymap-functions-accessing-the-keymap-for-the-current.md) to change the
       key map, the entries for these numbers must still be included.

    3) "(not converted)" refers to mouse button events. You must use the
       sequence "<CSI>2{" to inform the console driver that you wish to
       receive mouse events; otherwise these will not be transmitted.

    4) "(RESERVED)" indicates that these key codes have been reserved for
       national keyboards.  The $2B code key will be between the
       double-quote (") and Return keys. The $30 code key will be between
       the Shift and Z keys.


          +---------------------------------------------------------------+
          | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
          | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |
          | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 |
          | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 |
          |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
          | 00| 01| 02| 03| 04| 05| 06| 07| 08| 09| 0a| 0b| 0c| 0d| 0e| 0f|
```
+---------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 0000 00 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 0001 10 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 0010 20 | SP| ! | " | # | $ | % | & | ' | ( | ) | * | + | , | - | . | / |
| 0011 30 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | : | ; | < | = | > | ? |
| 0100 40 | @ | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O |
| 0101 50 | P | Q | R | S | T | U | V | W | X | Y | Z | [ | \ | ] | ^ | _ |
| 0110 60 | ` | a | b | c | d | e | f | g | h | i | j | k | l | m | n | o |
| 0111 70 | p | q | r | s | t | u | v | w | x | y | z | { | | | } | ~ |   |
| 1000 80 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 1001 90 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 1010 a0 |NBSP ¡ | ¢ | £ | ¤ | ¥ | ¦ | § | ¨ | © | ª | « | ¬ |SHY| ® | ¯ |
| 1011 b0 | ° | ± | ² | ³ | ´ | µ | ¶ | · | ¸ | ¹ | º | » | ¼ | ½ | ¾ | ¿ |
| 1100 c0 | À | Á | Â | Ã | Ä | Å | Æ | Ç | È | É | Ê | Ë | Ì | Í | Î | Ï |
| 1101 d0 | Ð | Ñ | Ò | Ó | Ô | Õ | Ö | × | Ø | Ù | Ú | Û | Ü | Ý | Þ | ß |
| 1110 e0 | à | á | â | ã | ä | å | æ | ç | è | é | ê | ë | ì | í | î | ï |
| 1111 f0 | ð | ñ | ò | ó | ô | õ | ö | ÷ | ø | ù | ú | û | ü | ý | þ | ÿ |
+-------------------------------------------------------------------------+


      Figure 34-3: ECMA-94 Latin1 International 8-Bit Character Set
