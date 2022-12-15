/* Modified by Lash (Christopher Coker) for use with:

 The Dead Souls Mud Library version 2
 developed by Cratylus
 http://www.dead-souls.net
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();

    SetKeyName("wooden club");
    SetId( ({ "club", "wooden club" }) );
    SetAdjectives( ({ "club", "wooden", "simple" }) );
    SetShort("a wooden club");
    SetLong("A simpel looking wooden club.");
    SetMass(30);
    SetBaseCost("gold",12);
    SetVendorType(VT_WEAPON);
    SetClass(8);
    SetDamageType(BLUNT);
    SetWeaponType("blunt");
}

void init(){
    ::init();
}
