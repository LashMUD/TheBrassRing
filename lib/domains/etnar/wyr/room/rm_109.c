// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_ROOM;

static void create() {

    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Road Through the Village of Wyr%^RESET%^");
    SetLong("   The road continues north and south. To the west lies the "
        "beginning of Farmer's Way. To the east there is a heavily guarded "
        "bank - a large stone building."
        );
    SetItems( ([ 
        ({"bank", "building"}) : "A large stone building with a big iron "
            "barred door. Usually the door is guarded. ",
        "road" : " The road is primitive consisting of a couple of tracks "+
            "made by passing carts and travelers on foot or horse.",
        ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_114",
        "east" : "/domains/etnar/wyr/room/rm_128",
        "south" : "/domains/etnar/wyr/room/rm_107",
        "west" : "/domains/etnar/wyr/room/rm_175",
        ] ));
}

void init(){
   ::init();
}
