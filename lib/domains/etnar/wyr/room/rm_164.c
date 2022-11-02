// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_ROOM;

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The West Jail Cell%^RESET%^");
    SetLong("   A small cell. A wooden plank juts out of the wall and is "
        "supposed to function as a bed. Water is seeping through the ceiling "
        "on the west wall and drips lazily into a puddle on the floor.");
    SetItems( ([ 
                "east" : "",
        ] ));
    SetExits( ([
                "east" : "/domains/etnar/wyr/room/rm_160",
        ] ));
    SetDoor("east", "/domains/etnar/wyr/doors/160_164");
}

void init(){
   ::init();
}
