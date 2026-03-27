---
title: 7 / Alerts / Types of Alerts
manual: libraries
chapter: libraries
section: 7-alerts-types-of-alerts
functions: []
libraries: []
---

# 7 / Alerts / Types of Alerts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are two levels of severity for alerts:

RECOVERY_ALERT

    Recovery alerts are used in situations where the caller believes that
    the system can resume operations after handling the error.  The alert
    is used as a warning, and is displayed in amber.

    A recoverable alert displays the text of the alert and flashes the
    border while waiting for the user to respond.  It returns TRUE if the
    user presses the left mouse button in response to the alert,
    otherwise FALSE is returned.
DEADEND_ALERT

    Deadend alerts are used in situations where the caller believes that
    no recovery from the error is possible, and further operation of the
    system is impossible.  This alert is used to inform the user of a
    fatal problem and is displayed in red.  Deadend alerts are the same
    as recoverable alerts in every way except color.
