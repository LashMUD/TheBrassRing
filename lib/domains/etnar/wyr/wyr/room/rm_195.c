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
    SetShort("%^BOLD%^Near the Well%^RESET%^");
    SetLong("   A modest but well-kept house can be seen to the west. "
        "Northwards is a four-way intersection with a tall statue "
        "dominating the view. The famous Cyclops Inn of Wyr is visible "
        "towards the northwest. You notice a well maintained well to the east. "
        "Southwards, the road continues but deteriorates to no more than a "
        "dirt road with tracks rutted into it from the wheels of passing wagons." 
        );
    SetItems( ([ 
            "statue": " A large figure of a man reading a scroll and leaning on "
            "the hilt of a huge sword.",
        ({"northwest", "Cyclops Inn", "cyclops inn", "inn", "cyclops"}) : " A large two "
            "storied structure that appears to be falling into disrepair.",
        ({"Town Hall", "town hall", "town", "hall"}) : " Bearing the signs of "
            "new construction the hall is of modest size. People bustle to "
            "and fro from the entrance.",
        ({"west", "house", "modest", "well kept house"}) : " A small but, tidy house "
            "rests here. It has light blue painted wooden walls and nicely tiled roof.", 
        "road"  : " The flagstones become broken and eventually fade out "
            "leaving nothing more than dirt tracks in the ground.",
        ({"east", "well"}) : " There is a cistern built here with water gushing from the "
            "top and draining into some grates below.",
        ] ));
    SetExits( ([
    "north" : "/domains/etnar/wyr/wyr/room/rm_116",
    "south" : "/domains/etnar/wyr/wyr/room/rm_117",
    "west" : "/domains/etnar/wyr/wyr/room/rm_193",
    "east" : "/domains/etnar/wyr/wyr/room/rm_196",
    ] ));
}

void init(){
   ::init();
}
