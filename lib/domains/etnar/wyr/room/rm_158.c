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
    SetShort("The Pet Store");
    SetLong("   This is where all the pets are kept for the shop in Wyr.");
    SetItems( ([ 
               ] ));
    SetExits( ([
               ] ));
}

void init(){
   ::init();
}
