---
title: Initializing a Boopsi Class
manual: amiga-mail
chapter: amiga-mail
section: initializing-a-boopsi-class
functions: []
libraries: []
---

# Initializing a Boopsi Class

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You need some simple code to initialize a class and its hook.  When
initializing a class, you specify the size of the class's instance and
what the superclass is, and you also have to supply a pointer to a hook
entry stub.

The following code fragment illustrates the initialization of a private
subclass of imageclass.




```c
    ULONG __saveds dispatchmyTextLabel();

    /* This is the data that each instance of our class will need. */
    struct localObjData
    {
        /* Font to use */
        struct TextFont *lod_Font;

        /* The key that is underlined */
        UWORD lod_Key;

        /* DrawMode */
        UBYTE lod_Mode;
    };

    #define MYCLASSID           NULL
    #define SUPERCLASSID        (IMAGECLASS)
    #define LSIZE               (sizeof(struct localObjData))

    Class *initmyTextLabelClass (VOID)
    {
        extern ULONG __saveds dispatchmyTextLabel();
        extern ULONG hookEntry ();        /* defined in hookface.asm */
        Class *cl;

        if (cl = MakeClass (MYCLASSID, SUPERCLASSID, NULL, LSIZE, 0))
        {
            /* Fill in the callback hook */
            cl->cl_Dispatcher.h_Entry = hookEntry;
            cl->cl_Dispatcher.h_SubEntry = dispatchmyTextLabel;
        }

        /* Return a pointer to the class */
        return (cl);
    }
```
In order to make the class public instead of private, do the following:



```c
    #define MYCLASSID           "mytextlabelclass"

    ULONG __saveds dispatchmyTextLabel();

    Class *initmyTextLabelClass (VOID)
    {
        extern ULONG __saveds dispatchmyTextLabel();
        extern ULONG hookEntry ();
        Class *cl;

        if (cl = MakeClass (MYCLASSID, SUPERCLASSID, NULL, LSIZE, 0))
        {
            /* Fill in the callback hook */
            cl->cl_Dispatcher.h_Entry = hookEntry;
            cl->cl_Dispatcher.h_SubEntry = dispatchmyTextLabel;

            /* Make the class public */
            AddClass (cl);
        }

        /* Return a pointer to the class */
        return (cl);
    }
```
