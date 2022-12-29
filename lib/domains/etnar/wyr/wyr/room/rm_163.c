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
    SetShort("%^BOLD%^The South Jail Cell%^RESET%^");
    SetLong("   A small cell. A wooden plank juts out of the wall and is "
        "supposed to function as a bed.");
    SetItems( ([ 
                "north" : "",
        ] ));
    SetExits( ([
                "north" : "/domains/etnar/wyr/wyr/room/rm_160",
        ] ));
    SetDoor("north", "/domains/etnar/wyr/wyr/doors/160_163");
}

void init(){
   ::init();
}
