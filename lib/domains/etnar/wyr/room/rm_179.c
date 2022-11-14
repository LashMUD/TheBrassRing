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
    SetShort("%^BOLD%^On Pyre Avenue.%^RESET%^");
    SetLong("   You are on Pyre Avenue. It continues east and west. To the south is "
            "Waltin Kelly's house."
        );
    SetItems( ([ 
        "east" : "Pyre Avenue continues.",
        "west" : "Pyre Avenue continues.",
        "south" : "Waltin Kelly's house.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "east" : "/domains/etnar/wyr/room/rm_178",
         "west" : "/domains/etnar/wyr/room/rm_180",
         "south" : "/domains/etnar/wyr/room/rm_189",
         ] ));
}

void init(){
   ::init();
}
