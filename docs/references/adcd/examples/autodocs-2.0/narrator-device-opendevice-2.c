/* Source: ADCD 2.1
 * Section: narrator-device-opendevice
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/narrator-device-opendevice.md
 */

    The narrator device will initialize the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block as follows
    (assume IORB points to the IOrequest block):

    IORB->rate = 150;               /* Speaking rate in words/minute */
    IORB->pitch = 110;              /* Baseline pitch in Hertz      */
    IORB->mode = NATURALF0;         /* Pitch (F0) mode              */
    IORB->sex = MALE;               /* Sex of voice                 */
    IORB->volume = 64               /* Volume, full on              */
    IORB->sampfreq = 22200          /* Audio sampling freq          */
    IORB->mouths = 0                /* Don't generate sync events   */

    and if the NDB_NEWIORB bit is set:

    IORB->F0enthusiasm = 0          /* F0 excursion factor          */
    IORB->F0perturb = 32            /* F0 perturbation (in 32nds)   */
    IORB->F1adj = 0                 /* F1 adjustment in ±5% steps   */
    IORB->F2adj = 0                 /* F2 adjustment in ±5% steps   */
    IORB->F3adj = 0                 /* F3 adjustment in ±5% steps   */
    IORB->A1adj = 0                 /* A1 adjustment in decibels    */
    IORB->A2adj = 0                 /* A2 adjustment in decibels    */
    IORB->A3adj = 0                 /* A3 adjustment in decibels    */
    IORB->articulate = 100          /* Transition time multiplier   */
    IORB->centralize = 0            /* Degree of vowel centralization */
    IORB->centphon = ""             /* Pointer to central ASCII phon  */
    IORB->AVbias = 0                /* AV bias                      */
    IORB->AFbias = 0                /* AF bias                      */
    IORB->priority = 100            /* Priority while speaking      */
