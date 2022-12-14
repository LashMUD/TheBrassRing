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

    SetSide("east", ([ "id" : ({"gate leading east", "gate", "east gate"}),
        "short" : "a jail cell gate leading into the jail cell room",
        "long" : "\nA barred metal cell door opening to the jail cell room.",
        "lockable" : 1 ]) );

    SetSide("west", ([ "id" : ({"gate leading west", "gate", "west gate"}),
        "short" : "a jail cell gate leading into the western jail cell",
        "long" : "\nA barred metal cell door opening to the west jail cell.",
        "lockable" : 1 ]) );

    SetClosed(1);
    SetLocked(0);
    SetKeys("east", ({ "key_wjk" }));
    SetKeys("west", ({ "key_wjk" }));
}

void init(){
    ::init();
}
