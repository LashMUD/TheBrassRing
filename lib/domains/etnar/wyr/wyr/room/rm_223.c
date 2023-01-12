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
    SetShort("rm_223");
    SetLong("rm_223");
    SetItems( ([ 
      ] ));
SetExits( ([
    "east" : "/domains/etnar/wyr/wyr/room/rm_222",
    "west" : "/domains/etnar/wyr/wyr/room/rm_224.c",
  ]) );

}

void init(){
    ::init();
}
