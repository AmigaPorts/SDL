---
title: 8SVX IFF 8-Bit Sampled Voice / Appendix B. 8SVX Example
manual: devices
chapter: devices
section: 8svx-iff-8-bit-sampled-voice-appendix-b-8svx-example
functions: []
libraries: []
---

# 8SVX IFF 8-Bit Sampled Voice / Appendix B. 8SVX Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here's a box diagram for a simple example containing the three octave [BODY](devices/standard-data-and-property-chunks-data-chunk-body.md)
shown earlier in Figure 2.


```c
                  +--------------------------+
                  |                          |
                  |  'FORM'            362   |  FORM 362 8SVX
                  |                          |
               -  +--------------------------+
               |  |                          |
               |  |    '8SVX'                |
               |  |                          |
               |  |  +--------------------+  |
               |  |  |  'VHDR'       20   |  |  .VHDR 20
               |  |  |--------------------|  |
               |  |  |  24, 16, 8, 10000, |  |
               |  |  |  3, 0, 1.0         |  |
               |  |  +--------------------+  |
               |  |                          |
               |  |  +--------------------+  |
               |  |  |  'NAME'       11   |  |  .NAME 11
               |  |  |--------------------|  |
               |  |  |  'bass guitar'     |  |
          368 <   |  +--------------------+  |
         bytes |  |     0                    |
               |  |  +--------------------+  |
               |  |  |  '(c) '        20  |  |
               |  |  |--------------------|  |  .(c)  20
               |  |  |'1985 Electronic    |  |
               |  |  | Arts'              |  |
               |  |  +--------------------+  |
               |  |                          |
               |  |  +--------------------+  |
               |  |  |  'BODY'      280   |  |
               |  |  |--------------------|  |  .BODY 280
               |  |  |  1, 2, 3, 4....    |  |
               |  |  +--------------------+  |
               |  |                          |
               -- +--------------------------+
```
The "0" after the NAME chunk is a pad byte.

