# Unresolved Issues


Unfortunately, it isn't possible to completely isolate network protocols
from the hardware they run on. Hardware types and addressing both remain
somewhat hardware-dependent in spite of our efforts. See the "[Packet Type](../AmigaMail_Vol2_guide/node011D.html)"
section for an explanation of how packet types are handled and why
protocols cannot be isolated from them. See the "[Addressing](../AmigaMail_Vol2_guide/node0120.html)" section for
an explanation of how addressing is handled any why protocols cannot be
isolated from it.

Additionally, there are at least two cases where a hardware type has
multiple framing methods in use (ethernet/802.3 and arcnet/(Novell)
"ARCNET Packet Header Definition Standard"). In both cases, software which
must interoperate with other platforms on this hardware may need to be
aware of the distinctions and may have to do extra processing in order to
use the appropriate frame type. See the sections on
"[Ethernet Packet Types](../AmigaMail_Vol2_guide/node011E.html)" and on "[ARCNET frames](../AmigaMail_Vol2_guide/node011F.html)" for more details.

