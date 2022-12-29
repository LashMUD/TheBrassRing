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
    SetKeyName("key_hsk");
    SetId( ({ "key", "shrine key", "key to the shrine" }) );
    SetAdjectives( ({ "ornate", "silver", "crafted" }) );
    SetShort("a silver crafted key");
    SetLong("This key is used to lock the doors of the small shrine in Wyr.");
    SetMass(1);
    SetBaseCost("gold",2);
    SetDisableChance(100);
}

void init(){
    ::init();
}
