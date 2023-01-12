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
    SetShort("rm_210.c");
    SetLong("   rm_210"
    );
    SetItems( ([ 
      ] ));
SetExits( ([
    "west" : "/domains/etnar/wyr/wyr/room/rm_209",
    "east" : "/domains/etnar/wyr/wyr/room/rm_211.c",
  ]) );

}

void init(){
    ::init();
}
