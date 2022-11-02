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
    SetLong("   You come to the end of the road. To the north is a small "
        "cottage. Westwards is an intersection with a lerge statue."
        );
    SetItems( ([ 
        "cottage" : "You see a small house. Not lavish in the least bit but "
            "well kept. A small wicker fence surrounds the home with a gate "
             "leading to the doorway. Small bushes and a couple of trees dot "
             "the yard. Rows of colorful flowers line front of the cottage.",
        "intersection" : " A busy four way intersection. A large statue "
            "dominates the view.",
        "statue": " A large figure of a man reading a scroll and leaning on "
            "the hilt of a huge sword.",
        "road" : "The road is well paved but worn. Large flagstone slabs pave the way.",
        ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_108",
        "west" : "/domains/etnar/wyr/room/rm_116",
        ] ));
    SetDoor("north", "/domains/etnar/wyr/doors/108_123");
}

void init(){
   ::init();
}
