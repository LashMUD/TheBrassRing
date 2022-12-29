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
    SetLong("   You are on Farmer Lane. Off to the west is Joe Farmer's " 
            "Pharm House and south is a regular house.");
    SetItems( ([ 
        "west" : "The lane continues to Joe Farmer's Pharm house.",
        "south" : "Someone's house.",
        "east" : "Farmer Lane.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "west" : "/domains/etnar/wyr/wyr/room/rm_184",
         "east" : "/domains/etnar/wyr/wyr/room/rm_182",
         "south" : "/domains/etnar/wyr/wyr/room/rm_192"
         ] ));
}

void init(){
   ::init();
}
