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
    SetShort("%^BOLD%^The Front Yard%^RESET%^");
    SetLong("   The grass is neatly cropped and there are a couple of large "
        "shade trees that can provide relief from the summer heat. Neatly "
        "trimmed bushes and shrubs line the front wall of the north cottage. "
        "Flower beds holding colorful flowers are interspersed between the "
        "foliage."
        );
    SetItems( ([ 
        ({"shade trees","trees","shade"}) : " Two Large sawtooth leafy oaks " 
            "stand at either end of the yard prividing deep shade cover on a "
            "sunny day.",
        ({"bushes", "bush", "shrubs", "shrub"}) : " Large leaf hostas, "
            "umbrella plants, and forest grass grow in abundance.",
        ({"flowers", "flowers beds", "beds", "bed"}) : " Tulips, roses, "
            "daisies, and bluebells explode in color among the leafy plants.",
        ({"cottage", "house"}) : " This modest house is painted white with "
            "black trim. A broad overhang keeps out the elements. Stone "
            "steps lead up and inside.",
        ] ));
    SetInventory(([
        "/domains/etnar/wyr/wyr/npc/lulu" : 1,
        ]) );
    SetExits( ([
        "south" : "/domains/etnar/wyr/wyr/room/rm_123", 
        "north" : "/domains/etnar/wyr/wyr/room/rm_168",
        ] ));
    SetDoor("south", "/domains/etnar/wyr/wyr/doors/108_123");
}

void init(){
   ::init();
}
