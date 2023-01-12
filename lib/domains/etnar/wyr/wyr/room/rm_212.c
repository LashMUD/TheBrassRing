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
    SetShort("rm_212.c");
    SetLong("   rm_212"
    );
    SetItems( ([ 
      ] ));
SetExits( ([
    "north" : "/domains/etnar/wyr/wyr/room/rm_211",
    "south" : "/domains/etnar/wyr/wyr/room/rm_213.c",
  ]) );

}

void init(){
    ::init();
}
