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
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^A Small Hallway in the Shrine%^RESET%^");
    SetLong("   Oil lamps hang by chains from the ceiling of this small "
        "hallway giving off a dim light. Shadows dance around the walls and "
        "the smell of incense fills the air. To the north there appears to be "
        "a small altar of some sort. The entrance to the Shrine is east."
        );          
    SetItems( ([
       ({"entranceway","entrance", "door"}) : " The doorway to the entrance "
            "of the shrine is made out of heavy reinforced wood.",
       ({"lamp", "lamps", "oil", "oil lamps"}) : " Votive candles infused with "
           "incense burn within metal lamps. The lamps are etched displaying "
           "a lightning filled sky at night. They hang by a slender chain "
           "affixed to the ceiling.",  
        "altar" : " A small altar made out of black obsidian juts from the "
            "floor. An angled lectern sits atop a sculpted cylindrical "
            "pedestal base.",
        ] ));
    SetExits( ([
                "north" : "/domains/etnar/wyr/wyr/room/rm_100",
                "east" : "/domains/etnar/wyr/wyr/room/rm_105", 
                //this needs to be a door
        ] ));
    SetDoor("east", "/domains/etnar/wyr/wyr/doors/104_105");
}

void init(){
   ::init();
}
