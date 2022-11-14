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
    SetShort("%^BOLD%^The end of Farmer's Way.%^RESET%^");
    SetLong("   You are at the end of Farmer's Way. Farmer Lane baranches off to"
            "the southest and Pyre Avenue bramches off to the northeast."
        );
    SetItems( ([ 
        "southwest" : "Farmer Lane.",
        "northwest" : "Pyre Avenue.",
        "east" : "Farmer's Way continues.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "southwest" : "/domains/etnar/wyr/room/rm_182",
         "northwest" : "/domains/etnar/wyr/room/rm_178",
         "east" : "/domains/etnar/wyr/room/rm_176",
         ] ));
}

void init(){
   ::init();
}
