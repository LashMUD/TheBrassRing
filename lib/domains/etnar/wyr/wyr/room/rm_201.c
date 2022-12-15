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
        "southwest" : "The lane continues.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "northeast" : "/domains/etnar/wyr/wyr/room/rm_200",
         "west" : "/domains/etnar/wyr/wyr/room/rm_202",
         ] ));
}

void init(){
   ::init();
}
