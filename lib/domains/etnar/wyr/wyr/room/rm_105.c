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
    SetShort("%^BOLD%^The Entrance to the Village Shrine%^RESET%^");
    SetLong("   Before you stands a sturdily built oak door; the entrance to "
        "the Shrine in the Village of Wyr. Above the doorway is a wood "
        "engraving. East will take you to the road and west into the Shrine."
        );
    SetItems( ([ 
        ({"engraving", "carving"}) : "  A black Stallion framed against a "
            "lightning filled sky is etched in an impressive piece of wood. "
            "The words 'Henli Zigil' are emblazoned in flowing script.",
        ] ));
    SetExits( ([
                "east" : "/domains/etnar/wyr/wyr/room/rm_106",
                "west" : "/domains/etnar/wyr/wyr/room/rm_104",
        ] ));
    SetDoor("west", "/domains/etnar/wyr/wyr/doors/104_105");
}

void init(){
   ::init();
}
