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
    SetShort("%^BOLD%^The Front Porch of the Morganheifer Estate%^RESET%^");
    SetLong("   The main room of the house.");
    SetItems( ([ 
        "north" : "The front door.",
        "south" : "Westbend Lane.",
    ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "south" : "/domains/etnar/wyr/wyr/room/rm_204",
         ] ));
}

void init(){
   ::init();
}
