# D / Errors / Menu Problems


A flickering menu is caused by leaving a pixel or more space between menu
subitems when designing your menu.  Crashing after browsing a menu
(looking at menu without selecting any items) is caused by not properly
handling [MENUNULL](../Libraries_Manual_guide/node0188.html#line20) select messages.  Multiple selection not working is
caused by not handling [NextSelect](../Libraries_Manual_guide/node019A.html#line93) properly.  See the "[Intuition Menus](../Libraries_Manual_guide/node0187.html)"
chapter.

