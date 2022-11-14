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
    SetShort("%^BOLD%^The Northern fields.%^RESET%^");
    SetLong("   You are in the northern field of Joe Farmers farm.");
    SetItems( ([ 
        "north" : "the northern fields.",
        "south" : "the center fields",
        "southeast" : "You can track back the end of Farmer Lane through the fields.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "south" : "/domains/etnar/wyr/room/rm_194",
         "southeast" : "/domains/etnar/wyr/room/rm_185",
         ] ));
}

void init(){
   ::init();
}
