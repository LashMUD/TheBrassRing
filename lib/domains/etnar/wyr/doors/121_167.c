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

    SetSide("south", ([ "id" : ({"gate leading south", "gate", "south gate"}),
        "short" : "the Wyr south gate leading out of the village",
        "long" : "\nThe village gates are made of rusty but tough iron bars. "
            "A chain with a padlock hangs off the middle crossbar.",
        "lockable" : 1 ]) );

    SetSide("north", ([ "id" : ({"gate leading north", "gate", "north gate"}),
        "short" : "the Wyr south gate leading into the village",
        "long" : "\nThe village gates are made of rusty but tough iron bars. "
            "A chain with a padlock hangs off the middle crossbar.",
        "lockable" : 1 ]) );

    SetClosed(0);
    SetLocked(0);
    SetKeys("north", ({ "key_wgks" }));
    SetKeys("south", ({ "key_wgks" }));
}

void init(){
    ::init();
}
