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
        "north" : "The Morganheifer Estate",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "north" : "/domains/etnar/wyr/room/rm_207",
         "east" : "/domains/etnar/wyr/room/rm_203",
         "west" : "/domains/etnar/wyr/room/rm_205",
         
         ] ));
}

void init(){
   ::init();
}
