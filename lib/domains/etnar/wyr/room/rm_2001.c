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
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^A Worn Path on the Plains%^RESET%^");
    SetLong("   You wander along a dusty path through the grasslands. The "
        "plains seem to be peaceful and every once in awhile you see a bird "
        "winging its way on to the horizon.");
    SetItems( ([ 
        "north" : "You can see cultivated fields and a few farmhouses dotting "
            "the horizon. Looks like you are approaching civilization.",
        "south" : "The plains continue southwards. A few small hills are "
            "beginning to rise.",
        ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_2000",
        "south" : "/domains/etnar/wyr/room/rm_2002",
        ] ));
}

void init(){
   ::init();
}
