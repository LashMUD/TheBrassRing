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
    SetShort("%^BOLD%^Blacksmith and Teamster's%^RESET%^");
    SetLong("   You are walking on a well developed road in Wyr. To the west "
        "is a small building, the village teamster in Wyr. You can hear the "
        "grunts and growls of animals emanating from the building. To the "
        "east you see the village blacksmith's shop, a small wooden building "
        "that resembles a large converted shed. The road continues north and "
        "south."
    );
    SetItems( ([ 
        ({"building", "teamster"}) : "  This is a small wooden building "
             "with a field in the back surrounded by a wooden fence. A sign "
             "hangs above the door:"
                "\n"
                "                              TEAMSTER\n"
                "\n"
                "                            Horses for sale\n",
        ({"shop", "blacksmith", "shed"}) : "  The eastern building looks like "
            "an oversized shed. There is a small front entranceway connected "
            "to a larger structure in the back. The furious banging of metal "
            "on metal comes from within within and the smoke billowing out of "
            "the chimney is thick and black. There is a sign above the door:\n"
                  "\n"
                  "                              BLACKSMITH \n",
        "smoke" : "  The smoke is thick and black. Every once and awhile "
            "green sparks can be seen in the midst of the smoke.",   
        "road"  : "  The road is well paved but worn. Large flagstone slabs "
            "pave the way.",
    ] ));
    SetExits( ([
         "north" : "/domains/etnar/wyr/room/rm_106",
         "south" : "/domains/etnar/wyr/room/rm_121",
         "west" : "/domains/etnar/wyr/room/rm_157",
         "east" : "/domains/etnar/wyr/room/rm_170",
         ] ));
}

void init(){
   ::init();
}
