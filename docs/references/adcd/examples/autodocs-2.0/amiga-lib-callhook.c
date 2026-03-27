/* Source: ADCD 2.1
 * Section: amiga-lib-callhook
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-callhook.md
 */

    If your hook's message was

        struct myMessage
        {
            ULONG mm_FirstGuy;
            ULONG mm_SecondGuy;
            ULONG mm_ThirdGuy;
        };

    You could write:

        result = CallHook( hook, obj, firstguy, secondguy, thirdguy );

    as a shorthand for:

        struct myMessage msg;

        msg.mm_FirstGuy = firstguy;
        msg.mm_SecondGuy = secondguy;
        msg.mm_ThirdGuy = thirdguy;

        result = CallHookA( hook, obj, &msg );
