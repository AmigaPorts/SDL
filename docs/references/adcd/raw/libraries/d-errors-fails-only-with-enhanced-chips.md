# D / Errors / Fails only with Enhanced Chips


Usually caused by writing or reading addresses past the end of older
custom chips, or writing something other than 0 (zero) to bits which are
undefined in older chip registers, or failing to mask out undefined bits
when interpreting the value read from a chip register.  Note that system
copper lists are different under 2.0 when ECS chips are present. See
"[Fails only on Chip-RAM-Only Machines](../Libraries_Manual_guide/node0549.html)".

