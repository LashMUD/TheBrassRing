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

    SetSide("north", ([ "id" : ({"door leading north", "door", "north door"}),
        "short" : "the door from Waltin Kelly's house to Pyre Avenue",
        "long" : "\nA plain wooden door to the Pyre Avenue.",
        "lockable" : 1 ]) );

    SetSide("south", ([ "id" : ({"door leading south", "door", "south door"}),
        "short" : "the front door of Waltin Kelly's house",
        "long" : "\nA plain woodenthat opens into Waltin Kelly's house.",
        "lockable" : 1 ]) );

    SetClosed(1);
    SetLocked(1);
    SetKeys("north", ({ "key_wkh" }));
    SetKeys("south", ({ "key_wkh" }));
}

void init(){
    ::init();
}
