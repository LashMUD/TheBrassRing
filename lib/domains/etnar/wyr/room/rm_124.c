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
    SetShort("%^BOLD%^The Village Supply Shop.%^RESET%^");
    SetLong("   You are inside what appears to be a small shop. Before you "
        "is a long counter containing various supplies; packs, torches, and "
        "lanterns. A sign hangs on the wall behind the counter. You notice a "
        "set of stairs, to your left, leading up.");
    SetItems( ([ 
        "west" : "",
        "up" : "Upstairs. You can see that the wooden stairs lead up to a "
             "doorway.",
        "down" : "",
        "sign" : "A sign you can read.",
         ] ));
    /*SetInventory( ([
        "/domains/etnar/wyr/npc/dirk" : 1,
        ]) );*/
    SetRead( ([
            "sign" : (:ReadSign:),
    ]) ); 
    SetExits( ([
         "west" : "/domains/etnar/wyr/room/rm_107",
         "up" : "/domains/etnar/wyr/room/rm_126",
         "down" : "/domains/etnar/wyr/room/rm_125",
         ] ));
}

mixed ReadSign(){
    return (mixed)this_player()->eventPage("/domains/etnar/text/vendorsign.txt");
}

void init(){
   ::init();
}
