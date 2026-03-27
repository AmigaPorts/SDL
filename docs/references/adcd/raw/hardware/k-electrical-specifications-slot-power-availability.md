# K / Electrical Specifications / Slot Power Availability


The system power for the Zorro III bus is totally based on the slot
configurations.  A backplane is always free to supply extra power, but it
must meet the minimum requirements specified here.  All PICs must be
designed with the minimum specifications in mind, especially the
tolerances.

	Pin	Supply
        ---     ------
	5,6     [+5VDC](../Hardware_Manual_guide/node02AF.html#line10)  +/- 5% @ 2 Amps
	8       [-5VDC](../Hardware_Manual_guide/node02AF.html#line15)  +/- 5% @ 60 mA
	10      [+12VDC](../Hardware_Manual_guide/node02AF.html#line19)  +/- 5% @ 500mA
	20      [-12VDC](../Hardware_Manual_guide/node02AF.html#line25)  +/- 5% @ 60mA

