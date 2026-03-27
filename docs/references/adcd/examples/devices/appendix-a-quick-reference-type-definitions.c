/* Source: ADCD 2.1
 * Section: appendix-a-quick-reference-type-definitions
 * Library: devices
 * ADCD reference: devices/appendix-a-quick-reference-type-definitions.md
 */

    #define ID_NAME MakeID('N', 'A', 'M', 'E')
    /* NAME chunk contains a CHAR[], the musical score's name.		*/

    #define ID_Copyright MakeID('(', 'c', ')', ' ')
    /* "(c) " chunk contains a CHAR[], the FORM's copyright notice.	*/

    #define ID_AUTH MakeID('A', 'U', 'T', 'H')
    /* AUTH chunk contains a CHAR[], the name of the score's author.	*/

    #define ID_ANNO MakeID('A', 'N', 'N', 'O')
    /* ANNO chunk contains a CHAR[], author's text annotations.		*/

    #define ID_INS1 MakeID('I', 'N', 'S', '1')
    /* Values for the RefInstrument field "type".			*/

    #define INS1_Name 0	/* just use the name; ignore data1, data2	*/
    #define INS1_MIDI 1	/* <data1, data2> = MIDI <channel, preset>	*/


    typedef struct {
