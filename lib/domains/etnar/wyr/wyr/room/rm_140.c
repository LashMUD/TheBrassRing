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
    SetShort("%^BOLD%^An Escape Route%^RESET%^");
    SetLong("   You are in a small cramped passageway under some stables. The "
        "passageway is little more than a hole tunneled through the earth. "
        "You can see the outlines of a trapdoor above and the passage "
        "continues to the east.");
    SetItems( ([ 
        "east" : "The passage continues.",
        "up" : "You make out the outlines of a trapdoor in the ceiling. You "
            "hear heavy footsteps on wood and the whinnying of horses.",
        ] ));
    SetExits( ([
        "east" : "/domains/etnar/wyr/wyr/room/rm_139",
        "up" : "/domains/etnar/wyr/wyr/room/rm_141",
        ] ));
}

void init(){
   ::init();
}
