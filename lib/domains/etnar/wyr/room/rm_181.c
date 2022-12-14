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
    SetShort("%^BOLD%^Fostaine Pyre's Lavish House%^RESET%^");
    SetLong("   The main room of Fostaine Pyre's house.");
    SetItems( ([ 
        "west" : "kitchen",
        "north" : "bedroom.",
        "south" : "living room",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "north" : "/domains/etnar/wyr/room/rm_179",
         "east" : "/domains/etnar/wyr/room/rm_180",
         ] ));
}

void init(){
   ::init();
}
