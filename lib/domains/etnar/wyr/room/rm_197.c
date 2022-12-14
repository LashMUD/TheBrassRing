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
    SetShort("%^BOLD%^Sybil Klaknor's House%^RESET%^");
    SetLong("   The main room of Sybil Klaknor's house is sparsely furnished, "
        "but very clean. A round carpet is laid out on the wooden floor and "
        "a modest sofa is against the south wall next to a fireplace. Above "
        "the sofa hangs a clock in a wooden frame. In the corner by the sofa "
        "is a wooden cabinet with a glass door.");
    SetItems( ([ 
        "north" : "There is a bed in this room with a nightstand next to it.",
        "south" : "A small room with a table, a chair, and a small bookcase.",
        "west" : "A small kitchen is beyond the entrance.",
        ({"carpet", "rug"}) : "Probably the most expensive thing in the house. "
            "The rug has red floral design woven into it.",
        ({"sofa", "couch"}) : "Well worn with some threads starting show.",
        "fireplace" : "Though not very big a fire here would be enough to heat "
            "the whole house.",
        "clock" : "It shows the correct time twice a day.",
        "cabinet" : "Through the glass doors you can see some trinkets sitting on "
            "three wooden shelves. The middle shelf has a small cloth doll sitting "
            "against the back of the cabinet.",
        ({"doll", "cloth doll"}) : "A raggedy doll with buttons for eyes and a nice "
            "little yellow dress. It smiles sweetly at you.",  
        ] ));
    SetInventory( ([
    ]) );
    SetExits( ([
         "east" : "/domains/etnar/wyr/room/rm_114",
         ] ));
    SetDoor("east", "/domains/etnar/wyr/doors/114_197");
}

void init(){
   ::init();
}
