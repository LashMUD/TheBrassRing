// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_ROOM;

int ReadSign();

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^On Farmer Lane.%^RESET%^");
    SetLong("   You are on Farmer Lane. Off to the east the lane ends at Joseph Farmer's Pharm house."
            " There is a small house to the south. Farmer Lane continues east.");
    SetItems( ([ 
        "west" : "Joe Farmer's Pharm house.",
        "east" : "Farmer Lane.",
        "south" : "A small house", 
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "west" : "/domains/etnar/wyr/room/rm_185",
         "east" : "/domains/etnar/wyr/room/rm_183",
         "south" : "/domains/etnar/wyr/room/rm_191",
         ] ));
}

void init(){
   ::init();
}