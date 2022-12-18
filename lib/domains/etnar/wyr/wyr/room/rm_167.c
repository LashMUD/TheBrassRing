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
    SetShort("%^BOLD%^Outside the South Gates of the Village of Wyr%^RESET%^");
    SetLong("   Newly constructed gates open through a ten foot high stone "
        "wall that shoots off to the east and west. The path leads north "
        "into a small village. Southwards, the path leads off into the plains."
        );
    SetItems( ([ 
        "path" : "\nA worn out path leads south into the plains. Well "
            "weatherd flagstones have been buried in the dirt leading towards "
            "the gates.\n",
        "plains" : "\nGrass and grazelands stretch out far into the distance. "
             "A couple of farmhouses and barns are visible within the immediate "
             "outskirts of the village.\n",
        ({"wall", "walls"}) : "\nNewly constructed, the walls are composed "
            "of large rocks mortared together by dirt and sand.\n", 
        ({"iron bars", "bars"}) : "\nThese bars look rusty but they are "
            "tough as nails. They make up the sturdy gates that keep trespassers out "
            "at night.",
        ({"padlock", "lock"}) : "\nA large and sturdy looking lock - not too "
           "fancy but certainly functional.",             
        ] ));
    SetInventory( ([
        "/domains/etnar/wyr/wyr/npc/waltin/waltin_kelley" : 1,
        "/domains/etnar/wyr/wyr/npc/albert/albert_derby" : 1,
        ]) );
    SetExits( ([
                "north" : "/domains/etnar/wyr/wyr/room/rm_121",
                "south" : "/domains/etnar/wyr/wyr/room/rm_2000",
        ] ));
    SetDoor("north", "/domains/etnar/wyr/wyr/doors/121_167");
}

void init(){
   ::init();
}
