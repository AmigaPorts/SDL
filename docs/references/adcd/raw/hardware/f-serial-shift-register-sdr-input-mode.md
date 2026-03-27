# F / Serial Shift Register (SDR) / Input Mode


In input mode, data on the SP pin is shifted into the shift register on
the rising edge of the signal applied to the CNT pin. After eight CNT
pulses, the data in the shift register is dumped into the serial data
register and an interrupt is generated.

