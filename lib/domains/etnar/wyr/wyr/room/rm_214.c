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
    SetShort("rm_214.c");
    SetLong("   rm_214"
    );
    SetItems( ([ 
      ] ));
SetExits( ([
    "north" : "/domains/etnar/wyr/wyr/room/rm_213",
    "southwest" : "/domains/etnar/wyr/wyr/room/rm_215",
    "southeast" : "/domains/etnar/wyr/wyr/room/rm_216.c",
  ]) );

}

void init(){
    ::init();
}
