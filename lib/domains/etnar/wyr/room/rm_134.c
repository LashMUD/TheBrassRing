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
    SetShort("%^BOLD%^A Secret Room%^RESET%^");
    SetLong("   You enter into a small dimly lit room. Usually a torch is "
        "hanging on the wall to provide enough light to see. A stone "
        "staircase leads down into the dark depths.");
    SetItems( ([ 
        "down" : "Down into the darkness the stairs lead. You think you hear "
            "something scuffling around down there.",
        ] ));
    SetExits( ([
        "east" : "/domains/etnar/wyr/room/rm_133", //secret door through wall
        "down" : "/domains/etnar/wyr/room/rm_135",
        ] ));
}

void init(){
   ::init();
}
