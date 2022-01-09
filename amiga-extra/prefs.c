#define DEBUG
#include "../src/main/amigaos4/SDL_os4debug.h"

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/radiobutton.h>

#include <intuition/classes.h>

#include <classes/window.h>

//#include <gadgets/space.h>
#include <gadgets/layout.h>
#include <gadgets/button.h>
#include <gadgets/radiobutton.h>

#include <stdio.h>

/*
TODO:
- event handling
- menu
- iconification
- load, save, reset variables
*/

#define NAME "SDL2 Prefs"
#define VERSION "1.0"

static const char* const version = NAME;
static const char* const fileVersion __attribute__((used)) = "$VER: " NAME " " VERSION " (" __AMIGADATE__ ")";
static const char* const name = NAME;

static struct ClassLibrary* WindowBase;
static struct ClassLibrary* RequesterBase;
static struct ClassLibrary* ButtonBase;
static struct ClassLibrary* LayoutBase;
//ClassLibrary* SpaceBase;
//ClassLibrary* CheckBoxBase;
//struct ClassLibrary* RadioButtonBase;

struct RadioButtonIFace* IRadioButton; 

static Class* WindowClass;
static Class* RequesterClass;
static Class* ButtonClass;
static Class* LayoutClass;
//Class* SpaceClass;
//Class* CheckBoxClass;
Class* RadioButtonClass;

enum EGadgetID
{
    GID_DriverList,
    GID_VsyncList,
    GID_BatchingList,
    GID_SaveButton,
    GID_UseButton,
    GID_ResetButton,
    GID_LAST
};

static struct List* driverList;
static struct List* vsyncList;
static struct List* batchingList;

