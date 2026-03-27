# IV-77: Optimized Window Refreshing


by Martin Taillefer


Maintaining the graphical contents of an Amiga window can be
difficult.  There are many subtleties associated with the process
known as window refreshing.  At present, many applications refresh
their windows in suboptimal ways, or fail to refresh correctly under
all conditions.  This article attempts to explore and resolve the
window refreshing problems commonly encountered by applications.

 [Damaging Information](../AmigaMail_Vol2_guide/node00BD.html)          [Using Multiple RastPorts](../AmigaMail_Vol2_guide/node00C1.html) 
 [When To Refresh](../AmigaMail_Vol2_guide/node00BE.html)               [Refreshing a Sizable Window](../AmigaMail_Vol2_guide/node00C2.html) 
 [Scrolling Your Life Away](../AmigaMail_Vol2_guide/node00BF.html)      [BeginRefresh() and EndRefresh()](../AmigaMail_Vol2_guide/node00C3.html) 
 [Faster Rendering](../AmigaMail_Vol2_guide/node00C0.html)              [Backfill Hook](../AmigaMail_Vol2_guide/node00C4.html) 

 [Optimrefresh.c](../AmigaMail_Vol2_guide/node01BA.html) 

