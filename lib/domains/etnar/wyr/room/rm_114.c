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
    SetLong("   To the east you see the modest sized Town Hall. A number of "
        "people are bustling to and fro through the door. Northward, the "
        "road continues and towards the northwest there appears to be "
        "stabling quarters for pack horses and such. The road takes a slight "
        "bend eastwards to the south."
        );
    SetItems( ([ 
        ({"town hall", "Town Hall", "town", "hall"}) : " A modest sized, busy building. "
            "A sign above the door reads:\n"
                    "\n"
                    "                               'INFORMATION'\n",
        ({"quarters","stabling","stabling quarters"}) : " Northwrds there is "
            "a small lane leads that leads off the road towards a small group "
            "of stables.",
        "road" : " Here, the road is improving. It is paved with well worn "
            "flagstones buried in the dirt",
               ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_117",
        "east" : "/domains/etnar/wyr/room/rm_165",
        "south" : "/domains/etnar/wyr/room/rm_109",
        ] ));
}

void init(){
   ::init();
}
