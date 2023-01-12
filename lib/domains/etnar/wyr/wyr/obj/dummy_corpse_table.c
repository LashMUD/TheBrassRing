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
    SetShort("a big wooden table in the shape of a coffin");
    SetLong("This is the corpse table where Pierce Pascal lays out the victims of his guards.");
    SetInvis(1);
    SetMaxCarry(10000);
    SetPreventGet("The table does not budge.");
}
void init(){
    ::init();
}
