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
    SetKeyName("key_susks");
    SetId( ({ "key", "key to  susans gate" }) );
    SetAdjectives( ({ "small", "looped", "black" }) );
    SetShort("a small loop handled  black key");
    SetLong("This small key is used to lock the gate in a wicker fence.");
    SetMass(1);
    SetBaseCost("gold",2);
    SetDisableChance(100);
}

void init(){
    ::init();
}
