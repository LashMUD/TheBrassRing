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
    SetLong("   To your west is the small Shrine that serves the community "
        "in Wyr. Further north, and off to the east of the road, stands a "
        "small two storied building. The road takes a bend further south."
        );
    SetItems( ([ 
        "shrine" : " The entrance to a small Shrine. The Shrine is built out "
            "of large stone blocks. Above the big oak doorway is a wood "
            "engraving depicting a black stallion against a lightning filled "
            "sky - the  symbol of Balcor, the wargod.",
        "building" : " An old dilpidated two-storied structure. There is a "
             "sign above the doorway. The surrounding landscape appears to be "
             "well tended.",
        "sign" : " It is too far away to make out the writing", 
        "road" : " The road is primitive consisting of a couple of tracks "
            "made by passing carts and travelers on foot or horse.",
        ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_107",
        "south" : "/domains/etnar/wyr/room/rm_118",
        "west" : "/domains/etnar/wyr/room/rm_105",
        ] ));
}

void init(){
   ::init();
}
