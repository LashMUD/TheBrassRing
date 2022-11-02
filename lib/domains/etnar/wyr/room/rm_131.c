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
    SetShort("%^BOLD%^The Common Room%^RESET%^");
    SetLong("   You enter a large dimly lit room. There are rectangular and round\n"+
        "tables scattered throughout. In the southern part of the room a large\n"+
        "fireplace holds a crackling fire spewing thick black smoke up into the\n"+
        "chimney. The room structure does not look very stable and four large pillars\n"+
        "have been erected to hold the ceiling in place. The smell of beer and smoke\n"+
        "permeate the air. To the north is a back room and there is a pair of double\n"+
        "doors to the west. To the east lies the entrance to the inn.");
    SetItems( ([ 
                "north" : "A pair of double doors. A sign is posted here.",
                "east" : "The entrance to the Cyclops Inn.",
                "west" : "A pair of doors. Above one door is an 'IN' sign while the sign above the\n"+
                    "other door says 'OUT'.",
                "up" : "The ceiling is covered in thick, nasty cobwebs. You think you can see \n"+
                    "something moving around up there.",
                ({"fireplace", "south"}) : 
                    "A roaring warm fire is always present. The fireplace is made out of large \n"+
                    "stones and is blackened by the perpetual smoke.",
                "sign" : "The sign says 'ROOMS FOR RENT'",
                ({"rafter", "rafters", "ceiling", "cobweb", "cobwebs"}) : 
                    "The ceiling is covered in thick nasty cobwebs.",
                ({"pillars", "pillar"}) : 
                    "The pillars are made out of a stone that you realize is not common to Wyr.",
               ] ));
    SetExits( ([
                "north" : "/domains/etnar/wyr/room/rm_132",
                "east" : "/domains/etnar/wyr/room/rm_130",
                "west" : "/domains/etnar/wyr/room/rm_171",
                //"northwest" : "/domains/etnar/wyr/room/rm_172",
                "southwest" : "/domains/etnar/wyr/room/rm_174",
               ] ));

}
void init(){
   ::init();
}