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
    SetShort("%^BOLD%^Pierce Pascal's House%^RESET%^");
    SetLong("rm_220");
    SetItems( ([ 
      ] ));
SetExits(([
    "west" : "/domains/etnar/wyr/wyr/room/rm_218",
  ]));
SetDoor("west", "/domains/etnar/wyr/wyr/doors/218_220");
}

void init(){
    ::init();
}
