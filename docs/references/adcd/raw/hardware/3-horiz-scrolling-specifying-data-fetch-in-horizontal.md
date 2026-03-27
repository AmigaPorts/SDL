# 3 / / Horiz. Scrolling / Specifying Data Fetch in Horizontal Scrolling


The normal data-fetch start for non-scrolled displays is ($38). If
horizontal scrolling is desired, then the data fetch must start one word
sooner ( [DDFSTRT](../Hardware_Manual_guide/node0072.html#line9)  = $0030). Incidentally, this will disable  [sprite 7](../Hardware_Manual_guide/node00C2.html#line5) .
 [DDFSTOP](../Hardware_Manual_guide/node0072.html#line31)  remains unchanged. Remember that the settings of the data-fetch
registers affect both playfields.

