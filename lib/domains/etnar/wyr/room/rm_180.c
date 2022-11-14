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
    SetShort("%^BOLD%^The End of Pyre Avenue.%^RESET%^");
    SetLong("   You at the end of Pyre Avenue. Fostaine Pyre's lavish house is to the west "
            "and Albert Derby's house is to the south."
        );
    SetItems( ([ 
         "west" : "Fostaine Pyres lavish house.",
         "east" : "Pyre Avenue continues.",
         "south" : "Albert Dewey's house.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "east" : "/domains/etnar/wyr/room/rm_179",
         "west" : "/domains/etnar/wyr/room/rm_181",
         "south" : "/domains/etnar/wyr/room/rm_190",
         ] ));
}

void init(){
   ::init();
}
