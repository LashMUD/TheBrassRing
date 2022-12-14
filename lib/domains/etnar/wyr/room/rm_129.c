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
    SetShort("%^BOLD%^Inside the Bank%^RESET%^");
    SetLong("   You are inside of a fortified room. Guards are usually "
        "present in abundance. At the back of the room is a caged in  "
        "chamber with a teller window. Behind the window is a large burly "
        "banker. There is a sign on the wall.");
    SetItems( ([ 
        "south" : "",
        "sign"  : "To make a deposit:      deposit <amount>\n"+
                  "\n"+
                  "To make a withdrawal:   withdraw <amount>\n"+
                    "\n"+
                    "To check your balance:  balance\n"+
                    "\n"+
                    "You may also sell and buy jewels and gems here.",
        ] ));
    SetExits( ([
        "west" : "/domains/etnar/wyr/room/rm_128",
        ] ));
}

void init(){
   ::init();
}
