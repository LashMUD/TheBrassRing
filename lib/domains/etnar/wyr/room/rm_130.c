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
    SetShort("%^BOLD%^The Entrance to the Cyclops Inn%^RESET%^");
    SetLong("   You stand at the entrance to the Cyclops Inn. Once a "
        "magnificent building, it looks as if the owner has not kept up on the "
        "repairs. You may enter to the west or go to the Main Road to the "
        "east.");
    SetItems( ([ 
         "east" : "The Main Road encircling Wyr.",
         "west" : "A dimly lit, very large, common room. You can hear the occasional sounds of\n"+
                    "debauchery from within.",
         "statue": "A large figure of a man reading a scroll and "+
                    "leaning on the hilt of a huge sword.",
         ] ));
    SetExits( ([
         "east" : "/domains/etnar/wyr/room/rm_116",
         "west" : "/domains/etnar/wyr/room/rm_131",
         ] ));
}

void init(){
   ::init();
}
