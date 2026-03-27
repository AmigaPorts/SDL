/* Source: ADCD 2.1
 * Section: icon-library-deletediskobject
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/icon-library-deletediskobject.md
 */

    error=NULL;

    *Check if you have the right library version*

    if (((struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *)IconBase)->lib_Version > 36)
    {
            if (!DeleteDiskObject(name)) error=IoErr();
    }
    else
    {
            * Delete name plus ".info" *
    }

    if (error)
    {
            * Do error routine...*
    }
