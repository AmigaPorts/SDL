# Glossary / slave


The device currently responding to the address on the expansion bus. There
is only one slave on the bus at a time; an error is signalled by the bus
collision detect logic if multiple slaves respond to the same address.
The slave also drives data on reads, the transfer acknowledge strobe, and
several other signals.

