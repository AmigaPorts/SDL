/* Source: ADCD 2.1
 * Section: ii-77-asyncio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-77-asyncio-c.md
 */

    /* This enables signalling when a packet comes back to the port */
    file->af_PacketPort.mp_Flags = PA_SIGNAL;

    /* Wait for the packet to come back, and remove it from the message
     * list. Since we know no other packets can come in to the port, we can
     * safely use Remove() instead of GetMsg(). If other packets could come in,
     * we would have to use GetMsg(), which correctly arbitrates access in such
     * a case
     */
    Remove((struct Node *)WaitPort(&file->af_PacketPort));

    /* set the port type back to PA_IGNORE so we won't be bothered with
     * spurious signals
     */
    file->af_PacketPort.mp_Flags = PA_IGNORE;

    /* packet is no longer pending, we got it */
    file->af_PacketPending = FALSE;
