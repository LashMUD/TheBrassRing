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
    SetShort("%^BOLD%^In Front of a Pen%^RESET%^");
    SetLong("   You stand in front of a holding pen for horses. The area is "
        "well kept as the resident stable-girl is very efficient at her "
        "job.");
    SetItems( ([ 
        "north" : "",
        "south" : "",
        "west" : "",
        ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_146",
        "south" : "/domains/etnar/wyr/room/rm_149",
        "west" : "/domains/etnar/wyr/room/rm_148",
        ] ));
}

void init(){
   ::init();
}
