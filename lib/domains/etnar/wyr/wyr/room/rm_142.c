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
    SetShort("%^BOLD%^In Front of a Pen%^RESET%^");
    SetLong("   You stand in front of a holding pen for horses. The area is "
        "well kept as the resident stable-girl is very efficient at her job.");
    SetItems( ([ 
        "south" : "",
        "east" : "",
        ] ));
    SetExits( ([
        "south" : "/domains/etnar/wyr/wyr/room/rm_143",
        "east" : "/domains/etnar/wyr/wyr/room/rm_141",
        ] ));
}

void init(){
   ::init();
}
