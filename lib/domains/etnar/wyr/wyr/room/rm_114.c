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
    SetShort("%^BOLD%^Town Hall%^RESET%^");
    SetLong("   To the east you see the modest sized Town Hall. A number of "
        "people are bustling to and fro through the door. A small house "
        "belonging to Sybil Klaknor is to the west. Northward, the road "
        "continues and towards the northwest there appears to be stabling "
        "quarters for pack horses and such. The road takes a slight bend "
        "eastwards to the south."
        );
    SetItems( ([ 
        ({"town hall", "Town Hall", "town", "hall"}) : " A modest sized, busy building. "
            "A sign above the door reads:\n"
                    "\n"
                    "                               'INFORMATION'\n",
        ({"quarters","stabling","stabling quarters"}) : " Northwrds there is "
            "a small lane that leads off the road towards a small group "
            "of stables.",
        "road" : " Here, the road is improving. It is paved with well worn "
            "flagstones buried in the dirt",
               ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/wyr/room/rm_117",
        "east" : "/domains/etnar/wyr/wyr/room/rm_165",
        "south" : "/domains/etnar/wyr/wyr/room/rm_109",
        "west" : "/domains/etnar/wyr/wyr/room/rm_197"
        ] ));
    SetDoor("west", "/domains/etnar/wyr/wyr/doors/114_197");
}

void init(){
   ::init();
}
