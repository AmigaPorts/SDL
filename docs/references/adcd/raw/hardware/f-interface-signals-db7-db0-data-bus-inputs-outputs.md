# F / / Interface Signals / DB7-DB0 - data bus inputs/outputs


The eight data bus output pins transfer information between the 8520 and
the system data bus.  These pins are high impedance inputs unless  [CS](../Hardware_Manual_guide/node014E.html)  is
low and  [R/W](../Hardware_Manual_guide/node014F.html)  and 02 are high, to read the device.  During this read, the
data bus output buffers are enabled, driving the data from the selected
register onto the system data bus.

