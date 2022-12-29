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
    SetShort("%^BOLD%^An Old Warehouse%^RESET%^");
    SetLong("   This warehouse has been converted to the barracks for the "
             "Orgonian guards and workers who are cuurently building the new "
             "wall around the village."
    );
    SetItems( ([ 
        "north" : "Inside the warehouse.",
        "south" : "Westbend Lane.",
    ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "south" : "/domains/etnar/wyr/wyr/room/rm_206",
         ] ));
}

void init(){
   ::init();
}
