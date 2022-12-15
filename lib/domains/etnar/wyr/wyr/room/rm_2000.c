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
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^A Worn Path on the Plains%^RESET%^");
    SetLong("   A small path on the plains leads north and south. The "
        "gates and encircling wall of a small village lie to the north. "
        "Southwards the plains open up before you. A few farm houses are "
        "scattered about the surounding grasslands."
    );
    SetItems( ([ 
        "north" : "Two gate towers stand to the north. A wall seems to encircle a small \n"+
                    "village.",
        "south" : "The path continues southwards, meandering through the plains.",
        ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/wyr/room/rm_167",
        "south" : "/domains/etnar/wyr/wyr/room/rm_2001",
        ] ));
}

void init(){
   ::init();
}
