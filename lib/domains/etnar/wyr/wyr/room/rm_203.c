/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_ROOM;

int ReadSign();

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^Westbend Lane%^RESET%^");
    SetLong("   You are on Westbend Lane.");
    SetItems( ([ 
        "west" : "The lane continues.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "east" : "/domains/etnar/wyr/wyr/room/rm_202",
         "west" : "/domains/etnar/wyr/wyr/room/rm_204",
         ] ));
}

void init(){
   ::init();
}
