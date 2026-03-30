/* amiport: stub PNG screenshot for AmigaOS 3.x
 * Screenshots require libpng which we don't have.
 * This replaces src/graphics/screenshot.c entirely. */

void graphics_save_screenshot(int full_city)
{
    (void)full_city;
    /* No PNG support on AmigaOS 3.x build */
}
