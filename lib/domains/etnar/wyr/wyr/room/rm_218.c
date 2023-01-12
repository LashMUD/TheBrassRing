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
    SetShort("rm_218");
    SetLong("rm_218");
    SetItems( ([ 
      ] ));
SetExits( ([
    "north" : "/domains/etnar/wyr/wyr/room/rm_217",
    "east" : "/domains/etnar/wyr/wyr/room/rm_220",
    "south" : "/domains/etnar/wyr/wyr/room/rm_219.c",
  ]) );
SetDoor("east", "/domains/etnar/wyr/wyr/doors/218_220");
}

void init(){
    ::init();
}
