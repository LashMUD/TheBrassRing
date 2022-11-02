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
    SetShort("%^BOLD%^The Loot Room%^RESET%^");
    SetLong("   You are in a chamber at the end of a secret passage. The "
        "rough hewn room is criss-crossed with large wooden beams for "
        "support. Cobwebs hang in thick strands throughout.");
    SetItems( ([ 
        "south" : "A passageway.",
        ] ));
    SetExits( ([
        "south" : "/domains/etnar/wyr/room/rm_137",
        ] ));
}

void init(){
   ::init();
}
