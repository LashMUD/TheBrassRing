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
    SetShort("%^BOLD%^Entering The Vexwood%^RESET%^");
    SetLong("   You are at the edge of the forest. The trees are tall and "
        "scraggly looking. There is not much underbrush but the trees are "
        "draped in thick moss giving an eerie green glow. To the west are the "
        "ruins of a small keep. The path runs north and south. In fact, "
        "towards the south, the path takes on the appearance of having once "
        "been a well trodden road which is now fallen into disuse.");
    SetItems( ([ 
        "north" : "The path continues out of the forest into the plains.",
        "south" : "The path runs south into the forest. The light rapidly deteriorates.",
        "west" : "A walkway leads towards a small keep. It looks like the walkway has\n"+
                    "seen recent use.",
        "keep" : "Covered in the green moss that is indiginous to this forest, the keep\n"+
                    "consists of two small towers connected by a stone wall. You can make out \n"+
                    "two entrances, one in each tower, to the northwest and southwest. The\n"+
                    "entrance gate on the northern tower is broken on its hinges while the\n"+
                    "south tower gate appears to be intact.",
        ] ));
    SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_2003",
        "south" : "/domains/etnar/wyr/room/rm_2004",
        "west" : "/domains/etnar/wyr/room/rm_2005",
        ] ));
}

void init(){
   ::init();
}
