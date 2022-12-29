/*
 * Modified by Lash (Christopher Coker) for use with:
 *
 * The Dead Souls Mud Library
 * developed by Cratylus
 * http://www.dead-souls.net
 */

#include <lib.h>
inherit LIB_BASE_DUMMY;
inherit LIB_SURFACE;

static void create() {
    base_dummy::create();
    surface::create();
    SetKeyName("table");
    SetId("table");
    SetAdjectives("wooden");
    SetShort("a plain wooden table");
    SetLong("This small wooden table is simple in its construction.");
    SetInvis(1);
    SetMaxCarry(500);
    SetPreventGet("The table does not budge.");
}
void init(){
    ::init();
}
