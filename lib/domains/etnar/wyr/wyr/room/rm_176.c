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
    SetShort("%^BOLD%^On Farmer's Way%^RESET%^");
    SetLong("   You are on Farmer's Way. It continues to the east and west."
        );
    SetItems( ([ 
         "east" : "Farmer's Way continues.",
         "west" : "Farmer's Way continues.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "east" : "/domains/etnar/wyr/wyr/room/rm_175",
         "west" : "/domains/etnar/wyr/wyr/room/rm_177",
         ] ));
}

void init(){
   ::init();
}
