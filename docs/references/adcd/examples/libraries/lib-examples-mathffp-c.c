/* Source: ADCD 2.1
 * Section: lib-examples-mathffp-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-mathffp-c.md
 */

    {

    n1 = afp(st1);            /* Call afp entry */
    n2 = afp(st2);            /* Call afp entry */
    printf("\n\nASCII %s converts to floating point %f", st1, n1);
    printf("\nASCII %s converts to floating point %f", st2, n2);

    num1 = 3.1415926535897;
    num2 = 2.718281828459045;

    exp1 = fpa(num1, st3);    /* Call fpa entry */
    exp2 = fpa(num2, st4);    /* Call fpa entry */
    printf("\n\nfloating point %f converts to ASCII %s", num1, st3);
    printf("\nfloating point %f converts to ASCII %s", num2, st4);

    place1 = -2;
    place2 = -1;
    arnd(place1, exp1, st3);    /* Call arnd entry */
    arnd(place2, exp2, st4);    /* Call arnd entry */
    printf("\n\nASCII round of %f to %d places yields %s", num1, place1, st3);
    printf("\nASCII round of %f to %d places yields %s", num2, place2, st4);

    exp1  = -3;   exp2  = 3;    exp3  = -3;   exp4  = 3;
    mant1 = 12345;  mant2 = -54321;  mant3 = -12345; mant4 = 54321;

    n1 = dbf(exp1, mant1);        /* Call dbf entry */
    n2 = dbf(exp2, mant2);        /* Call dbf entry */
    n3 = dbf(exp3, mant3);        /* Call dbf entry */
    n4 = dbf(exp4, mant4);        /* Call dbf entry */
    printf("\n\ndbf of exp = %d and mant = %d yields FFP number of %f", exp1, mant1, n1);
    printf("\ndbf of exp = %d and mant = %d yields FFP number of %f", exp2, mant2, n2);
    printf("\ndbf of exp = %d and mant = %d yields FFP number of %f", exp3, mant3, n3);
    printf("\ndbf of exp = %d and mant = %d yields FFP number of %f", exp4, mant4, n4);

    CloseLibrary(MathBase);
    }
