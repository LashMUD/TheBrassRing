// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_ROOM;

static void create() {

    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^At the Stables%^RESET%^");
    SetLong("   To the north lies the stables of the Cyclops Inn. Weary "
        "travelers rest their equally weary horses and other beasts here.");
    SetItems( ([ 
        "north" : "",
        "east" : "",
        ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_147",
        "east" : "/domains/etnar/wyr/room/rm_117",
        ] ));
}

void init(){
   ::init();
}
