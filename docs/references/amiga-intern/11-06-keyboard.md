# The Keyboard

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

The Amiga keyboard is an intelligent keyboard. It has its own microprocessor, which handles the time-consuming job of reading the keys and returning complete key codes to the Amiga. The following figure shows the layout of the keys and their codes for the German and
American versions of the keyboard. As you can see, the codes do not 

correspond to the ASCII standard. The keyboard only returns raw key codes, which the operating system converts to ASCII using a  translation table called the key map. There is, however, a  system to the raw key code assignments:

$00-$3F Codes for the letters, digits and punctuation characters. 

Their assignments correspond to the arrangement on the keyboard.

$40-$4F Codes for the standard special keys like I  Spacebar I , [Enter!. 

Iiab 1  etc. 

$50-$5F Function keys and HELP. 

$60-$67 Keys for selecting keyboard control levels (1 Shift I. Amiga, 

(AJQ and fcFFTll 

American keyboard 

EM f\ 

45 SO 

p IB rr. m m. p ps p r

| 51 |      52 I      S3 I    54 55 I      56 I     57 I       58 

wmpn

"' f     Y F     I I      I V 

42 I  10 I  11 I     12 I     13 14 15 I 

HIM ft '   18 '      II1 It'1 »' B1 

P 31 132 133 [34 f35 Im In l3e 39 1/ 

I 25 26 I    27 28 I* 29 '  2A I 

67 ■      65 I 

3D 

3E 

3P 

' 2D 

2E 

2F 

in

IE 

IF 

OF 

3C 

ih 1           43

German keyboard 

• JO f  31 

> r  66 

! P R f IS IS IB p— 

" I   50 I   51 I   52 I   5j 54 I   55 I  56 

00 |   01 T  02 I   03 I  04 T  05 I  06 07 1 00 I  09 \     0A 00 1' OC I 

* r   r i     r r    l" I* r  h i   l l 

43 I     10 11 12 I     13 14 I      15 16 I   17 I     10 I  19 1A I" IB 

*• bs f     r r     r i     \ r     \ t  t I  \ 

J ^2 20 21 22 23 24 I  25 I   26 27 20 29 2A P  2B 

EE 

E 

r

3D 

3£ 

5F 

2D 

2E 

IP 

ID 

IE 

IF 

OF 

3C 

1A 1             43 

The keyboard ' The keyboard processor can do more than read the keys. It can distinguish between when a  key is pressed and when it is released. As you can see, all keyboard codes are only 7  bits (values range from $00-
$7f)- The eighth bit is the KEYup/down flag. It is used by the keyboard 

to tell the computer whether the key was just pressed or released. If the eighth bit is 0, this means that the key was just pressed (KEYdown). If it is 1, then the key was just released (KEYup). This way the Amiga always knows which keys are currendy pressed. The keyboard can thus be used for other purposes that require various keys to be held simultaneously. This includes music programs, for example, which use the keyboard for playing polyphonically.

One exception is the leaps Lock >  key. The keyboard simulates a  toggle 

switch with this key. The first time it is pressed, it engages and the LED goes on. It does not disengage until it is pressed again. The LED then turns off. This behavior is also reflected in the KEYup/down flag. If
(caps Lock \  is pressed, the LED turns on, and the key code for leaps Lock I 

is sent to the computer along with a  cleared eighth bit to show that a  key was just pressed. When the key is released, no KEYup code is sent, and the LED stays on. Not until leaps Lock \  is pressed again is a  KEYup code sent (with a  set eighth bit), and the LED turns off.

11 .6.1 Data Transfer from the Keyboard 

Ct.lt 

LrTJ~xrxr~UH_rTJ~i_r 

max. .

14 5ns »Jn' 

7SJ1S 

I \6 X5X4X3X2X1X°X7/ 

~~ L_J- 

Handshake 

signal

60|iB 

Data transfer from the keyboard 

The keyboard is connected to the Amiga by a  four-line coiled cable. Two of the lines are used to supply power to the keyboard electronics (5 volts). The entire data transfer takes place over the remaining two lines.
One of these lines is used for data (KDAT), and the other is the clock line 

(KCLK). Inside the Amiga, KDAT is connected to the serial input SP, and 

KCLK is connected to the CNT pin of CIA-A. The data transfer is 

unidirectional. It always runs from the keyboard to the computer. The processor in the keyboard places the individual data bits on the data line
(KDAT), accompanied by 20 microsecond-long low pulses on the clock 

line (KCLK). Between the individual clock pulses are 40 microsecond- long pauses. This amounts to a  transfer time of 60 microseconds for each bit, or 480 microseconds per 8-bit byte. The resulting data transfer rate is
16666 baud (bits/second). 

After the last bit has been sent, the keyboard waits for a  handshake pulse from the computer. The Amiga sends this signal by pulling the KDAT line low for at least 75 microseconds. The exact process can be seen in above the diagram. The bits are not sent in the usual order 7-6-5-4-3-2-1-0, but rotated one bit position to the left: 6-5-4-3-2-1-0-7. For example, the key code for "J" with the eighth bit set is 101001 10, and after rotation it is
01001 101. The KEYup/down flag is always the last bit sent. 

The data line is active low. This means that a  0 is represented by a  high signal and a  1 by a  low. The CIA shift register in the Amiga reads the current bit on the SP line at each clock pulse. After eight clock pulses the CIA has received a complete data byte. The CIA then normally generates a  level 2  interrupt, which causes the operating system to do the following:

• Read the serial data register in the CIA. 

• Invert and right-rotate the byte to get the original key code back. 

• Output the handshake pulse. 

• Process the received code. 

Synchronization 

In order to have an error-free data transfer, the timing of the sender and receiver must match. The bit position for the serial transfer must be identical for both. Otherwise the keyboard may have sent all eight bits, while the serial port of the CIA is still somewhere in the middle of the byte. Such a  loss of synchronization occurs whenever the Amiga is turned on or the keyboard is plugged into a  running Amiga. The computer has no way of recognizing improper synchronization. This task is handled by the keyboard. After each byte is sent, the keyboard waits a  maximum of 145 milliseconds for the handshake signal. If it does not occur in this time, the keyboard processor assumes that a  transfer error has occurred and enters a special mode in which it tries to restore the lost synchronization. It sends a  1 on the KDAT line together with a  clock pulse and waits another 145ms for the synchronization signal. It repeats this until it receives a  handshake signal from the Amiga. Synchronization is now restored. The data byte received by the Amiga is incorrect, however. The state of the first seven bits is uncertain. Only the last bit received is definitely a  1, because the keyboard processor only outputs l's during the procedure described above. Since this last bit is the KEYup/down flag, the incorrect code is always a  KEYup code, or a  released key. This causes less program disturbances than if an incorrect KEYdown code had been sent. This is why each byte is rotated one bit to the left before it is sent, so that the
KEYup/down flag is always the last bit sent. 

Special codes 

There are some other special cases in transmission, which the keyboard tells the Amiga through special key codes. The following table contains all possible special codes:

Code Meaning 

$F9 

$FA 

$FC 

$FD 

$FE 

Last key code was incorrect 

Keyboard buffer is full 

Error in keyboard self-test 

Start of keys held on power up 

End of keys held on power up 

$F9 

The $F9 code is always sent by the keyboard after a  loss of synchronization and subsequent resynchronization. This is how the
Amiga knows that the last key code was incorrect. After this code the 

keyboard retransmits the lost key code.

$FA 

The keyboard has an internal buffer of 10 characters. When this buffer is full, it sends a  $FA to the computer to signal that it must empty the buffer or lose characters.

$FC 

After it is turned on, the keyboard processor performs a  self-test. This is indicated by the brief lighting of the [caps Lock! LED. If it discovers an error, it sends a  $FC to the Amiga and then goes into an endless loop in which it flashes the LED.

$FD &  $FE 

If the self-test was successful, the keyboard transmits all the keys that were held when the computer was powered up. To tell the computer this, it starts the transmission with the $FD code. Then follow the codes of the keys pressed on power up, terminated by the code $FE. After that normal transmission begins. If no keys were pressed, $FD and $FE are sent in immediate succession.

Reset through the keyboard 

The keyboard can also generate a  reset on the Amiga. If the two Amiga keys and the Ictnl key are pressed simultaneously, the keyboard processor pulls the KCLK line low for about 0.5 seconds. This causes the reset circuit in the Amiga to generate a  processor reset. After at least one of these keys has been released, the keyboard also resets itself. This can be seen by the flashing of the I  caps lock I  LED.
