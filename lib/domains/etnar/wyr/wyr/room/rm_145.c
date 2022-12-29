/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_ROOM;

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^A Pen in the Stables%^RESET%^");
    SetLong("   You are in a holding pen for horses in the stables. Some hay "
        "and straw are scattered on the floor. Other than that the stables "
        "are well maintained by the stable-girl. The gate is to the east.");
    SetItems( ([ 
        "east" : "",
        "down" : "You see some hay and straw scattered on the floor.",
        ({"hay", "straw", "floor"}) : "You search through the hay and straw "
            "and find nothing special.",
        "gate" : "The gate is well kept and shines like new.",
        ] ));
    SetExits( ([
        "east" : "/domains/etnar/wyr/wyr/room/rm_146",
        ] ));
}

void init(){
   ::init();
}
