# 36 Translator Library / Additional Notes About Translate


The English language has many words that do not sound the same as they are
spelled. The translator library has exception rules that it consults as
the translation progresses. It also provides for common abbreviations such
as Dr., Prof., LB., etc. Words that are not in the exception table are
translated literally. This translation allows unrestricted English text as
input, and uses over four hundred and fifty context sensitive rules. It
automatically accents content words, and leaves function words (e.g. of,
by, the, and at) unaccented. It is possible, however, that certain words
will not translate well. You can improve the quality of translation by
handling those words on your own.

The phoneme table that the narrator uses is listed in the
"[Narrator Device](../Devices_Manual_guide/node011B.html)" chapter of the Amiga ROM Kernel Reference Manual:
Devices.  You will also find other important information about the Amiga's
speech capability in the narrator chapter including a [working example](../Devices_Manual_guide/node01A9.html)
which shows how to use the translator library together with the narrator
device.

