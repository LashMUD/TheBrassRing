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
    SetKeyName("key_pph");
    SetId( ({ "key" }) );
    SetAdjectives( ({ "small", "iron", "dull" }) );
    SetShort("a small dull key");
    SetLong("This small key is used to lock the door to Pierce Pascal's house.");
    SetMass(1);
    SetBaseCost("gold",2);
    SetDisableChance(100);
}

void init(){
    ::init();
}
