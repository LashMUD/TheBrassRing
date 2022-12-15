/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_ROOM;

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^An Escape Route%^RESET%^");
    SetLong("   This small cramped passageway leads to the east and west.");
    SetItems( ([ 
        "west" : "The cramped passage continues.", 
        "east" : "It looks like the passageway opens up a bit.",
        ] ));
    SetExits( ([
        "west" : "/domains/etnar/wyr/wyr/room/rm_140",
        "east" : "/domains/etnar/wyr/wyr/room/rm_137",
        ] ));
}

void init(){
   ::init();
}
