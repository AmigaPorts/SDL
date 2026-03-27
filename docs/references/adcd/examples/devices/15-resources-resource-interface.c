/* Source: ADCD 2.1
 * Section: 15-resources-resource-interface
 * Library: devices
 * ADCD reference: devices/15-resources-resource-interface.md
 */

    #include <hardware/cia.h>
    #include <resources/cia.h>

    struct Library *CIAResource = NULL;

    void main()
    {

    WORD mask = 0;

    if (!(CIAResource = OpenResource(CIABNAME)))
        printf("Cannot open %s\n",CIABNAME);
    else
       {
        /* What is the interrupt enable mask? */
         mask = AbleICR(CIAResource,0);

        printf("\nThe CIA interrupt enable mask: %x \n",mask);
       }
    }
