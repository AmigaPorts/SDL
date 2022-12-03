/*
  Copyright (C) 1997-2022 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#include "../src/main/amigaos4/SDL_os4debug.h"

#include "../include/SDL_hints.h"

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/icon.h>
#include <proto/intuition.h>
#include <proto/chooser.h>

#include <intuition/classes.h>
#include <intuition/menuclass.h>

#include <classes/requester.h>
#include <classes/window.h>

#include <gadgets/layout.h>
#include <gadgets/button.h>
#include <gadgets/chooser.h>
#include <images/label.h>

#include <stdio.h>
#include <string.h>

#define NAME "SDL2 Prefs"
#define VERSION "1.4"
#define MAX_PATH_LEN 1024
#define MAX_VARIABLE_NAME_LEN 32

static const char* const versingString __attribute__((used)) = "$VER: " NAME " " VERSION " (" __AMIGADATE__ ")";
static const char* const name = NAME;

static struct ClassLibrary* WindowBase;
static struct ClassLibrary* RequesterBase;
static struct ClassLibrary* ButtonBase;
static struct ClassLibrary* LayoutBase;
static struct ClassLibrary* LabelBase;

struct ChooserIFace* IChooser;

static Class* WindowClass;
static Class* RequesterClass;
static Class* ButtonClass;
static Class* LayoutClass;
static Class* LabelClass;
Class* ChooserClass;

enum EGadgetID
{
    GID_DriverList = 1,
    GID_VsyncList,
    GID_BatchingList,
    GID_ScaleQualityList,
    GID_LogicalSizeModeList,
    GID_ScreenSaverList,
    GID_SaveButton,
    GID_ResetButton,
    GID_CancelButton
};

enum EMenuID
{
    MID_Iconify = 1,
    MID_About,
    MID_Quit
};

static struct Window* window;

struct OptionName
{
    const char* const displayName;
    const char* const envName;
    const char* const envNameAlias;
};

static const struct OptionName driverNames[] =
{
    { "default", NULL, NULL },
    { "compositing", "compositing", NULL },
    { "opengl", "opengl", NULL },
    { "opengles2", "opengles2", NULL },
    { "software", "software", NULL },
    { NULL, NULL, NULL }
};

static const struct OptionName vsyncNames[] =
{
    { "default", NULL, NULL },
    { "enabled", "1", NULL },
    { "disabled", "0", NULL },
    { NULL, NULL, NULL }
};

static const struct OptionName batchingNames[] =
{
    { "default", NULL, NULL },
    { "enabled", "1", NULL },
    { "disabled", "0", NULL },
    { NULL, NULL, NULL }
};

static const struct OptionName scaleQualityNames[] =
{
    { "default", NULL, NULL },
    { "nearest", "0", "nearest" },
    { "linear", "1", "linear" },
    { NULL, NULL, NULL }
};

static const struct OptionName logicalSizeModeNames[] =
{
    { "default", NULL, NULL },
    { "letterbox / sidebars", "0", "letterbox" },
    { "overscan", "1", "overscan" },
    { NULL, NULL, NULL }
};

static const struct OptionName screenSaverNames[] =
{
    { "default", NULL, NULL },
    { "enabled", "1", NULL },
    { "disabled", "0", NULL },
    { NULL, NULL, NULL }
};

struct Variable
{
    const enum EGadgetID gid;
    int index;
    const char* const name;
    char value[MAX_VARIABLE_NAME_LEN];
    Object* object;
    struct List* list;
    const struct OptionName* const names;
};

static struct Variable driverVar = { GID_DriverList, 0, SDL_HINT_RENDER_DRIVER, "", NULL, NULL, driverNames };
static struct Variable vsyncVar = { GID_VsyncList, 0, SDL_HINT_RENDER_VSYNC, "", NULL, NULL, vsyncNames };
static struct Variable batchingVar = { GID_BatchingList, 0, SDL_HINT_RENDER_BATCHING, "", NULL, NULL, batchingNames };
static struct Variable scaleQualityVar = { GID_ScaleQualityList, 0, SDL_HINT_RENDER_SCALE_QUALITY, "", NULL, NULL, scaleQualityNames };
static struct Variable logicalSizeModeVar = { GID_LogicalSizeModeList, 0, SDL_HINT_RENDER_LOGICAL_SIZE_MODE, "", NULL, NULL, logicalSizeModeNames };
static struct Variable screenSaverVar = { GID_ScreenSaverList, 0, SDL_HINT_VIDEO_ALLOW_SCREENSAVER, "", NULL, NULL, screenSaverNames };

static char*
GetVariable(const char* const name)
{
    static char buffer[MAX_VARIABLE_NAME_LEN];
    buffer[0] = '\0';

    const int32 len = IDOS->GetVar(name, buffer, sizeof(buffer), GVF_GLOBAL_ONLY);

    if (len > 0) {
        dprintf("value '%s', len %ld\n", buffer, len);
    } else {
        dprintf("len %ld, IoErr %ld\n", len, IDOS->IoErr());
    }

    return buffer;
}

static void
SaveVariable(const char* const name, const char* const value, uint32 control)
{
    const int32 success = IDOS->SetVar(name, value, -1, LV_VAR | GVF_GLOBAL_ONLY | control);

    dprintf("name '%s', value '%s', success %ld\n", name, value, success);
}

static void
DeleteVariable(const char* const name, uint32 control)
{
    const int32 success = IDOS->DeleteVar(name, LV_VAR | GVF_GLOBAL_ONLY | control);

    dprintf("name '%s', success %d\n", name, success);
}

static void
LoadVariable(struct Variable* var)
{
    const char* const value = GetVariable(var->name);

    snprintf(var->value, sizeof(var->value), "%s", value);
    var->index = 0;

    if (strlen(var->value) > 0) {
        const char* cmp;
        int i = 1;
        while ((cmp = var->names[i].envName)) {
            if (strcmp(var->value, cmp) == 0) {
                dprintf("Value match '%s', index %d\n", cmp, i);
                var->index = i;
                break;
            } else if ((cmp = var->names[i].envNameAlias)) {
                if (strcmp(var->value, cmp) == 0) {
                    dprintf("Alias value match '%s', index %d\n", cmp, i);
                    var->index = i;
                    break;
                }
            }
            i++;
        }
    }
}

static void
LoadVariables()
{
    LoadVariable(&driverVar);
    LoadVariable(&vsyncVar);
    LoadVariable(&batchingVar);
    LoadVariable(&scaleQualityVar);
    LoadVariable(&logicalSizeModeVar);
    LoadVariable(&screenSaverVar);
}

static void
SaveOrDeleteVariable(const struct Variable* const var)
{
    if (var->index > 0) {
        SaveVariable(var->name, var->names[var->index].envName, GVF_SAVE_VAR);
    } else {
        DeleteVariable(var->name, GVF_SAVE_VAR);
    }
}

static void
SaveVariables()
{
    SaveOrDeleteVariable(&driverVar);
    SaveOrDeleteVariable(&vsyncVar);
    SaveOrDeleteVariable(&batchingVar);
    SaveOrDeleteVariable(&scaleQualityVar);
    SaveOrDeleteVariable(&logicalSizeModeVar);
    SaveOrDeleteVariable(&screenSaverVar);
}

static BOOL
OpenClasses()
{
    const int version = 53;

    dprintf("\n");

    WindowBase = IIntuition->OpenClass("window.class", version, &WindowClass);
    if (!WindowBase) dprintf("Failed to open window.class\n");

    RequesterBase = IIntuition->OpenClass("requester.class", version, &RequesterClass);
    if (!RequesterBase) dprintf("Failed to open requester.class\n");

    ButtonBase = IIntuition->OpenClass("gadgets/button.gadget", version, &ButtonClass);
    if (!ButtonBase) dprintf("Failed to open button.gadget\n");

    LayoutBase = IIntuition->OpenClass("gadgets/layout.gadget", version, &LayoutClass);
    if (!LayoutBase) dprintf("Failed to open layout.gadget\n");

    LabelBase = IIntuition->OpenClass("images/label.image", version, &LabelClass);
    if (!LabelBase) dprintf("Failed to open label.image\n");

    ChooserBase = (struct Library *)IIntuition->OpenClass("gadgets/chooser.gadget", version, &ChooserClass);
    if (!ChooserBase) dprintf("Failed to open chooser.gadget\n");

    IChooser = (struct ChooserIFace *)IExec->GetInterface((struct Library *)ChooserBase, "main", 1, NULL);
    if (!IChooser) {
        dprintf("Failed to get ChooserIFace\n");
    }

    return WindowBase &&
           RequesterBase &&
           ButtonBase &&
           LayoutBase &&
           LabelBase &&
           ChooserBase &&
           IChooser;
}

static void
CloseClasses()
{
    dprintf("\n");

    if (IChooser) {
        IExec->DropInterface((struct Interface *)(IChooser));
    }

    IIntuition->CloseClass(WindowBase);
    IIntuition->CloseClass(RequesterBase);
    IIntuition->CloseClass(ButtonBase);
    IIntuition->CloseClass(LayoutBase);
    IIntuition->CloseClass(LabelBase);
    IIntuition->CloseClass((struct ClassLibrary *)ChooserBase);
}

static struct List*
CreateList()
{
    dprintf("\n");

    struct List* list = (struct List *)IExec->AllocSysObjectTags(ASOT_LIST, TAG_DONE);

    if (!list) {
        dprintf("Failed to allocate list\n");
    }

    return list;
}

static void
AllocChooserNode(struct List* list, const char* const name)
{
    dprintf("%p '%s'\n", list, name);

    struct Node* node = IChooser->AllocChooserNode(CNA_CopyText, TRUE,
                                                   CNA_Text, name,
                                                   TAG_DONE);

    if (!node) {
        dprintf("Failed to allocate chooser node\n");
        return;
    }

    IExec->AddTail(list, node);
}

static void
PurgeChooserList(struct List* list)
{
    dprintf("%p\n", list);

    if (list) {
        struct Node* node;

        while ((node = IExec->RemTail(list))) {
            IChooser->FreeChooserNode(node);
        }

        IExec->FreeSysObject(ASOT_LIST, list);
    }
}

static void
PopulateChooserList(struct Variable * var)
{
    const char* name;
    int i = 0;

    while ((name = var->names[i++].displayName)) {
        AllocChooserNode(var->list, name);
    }
}

static Object*
CreateChooserButtons(struct Variable* var, const char* const name, const char* const hint)
{
    dprintf("gid %d, list %p, name '%s', hint '%s'\n", var->gid, var->list, name, hint);

    var->list = CreateList();
    if (!var->list) {
        return NULL;
    }

    PopulateChooserList(var);

    var->object = IIntuition->NewObject(ChooserClass, NULL,
        GA_ID, var->gid,
        GA_RelVerify, TRUE,
        GA_HintInfo, hint,
        CHOOSER_Labels, var->list,
        CHOOSER_Selected, var->index,
        TAG_DONE);

    if (!var->object) {
        dprintf("Failed to create %s buttons\n", name);
    }

    return var->object;
}

static Object*
CreateDriverButtons()
{
    return CreateChooserButtons(&driverVar, "driver",
        "Select driver implementation:\n"
        "- compositing doesn't support some blend modes\n"
        "- opengl (MiniGL) doesn't support render targets and some blend modes\n"
        "- opengles2 supports most features\n"
        "- software supports most features but is not accelerated");
}

static Object*
CreateVsyncButtons()
{
    return CreateChooserButtons(&vsyncVar, "vsync",
        "Synchronize display update to monitor refresh rate");
}

static Object*
CreateBatchingButtons()
{
    return CreateChooserButtons(&batchingVar, "batching",
        "Batching may improve drawing speed if application does many operations per frame "
        "and SDL2 is able to combine those");
}

static Object*
CreateScaleQualityButtons()
{
    return CreateChooserButtons(&scaleQualityVar, "scale quality",
        "Nearest pixel sampling or linear filtering");
}

static Object*
CreateLogicalSizeModeButtons()
{
    return CreateChooserButtons(&logicalSizeModeVar, "logical size mode",
        "Scaling policy for SDL_RenderSetLogicalSize");
}

static Object*
CreateScreenSaverButtons()
{
    return CreateChooserButtons(&screenSaverVar, "allow screensaver",
        "Allow screensaver (disabled by default)");
}

static Object*
CreateButton(enum EGadgetID gid, const char* const name, const char* const hint)
{
    dprintf("gid %d, name '%s', hint '%s'\n", gid, name, hint);

    Object* b = IIntuition->NewObject(ButtonClass, NULL,
        GA_Text, name,
        GA_ID, gid,
        GA_RelVerify, TRUE,
        GA_HintInfo, hint,
        TAG_DONE);

    if (!b) {
        dprintf("Failed to create '%s' button\n", name);
    }

    return b;
}

static Object*
CreateSaveButton()
{
    return CreateButton(GID_SaveButton, "_Save", "Store settings to ENVARC: and exit");
}

static Object*
CreateResetButton()
{
    return CreateButton(GID_ResetButton, "_Reset", "Reset GUI to default values");
}

static Object*
CreateCancelButton()
{
    return CreateButton(GID_CancelButton, "_Cancel", "Exit program");
}

static Object*
CreateLabel(const char* const name)
{
    Object* l = IIntuition->NewObject(LabelClass, NULL,
        LABEL_Text, name,
        TAG_DONE);

    if (!l) {
        dprintf("Failed to create '%s' label\n", name);
    }

    return l;
}

static Object*
CreateRendererLayout()
{
    Object* layout = IIntuition->NewObject(LayoutClass, NULL,
        LAYOUT_Orientation, LAYOUT_ORIENT_HORIZ,
        LAYOUT_BevelStyle, BVS_GROUP,
        LAYOUT_Label, "2D Renderer Options",
        LAYOUT_AddChild, IIntuition->NewObject(LayoutClass, NULL,
            LAYOUT_HorizAlignment, LALIGN_CENTER,
            LAYOUT_AddChild, IIntuition->NewObject(LayoutClass, NULL,
                LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
                LAYOUT_AddChild, CreateDriverButtons(),
                CHILD_Label, CreateLabel("_Driver"),
                LAYOUT_AddChild, CreateVsyncButtons(),
                CHILD_Label, CreateLabel("_Vertical Sync"),
                LAYOUT_AddChild, CreateBatchingButtons(),
                CHILD_Label, CreateLabel("_Batching Mode"),
                LAYOUT_AddChild, CreateScaleQualityButtons(),
                CHILD_Label, CreateLabel("Scale _Quality"),
                LAYOUT_AddChild, CreateLogicalSizeModeButtons(),
                CHILD_Label, CreateLabel("_Logical Size Mode"),
                TAG_DONE), // vertical layout
                CHILD_WeightedWidth, 0,
            TAG_DONE),
        TAG_DONE); // horizontal layout

    if (!layout) {
        dprintf("Failed to create renderer layout\n");
    }

    return layout;
}

static Object*
CreateVideoLayout()
{
    Object* layout = IIntuition->NewObject(LayoutClass, NULL,
        LAYOUT_Orientation, LAYOUT_ORIENT_HORIZ,
        LAYOUT_BevelStyle, BVS_GROUP,
        LAYOUT_Label, "Video Options",
        LAYOUT_AddChild, IIntuition->NewObject(LayoutClass, NULL,
            LAYOUT_HorizAlignment, LALIGN_CENTER,
            LAYOUT_AddChild, IIntuition->NewObject(LayoutClass, NULL,
                LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
                LAYOUT_AddChild, CreateScreenSaverButtons(),
                CHILD_Label, CreateLabel("_Allow Screen Saver"),
                TAG_DONE), // vertical layout
                CHILD_WeightedWidth, 0,
            TAG_DONE),
        TAG_DONE); // horizontal layout

    if (!layout) {
        dprintf("Failed to create video layout\n");
    }

    return layout;
}

static Object*
CreateSettingsLayout()
{
    Object* layout = IIntuition->NewObject(LayoutClass, NULL,
        LAYOUT_Orientation, LAYOUT_ORIENT_HORIZ,
        LAYOUT_BevelStyle, BVS_GROUP,
        LAYOUT_Label, "Settings",
        LAYOUT_AddChild, CreateSaveButton(),
        LAYOUT_AddChild, CreateResetButton(),
        LAYOUT_AddChild, CreateCancelButton(),
        TAG_DONE); // horizontal layout

    if (!layout) {
        dprintf("Failed to create settings layout\n");
    }

    return layout;
}

static Object*
CreateLayout()
{
    dprintf("\n");

    Object* layout = IIntuition->NewObject(LayoutClass, NULL,
        LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
        LAYOUT_AddChild, CreateRendererLayout(),
        LAYOUT_AddChild, CreateVideoLayout(),
        LAYOUT_AddChild, CreateSettingsLayout(),
            CHILD_WeightedHeight, 0,
        TAG_DONE); // vertical main layout

    if (!layout) {
        dprintf("Failed to create layout object\n");
    }

    return layout;
}

static Object*
CreateMenu()
{
    dprintf("\n");

    Object* menuObject = IIntuition->NewObject(NULL, "menuclass",
        MA_Type, T_ROOT,

        // Main
        MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
            MA_Type, T_MENU,
            MA_Label, "Main",
            MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
                MA_Type, T_ITEM,
                MA_Label, "I|Iconify",
                MA_ID, MID_Iconify,
                TAG_DONE),
            MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
                MA_Type, T_ITEM,
                MA_Label, "A|About...",
                MA_ID, MID_About,
                TAG_DONE),
            MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
                MA_Type, T_ITEM,
                MA_Separator, TRUE,
                TAG_DONE),
            MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
                MA_Type, T_ITEM,
                MA_Label, "Q|Quit",
                MA_ID, MID_Quit,
                TAG_DONE),
            TAG_DONE),
         TAG_DONE); // Main

    if (!menuObject) {
        dprintf("Failed to create menu object\n");
    }

    return menuObject;
}

static char*
GetApplicationName()
{
    dprintf("\n");

    static char pathBuffer[MAX_PATH_LEN];

    if (!IDOS->GetCliProgramName(pathBuffer, sizeof(pathBuffer) - 1)) {
        //dprintf("Failed to get CLI program name, checking task node");
        snprintf(pathBuffer, sizeof(pathBuffer), "%s", ((struct Node *)IExec->FindTask(NULL))->ln_Name);
    }

    dprintf("Application name '%s'\n", pathBuffer);

    return pathBuffer;
}

static struct DiskObject*
MyGetDiskObject()
{
    dprintf("\n");

    BPTR oldDir = IDOS->SetCurrentDir(IDOS->GetProgramDir());
    struct DiskObject* diskObject = IIcon->GetDiskObject(GetApplicationName());

    if (diskObject) {
        diskObject->do_CurrentX = NO_ICON_POSITION;
        diskObject->do_CurrentY = NO_ICON_POSITION;
    }

    IDOS->SetCurrentDir(oldDir);

    return diskObject;
}

static Object*
CreateWindow(Object* menuObject, struct MsgPort* appPort)
{
    dprintf("menu %p, appPort %p\n", menuObject, appPort);

    Object* w = IIntuition->NewObject(WindowClass, NULL,
        WA_Activate, TRUE,
        WA_Title, name,
        WA_ScreenTitle, name,
        WA_IDCMP, IDCMP_CLOSEWINDOW | IDCMP_RAWKEY | IDCMP_MENUPICK,
        WA_CloseGadget, TRUE,
        WA_DragBar, TRUE,
        WA_DepthGadget, TRUE,
        WA_SizeGadget, TRUE,
        WA_MenuStrip, menuObject,
        WINDOW_IconifyGadget, TRUE,
        WINDOW_Icon, MyGetDiskObject(),
        WINDOW_IconTitle, name,
        WINDOW_AppPort, appPort, // Iconification needs it
        WINDOW_Position, WPOS_CENTERSCREEN,
        WINDOW_Layout, CreateLayout(),
        WINDOW_GadgetHelp, TRUE,
        TAG_DONE);

    if (!w) {
        dprintf("Failed to create window object\n");
    }

    return w;
}

static void
HandleIconify(Object* windowObject)
{
    dprintf("\n");
    window = NULL;
	IIntuition->IDoMethod(windowObject, WM_ICONIFY);
}

static void
HandleUniconify(Object* windowObject)
{
    dprintf("\n");

    window = (struct Window *)IIntuition->IDoMethod(windowObject, WM_OPEN);

    if (!window) {
        dprintf("Failed to reopen window\n");
    }
}

static void
ShowAboutWindow()
{
    dprintf("\n");

    Object* object = IIntuition->NewObject(RequesterClass, NULL,
        REQ_TitleText, "About " NAME,
        REQ_BodyText, NAME " " VERSION " (" __AMIGADATE__ ")\nWritten by Juha Niemimaki",
        REQ_GadgetText, "_Ok",
        REQ_Image, REQIMAGE_INFO,
        REQ_TimeOutSecs, 10,
        TAG_DONE);

    if (object) {
        IIntuition->SetWindowPointer(window, WA_BusyPointer, TRUE, TAG_DONE);
        IIntuition->IDoMethod(object, RM_OPENREQ, NULL, window, NULL);
        IIntuition->SetWindowPointer(window, TAG_DONE);
        IIntuition->DisposeObject(object);
    } else {
        dprintf("Failed to create requester object\n");
    }
}

static BOOL
HandleMenuPick(Object* windowObject)
{
    BOOL running = TRUE;

    uint32 id = NO_MENU_ID;

    while (window && (id = IIntuition->IDoMethod((Object *)window->MenuStrip, MM_NEXTSELECT, 0, id)) != NO_MENU_ID) {
        dprintf("menu id %lu\n", id);
        switch(id) {
            case MID_About:
                ShowAboutWindow();
                break;
            case MID_Quit:
                running = FALSE;
                break;
            case MID_Iconify:
                HandleIconify(windowObject);
                break;
            default:
                dprintf("Unknown menu item %d\n", id);
                break;
         }
    }

    return running;
}

static void
ReadSelection(struct Variable* var)
{
    uint32 selected = 0;

    const ULONG result = IIntuition->GetAttrs(var->object, CHOOSER_Selected, &selected, TAG_DONE);

    if (!result) {
        dprintf("Failed to get radiobutton selection\n");
    }

    var->index = selected;
}

static void
ResetSelection(struct Variable* var)
{
    var->index = 0;
    IIntuition->RefreshSetGadgetAttrs((struct Gadget *)var->object, window, NULL, CHOOSER_Selected, 0, TAG_DONE);
}

static BOOL
HandleGadgets(enum EGadgetID gid)
{
    BOOL running = TRUE;

    dprintf("gid %d\n", gid);

    switch (gid) {
        case GID_DriverList:
            ReadSelection(&driverVar);
            break;
        case GID_VsyncList:
            ReadSelection(&vsyncVar);
            break;
        case GID_BatchingList:
            ReadSelection(&batchingVar);
            break;
        case GID_ScaleQualityList:
            ReadSelection(&scaleQualityVar);
            break;
        case GID_LogicalSizeModeList:
            ReadSelection(&logicalSizeModeVar);
            break;
        case GID_ScreenSaverList:
            ReadSelection(&screenSaverVar);
            break;
        case GID_SaveButton:
            SaveVariables();
            running = FALSE;
            break;
        case GID_ResetButton:
            ResetSelection(&driverVar);
            ResetSelection(&vsyncVar);
            ResetSelection(&batchingVar);
            ResetSelection(&scaleQualityVar);
            ResetSelection(&logicalSizeModeVar);
            ResetSelection(&screenSaverVar);
            break;
        case GID_CancelButton:
            running = FALSE;
            break;
        default:
            dprintf("Unhandled gadget %d\n", gid);
            break;
    }

    return running;
}

static BOOL
HandleEvents(Object* windowObject)
{
    BOOL running = TRUE;

    uint32 winSig = 0;
    if (!IIntuition->GetAttr(WINDOW_SigMask, windowObject, &winSig)) {
        dprintf("GetAttr failed\n");
    }

    const ULONG signals = IExec->Wait(winSig | SIGBREAKF_CTRL_C);
    //dprintf("signals %lu\n", signals);
    if (signals & SIGBREAKF_CTRL_C) {
        dprintf("Control-C\n");
        running = FALSE;
    }

	uint32 result;
	int16 code = 0;

    while ((result = IIntuition->IDoMethod(windowObject, WM_HANDLEINPUT, &code)) != WMHI_LASTMSG) {
        switch (result & WMHI_CLASSMASK) {
            case WMHI_CLOSEWINDOW:
                running = FALSE;
            	break;
            case WMHI_ICONIFY:
            	HandleIconify(windowObject);
            	break;
            case WMHI_UNICONIFY:
            	HandleUniconify(windowObject);
            	break;
            case WMHI_MENUPICK:
            	if (!HandleMenuPick(windowObject)) {
                    running = FALSE;
                }
            	break;
            case WMHI_GADGETUP:
                if (!HandleGadgets(result & WMHI_GADGETMASK)) {
                    running = FALSE;
                }
                break;
        	default:
        		//dprintf("Unhandled event result %lx, code %x\n", result, code);
        		break;
        }
    }

    return running;
}

int
main(int argc, char** argv)
{
    LoadVariables();

    if (OpenClasses()) {
        struct MsgPort* appPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_DONE);

        Object* menuObject = CreateMenu();
        Object* windowObject = CreateWindow(menuObject, appPort);

        if (windowObject) {
            window = (struct Window *)IIntuition->IDoMethod(windowObject, WM_OPEN);

            if (window) {
                do {
                } while (HandleEvents(windowObject));
            } else {
                dprintf("Failed to open window\n");
            }

            IIntuition->DisposeObject(windowObject);
            windowObject = NULL;
        }

        if (menuObject) {
            IIntuition->DisposeObject(menuObject);
            menuObject = NULL;
        }

        if (appPort) {
            IExec->FreeSysObject(ASOT_PORT, appPort);
            appPort = NULL;
        }

        PurgeChooserList(driverVar.list);
        PurgeChooserList(vsyncVar.list);
        PurgeChooserList(batchingVar.list);
        PurgeChooserList(scaleQualityVar.list);
        PurgeChooserList(logicalSizeModeVar.list);
        PurgeChooserList(screenSaverVar.list);
    }

    CloseClasses();

    return 0;
}

