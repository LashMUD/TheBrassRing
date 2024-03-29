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
    SetShort("%^BOLD%^The Village Well%^RESET%^");
    SetLong("   There is a large stone cistern built here. Water gushes from the top and falls over " 
            "into some grates below.  People from the town use the well for their drinking water."
        );
    SetItems( ([
        ({"well", "cistern"}) : "Evidently there is an underground resevoir that has enough " 
            "pressure to drive the water up and out from below.",
        "west" : "The  main road through the village of Wyr",
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "west" : "/domains/etnar/wyr/wyr/room/rm_195",
         ] ));
}

void init(){
   ::init();
}
