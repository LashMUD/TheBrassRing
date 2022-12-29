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
    SetShort("%^BOLD%^The Center fields.%^RESET%^");
    SetLong("   You are in the central field of Joe Farmers farm.");
    SetItems( ([ 
        "north" : "the northern fields.",
        "south" : "the southern fields",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "north" : "/domains/etnar/wyr/wyr/room/rm_188",
         "south" : "/domains/etnar/wyr/wyr/room/rm_187",
         "east" : "/domains/etnar/wyr/wyr/room/rm_186",
         ] ));
}

void init(){
   ::init();
}
