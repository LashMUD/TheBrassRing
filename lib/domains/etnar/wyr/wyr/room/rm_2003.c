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
    SetShort("%^BOLD%^A Worn Path on the Plains%^RESET%^");
    SetLong("   You wander along a dusty path through the grasslands. The "
        "plains seem to be peaceful and every once in a while you see a bird "
        "winging its way on to the horizon. Towards the east the path "
        "continues between two small hills. Off to the south you see a small "
        "keep of some sort framed by the background of a forest. A few "
        "outlying trees and shrubs are scattered by the path.");
    SetItems( ([ 
        "east" : "The path continues between two small hills.",
        "south" : "You see a small keep framed by the outline of a scraggly "
        "forest. Every once in a while a puff of smoke billows out of the keep.",
        ] ));
    SetExits( ([
        "east" : "/domains/etnar/wyr/wyr/room/rm_2002",
        "south" : "/domains/etnar/wyr/wyr/room/rm_2004",
        ] ));
}

void init(){
   ::init();
}
