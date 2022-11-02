// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("outdoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^A Four Way Intersection%^RESET%^");
    SetLong("   To the west there is a large wooden building. Smoke pours "
        "forth from the chimney and there are sounds of merriment coming from "
        "within. There is a sign above the door. To the east the road dead "
        "ends where there is a small humble looking abode. To the north the "
        "road continues leading out of the village."
        );
    SetItems( ([
        ({"wooden building", "wooden", "building"}) : " The famous Cyclops "
            "Inn. Known for its Cyclopian Brew and casual atmosphere, the "
            "building is falling into disrepair. Shingles are missing from the "
            "roof and paint is peeling away from the exterior. The inn is two "
            "storied with the common room and dining areas on the first floor "
            "and luxury rooms for rent on the second. The current proprieter, "
            "Blake Bannor, is a personage of some repute known throughout the "
            "surrounding area.",
        "sign" : " Hanging above the door is a large sign with an impressive "
            "painting of a huge one-eyed creature wielding a fearsome club "
            "looking for something to eat. The lettering underneath reads:\n\n"
            "                 The Cyclops Inn\n"
            "                by Fulsome Bannor\n",
        ({"abode", "cottage"}) : " A small well maintained cottage lies to "
            "the north of the dead end.",
        "statue" : " The rock used to construct the statue looks like white "
            "marble mottled with bright green colorations. The likeness of a "
            "tall man is depicted. He stands reading a scroll he holds in his "
            "left hand while leaning on the hilt of a large broadsword that "
            "he holds in his right hand. The ears are slightly pointed and "
            "the eyes are yellow gemstones. The baseplate had some lettering "
            "carved but all that can be made out now is:"
            "\n"
            "                         E LAM\n"
            "\n"
            "                  ROT  TE T R OF   E SOUTH\n",
            "road" : " The road is well paved but worn. Large flagstone slabs "
                "pave the way in four directions.",                
        ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_115",
        "east" : "/domains/etnar/wyr/room/rm_123",
        "south" : "/domains/etnar/wyr/room/rm_117",
        "west" : "/domains/etnar/wyr/room/rm_130",
        ] ));
}

void init(){
   ::init();
}
