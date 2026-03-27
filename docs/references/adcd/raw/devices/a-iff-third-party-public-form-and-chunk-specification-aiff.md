# A / IFF Third Party Public Form and Chunk Specification / AIFF.doc


Audio 1-32 bit samples (Mac,AppleII,Synthia Pro)

provided by Steve Milne and Matt Deatherage, Apple Computer, Inc.



           AIFF: Audio Interchange File Format File
The Audio Interchange File Format (Audio IFF) provides a standard for
storing sampled sounds.  The format is quite flexible, allowing the
storage of monaural or multichannel sampled sounds at a variety of sample
rates and sample widths.

Audio IFF conforms to the "EA IFF 85: Standard for Interchange Format
Files" developed by Electronic Arts.

Audio IFF is primarily an interchange format, although application
designers should find it flexible enough to use as a data storage format
as well.  If an application does choose to use a different storage format,
it should be able to convert to and from the format defined in this
document.  This ability to convert will facilitate the sharing of sound
data between applications.

Audio IFF is the result of several meetings held with music developers
over a period of ten months during 1987 and 1988.  Apple Computer greatly
appreciates the comments and cooperation provided by all developers who
helped define this standard.

Another "EA IFF 85" sound storage format is "8SVX IFF 8-bit Sampled
Voice", by Electronic Arts.  '8SVX', which handles eight-bit monaural
samples, is intended mainly for storing sound for playback on personal
computers.  Audio IFF is intended for use with a larger variety of
computers, sampled sound instruments, sound software applications, and
high fidelity recording devices.

 [Data Types](../Devices_Manual_guide/node0214.html)                              [The Marker Chunk](../Devices_Manual_guide/node021F.html) 
 [Constants](../Devices_Manual_guide/node0215.html)                               [The Instrument Chunk](../Devices_Manual_guide/node0222.html) 
 [Data Organization](../Devices_Manual_guide/node0216.html)                       [The MIDI Data Chunk](../Devices_Manual_guide/node0225.html) 
 [Referring to Audio IFF](../Devices_Manual_guide/node0217.html)                  [Audio Recording Chunk](../Devices_Manual_guide/node0226.html) 
 [File Structure](../Devices_Manual_guide/node0218.html)                          [Application Specific Chunk](../Devices_Manual_guide/node0227.html) 
 [Storage of AIFF on Other Platforms](../Devices_Manual_guide/node0219.html)      [The Comments Chunk](../Devices_Manual_guide/node0228.html) 
 [Local Chunk Types](../Devices_Manual_guide/node021A.html)                       [Text Chunks](../Devices_Manual_guide/node022B.html) 
 [Sample Points and Sample Frames](../Devices_Manual_guide/node021D.html)         [Chunk Precedence](../Devices_Manual_guide/node0230.html) 
 [Block Aligning Sound Data](../Devices_Manual_guide/node021E.html)               [Further Reference](../Devices_Manual_guide/node0231.html) 

