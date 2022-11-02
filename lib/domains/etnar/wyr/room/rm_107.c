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
    SetLong("   Off the road to the east is the traders shop, a two storied "
        "small house. Its modest architecture make it appealing and "
        "comfortable looking. The surrounding yard is well tended. To the "
        "southwest is a small building that looks like a shrine of some sort, "
        "while to the north the road takes a bend."
        );
    SetItems( ([ 
        ({"house", "shop"}) : " A small wooden two storied building with a "
            "sign above the door. While the building looks weathered and run "
            "down, the surrounding yard looks to be well tended.",
        "yard" : " The grass is cut and is an illustrious green. Small bushes "
            "and colorful flowerbeds line the front of the house", 
        "road" : " The road is primitive consisting of a couple of tracks "
            "made by passing carts and travelers on foot or horse.",
        "sign" : "  The sign reads:\n"
                 "                'SUPPLIES'\n",
        ({"shrine", "building"}) : " A small square structure built out of "
             "stone blocks.",
        ] ));
    SetExits( ([
                "north" : "/domains/etnar/wyr/room/rm_109",
                "east" : "/domains/etnar/wyr/room/rm_124",
                "south" : "/domains/etnar/wyr/room/rm_106",
        ] ));
}

void init(){
   ::init();
}
