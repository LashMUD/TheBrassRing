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
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^Albert Derby's House%^RESET%^");
    SetLong("   The main room of Albert Derby's house.");
    SetItems( ([ 
        "west" : "kitchen",
        "north" : "bedroom.",
        "south" : "living room",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "north" : "/domains/etnar/wyr/room/rm_180",
         ] ));
}

void init(){
   ::init();
}
