/* amiport: stub tinyfiledialogs for AmigaOS 3.x
 * Julius uses this for folder-select dialogs on desktop.
 * On Amiga, Caesar III data is at a fixed path -- no dialog needed. */

#include <stddef.h>

int tinyfd_messageBox(
    char const *aTitle,
    char const *aMessage,
    char const *aDialogType,
    char const *aIconType,
    int aDefaultButton)
{
    (void)aTitle; (void)aMessage; (void)aDialogType;
    (void)aIconType; (void)aDefaultButton;
    return 0;
}

char const *tinyfd_selectFolderDialog(
    char const *aTitle,
    char const *aDefaultPath)
{
    (void)aTitle; (void)aDefaultPath;
    return NULL;
}
