/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_ROOM;

int ReadSign();

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Living Room%^RESET%^");
    SetLong(" The living room.");
    SetItems( ([ 
        "north" : "main room.",
        ] ));
    SetInventory( ([
        ]) );
    SetExits( ([
         "north" : "/domains/etnar/wyr/wyr/room/rm_197",
         ] ));
}

void init(){
   ::init();
}
