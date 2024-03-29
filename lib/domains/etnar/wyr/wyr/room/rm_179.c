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
    SetLong("   You are on Pyre Avenue. It continues east and west. To the south is "
            "Waltin Kelly's house."
        );
    SetItems( ([ 
        "east" : "Pyre Avenue continues.",
        "west" : "Pyre Avenue continues.",
        "south" : "Waltin Kelly's house.",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "east" : "/domains/etnar/wyr/wyr/room/rm_178",
         "west" : "/domains/etnar/wyr/wyr/room/rm_180",
         "south" : "/domains/etnar/wyr/wyr/room/rm_189",
         ] ));
    SetDoor("south", "/domains/etnar/wyr/wyr/doors/179_189");
}

void init(){
   ::init();
}
