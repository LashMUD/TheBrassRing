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
        "short" : "a gate leading south in a small wicker fence",
        "long" : "\nThis small wooden gate leads south to a dead end road.",
        "lockable" : 1 ]) );

    SetSide("north", ([ "id" : ({"gate leading north", "gate", "north gate"}),
        "short" : "a gate leading north in a small wicker fence",
        "long" : "\nThis small wooden gate leads north into the front yard of "
             "a small cottage.",
        "lockable" : 1 ]) );

    SetClosed(0);
    SetLocked(0);
    SetKeys("north", ({ "key_susks" }));
    SetKeys("south", ({ "key_susks" }));
}

void init(){
    ::init();
}
