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
    SetShort("%^BOLD%^The End of Farmer Lanes.%^RESET%^");
    SetLong("   You are at the end of Farmer Lane.");
    SetItems( ([ 
        "west" : "Joe Farmer's Pharm house.",
        "east" : "Farmer Lane.",
        "northwest" : "Behind the house there are the northern fields of Joseph Farmer.",
        "southwest" : "Behind the house there are the southern fields of Joseph Farmer.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "west" : "/domains/etnar/wyr/room/rm_186",
         "east" : "/domains/etnar/wyr/room/rm_184",
         "northwest" : "/domains/etnar/wyr/room/rm_188",
         "southwest" : "/domains/etnar/wyr/room/rm_187",
         ] ));
}

void init(){
   ::init();
}
