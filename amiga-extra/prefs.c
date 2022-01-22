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

#define DEBUG
#include "../src/main/amigaos4/SDL_os4debug.h"

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/icon.h>
#include <proto/intuition.h>
#include <proto/radiobutton.h>

#include <intuition/classes.h>
#include <intuition/menuclass.h>

#include <classes/requester.h>
#include <classes/window.h>

#include <gadgets/layout.h>
#include <gadgets/button.h>
#include <gadgets/radiobutton.h>

#include <stdio.h>
#include <string.h>

#define NAME "SDL2 Prefs"
#define VERSION "1.1"
#define MAX_PATH_LEN 1024
#define MAX_VARIABLE_NAME_LEN 32

static const char* const versingString __attribute__((used)) = "$VER: " NAME " " VERSION " (" __AMIGADATE__ ")";
static const char* const name = NAME;

static struct ClassLibrary* WindowBase;
static struct ClassLibrary* RequesterBase;
static struct ClassLibrary* ButtonBase;
static struct ClassLibrary* LayoutBase;

struct RadioButtonIFace* IRadioButton; 

static Class* WindowClass;
static Class* RequesterClass;
static Class* ButtonClass;
static Class* LayoutClass;
Class* RadioButtonClass;

enum EGadgetID
{
    GID_DriverList = 1,
    GID_VsyncList,
    GID_BatchingList,
    GID_ScaleQualityList,
    GID_SaveButton,
    GID_UseButton,
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
};

static const struct OptionName driverNames[] =
{
    { "default", NULL },
    { "compositing", "compositing" },
    { "opengl", "opengl" },
    { "opengles2", "opengles2" },
    { "software", "software" },
    { NULL, NULL }
};

static const struct OptionName vsyncNames[] =
{
    { "default", NULL },
    { "enabled", "1" },
    { "disabled", "0" },
    { NULL, NULL }
};

static const struct OptionName batchingNames[] =
{
    { "default", NULL },
    { "enabled", "1" },
    { "disabled", "0" },
    { NULL, NULL }
};

static const struct OptionName scaleQualityNames[] =
{
    { "default", NULL },
    { "nearest", "0" },
    { "linear", "1" },
    { NULL, NULL }
};

struct Variable
{
    int index;
    const char* const name;
    char value[MAX_VARIABLE_NAME_LEN];
    Object* object;
    struct List* list;
    const struct OptionName* const names;
};

static struct Variable driverVar = { 0, "SDL_RENDER_DRIVER", "", NULL, NULL, driverNames };
static struct Variable vsyncVar = { 0, "SDL_RENDER_VSYNC", "", NULL, NULL, vsyncNames };
static struct Variable batchingVar = { 0, "SDL_RENDER_BATCHING", "", NULL, NULL, batchingNames };
static struct Variable scaleQualityVar = { 0, "SDL_RENDER_SCALE_QUALITY", "", NULL, NULL, scaleQualityNames };

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
}

