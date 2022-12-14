/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_ROOM;

int ReadPlacard();

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Blacksmith's Shop%^RESET%^");
    SetLong("   Many trophies ranging from huge Orcish heads to dragon "
        "scales, as well as thick books of knowledge, line the walls of this "
        "room. A blasting heat comes from an entranceway to the east and the "
        "sound of metal striking metal emanate from within. A table forms a "
        "wall between you and the racks of equipment and weapons on display "
        "against the back wall. A placard you can read is placed on the table."
    );
    SetItems( ([ 
        ({"placard", "sign"}) : "A small wooden placard you can read.",
        ({"entrance", "entranceway"}) : " A large muscular figure is just "
            "inside hidden by the shadows.",
    ]) );
    SetRead( ([
            "placard" : (:ReadPlacard:),
    ]) ); 
    SetExits( ([
        "west" : "/domains/etnar/wyr/room/rm_118", //through a door
        "east" : "/domains/etnar/wyr/room/rm_156"
    ] ));
}

mixed ReadPlacard(){
    return (mixed)this_player()->eventPage("/domains/etnar/text/vendorsign.txt");
}

void init(){
   ::init();
}
