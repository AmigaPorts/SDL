/* Source: ADCD 2.1
 * Section: standard-data-and-property-chunks-optional-property-ins1
 * Library: devices
 * ADCD reference: devices/standard-data-and-property-chunks-optional-property-ins1.md
 */

    #define ID_INS1 MakeID('I', 'N', 'S', '1')

    /* Values for the RefInstrument field "type".	*/
    #define INS1_Name  0    /* just use the name; ignore data1, data2  */
    #define INS1_MIDI  1    /* <data1, data2> = MIDI <channel, preset> */

    typedef struct {
