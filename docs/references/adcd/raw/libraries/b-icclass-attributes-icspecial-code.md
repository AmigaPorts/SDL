# B / icclass / Attributes: ICSPECIAL_CODE ()


This is a dummy attribute for the [ICA_MAP](../Libraries_Manual_guide/node04CA.html).  If any attribute maps to
ICSPECIAL_CODE and [ICA_TARGET](../Libraries_Manual_guide/node04C9.html) is ICTARGET_IDCMP, then the value of the
mapped attribute will be copied into the [IntuiMessage.Code](../Libraries_Manual_guide/node01D9.html#line33) field of the
[IDCMP_IDCMPUPDATE](../Libraries_Manual_guide/node01E1.html#line98) message (just the lower sixteen bits of the attribute
value will fit).

