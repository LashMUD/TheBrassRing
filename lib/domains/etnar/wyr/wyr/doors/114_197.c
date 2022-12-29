/* Modified by Lash (Christopher Coker) for use with:
 *
 * The Dead Souls Mud Library
 * developed by Cratylus
 * http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_DOOR;

static void create() {
    door::create();

    SetSide("east", ([ "id" : ({"door leading east", "door", "east door"}),
        "short" : "the door from Sybil Klaknor's house to the Main Road through Wyr",
        "long" : "\nA plain door with a small window that leads out to the Main "
                 "Road through the Village of Wyr.",
        "lockable" : 1 ]) );

    SetSide("west", ([ "id" : ({"door leading west", "door", "west door"}),
        "short" : "the front door of Sybil Klaknor's house",
        "long" : "\nA plain door with a small window that opens into Sybil Klacknor's "
                 "house.Through the window you can see the interior of the main room "
                 "of the house.",
        "lockable" : 1 ]) );

    SetClosed(1);
    SetLocked(1);
    SetKeys("east", ({ "key_skh" }));
    SetKeys("west", ({ "key_skh" }));
}

void init(){
    ::init();
}
