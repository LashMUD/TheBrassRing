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
    SetShort("%^BOLD%^The Walkway to the Keep%^RESET%^");
    SetLong("   You walk down a ruined walkway towards the keep. Broken "
        "flagstones make up the walkway and you find that you almost lose "
        "your balance on the loose stones. At the end of the walkway you "
        "find yourself in front of a tall wall that stretches north and "
        "south and connects two small towers. A huge ball of brush, covered "
        "in thick green moss, runs along the wall. The walkway looks like it "
        "continues straight into the wall and goes north and south to the "
        "tower entrances.");
    SetItems( ([ 
        "north" : "You see the entrance to north tower. An iron gate hangs by its hinges.\n"+
                    "Darkness lies beyond the entrance.",
        "east" : "The walkway continues towards a path in the forest.",
        "south" : "An iron gate closes off the entrance to the south tower. Behind the gate\n"+
                    "lies a large, banded, wooden door.",
        "west" : "You peer ahead and think you can make out an opening beyond the thick\n"+
                    "vegetation.",
        ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/wyr/room/rm_2006",
        "east" : "/domains/etnar/wyr/wyr/room/rm_2004",
        "south" : "/domains/etnar/wyr/wyr/room/rm_2005 ",
        "west" : "/domains/etnar/wyr/wyr/room/rm_2005",
        ] ));
}

void init(){
   ::init();
}
