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
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^Farmer's Way%^RESET%^");
    SetLong("   You are on Farmer's Way. to the east is the main road that runs north"
            "and south through Wyr and Farmer's Way continues to the west."
        );
    SetItems( ([ 
        "east" : "Farmer's Way continues.",
        "west" : "The main road through the village of Wyr.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "east" : "/domains/etnar/wyr/wyr/room/rm_109",
         "west" : "/domains/etnar/wyr/wyr/room/rm_176",
         ] ));
}

void init(){
   ::init();
}
