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
    SetShort("%^BOLD%^The Back Room of the Cyclops Inn%^RESET%^");
    SetLong("   There is a doorway to the west and a sign hanging on the wall "
        "in front of you.");
    SetItems( ([ 
        "south" : "The common room.",
        "west" : "",
        "sign" : "\nProprietors room - KEEP OUT\n",
        ] ));
    SetRead( ([
            "sign" : (:ReadSign:),
            ]) );      
    SetExits( ([
        "south" : "/domains/etnar/wyr/room/rm_131",
        "west" : "/domains/etnar/wyr/room/rm_133", //needs a door
        ] ));
}

mixed ReadSign(){
    return (mixed)this_player()->eventPage("/domains/etnar/wyr/text/proprietorsign.txt");
}

void init(){
   ::init();
}
