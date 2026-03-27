/* Source: ADCD 2.1
 * Section: intuition-library-newobject
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-newobject.md
 */

    This is the general method of creating objects from 'boopsi' classes.
    ('Boopsi' stands for "basic object-oriented programming system for
    Intuition".)

    You specify a class either as a pointer (for a private class) or
    by its ID string (for public classes).  If the class pointer
    is NULL, then the classID is used.

    You further specify initial "create-time" attributes for the
    object via a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list, and they are applied to the resulting
    generic data object that is returned.  The attributes, their meanings,
    attributes applied only at create-time, and required attributes
    are all defined and documented on a class-by-class basis.