static BOOL OpenClasses()
{
    const int version = 53;

    dprintf("%s\n", __func__);

    WindowBase = IIntuition->OpenClass("window.class", version, &WindowClass);
    if (!WindowBase) dprintf("Failed to open window.class\n");

    RequesterBase = IIntuition->OpenClass("requester.class", version, &RequesterClass);
    if (!RequesterBase) dprintf("Failed to open requester.class\n");

    ButtonBase = IIntuition->OpenClass("gadgets/button.gadget", version, &ButtonClass);
    if (!ButtonBase) dprintf("Failed to open button.gadget\n");

    LayoutBase = IIntuition->OpenClass("gadgets/layout.gadget", version, &LayoutClass);
    if (!LayoutBase) dprintf("Failed to open layout.gadget\n");

//    classes.SpaceBase = IIntuition->OpenClass("gadgets/space.gadget", version, &classes.SpaceClass);
//    if (!classes.SpaceBase) throw std::runtime_error("Failed to open space.gadget");

//    classes.CheckBoxBase = IIntuition->OpenClass("gadgets/checkbox.gadget", version, &classes.CheckBoxClass);
//    if (!classes.CheckBoxBase) throw std::runtime_error("Failed to open checkbox.gadget");

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

static void CloseClasses()
{
    dprintf("%s\n", __func__);

    if (IRadioButton) {
        IExec->DropInterface((struct Interface *)(IRadioButton));
    }

    IIntuition->CloseClass(WindowBase);
    IIntuition->CloseClass(RequesterBase);
    IIntuition->CloseClass(ButtonBase);
    IIntuition->CloseClass(LayoutBase);
    //IIntuition->CloseClass(classes.SpaceBase);
    //IIntuition->CloseClass(classes.CheckBoxBase);
    IIntuition->CloseClass((struct ClassLibrary *)RadioButtonBase);
}

struct List* CreateList()
{
    dprintf("%s\n", __func__);

    struct List* list = (struct List *)IExec->AllocSysObjectTags(ASOT_LIST, TAG_DONE);

    if (!list) {
        dprintf("Failed to allocate list\n");
    }

    return list;
}

void AllocNode(struct List* list, const char* const name)
{
    dprintf("%s '%s'\n", __func__, name);

    struct Node* node = IRadioButton->AllocRadioButtonNode(0, RBNA_Label, name, TAG_DONE);

    if (!node) {
        dprintf("Failed to allocate list node\n");
        return;
    }

    IExec->AddTail(list, node);
}

static void PurgeList(struct List* list)
{
    dprintf("%s\n", __func__);

    if (list) {
        struct Node* node;

        while ((node = IExec->RemTail(list))) {
            IRadioButton->FreeRadioButtonNode(node);
        }

        IExec->FreeSysObject(ASOT_LIST, list);
    }
}

static Object* CreateRadioButtons(enum EGadgetID gid, struct List* list, const char* const name)
{
    dprintf("%s '%s'\n", __func__, name);

    Object* rb = IIntuition->NewObject(RadioButtonClass, NULL,
        GA_ID, gid,
        GA_RelVerify, TRUE,
        RADIOBUTTON_Labels, list,
        RADIOBUTTON_Spacing, 4,
        RADIOBUTTON_Selected, 0,
        TAG_DONE);

    if (!rb) {
        dprintf("Failed to create %s buttons\n", name);
    }

    return rb;
}

static Object* CreateDriverButtons()
{
    driverList = CreateList();

    if (!driverList) {
        return NULL;
    }

    AllocNode(driverList, "default");
    AllocNode(driverList, "compositing");
    AllocNode(driverList, "opengl");
    AllocNode(driverList, "opengles2");
    AllocNode(driverList, "software");

    return CreateRadioButtons(GID_DriverList, driverList, "driver");
}

static Object* CreateVsyncButtons()
{
    vsyncList = CreateList();

    if (!vsyncList) {
        return NULL;
    }

    AllocNode(vsyncList, "default");
    AllocNode(vsyncList, "enabled");
    AllocNode(vsyncList, "disabled");

    return CreateRadioButtons(GID_VsyncList, vsyncList, "vsync");
}

static Object* CreateBatchingButtons()
{
    batchingList = CreateList();

    if (!batchingList) {
        return NULL;
    }

    AllocNode(batchingList, "default");
    AllocNode(batchingList, "enabled");
    AllocNode(batchingList, "disabled");

    return CreateRadioButtons(GID_BatchingList, batchingList, "batching");
}

static Object* CreateButton(enum EGadgetID gid, const char* const name)
{
    Object* b = IIntuition->NewObject(ButtonClass, NULL,
        GA_Text, name,
        GA_ID, gid,
        GA_RelVerify, TRUE,
        TAG_DONE);

    if (!b) {
        dprintf("Failed to create '%s' button\n", name);
    }

    return b;
}

static Object* CreateUseButton()
{
    return CreateButton(GID_UseButton, "Use");
}

static Object* CreateSaveButton()
{
    return CreateButton(GID_SaveButton, "Save");
}

static Object* CreateResetButton()
{
    return CreateButton(GID_ResetButton, "Reset");
}

static Object* CreateLayout()
{
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

static Object* CreateWindow()
{
    Object* window = IIntuition->NewObject(WindowClass, NULL,
        WA_Activate, TRUE,
        WA_Title, version,
        WA_ScreenTitle, version,
        //WA_PubScreen, screen,
        //WA_BackFill, LAYERS_NOBACKFILL,
        //WA_InnerWidth, 200,
        //WA_InnerHeight, 200,
        //WA_Flags, WFLG_REPORTMOUSE,
        WA_IDCMP, IDCMP_CLOSEWINDOW | IDCMP_RAWKEY | IDCMP_MENUPICK,
        WA_CloseGadget, TRUE,
        WA_DragBar, TRUE,
        WA_DepthGadget, TRUE,
        WA_SizeGadget, TRUE,
        //WA_MenuStrip, menuObject,
        WINDOW_IconifyGadget, TRUE,
        //WINDOW_Icon, MyGetDiskObject(),
        WINDOW_IconTitle, name,
        //WINDOW_AppPort, appPort, // Iconification needs it
        //WINDOW_IDCMPHook, &idcmpHook,
        //WINDOW_IDCMPHookBits, IDCMP_MOUSEBUTTONS | IDCMP_MOUSEMOVE,
        WINDOW_Position, WPOS_CENTERSCREEN,
        WINDOW_Layout, CreateLayout(),
        TAG_DONE);

    if (!window) {
        dprintf("Failed to create window object\n");
    }

    return window;
}

int main(int argc, char** argv)
{
    if (OpenClasses()) {
        Object* windowObject = CreateWindow();
        if (windowObject) {
            struct Window* window = (struct Window *)IIntuition->IDoMethod(windowObject, WM_OPEN);

            if (window) {
                IDOS->Delay(5 * 50);
            } else {
                dprintf("Failed to open window\n");
            }

            IIntuition->DisposeObject(windowObject);
        }

        PurgeList(driverList);
        PurgeList(vsyncList);
        PurgeList(batchingList);
    }

    CloseClasses();

    return 0;
}

