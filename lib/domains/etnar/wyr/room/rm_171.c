// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_ROOM;

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Kitchen%^RESET%^");
    SetLong("   A large room with two fireplaces used for cooking the quisine served\n"+
            "at the Cyclops Inn.");
    SetItems( ([ 
                "east" : 
                    "A pair of doors. Above one door is an 'IN' sign while the sign\n"+
                    "above the other door says 'OUT'.",
                ({"fireplace","fireplaces"}) : 
                    "Pots and pans rest on makeshift grills above the fire. The cooks in the\n"+
                    "kitchen busily tend to them." 
        ] ));
    SetExits( ([
        "east" : "/domains/etnar/wyr/room/rm_131",
        ] ));
}

void init(){
   ::init();
}
