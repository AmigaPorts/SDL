/* Source: ADCD 2.1
 * Section: amiga-lib-setsuperattrs
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-setsuperattrs.md
 */

    Boopsi support function which invokes the OM_SET method on the
    superclass of the supplied class for the supplied object.  Allows
    the ops_AttrList to be supplied on the stack (i.e. in a varargs
    way).  The equivalent non-varargs function would simply be

        DoSuperMethod( cl, obj, OM_SET, taglist, NULL );
