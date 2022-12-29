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
    SetShort("%^BOLD%^The Bedroom%^RESET%^");
    SetLong(" The bedroom.");
    SetItems( ([ 
        "south" : "main room",
        ] ));
    SetInventory( ([
    
    ]) );
    SetExits( ([
         "south" : "/domains/etnar/wyr/wyr/room/rm_197",
         ] ));
}

void init(){
   ::init();
}
