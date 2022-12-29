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
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Bank Entrance%^RESET%^");
    SetLong("   You stand outside of the village bank, an impressive "
        "structure. The whole building is made entirely of stone. Heavy, iron "
        "gated, wooden doors provide security during non-business hours. "
        "Usually there are a couple of guards at the doors.");
    SetItems( ([ 
        "north" : "",
        "south" : "",
        ] ));
    SetExits( ([
        "east" : "/domains/etnar/wyr/wyr/room/rm_129",
        "west" : "/domains/etnar/wyr/wyr/room/rm_109",
        ] ));
}

void init(){
   ::init();
}
