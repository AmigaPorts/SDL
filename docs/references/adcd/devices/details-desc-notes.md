---
title: Details /  DESC notes
manual: devices
chapter: devices
section: details-desc-notes
functions: []
libraries: []
---

# Details /  DESC notes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Again, most of these fields are optional, and defaults are supplied.
However, if there is a FACE chunk, there must also be a CLST chunk, an
RLST chunk and a TLST chunk -- all with matching "count" fields. The SHAP
chunk is not optional.

Defaults are:  Colors set to (240,240,240); reflection and transmission
coefficients set to zero; illegal shape; no story or special surface
types; position at (0,0,0); axes aligned to the world axes; size fields
all 32.0; intensity at 300; no name; no points/edges or faces; texture
parameters set to zero; refraction type 0 with index 1.00; specular,
hardness and roughness set to zero; blending at 255; glossy off; phong
shading on; not a light source; not brightly lit;

In Imagine, defaults are the same, but with colors (255,255,255).

