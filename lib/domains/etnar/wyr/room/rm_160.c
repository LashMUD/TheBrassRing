//Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_ROOM;

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Jail%^RESET%^");
    SetLong("   You enter a small square room that surrounded by a few jail "
        "cell cubicles. Sturdy metal gates bar the doors.");
    SetItems( ([ 
        "up" : "A stairway leading up to the guardhouse proper.",
        ] ));
    SetActionsMap( ([
        "A drop of water spalshes from within one of the cell blocks" : 20,
        ]) );
    SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_161",
        "east" : "/domains/etnar/wyr/room/rm_162",
        "south" : "/domains/etnar/wyr/room/rm_163",
        "west" : "/domains/etnar/wyr/room/rm_164",
        "up" : "/domains/etnar/wyr/room/rm_159",
        ] ));
    SetDoor("north", "/domains/etnar/wyr/doors/160_161");
    SetDoor("east", "/domains/etnar/wyr/doors/160_162");
    SetDoor("south", "/domains/etnar/wyr/doors/160_163");
    SetDoor("west", "/domains/etnar/wyr/doors/160_164");
}

void init(){
   ::init();
}