static void
SetOrDeleteVariable(const struct Variable* const var)
{
    if (var->index > 0) {
        SaveVariable(var->name, var->names[var->index].envName, 0);
    } else {
        DeleteVariable(var->name, 0);
    }
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
SetVariables()
{
    SetOrDeleteVariable(&driverVar);
    SetOrDeleteVariable(&vsyncVar);
    SetOrDeleteVariable(&batchingVar);
    SetOrDeleteVariable(&scaleQualityVar);
}

static void
SaveVariables()
{
    SaveOrDeleteVariable(&driverVar);
    SaveOrDeleteVariable(&vsyncVar);
    SaveOrDeleteVariable(&batchingVar);
    SaveOrDeleteVariable(&scaleQualityVar);
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

    RadioButtonBase = (struct Library *)IIntuition->OpenClass("gadgets/radiobutton.gadget", version, &RadioButtonClass);
    if (!RadioButtonBase) dprintf("Failed to open radiobutton.gadget\n");

    IRadioButton = (struct RadioButtonIFace *)IExec->GetInterface((struct Library *)RadioButtonBase, "main", 1, NULL);

    if (!IRadioButton) {
        dprintf("Failed to get RadioButtonIFace\n");
    }

    return WindowBase &&
           RequesterBase &&
           ButtonBase &&
           LayoutBase &&
           RadioButtonBase &&
           IRadioButton;
}

static void
CloseClasses()
{
    dprintf("\n");

    if (IRadioButton) {
        IExec->DropInterface((struct Interface *)(IRadioButton));
    }

    IIntuition->CloseClass(WindowBase);
    IIntuition->CloseClass(RequesterBase);
    IIntuition->CloseClass(ButtonBase);
    IIntuition->CloseClass(LayoutBase);
    IIntuition->CloseClass((struct ClassLibrary *)RadioButtonBase);
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
AllocNode(struct List* list, const char* const name)
{
    dprintf("%p '%s'\n", list, name);

    struct Node* node = IRadioButton->AllocRadioButtonNode(0, RBNA_Label, name, TAG_DONE);

    if (!node) {
        dprintf("Failed to allocate list node\n");
        return;
    }

    IExec->AddTail(list, node);
}

static void
PurgeList(struct List* list)
{
    dprintf("%p\n", list);

    if (list) {
        struct Node* node;

        while ((node = IExec->RemTail(list))) {
            IRadioButton->FreeRadioButtonNode(node);
        }

        IExec->FreeSysObject(ASOT_LIST, list);
    }
}

static Object*
CreateRadioButtons(enum EGadgetID gid, struct Variable* var, const char* const name, const char* const hint)
{
    dprintf("gid %d, list %p, name '%s', hint '%s'\n", gid, var->list, name, hint);

    Object* rb = IIntuition->NewObject(RadioButtonClass, NULL,
        GA_ID, gid,
        GA_RelVerify, TRUE,
        GA_HintInfo, hint,
        RADIOBUTTON_Labels, var->list,
        RADIOBUTTON_Spacing, 4,
        RADIOBUTTON_Selected, var->index,
        TAG_DONE);

    if (!rb) {
        dprintf("Failed to create %s buttons\n", name);
    }

    return rb;
}

static void
PopulateList(struct List* list, const struct OptionName names[])
{
    const char* name;
    int i = 0;

    while ((name = names[i++].displayName)) {
        AllocNode(list, name);
    }
}

static Object*
CreateDriverButtons()
{
    driverVar.list = CreateList();

    if (!driverVar.list) {
        return NULL;
    }

    PopulateList(driverVar.list, driverVar.names);
    driverVar.object =  CreateRadioButtons(GID_DriverList, &driverVar, "driver",
        "Select driver implementation:\n"
        "- compositing doesn't support some blend modes\n"
        "- opengl (MiniGL) doesn't support render targets and some blend modes\n"
        "- opengles2 supports most features\n"
        "- software supports most features but is not accelerated");

    return driverVar.object;
}

static Object*
CreateVsyncButtons()
{
    vsyncVar.list = CreateList();

    if (!vsyncVar.list) {
        return NULL;
    }

    PopulateList(vsyncVar.list, vsyncVar.names);
    vsyncVar.object = CreateRadioButtons(GID_VsyncList, &vsyncVar, "vsync",
        "Synchronize display update to monitor refresh rate");

    return vsyncVar.object;
}

static Object*
CreateBatchingButtons()
{
    batchingVar.list = CreateList();

    if (!batchingVar.list) {
        return NULL;
    }

    PopulateList(batchingVar.list, batchingVar.names);
    batchingVar.object = CreateRadioButtons(GID_BatchingList, &batchingVar, "batching",
        "Batching may improve drawing speed if application does many operations per frame "
        "and SDL2 is able to combine those");

    return batchingVar.object;
}

static Object*
CreateScaleQualityButtons()
{
    scaleQualityVar.list = CreateList();

    if (!scaleQualityVar.list) {
        return NULL;
    }

    PopulateList(scaleQualityVar.list, scaleQualityVar.names);
    scaleQualityVar.object = CreateRadioButtons(GID_ScaleQualityList, &scaleQualityVar,
        "scale quality", "Nearest pixel sampling or linear filtering");

    return scaleQualityVar.object;
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

#if 0
// When variable is stored in "default" (non-existing) state, it would be
// deleted from ENV. But if it's still in ENVARC, it will be reload on GetVar()
// so it would probably be just confusing?
static Object*
CreateUseButton()
{
    return CreateButton(GID_UseButton, "_Use", "Store settings to ENV:");
}
#endif

static Object*
CreateSaveButton()
{
    return CreateButton(GID_SaveButton, "_Save", "Store settings to ENVARC:");
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
CreateLayout()
{
    dprintf("\n");

    Object* layout = IIntuition->NewObject(LayoutClass, NULL,
        LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
        LAYOUT_AddChild, IIntuition->NewObject(LayoutClass, NULL,
            LAYOUT_Orientation, LAYOUT_ORIENT_HORIZ,
            LAYOUT_BevelStyle, BVS_GROUP,
            LAYOUT_Label, "2D Renderer Options",
            LAYOUT_AddChild, IIntuition->NewObject(LayoutClass, NULL,
                LAYOUT_BevelStyle, BVS_GROUP,
                LAYOUT_Label, "Driver",
                LAYOUT_Orientation, LAYOUT_ORIENT_HORIZ,
                LAYOUT_AddChild, CreateDriverButtons(),
                TAG_DONE),
            LAYOUT_AddChild, IIntuition->NewObject(LayoutClass, NULL,
                LAYOUT_BevelStyle, BVS_GROUP,
                LAYOUT_Label, "Vertical Sync",
                LAYOUT_Orientation, LAYOUT_ORIENT_HORIZ,
                LAYOUT_AddChild, CreateVsyncButtons(),
                TAG_DONE),
            LAYOUT_AddChild, IIntuition->NewObject(LayoutClass, NULL,
                LAYOUT_BevelStyle, BVS_GROUP,
                LAYOUT_Label, "Batching Mode",
                LAYOUT_Orientation, LAYOUT_ORIENT_HORIZ,
                LAYOUT_AddChild, CreateBatchingButtons(),
                TAG_DONE),
            LAYOUT_AddChild, IIntuition->NewObject(LayoutClass, NULL,
                LAYOUT_BevelStyle, BVS_GROUP,
                LAYOUT_Label, "Scale Quality",
                LAYOUT_Orientation, LAYOUT_ORIENT_HORIZ,
                LAYOUT_AddChild, CreateScaleQualityButtons(),
                TAG_DONE),
            TAG_DONE), // horizontal layout
        LAYOUT_AddChild, IIntuition->NewObject(LayoutClass, NULL,
            LAYOUT_Orientation, LAYOUT_ORIENT_HORIZ,
            LAYOUT_BevelStyle, BVS_GROUP,
            LAYOUT_Label, "Settings",
            //LAYOUT_AddChild, CreateUseButton(),
            LAYOUT_AddChild, CreateSaveButton(),
            LAYOUT_AddChild, CreateResetButton(),
            LAYOUT_AddChild, CreateCancelButton(),
            TAG_DONE), // horizontal layout
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
                MA_Label, "Iconify",
                MA_ID, MID_Iconify,
                TAG_DONE),
            MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
                MA_Type, T_ITEM,
                MA_Label, "About",
                MA_ID, MID_About,
                TAG_DONE),
            MA_AddChild, IIntuition->NewObject(NULL, "menuclass",
                MA_Type, T_ITEM,
                MA_Label, "Quit",
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

static uint32
GetSelection(Object* object)
{
    uint32 selected = 0;

    const ULONG result = IIntuition->GetAttrs(object, RADIOBUTTON_Selected, &selected, TAG_DONE);

    if (!result) {
        dprintf("Failed to get radiobutton selection\n");
    }

    return selected;
}

static void
ResetSelection(struct Variable* var)
{
    var->index = 0;
    IIntuition->RefreshSetGadgetAttrs((struct Gadget *)var->object, window, NULL, RADIOBUTTON_Selected, 0, TAG_DONE);
}

static BOOL
HandleGadgets(enum EGadgetID gid)
{
    BOOL running = TRUE;

    dprintf("gid %d\n", gid);

    switch (gid) {
        case GID_DriverList:
            driverVar.index = GetSelection(driverVar.object);
            break;
        case GID_VsyncList:
            vsyncVar.index = GetSelection(vsyncVar.object);
            break;
        case GID_BatchingList:
            batchingVar.index = GetSelection(batchingVar.object);
            break;
        case GID_ScaleQualityList:
            scaleQualityVar.index = GetSelection(scaleQualityVar.object);
            break;
        case GID_SaveButton:
            SaveVariables();
            break;
        case GID_UseButton:
            SetVariables();
            break;
        case GID_ResetButton:
            ResetSelection(&driverVar);
            ResetSelection(&vsyncVar);
            ResetSelection(&batchingVar);
            ResetSelection(&scaleQualityVar);
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

        PurgeList(driverVar.list);
        PurgeList(vsyncVar.list);
        PurgeList(batchingVar.list);
        PurgeList(scaleQualityVar.list);
    }

    CloseClasses();

    return 0;
}

