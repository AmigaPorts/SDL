/* Source: ADCD 2.1
 * Section: lib-examples-findboards-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-findboards-c.md
 */

    /*--------------------------------------------------*/
    /* FindConfigDev(oldConfigDev,manufacturer,product) */
    /* oldConfigDev = NULL for the top of the list      */
    /* manufacturer = -1 for any manufacturer           */
    /* product      = -1 for any product                */
    /*--------------------------------------------------*/

    myCD = NULL;
    while(myCD=FindConfigDev(myCD,-1L,-1L)) /* search for all ConfigDevs */
