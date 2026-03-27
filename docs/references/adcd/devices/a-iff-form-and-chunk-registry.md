---
title: A / IFF Form and Chunk Registry
manual: devices
chapter: devices
section: a-iff-form-and-chunk-registry
functions: []
libraries: []
---

# A / IFF Form and Chunk Registry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following is an alphabetical list of registered FORMs, generic chunks
(shown as (any).chunkname), and registered new chunks for existing FORMs
(shown as formname.chunkname).  The center column describes where
additional information on the FORM or chunk may be found.  Items marked
"EA_IFF" are described in the main chapters of the EA IFF specs.  Those
marked "IFF_TP" are described in the third-party specications section.
Items marked "propos" are proposals which have been submitted to CATS,
some of which are private.  And items marked with "----" are private or
yet unreleased specifications.  New chunks and FORMS should be registered
with CATS US, IFF Registry, 1200 Wilson Drive, West Chester, PA. 19380.
Please make all submissions on Amiga diskette and include your address,
phone, fax.

(any).ANNO         EA_IFF  EA IFF 85 Generic Annotation chunk
(any).AUTH         EA_IFF  EA IFF 85 Generic Author chunk
(any).CHRS         EA_IFF  EA IFF 85 Generic character string chunk
(any).CSET.doc     IFF_TP  chunk for specifying character set
(any).FVER.doc     IFF_TP  chunk for 2.0 VERSION string of an IFF file
(any).HLID.doc      ----   HotLink IDentification (Contact CATS for info)
(any).NAME         EA_IFF  EA IFF 85 Generic Name of art, music, etc. chunk
(any).TEXT         EA_IFF  EA IFF 85 Generic unformatted ASCII text chunk
(any).(c)          EA_IFF  EA IFF 85 Generic Copyright text chunk
8SVX               EA_IFF  EA IFF 85 8-bit sound sample form
8SVX.CHAN.PAN.doc  IFF_TP  Stereo chunks for 8SVX form
8SVX.SEQN.FADE.doc IFF_TP  Looping chunks for 8SVX form
ACBM.doc           IFF_TP  Amiga Contiguous Bitmap form
AHAM                ----   unregistered (???)
AIFF.doc           IFF_TP  Audio 1-32 bit samples (Mac,AppleII,Synthia Pro)
ANBM.doc           IFF_TP  Animated bitmap form (Framer, Deluxe Video)
ANIM.brush.doc     IFF_TP  ANIM brush format
ANIM.doc           IFF_TP  Cel animation form
ANIM.op6.doc       IFF_TP  Stereo (3D) Animations
ARC.proposal       propos  archive format proposal (old)
ARES                ----   unregistered (???)
ATXT                ----   temporariliy reserved
AVCF                ----   AmigaVision flow (format not yet released)
AVCF.doc           IFF_TP
AVCO                ----   AmigaVision commands (format not yet released)
AVEV                ----   AmigaVision events (format not yet released)
BANK                ----   Soundquest Editor/Librarian MIDI Sysex dump
BBSD                ----   BBS Database, F.Patnaude,Jr., Phalanx Software
C100                ----   Cloanto Italia private format
CAT                EA_IFF  EA IFF 85 group identifier
CHBM                ----   Chunky bitmap (name reserved by Eric Lavitsky)
CLIP                ----   CAT CLIP to hold various formats in clipboard
CPFM                ----   Cloanto Personal FontMaker (doc in their manual)
DCCL                ----   DCCL - DCTV paint clip
DCPA                ----   DCPA - DCTV paint palette
DCTV                ----   DCTV - DCTV raw picture file
DECK                ----   private format for Inovatronics CanDo
DR2D.doc           IFF_TP  2-D Object standard format
DRAW                ----   reserved by Jim Bayless, 12/90
FANT.doc           IFF_TP  Fantavision movie format
FIGR                ----   Deluxe Video - reserved
FNTR               EA_IFF  EA IFF 85 reserved for raster font
FNTV               EA_IFF  EA IFF 85 reserved for vector font
FORM               EA_IFF  EA IFF 85 group identifier
FTXT               EA_IFF  EA IFF 85 formatted text form
GRYP.proposal      propos  byteplane storage proposal (copyrighted)
GSCR               EA_IFF  EA IFF 85 reserved gen. music score
GUI.proposal       propos  user interface storage proposal (private)
HEAD.doc           IFF_TP  Flow -  New Horizons Software
ILBM               EA_IFF  EA IFF 85 raster bitmap form
ILBM.3DCM           ----   reserved by Haitex
ILBM.3DPA           ----   reserved by Haitex
ILBM.ASDG           ----   private ASDG application chunk
ILBM.BHBA           ----   private Photon Paint chunk (brushes)
ILBM.BHCP           ----   private Photon Paint chunk (screens)
ILBM.BHSM           ----   private Photon Paint chunk
ILBM.CLUT.doc      IFF_TP  Color Lookup Table chunk
ILBM.CMYK.doc      IFF_TP  Cyan,Magenta,Yellow, & Black cmap (Contact CATS)
ILBM.CNAM.doc       ----   Color naming chunk (Soft-Logik) (Contact CATS)
ILBM.CTBL.DYCP.doc IFF_TP  Newtek Dynamic Ham color chunks
ILBM.DCTV           ----   reserved
ILBM.DGVW           ----   private Newtek DigiView chunk
ILBM.DPI.doc       IFF_TP  Dots per inch chunk
ILBM.DPPV.doc      IFF_TP  DPaint perspective chunk (EA)
ILBM.DRNG.doc      IFF_TP  DPaint IV enhanced color cycle chunk (EA)
ILBM.EPSF.doc      IFF_TP  Encapsulated Postscript chunk
ILBM.TMAP           ----   Transparency map (temporarily reserved)
ILBM.VTAG.proposal propos  Viewmode tags chunk suggestion
ILBM.XBMI.doc      IFF_TP  eXtended BitMap Information (Contact CATS)
IOBJ                ----   reserved by Seven Seas Software
ITRF                ----   reserved
LIST               EA_IFF  EA IFF 85 group identifier
MIDI                ----   Circum Design
MOVI                ----   LIST MOVI - private format
MSCX                ----   private Music-X format
MSMP                ----   temporarily reserved
MTRX.doc           IFF_TP  Numerical data storage (MathVision - Seven Seas)
NSEQ                ----   Numerical sequence (Stockhausen GmbH)
OCMP               EA_IFF  EA IFF 85 reserved computer prop
OCPU               EA_IFF  EA IFF 85 reserved processor prop
OPGM               EA_IFF  EA IFF 85 reserved program prop
OSN                EA_IFF  EA IFF 85 reserved serial num prop
PGTB.doc           IFF_TP  Program traceback (SAS Institute)
PICS               EA_IFF  EA IFF 85 reserved Macintosh picture
PLBM               EA_IFF  EA IFF 85 reserved obsolete name
PROP               EA_IFF  EA IFF 85 group identifier
PRSP.doc           IFF_TP  DPaint IV perspective move form (EA)
PTCH                ----   Patch file format (SAS Institute)
PTXT                ----   temporarily reserved
README              ----
RGB4                ----   4-bit RGB (format not available)
RGBN-RGB8.doc      IFF_TP  RGB image forms, Turbo Silver (Impulse)
RGBX                ----   temporarily reserved
ROXN                ----   private animation form
SAMP.doc           IFF_TP  Sampled sound format
SC3D                ----   private scene format (Sculpt-3D)
SHAK                ----   private Shakespeare format
SHO1                ----   Reserved by Gary Bonham (private)
SHOW                ----   Reserved by Gary Bonham (private)
SMUS               EA_IFF  EA IFF 85 simple music score form
SYTH                ----   SoundQuest Master Librarian MIDI System driver
TCDE                ----   reserved by Merging Technologies
TDDD.doc           IFF_TP  3-D rendering data, Turbo Silver (Impulse)
UNAM               EA_IFF  EA IFF 85 reserved user name prop
USCR               EA_IFF  EA IFF 85 reserved Uhuru score
UVOX               EA_IFF  EA IFF 85 reserved Uhuru Mac voice
VDEO                ----   private Deluxe Video format
WORD.doc           IFF_TP  ProWrite document format (New Horizons)

