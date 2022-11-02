// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_ROOM;

int ReadScroll();

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Mystics Room%^RESET%^");
    SetLong("   This room is dark and lit only by candles. The flames cast an "
        "eerie light on the walls and the shadows dance in mysterious shapes. "
        "Incense permeates the room giving off an aura of awe. A scroll hangs "
        "on the wall.");
    SetItems( ([ 
        "south" : "A large curtain of black silk covered in ancient runes "
            "lends egress to a doorway.",
        "scroll" : "\nWelcome. Feel free to ask Susan for help in advancing in "
            "the magical arts.\n",
        ] ));
    SetInventory( ([
        "/domains/etnar/wyr/npc/susan_halof" : 1,
    ]) );
    SetRead( ([
            "scroll" : (:ReadScroll:),
        ]) );      
    SetExits( ([
        "south" : "/domains/etnar/wyr/room/rm_168",
        ] ));
}

mixed ReadScroll(){
    return (mixed)this_player()->eventPage("/domains/etnar/wyr/text/suescroll.txt");
}

void init(){
   ::init();
}
