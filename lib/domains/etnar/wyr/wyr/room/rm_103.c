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
    SetShort("%^BOLD%^A secret compartment!%^RESET%^");
    SetLong(" A secret compartment");
    SetExits( ([
                "north" : "/domains/etnar/wyr/wyr/room/rm_102", 
                 //set door through the tapestry
        ] ));

}
void init(){
   ::init();
}
