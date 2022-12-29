/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("key_wgk");
    SetId( ({ "key", "village key", "south gate key", "wyr south gate key" }) );
    SetAdjectives( ({ "small", "iron", "shiny" }) );
    SetShort("a small shiny key");
    SetLong("This small key is used to lock the south gates of the Village of Wyr.");
    SetMass(1);
    SetBaseCost("gold",2);
    SetDisableChance(100);
}

void init(){
    ::init();
}
