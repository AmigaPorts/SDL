# 1 / / Design Decisions / ASL Requesters


The [Release 2 ASL library](../Libraries_Manual_guide/node027A.html#line4) provides standard file and font requesters.
[Allocation](../Libraries_Manual_guide/node027B.html) and use of an ASL requester can be handled by coding a simple
subroutine to use the ASL requester if available.  Otherwise use fallback
code or a public domain requester. By now, many of you have probably coded
your own requesters and you may be quite attached to them.  In that case,
at least give your users the option to use the ASL requester if they wish.
By using the ASL requesters, you can provide a familiar interface to your
users, gain the automatic benefit of all ASL file requester improvements,
and stop maintaining your own requester code.

