/* Source: ADCD 2.1
 * Section: on-line
 * Library: amiga-mail
 * ADCD reference: amiga-mail/on-line.md
 */

    Event types (S2EVENT_xxx):

      ERROR    - Return when any error occurs.
      TX       - Return on any transmit error (always an error).
      RX       - Return on any receive error (always an error).
      ONLINE   - Return when unit goes on-line or return immediately if
                 unit is already on-line (not an error).
      OFFLINE  - Return when unit goes off-line or return immediately if
                 unit is already off-line (not an error.)
      BUFF     - Return on any buffer management function error (always
                 an error).
      HARDWARE - Return when any hardware error occurs (always an error,
                 may be a TX or RX, too).
      SOFTWARE - Return when any software error occurs (always an error,
                 may be a TX or RX, too).
