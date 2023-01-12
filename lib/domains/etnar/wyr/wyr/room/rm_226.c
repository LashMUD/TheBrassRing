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
    SetShort("rm_226");
    SetLong("rm_226");
    SetItems( ([ 
      ] ));
SetExits(([
    "east" : "/domains/etnar/wyr/wyr/room/rm_225",
    "west" : "/domains/etnar/wyr/wyr/room/rm_121",
  ]));

}

void init(){
    ::init();
}
