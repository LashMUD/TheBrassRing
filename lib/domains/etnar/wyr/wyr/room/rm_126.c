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
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^A Doorway%^RESET%^");
    SetLong("   You are at the top of the stairway. Below is the ground floor "
        "of the village shop and to the east a door.");
    SetItems( ([ 
        "east" : "",
        "down" : "",
        ] ));
    SetExits( ([
        "east" : "/domains/etnar/wyr/wyr/room/rm_127",
        "down" : "/domains/etnar/wyr/wyr/room/rm_124",
        ] ));
}

void init(){
   ::init();
}
