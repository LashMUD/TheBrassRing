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
    SetShort("%^BOLD%^The Northern Road%^RESET%^");
    SetLong("   The small village of Wyr lies to the south. There is a four "
        "way intersection with a large statue. Northwards, the road continues "
        "out into the wilderness"
        );
    SetItems( ([ 
        ({"small village","village","small","Wyr","wyr"}) : " To the southeast you see a modest sized building.",
        "road" : "The road is well paved but worn. Large flagstone slabs pave the way.",
        "statue": "A large figure of a man reading a scroll and "+
                    "leaning on the hilt of a huge sword.",
        ] ));
    SetExits( ([
        //"north" : "/domains/etnar/wyr/room/rm_xxx", out to the wilderness
        "south" : "/domains/etnar/wyr/room/rm_116",
        ] ));
}

void init(){
   ::init();
}
