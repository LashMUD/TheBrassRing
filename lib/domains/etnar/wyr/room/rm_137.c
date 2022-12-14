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
    SetShort("%^BOLD%^A secret Passage%^RESET%^");
    SetLong("   You are in a secret passage. The earthen walls are supported "
        "by huge wooden beams, much like you would see in a mine. There is a "
        "small passage to the north or you may continue east or west.");
    SetItems( ([ 
        "north" : "You see that the passageway leads into a large shadowy "
            "opening.",
        "east" : "",
        ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_138",
        "east" : "/domains/etnar/wyr/room/rm_136",
        "west" : "/domains/etnar/wyr/room/rm_139",
        ] ));
}

void init(){
   ::init();
}
