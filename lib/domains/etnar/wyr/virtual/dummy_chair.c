#include <lib.h>
inherit LIB_BASE_DUMMY;
inherit LIB_SIT;
inherit LIB_SURFACE;

static void create() {
    base_dummy::create();
    surface::create();
    SetKeyName("chair");
    SetId("chair");
    SetAdjectives("wooden");
    SetShort("a plain wooden chair");
    SetLong("A simple wooden chair, yet sturdily crafted. "
            "It appears to be designed for sitting on.");
    SetMaxSitters(1);
    SetMaxCarry(500);
    SetInvis(1);
    SetPreventGet("The chair does not budge.");
}
void init(){
    ::init();
}
