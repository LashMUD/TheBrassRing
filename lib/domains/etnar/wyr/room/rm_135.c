// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>
#include <terrain_types.h>

inherit LIB_ROOM;

static void create() {

    room::create();
    SetClimate("indoors");
    SetTerrainType(T_UNDERGROUND);
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Meeting Room%^RESET%^");
    SetLong("   Dominating the room is a long table surrounded by chairs. "
        "Torch holders line the walls.");
    SetItems( ([ 
        "west"  : "There is a passageway leading out of the room.",
        "up" : "Up the staircase.",
        "table" : "This is a long, well polished, and maintained table. "
             "Looking closer you notice an image in the table - and it's not "
             "yours.",
        "image" : "The eyes of a maddened wizened old man stare back at you "
            "and occasionally blink mindlessly.",
        ({"chair", "chairs"}) : "They are simple constructs that are built "
            "more for purpose than comfort.",
        ] ));
    SetExits( ([
        "west" : "/domains/etnar/wyr/room/rm_136",
        "up" : "/domains/etnar/wyr/room/rm_134",
        ] ));
}

void init(){
   ::init();
}
