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
    SetShort("%^BOLD%^On Pyre Avenue%^RESET%^");
    SetLong("   You are at the beginning Pyre Avenue. Farmer's Way branches off to "
            "the southest."
        );
    SetItems( ([ 
        "southeast" : "Farmer's Way.",
        "west" : "Pyre Avenue continues.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "west" : "/domains/etnar/wyr/room/rm_179",
         "southeast" : "/domains/etnar/wyr/room/rm_177",
         ] ));
}

void init(){
   ::init();
}
