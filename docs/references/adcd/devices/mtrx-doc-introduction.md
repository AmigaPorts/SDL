---
title: MTRX.doc / Introduction
manual: devices
chapter: devices
section: mtrx-doc-introduction
functions: []
libraries: []
---

# MTRX.doc / Introduction

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Numerical data, as it comes from the real world, is an ill-mannered beast.
Often much is assumed about the data, such as the number of dimensions,
formatting, compression, limits, and sizes.  As such, data is not
portable. The MTRX FORM will both store the data, and completely describe
its format, such that programs no longer need to guess the parameters of a
data file.  There needs to be but one program to read ascii files and
output MTRX IFF files.

A matrix, by our definition, is composed of three types of things.
Firstly, the atomic data, such as an integer, or floating point number.
Secondly, arrays, which are simply lists of things which are all the same.
Thirdly, structures, which are lists of things which are different. Both
arrays and structures may be composed of things besides atomic data - they
may contain other structures and arrays as well.  This concept of nesting
structures may be repeated to any desired depth.

For example, a list of data pairs could be encoded as an array of
structures, where each structure contains two numbers.  A two-dimensional
array is simply an array of arrays.

Since space conservation is often desirable, there is provision for
representing each number with fewer bits, and compressing the bits
together.

