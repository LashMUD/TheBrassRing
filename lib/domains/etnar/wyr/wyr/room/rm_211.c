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
    SetShort("rm_211.c");
    SetLong("   rm_211"
    );
    SetItems( ([ 
      ] ));
SetExits( ([
    "west" : "/domains/etnar/wyr/wyr/room/rm_210",
    "south" : "/domains/etnar/wyr/wyr/room/rm_212.c",
  ]) );

}

void init(){
    ::init();
}
