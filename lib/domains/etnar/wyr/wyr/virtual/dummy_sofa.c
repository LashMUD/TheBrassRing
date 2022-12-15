/*
 * Modified by Lash (Christopher Coker) for use with:
 *
 * The Dead Souls Mud Library
 * developed by Cratylus
 * http://www.dead-souls.net
 */

#include <lib.h>
inherit LIB_BASE_DUMMY;
inherit LIB_SIT;
inherit LIB_SURFACE;

static void create() {
    base_dummy::create();
    surface::create();
    SetKeyName("sofa");
    SetId("sofa");
    SetAdjectives("worn", "comfortable");
    SetShort("a worn but comfortable looking sofa");
    SetLong("A simple worn sofa. It has seen better days but is in decent condition. It has "
        "a plush green covering on it with floral designs.");
    SetMaxSitters(3);
    SetMaxCarry(500);
    SetInvis(1);
    SetPreventGet("The sofa does not budge.");
}
void init(){
    ::init();
}
