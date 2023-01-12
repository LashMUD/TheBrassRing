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
    SetShort("rm_215.c");
    SetLong("   rm_215"
    );
    SetItems( ([ 
      ] ));
SetExits(([
    "northeast" : "/domains/etnar/wyr/wyr/room/rm_214",
  ]));

}

void init(){
    ::init();
}
