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
    SetShort("%^BOLD%^The Sorthern fields.%^RESET%^");
    SetLong("   You are in the southern field of Joe Farmers farm.");
    SetItems( ([ 
        "north" : "the northern fields.",
        "south" : "the center fields",
        "northeast" : "You can track back the end of Farmer Lane through the fields.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "north" : "/domains/etnar/wyr/room/rm_194",
         "northeast" : "/domains/etnar/wyr/room/rm_185",
         ] ));
}

void init(){
   ::init();
}
