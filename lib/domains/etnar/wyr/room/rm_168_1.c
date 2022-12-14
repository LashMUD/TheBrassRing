/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_ROOM;

static void create() {
    ::create();

    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("The Mystics' Storage Room");
    SetLong("  This is a small, bare room where the Emma Kirkland keeps her goods.");
    SetInventory( ([
        "/domains/etnar/wyr/obj/scroll_recall" : 100,
	    ]) );
    SetNoClean(1);
    SetExits(([
        "None" : "",
        ]));
}

void init(){
    ::init();
}
