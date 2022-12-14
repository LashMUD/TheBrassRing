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
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^Sybil Klaknor's House%^RESET%^");
    SetLong(" The Kitchen.");
    SetItems( ([ 
        "east" : "main room",
        ] ));
    SetInventory( ([
        ]) );
    SetExits( ([
         "east" : "/domains/etnar/wyr/room/rm_197",
        ] ));
}

void init(){
   ::init();
}
