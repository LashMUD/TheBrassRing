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
    SetShort("%^BOLD%^North Tower Entrance%^RESET%^");
    SetLong("   You step inside the entranceway in the North Tower. A strong "
        "smell of must and decay immediately hits your nostrils and seems to "
        "come primarily from an alcove to the east. Cobwebs cover the room "
        "and pools of water lie scattered on the floor.");
    SetItems( ([ 
        "north" : "",
        "east" : "",
        "south" : "You see the entranceway to the tower. Outside, the trees sway gently in a\n"+
                    "breeze. Even though the forest is somewhat dark you feel dazzled by the\n"+
                    "light compared to the inside of the Keep.",
        ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_2006",
        "east" : "/domains/etnar/wyr/room/rm_2006",
        "south" : "/domains/etnar/wyr/room/rm_2005",
        ] ));
}

void init(){
   ::init();
}
