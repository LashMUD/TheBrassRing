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
    SetLong("   To the west are some small buildings used for stabling "
        "horses. The famous Cyclops Inn of Wyr is visible aways off towards "
        "the northwest. Southwards, the road continues but "
        "deteriorates to no more than a dirt road with tracks rutted into it "
        "from the wheels of passing wagons. Off to the southeast is the "
        "modest Town Hall." 
        );
    SetItems( ([ 
        ({"buildings", "stables"}) : " A small lane leads off the main road to "
            "the stables holding the riding mounts for patronages visiting the "
            "famous Cyclops Inn of Wyr.",
        "statue": " A large figure of a man reading a scroll and leaning on "
            "the hilt of a huge sword.",
        ({"Cyclops Inn", "cyclops inn", "inn", "cyclops"}) : " A large two "
            "storied structure that appears to be falling into disrepair.",
        ({"Town Hall", "town hall", "town", "hall"}) : " Bearing the signs of "
            "new construction the hall is of modest size. People bustle to "
            "and fro from the entrance",
        "road"  : " The flagstones become broken and eventually fade out "
            "leaving nothing more than dirt tracks in the ground.",
        ] ));
    SetExits( ([
    "north" : "/domains/etnar/wyr/room/rm_195",
    "south" : "/domains/etnar/wyr/room/rm_114",
    "west" : "/domains/etnar/wyr/room/rm_149",
    ] ));
}

void init(){
   ::init();
}
