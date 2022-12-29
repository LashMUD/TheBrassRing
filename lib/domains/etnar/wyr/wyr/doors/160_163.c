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

    SetSide("north", ([ "id" : ({"gate leading north", "gate", "north gate"}),
        "short" : "a jail cell gate leading into the jail cell room",
        "long" : "\nA barred metal cell door opening to the jail cell room.",
        "lockable" : 1 ]) );

    SetSide("south", ([ "id" : ({"gate leading south", "gate", "south gate"}),
        "short" : "a jail cell gate leading into the southern jail cell",
        "long" : "\nA barred metal cell door opening to the south jail cell.",
        "lockable" : 1 ]) );

    SetClosed(1);
    SetLocked(0);
    SetKeys("north", ({ "key_wjk" }));
    SetKeys("south", ({ "key_wjk" }));
}

void init(){
    ::init();
}
