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

    WindowBase = IIntuition->OpenClass("window.class", version, &WindowClass);
    if (!WindowBase) puts("Failed to open window.class");

    RequesterBase = IIntuition->OpenClass("requester.class", version, &RequesterClass);
    if (!RequesterBase) puts("Failed to open requester.class");

    ButtonBase = IIntuition->OpenClass("gadgets/button.gadget", version, &ButtonClass);
    if (!ButtonBase) puts("Failed to open button.gadget");

    LayoutBase = IIntuition->OpenClass("gadgets/layout.gadget", version, &LayoutClass);
    if (!LayoutBase) puts("Failed to open layout.gadget");

//    classes.SpaceBase = IIntuition->OpenClass("gadgets/space.gadget", version, &classes.SpaceClass);
//    if (!classes.SpaceBase) throw std::runtime_error("Failed to open space.gadget");

//    classes.CheckBoxBase = IIntuition->OpenClass("gadgets/checkbox.gadget", version, &classes.CheckBoxClass);
//    if (!classes.CheckBoxBase) throw std::runtime_error("Failed to open checkbox.gadget");

    RadioButtonBase = (struct Library *)IIntuition->OpenClass("gadgets/radiobutton.gadget", version, &RadioButtonClass);
    if (!RadioButtonBase) puts("Failed to open radiobutton.gadget");

    IRadioButton = (struct RadioButtonIFace *)IExec->GetInterface((struct Library *)RadioButtonBase, "main", 1, NULL);

    return WindowBase &&
           RequesterBase &&
           ButtonBase &&
           LayoutBase &&
           RadioButtonBase &&
           IRadioButton;
}

static void CloseClasses()
{
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
    struct List* list = (struct List *)IExec->AllocSysObjectTags(ASOT_LIST, TAG_DONE);

    if (!list) {
        puts("Failed to allocate list");
    }

    return list;
}

void AllocNode(struct List* list, const char* const name)
{
    struct Node* node = IRadioButton->AllocRadioButtonNode(0, RBNA_Label, name, TAG_DONE);

    if (!node) {
        puts("Failed to allocate list node");
        return;
    }

    IExec->AddTail(list, node);
}

static void PurgeList(struct List* list)
{
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
    Object* rb = IIntuition->NewObject(RadioButtonClass, NULL,
        GA_ID, gid,
        GA_RelVerify, TRUE,
        RADIOBUTTON_Labels, list,
        RADIOBUTTON_Spacing, 4,
        RADIOBUTTON_Selected, 0,
        TAG_DONE);

    if (!rb) {
        printf("Failed to create %s buttons", name);
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
        printf("Failed to create %s button", name);
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
        puts("Failed to create layout object");
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
        puts("Failed to create window object");
    }

    return window;
}

int main(int argc, char** argv)
{
    puts("main");

    if (OpenClasses()) {
        Object* windowObject = CreateWindow();
        if (windowObject) {
            struct Window* window = (struct Window *)IIntuition->IDoMethod(windowObject, WM_OPEN);

            if (window) {
                IDOS->Delay(5 * 50);
            } else {
                puts("Failed to open window");
            }

            IIntuition->DisposeObject(windowObject);
        }

        PurgeList(driverList);
        PurgeList(vsyncList);
        PurgeList(batchingList);
    }

    puts("close");

    CloseClasses();

    return 0;
}
