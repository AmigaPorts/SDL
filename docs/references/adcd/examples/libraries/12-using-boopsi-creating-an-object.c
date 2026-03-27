/* Source: ADCD 2.1
 * Section: 12-using-boopsi-creating-an-object
 * Library: libraries
 * ADCD reference: libraries/12-using-boopsi-creating-an-object.md
 */

    mystringgadget = (struct Gadget *)NewObject(NULL, "strgclass",
                                                GA_ID,           1L,
                                                GA_Left,         0L,
                                                GA_Top,          0L,
                                                STRINGA_LongVal, 100L,
                                                TAG_END);
