/* Source: ADCD 2.1
 * Section: sana2-device-s2-readorphan
 * Library: amiga-mail
 * ADCD reference: amiga-mail/sana2-device-s2-readorphan.md
 */

    This is intended for debugging and management tools.  Protocols should
    not use this.

    As with 802.3 packets on an ethernet, to determine which protocol
    family the returned packet belongs to you may have to specify
    SANA2IOB_RAW to get the entire data link layer wrapper (which is where
    the protocol type may be kept). Notice this necessarily means that
    this cannot be done in a network interface independent fashion.  The
    driver will, however, fill in the PacketType field to the best of its
    ability.
