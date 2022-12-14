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
    SetShort("%^BOLD%^Farmer Lane%^RESET%^");
    SetLong("   You are on Farmer Lane. A ways off to the west is Joe Farmer's " 
            "Pharm House. There are a couple of other houses to the southwest "
            "further west on the lane.");
    SetItems( ([ 
        "west" : "The lane continues.",
        "northeast" : "The end of Farmer's Way.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "west" : "/domains/etnar/wyr/room/rm_183",
         "northeast" : "/domains/etnar/wyr/room/rm_177",
         "south" : "/domains/etnar/wyr/room/rm_198",
         ] ));
}

void init(){
   ::init();
}
