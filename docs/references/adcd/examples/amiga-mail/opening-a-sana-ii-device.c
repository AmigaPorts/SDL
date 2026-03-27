/* Source: ADCD 2.1
 * Section: opening-a-sana-ii-device
 * Library: amiga-mail
 * ADCD reference: amiga-mail/opening-a-sana-ii-device.md
 */

                          in this field before calling OpenDevice().
                          Functions pointed to in the tag list are
                          called by the device when processing
                          IORequests from the opener. When returned
                          from OpenDevice(), this field contains a
                          pointer to driver-private information
                          used to access these functions.
                          See "[Buffer Management](../AmigaMail_Vol2_guide/node011C.html)" below for more
                          details.
