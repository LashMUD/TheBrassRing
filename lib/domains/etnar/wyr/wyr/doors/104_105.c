/* Modified by Lash (Christopher Coker) for use with:
 *
 * The Dead Souls Mud Library
 * developed by Cratylus
 * http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_DOOR;

static void create() {
    door::create();

    SetSide("east", ([ "id" : ({"door leading east", "door", "east door"}),
        "short" : "the door to the Shrine",
        "long" : "\nA large reinforced oak door.",
        "lockable" : 1 ]) );

    SetSide("west", ([ "id" : ({"door leading west", "door", "west door"}),
        "short" : "a massive door leading into the small Shrine",
        "long" : "\n This is a large reinforced oak door with an engraving "
            "depicting a heavily armored figure sitting atop a massive horse. "
            "The night sky surrounding the mounted figure is filled with "
            "lightning. Instead of a sword, a lightning bolt is held in the "
            "raised hand, ready to be hurled at an unseen foe.",
        "lockable" : 1 ]) );

    SetClosed(0);
    SetLocked(0);
    SetKeys("east", ({ "key_hsk" }));
    SetKeys("west", ({ "key_hsk" }));
}

void init(){
    ::init();
}
