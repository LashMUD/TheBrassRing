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
    SetShort("The Shrine Room");
    SetLong("   You are in a small semi-circular room. Pungent incense fills the air \n"+
        "and is wafting about from two lit candles located on top of a small \n"+
        "marble altar standing in the middle of the room. A sense of holiness \n"+
        "pervades throughout the area. There are some curtains hanging on the east \n"+
        "and west walls.");
    SetItems( ([
                /*"curtains" : "  Some nice silk magenta curtains flow from the ceiling to the floor \n"+
                    "on the eastern and western walls, seeming to cover an entranceway \n"+
                    "present on each side.",*/
                ({"altar", "marble", "altar"}) : "  An irregularly shaped marble slab, situated on a stone pillar, stands about \n"+
                    "three feet from the floor. The slab has seen some use - tiny scratches and brown-red stains are noticeable.",
                ({"candle", "candles"}) : "  Wax drips down the tapered shafts.",
                ({"stain", "stains"}) : "  Of course they look like dried blood. What kind of sacrifices go on here?",
               ] ));
    /*SetExits( ([
                "east" : "/domains/Etnar/Wyr/room/rm_101",
                "west" : "/domains/Etnar/Wyr/room/rm_102",
                "south" : "/domains/Etnar/Wyr/room/rm_104",
               ] ));

    SetDoor("east", "/domains/Etnar/Wyr/doors/100_101");
    SetDoor("west", "/domains/Etnar/Wyr/doors/100_102");
    */

}
void init(){
   ::init();
}
