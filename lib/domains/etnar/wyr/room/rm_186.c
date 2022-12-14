/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_ROOM;

int ReadSign();

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^Joeseph Farmer's Pharm House.%^RESET%^");
    SetLong("   The main room of the house.");
    SetItems( ([ 
        "west" : "kitchen",
        "north" : "bedroom.",
        "south" : "children's room",
        ] ));
    SetInventory( ([
    ]) );
    SetRead( ([
            "sign" : (:ReadSign:),
    ]) ); 
    SetExits( ([
         "east" : "/domains/etnar/wyr/room/rm_185",
         "west" : "/domains/etnar/wyr/room/rm_194",
         ] ));
}

mixed ReadSign(){
    return (mixed)this_player()->eventPage("/domains/etnar/wyr/text/vendorsign.txt");
}

void init(){
   ::init();
}
