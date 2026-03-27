---
title: 5 / / Proportional Gadget Components / Functions for Using a Slider
manual: libraries
chapter: libraries
section: 5-proportional-gadget-components-functions-for-using-a-2
functions: []
libraries: []
---

# 5 / / Proportional Gadget Components / Functions for Using a Slider

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
**     FindSliderValues( )
**
** Function to calculate the Body and Pot values of a slider gadget given
** the two values numlevels and level, representing the number of levels
** available in the slider, and the current level.  For example, a Red,
** Green, or Blue slider would have (currently) numlevels = 16,
** level = the color level (0-15).
*/

void FindSliderValues(UWORD numlevels, UWORD level,


```c
                      UWORD *body, UWORD *pot)
```
{
/* body is the relative size of the proportional gadget's body.
** Clearly, this proportion should be 1 / numlevels.
*/

if (numlevels > 0)
```c
    (*body) = (MAXBODY) / numlevels;
```
else


```c
    (*body) = MAXBODY;
```
/* pot is the position of the proportional gadget body, with zero meaning
** that the slider is all the way up (or left), and full (MAXPOT) meaning
** that the slider is all the way down (or right).
**
** For slider gadgets the derivation is a bit ugly:
**
** We illustrate a slider of four levels (0, 1, 2, 3) with the slider at
** level 2.  The key observation is that pot refers the the leading edge of
** the knob, and as such MAXPOT is not all the way to the right, but is one
** body's width left of that.
**
** Level:   0       1       2       3
**      ---------------------------------
**      |       |       |*******|       |
**      |       |       |*******|       |
**      |       |       |*******|       |
**      |       |       |*******|       |
**      ---------------------------------
**      |               |       |
**      0              pot    MAXPOT
**
** From which we observe that pot = MAXPOT * (level/(numlevels-1))
*/

if (numlevels > 1)
```c
    {
    (*pot) = (((ULONG)MAXPOT) * level)/(numlevels-1);
    }
```
else
```c
    {
    (*pot) = 0;
    }
```
}


/*
**     FindSliderLevel( )
**
** Function to calculate the level of a slider gadget given the total
** number of levels as well as the HorizPot or VertPot value.
*/

UWORD FindSliderLevel(UWORD numlevels, UWORD pot)


{
UWORD level;

/* We illustrate a 4-level slider (0, 1, 2, 3) with the knob on the
** transition point between calling it at levels 1 and 2.
**
** Level:   0       1       2       3
**      ---------------------------------
**      |       |    ***|***    |       |
**      |       |    ***|***    |       |
**      |       |    ***|***    |       |
**      |       |    ***|***    |       |
**      ---------------------------------
**      |           |           |
**      0          pot        MAXPOT
**
**
** We've already shown that the vertical lines (which represent the natural
** position of the knob for a given level are:
**
**     pot = MAXPOT * (level/(numlevels-1))
**
** and we see that the threshold between level and level-1 is half-way
** between pot(level) and pot(level-1), from which we get
**
**     level = (numlevels-1) * (pot/MAXPOT) + 1/2
*/

if (numlevels > 1)
```c
    {
    level = (((ULONG)pot) * (numlevels-1) + MAXPOT/2) / MAXPOT;
    }
```
else

```c
    {
    level = 0;
    }
```
return(level);
}

