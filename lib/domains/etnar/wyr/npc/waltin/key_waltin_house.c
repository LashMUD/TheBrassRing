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
    SetKeyName("key_wkh");
    SetId( ({ "key", "waltin kelly house key", "key to Waltin Kelly's house" }) );
    SetAdjectives( ({ "plain", "iron", "small" }) );
    SetShort("a small, plain, iron crafted key");
    SetLong("This key is used to lock the front door of Waltin Kelly's house.");
    SetMass(1);
    SetBaseCost("gold",2);
    SetDisableChance(100);
}

void init(){
    ::init();
}
