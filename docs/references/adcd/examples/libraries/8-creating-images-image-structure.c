/* Source: ADCD 2.1
 * Section: 8-creating-images-image-structure
 * Library: libraries
 * ADCD reference: libraries/8-creating-images-image-structure.md
 */

    This is a pointer to the bits that define the image and determine the
    colors of each pixel.  Image data must be placed in Chip memory.  The
    data is organized as an array of 16 bit words whose size can be
    computed as follows:

        WordWidth = ((Width + 16) / 16);
        NumImageWords = WordWidth * Height * Depth;

    The width of the image is rounded up to the nearest word (16 bits)
    and extra trailing bits are ignored.  Each line of each bitplane must
    have enough words to contain the image width, with extra bits at the
    end of each line set to zero.  For example, an image 7 bits wide
    requires one word for each line in the bitplane, whereas an image 17
    bits wide requires two words for each line in the bitplane.
