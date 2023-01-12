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

    SetSide("west", ([ "id" : ({"door leading west", "door", "west door"}),
        "short" : "a door leading out of Pierce Pascal's house",
        "long" : "\nAn ornate door leading to Whatever Avenue.",
        "lockable" : 1 ]) );

    SetSide("east", ([ "id" : ({"door leading east", "door", "east door"}),
        "short" : "a door leading in to Pierce Pascal's house",
        "long" : "\nAn ornate door leading to Pierce Pascal's house.",
        "lockable" : 0 ]) );

    SetClosed(1);
    SetLocked(0);
    SetKeys("west", ({ "key_pph" }));
    SetKeys("east", ({ "key_pph" }));
}

void init(){
    ::init();
}
