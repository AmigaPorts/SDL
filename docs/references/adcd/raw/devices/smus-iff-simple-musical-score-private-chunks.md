# SMUS IFF Simple Musical Score / Private Chunks


As in any IFF [FORM](../Devices_Manual_guide/node01C7.html#line51), there can be private chunks in a FORM [SMUS](../Devices_Manual_guide/node02AB.html) that are
designed for one particular program to store its private information.  All
IFF reader programs skip over unrecognized chunks, so the presense of
private chunks can't hurt.

Instant Music stores some global score information in a chunk of ID "IRev"
and some other information in a chunk of ID "BIAS".

