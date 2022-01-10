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

/*
TODO:
- load, save, reset variables
*/

#define NAME "SDL2 Prefs"
#define VERSION "1.0"
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
    GID_SaveButton,
    GID_UseButton,
    GID_ResetButton,
};

enum EMenuID
{
    MID_Iconify = 1,
    MID_About,
    MID_Quit
};

static struct List* driverList;
static struct List* vsyncList;
static struct List* batchingList;

static struct Window* window;

struct Variable
{
    int index;
    const char* const name;
    char value[MAX_VARIABLE_NAME_LEN];
};

static struct Variable driverVar = { 0, "SDL_RENDER_DRIVER", "" };
static struct Variable vsyncVar = { 0, "SDL_RENDER_VSYNC", "" };
static struct Variable batchingVar = { 0, "SDL_RENDER_BATCHING", "" };

struct OptionName
{
    const char* const displayName;
    const char* const envName;
};

static const struct OptionName driverNames[] =
{
    { "default", NULL },
    { "compositing (default)", "compositing" },
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
SetVariable(const char* const name, const char* const value)
{
    const int32 success = IDOS->SetVar(name, value, -1, LV_VAR | GVF_GLOBAL_ONLY);

    dprintf("name '%s', value '%s', success %ld\n", name, value, success);
}

static void
SaveVariable(const char* const name, const char* const value)
{
    const int32 success = IDOS->SetVar(name, value, -1, LV_VAR | GVF_GLOBAL_ONLY | GVF_SAVE_VAR);

    dprintf("name '%s', value '%s', success %ld\n", name, value, success);
}

static void
DeleteVariable(const char* const name)
{
    const int32 success = IDOS->DeleteVar(name, LV_VAR | GVF_GLOBAL_ONLY | GVF_SAVE_VAR);
    const int32 success2 = 0;//IDOS->DeleteVar(name, LV_VAR | GVF_SAVE_VAR);

    dprintf("name '%s', success %d, success2 %d\n", name, success, success2);
}

static void
LoadVariable(struct Variable* var, const struct OptionName names[])
{
    const char* const value = GetVariable(var->name);

    snprintf(var->value, sizeof(var->value), "%s", value);
    var->index = 0;

    if (strlen(var->value) > 0) {
        const char* cmp;
        int i = 1;
        while ((cmp = names[i].envName)) {
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
    LoadVariable(&driverVar, driverNames);
    LoadVariable(&vsyncVar, vsyncNames);
    LoadVariable(&batchingVar, batchingNames);
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
CreateRadioButtons(enum EGadgetID gid, struct List* list, const char* const name, const char* const hint, int selected)
{
    dprintf("gid %d, list %p, name '%s', hint '%s'\n", gid, list, name, hint);

    Object* rb = IIntuition->NewObject(RadioButtonClass, NULL,
        GA_ID, gid,
        GA_RelVerify, TRUE,
        GA_HintInfo, hint,
        RADIOBUTTON_Labels, list,
        RADIOBUTTON_Spacing, 4,
        RADIOBUTTON_Selected, selected,
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
    driverList = CreateList();

    if (!driverList) {
        return NULL;
    }

    PopulateList(driverList, driverNames);
    return CreateRadioButtons(GID_DriverList, driverList, "driver",
        "Select driver implementation. Available features may vary",
        driverVar.index);
}

static Object*
CreateVsyncButtons()
{
    vsyncList = CreateList();

    if (!vsyncList) {
        return NULL;
    }

    PopulateList(vsyncList, vsyncNames);
    return CreateRadioButtons(GID_VsyncList, vsyncList, "vsync",
        "Synchronize display update to monitor refresh rate", vsyncVar.index);
}

static Object*
CreateBatchingButtons()
{
    batchingList = CreateList();

    if (!batchingList) {
        return NULL;
    }

    PopulateList(batchingList, batchingNames);
    return CreateRadioButtons(GID_BatchingList, batchingList, "batching",
        "Batching may improve drawing speed if application does many operations per frame "
        "and SDL2 is able to combine those", batchingVar.index);
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
CreateUseButton()
{
    return CreateButton(GID_UseButton, "_Use", "Store settings to ENV:");
}

static Object*
CreateSaveButton()
{
    return CreateButton(GID_SaveButton, "_Save", "Store settings to ENVARC:");
}

static Object*
CreateResetButton()
{
    return CreateButton(GID_ResetButton, "_Reset", "Reset GUI to defaults");
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
            TAG_DONE), // horizontal layout
        LAYOUT_AddChild, IIntuition->NewObject(LayoutClass, NULL,
            LAYOUT_Orientation, LAYOUT_ORIENT_HORIZ,
            LAYOUT_BevelStyle, BVS_GROUP,
            LAYOUT_Label, "Settings",
            LAYOUT_AddChild, CreateUseButton(),
            LAYOUT_AddChild, CreateSaveButton(),
            LAYOUT_AddChild, CreateResetButton(),
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

static void
HandleGadgets(enum EGadgetID gid)
{
    dprintf("gid %d\n", gid);

    switch (gid) {
        case GID_DriverList:
            break;
        case GID_VsyncList:
            break;
        case GID_BatchingList:
            break;
        case GID_SaveButton:
            break;
        case GID_UseButton:
            break;
        case GID_ResetButton:
            break;
        default:
            dprintf("Unhandled gadget %d\n", gid);
            break;
    }
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
                HandleGadgets(result & WMHI_GADGETMASK);
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

    //SetVariable("SDL_RENDER_DRIVER", "abcdef");
    //SaveVariable("SDL_RENDER_SAVE", "save");

    //GetVariable("SDL_RENDER_DRIVER");
    //GetVariable("SDL_RENDER_save");
    //GetVariable("SDL_RENDER_VSYNC");
    //GetVariable("SDL_RENDER_BATCHING");

    //DeleteVariable("SDL_RENDER_DRIVER");
    //DeleteVariable("SDL_RENDER_VSYNC");
    //DeleteVariable("SDL_RENDER_BATCHING");
    //DeleteVariable("SDL_RENDER_SAVE");

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

        PurgeList(driverList);
        PurgeList(vsyncList);
        PurgeList(batchingList);
    }

    CloseClasses();

    return 0;
}

