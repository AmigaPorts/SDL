# F / Register Functional Description / Handshaking


Handshaking occurs on data transfers using the PC output pin and the FLAG
input pin.  PC will go low on the third cycle after a  [port B](../Hardware_Manual_guide/node0131.html)  access.
This signal can be used to indicate "data ready" at  [port B](../Hardware_Manual_guide/node0131.html)  or "data
accepted" from  [port B](../Hardware_Manual_guide/node0131.html) . Handshaking on 16-bit data transfers (using both
 [ports A and B](../Hardware_Manual_guide/node0131.html) ) is possible by always reading or writing  [port A](../Hardware_Manual_guide/node0131.html)  first.
FLAG is a negative edge-sensitive input that can be used for receiving the
PC output from another 8520 or as a general- purpose interrupt input.  Any
negative transition on FLAG will set the FLAG interrupt bit.


        REG  NAME   D7   D6   D5   D4   D3   D2   D1   D0
        ---  ----   ---- ---- ---- ---- ---- ---- ---- ----
         0   PRA    PA7  PA6  PA5  PA4  PA3  PA2  PA1  PA0
         1   PRB    PB7  PB6  PB5  PB4  PB3  PB2  PB1  PB0
         2   DDRA   DPA7 DPA6 DPA5 DPA4 DPA3 DPA2 DPA1 DPA0
         3   DDRB   DPB7 DPB6 DPB5 DPB4 DPB3 DPB2 DPB1 DPB0
