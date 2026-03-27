/* Source: ADCD 2.1
 * Section: ii-95-compareio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-95-compareio-c.md
 */

                                      /* when the program hasn't read anything yet.  */
                                      /* This is to set up for the main loop.  The   */
                                      /* main loop swaps the ACTION_READ buffer with */
                                      /* the ACTION_WRITE buffer when it receives    */
                                      /* a completed read.  Likewise, dp_Arg3 and    */
                                      /* dp_Res1 are set to make the ACTION_READ     */
                                      /* look like it has a valid return value so    */
                                      /* main loop won't fail the first time through */
                                      /* the loop.                                   */

                /* main() has already taken care of sending the initial read to the  */
                /* handler.  Because we need the data from that read before we can   */
