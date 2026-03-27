/* Source: ADCD 2.1
 * Section: 26-servicing-interrupts-interrupt-data-structure
 * Library: libraries
 * ADCD reference: libraries/26-servicing-interrupts-interrupt-data-structure.md
 */

    struct Interrupt
    {
        struct Node is_Node;
        APTR        is_Data;
        VOID      (*is_Code)();
    };
