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
    SetShort("%^BOLD%^The Innkeepers Room%^RESET%^");
    SetLong("   You enter a huge diamond shaped room with an arched ceiling. "
        "The walls are painted a deep red and yield an air of mystery. Two "
        "pillars give support to the creaking roof. A lavish canopied bed "
        "occupies the south wall and a huge painting hangs on the north wall. "
        "You would expect to see a window or two but there is none. The only "
        "exit you see is to the east.");
    SetItems( ([ 
        "east" : "",
        "west" : "",
        "bed"  : "This bed is made of the finest wood you have ever seen. You "
            "wish you could sleep forever on the expensive comfortable "
            "mattress. A small hole in the wall behind the headboard almost "
            "escapes your attention.",
        ({"painting", "picture"}) : "A very mean looking old man in glasses "
            "stares back at you. The plaque beneath reads 'Fulsome Banner, "
            "Esq.'",
        ]) );
    SetExits( ([
        "east" : "/domains/etnar/wyr/wyr/room/rm_132",
        "west" : "/domains/etnar/wyr/wyr/room/rm_134", //secret door in wall
        ] ));
}

void init(){
   ::init();
}
