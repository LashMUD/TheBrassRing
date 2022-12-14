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
    SetShort("%^BOLD%^A Small Chamber.%^RESET%^");
    SetLong("   You are in a small room. A lantern on the wall provides "
        "illumination and shows off how clean and tidy the room is.");
    SetItems( ([ 
        "up" : "A trapdoor in the ceiling.",
        ({"door", "trapdoor"}) : "You see the outline of a trapdoor in the "
            "wooden floorboards.",
        ({"lantern", "light"}) : "The lantern looks as if it is about to go out.",
        ] ));
    SetExits( ([
        "up" : "/domains/etnar/wyr/room/rm_124",
        ] ));
}

void init(){
   ::init();
}
