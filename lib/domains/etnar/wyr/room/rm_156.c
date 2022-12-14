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
    SetShort("%^BOLD%^The Blacksmiths Shop%^RESET%^");
    SetLong("   You enter an oversized shed with a dirt floor. In the center "
        "is a large forge surrounded by various smithying tools stored "
        "neatly in racks. Dark smoke billows up and out of a makeshift "
        "chimney. Along the back wall is a long shelf displaying some "
        "weaponry and armor."
    ); 
    SetItems( ([ 
    ]) );
    SetInventory( ([
        "/domains/etnar/wyr/npc/caltan/caltan_dowini" : 1,
    ]) );
    SetExits( ([
        "west" : "/domains/etnar/wyr/room/rm_170", //through a door
    ]) );
}

void init(){
   ::init();
}
