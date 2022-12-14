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
        "plains seem to be peaceful and every once in a while you see a bird "
        "winging its way on to the horizon. The path bends towards the north "
        "and west here.");
    SetItems( ([ 
        "north" : "The plains continue northwards and the small hills roll "
            "into the grasslands.",
        "west" : "You can see that the path cuts through a valley of two "
        "small rises on either side of you.",
        ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_2001",
        "west" : "/domains/etnar/wyr/room/rm_2003",
        "south" : "/domains/diku-alfa/room/60.zon/rm_6000",
        ] ));
}

void init(){
   ::init();
}
