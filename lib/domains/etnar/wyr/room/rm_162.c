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
    SetShort("%^BOLD%^The East Jail Cell%^RESET%^");
    SetLong("   A small cell. A wooden plank juts out of the wall and is "
        "supposed to function as a bed.");
    SetItems( ([ 
                "west" : "",
        ] ));
    SetExits( ([
                "west" : "/domains/etnar/wyr/room/rm_160",
        ] ));
    SetDoor("west", "/domains/etnar/wyr/doors/160_162");
}

void init(){
   ::init();
}
