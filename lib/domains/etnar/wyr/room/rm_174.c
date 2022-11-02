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
    SetShort("%^BOLD%^The Lounge%^RESET%^");
    SetLong("   The lounge is smaller and more comfortable than the common room "
               "but still spacious. There are a few tables and chairs around. "
               "In the back wall behind a stage, there is a small fireplace with " 
               "a sitting stool on it.");
    SetItems( ([ 
                "stage" : 
                    "The stage is a rough wooden platform about a foot above floor "
                    "level.",
                "fireplace" : 
                    "The fireplace is small enough to emit enough warmth for any "
                    "players on the stage.",
        ] ));
    SetInventory(([
        "/domains/etnar/wyr/obj/bard_stool" : 1,
        ]) );
    SetActionsMap( ([ 
                "%^RED%^The fire crackles merrily.%^RESET%^" : 5,
        ]) );
    SetExits( ([
        "northeast" : "/domains/etnar/wyr/room/rm_131",
        ] ));
}

void init(){
   ::init();
}
