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
    SetShort("rm_219");
    SetLong("rm_219");
    SetItems( ([ 
      ] ));
SetExits( ([
    "north" : "/domains/etnar/wyr/wyr/room/rm_218",
    "south" : "/domains/etnar/wyr/wyr/room/rm_221.c",
  ]) );

}

void init(){
    ::init();
}
