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
    SetShort("%^BOLD%^A Secret Passage%^RESET%^");
    SetLong("   You are in a secret passage. The earthen walls are supported "
        "by huge wooden beams, much like you would see in a mine. The passage "
        "continues to the west and east.");
    SetItems( ([ 
        "east" : "",
        "west" : "",
        ] ));
    SetExits( ([
        "east" : "/domains/etnar/wyr/wyr/room/rm_135",
        "west" : "/domains/etnar/wyr/wyr/room/rm_137",
        ] ));
}

void init(){
   ::init();
}
