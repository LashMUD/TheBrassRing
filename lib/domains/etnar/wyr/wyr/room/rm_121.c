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
    SetShort("%^BOLD%^Outside the Guardhouse%^RESET%^");
    SetLong("   You are on a small road running north and south through Wyr. " 
            "The road is in good shape for such a small village. To the " 
            "south lie the village gates and to the west is a small " 
            "forboding looking building.");
    SetItems( ([ 
        "road" : "\nThe road is well paved but worn. Weathered and well "+
            "trodden flagstone slabs lie buried in the dirt.\n",
        "building" : "\nSquatting off to the west is a weathered looking "+
            "stone structure. There is an overhang above the entranceway for "+
            "protection from the elements.\n",
        ] ));
    SetInventory(([
        "/domains/etnar/wyr/wyr/npc/pierce/pierce_pascal_1" : 1,
        ]) );
    SetExits( ([
        "north" : "/domains/etnar/wyr/wyr/room/rm_118",
        "east" : "/domains/etnar/wyr/wyr/room/rm_226",
        "south" : "/domains/etnar/wyr/wyr/room/rm_167",
        "west" : "/domains/etnar/wyr/wyr/room/rm_159",
        ] ));
    SetDoor("south", "/domains/etnar/wyr/wyr/doors/121_167");

}
void init(){
   ::init();
}
