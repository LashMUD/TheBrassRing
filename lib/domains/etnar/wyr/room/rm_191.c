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
    SetShort("%^BOLD%^Someone's House%^RESET%^");
    SetLong("   The main room of the house.");
    SetItems( ([ 
        "west" : "kitchen",
        "north" : "bedroom.",
        "south" : "living room",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "north" : "/domains/etnar/wyr/wyr/room/rm_184",
         ] ));
}

void init(){
   ::init();
}
