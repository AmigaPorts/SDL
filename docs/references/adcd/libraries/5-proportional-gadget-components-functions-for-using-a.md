---
title: 5 / / Proportional Gadget Components / Functions for Using a Scroller
manual: libraries
chapter: libraries
section: 5-proportional-gadget-components-functions-for-using-a
functions: []
libraries: []
---

# 5 / / Proportional Gadget Components / Functions for Using a Scroller

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
**   FindScrollerValues( )
**
** Function to calculate the Body and Pot values of a proportional gadget
** given the three values total, displayable, and top, representing the
** total number of items in a list, the number of items displayable at one
** time, and the top item to be displayed.  For example, a file requester
** may be able to display 10 entries at a time.  The directory has 20
** entries in it, and the top one displayed is number 3 (the fourth one,
** counting from zero), then total = 20, displayable = 10, and top = 3.
**
** Note that this routine assumes that the displayable variable is greater
** than the overlap variable.
**
** A final value, overlap, is used to determine the number of lines of
** "overlap" between pages.  This is the number of lines displayed from the
** previous page when jumping to the next page.
*/

void FindScrollerValues(UWORD total, UWORD displayable, UWORD top,
```c
                        WORD overlap, UWORD *body, UWORD *pot)
```
{
UWORD hidden;


/* Find the number of unseen lines: */

hidden = max(total - displayable, 0);


/* If top is so great that the remainder of the list won't even
** fill the displayable area, reduce top:
*/

if (top > hidden)


```c
    top = hidden;
```
/* body is the relative size of the proportional gadget's knob.  Its size
** in the container represents the fraction of the total that is in view.
** If there are no lines hidden, then body should be full-size (MAXBODY).
** Otherwise, body should be the fraction of (the number of displayed
** lines - overlap) / (the total number of lines - overlap).
** The "- overlap" is so that when the  user scrolls by clicking in the
** container of the scroll gadget, then there is some overlap between the
** two views.
*/

(*body) = (hidden > 0) ?


```c
    (UWORD) (((ULONG) (displayable - overlap) * MAXBODY)
                           / (total - overlap)) :
    MAXBODY;
```
/* pot is the position of the proportional gadget knob, with zero meaning
** that the scroll gadget is all the way up (or left), and full (MAXPOT)
** meaning that the scroll gadget is all the way down (or right).  If we
** can see all the lines, pot should be zero.  Otherwise, pot is the top
** displayed line divided by the number of unseen lines.
*/

(*pot) = (hidden > 0) ? (UWORD) (((ULONG) top * MAXPOT) / hidden) : 0;
}


/*
**   FindScrollerTop( )
**
** Function to calculate the top line that is displayed in a proportional
** gadget, given the total number of items in the list and the number
** displayable, as well as the HorizPot or VertPot value.
*/

UWORD FindScrollerTop(UWORD total, UWORD displayable, UWORD pot)

{
UWORD top, hidden;


/* Find the number of unseen lines: */

hidden = max(total - displayable, 0);


/* pot can be thought of as the fraction of the hidden lines that are
** before the displayed part of the list, in other words a pot of zero
** means all hidden lines are after the displayed part of the list
** (i.e. top = 0), and a pot of MAXPOT means all the hidden lines are
** before the displayed part (i.e. top = hidden).
**
** MAXPOT/2 is added to round up values more than half way to the next
** position.
*/

top = (((ULONG) hidden * pot) + (MAXPOT/2)) >> 16;


/* Once you get back the new value of top, only redraw your list if top
** changed from its previous value.  The proportional gadget may not have
** moved far enough to change the value of top.
*/

return(top);
}

