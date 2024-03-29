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
    SetShort("%^BOLD%^The South Gate Guardhouse%^RESET%^");
    SetLong("   This small stone structure was obviously built for "
        "functionality. There is very little in the way of creature "
        "comforts. A small table and chair are present as well as a "
        "banner hanging on the back wall. A note is pinned to the east "
        "wall. A stone stairway to the left leads down.");
    SetItems( ([ 
        "east" : "The village road winds north and south. The gates lie "
            "towards the south.", 
        "down" : "A stairway leads down into a small room.",
        "banner" : "A black backdrop ringed by gold felt depicts a mighty "
            "warrior on a white stallion. The warrior is heavily armored and "
            "wields a lightning bolt instead of a sword.",
        ({"stairs", "stair", "stairway"}) : "A stairway, roughly hewn from the "
            "stone foundation, leads straight down into the depths below.",
        "note" : "\nPlease help me find my husband Irwin. He went missing days ago! "
                 "\n-Sybil Klakner-\n",
        ] ));
    SetInventory( ([
        "/domains/etnar/wyr/wyr/virtual/dummy_chair" : 1,
        "/domains/etnar/wyr/wyr/virtual/dummy_table" : 1,
        ]) );
    SetExits( ([
                "east" : "/domains/etnar/wyr/wyr/room/rm_121",
                "down" : "/domains/etnar/wyr/wyr/room/rm_160",
        ] ));
}

void init(){
   ::init();
}
