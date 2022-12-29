/*
 * Modified by Lash (Christopher Coker) for use with:
 *
 * The Dead Souls Mud Library
 * developed by Cratylus
 * http://www.dead-souls.net
 */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();

    SetKeyName("long sword");
    SetId( ({"longsword", "long sword", "sword" }) );
    SetAdjectives( ({ "long", "sharp" }));
    SetShort("an Orcish long sword");
    SetLong("Caltan's forged long sword. It is made from dull green metal.");
    SetClass(75);
    SetDamageType(BLADE);
    SetWeaponType("blade");
    SetMass(150);
    SetBaseCost("gold", 1500);
    SetDamagePoints(200);
    SetVendorType(VT_WEAPON);
    
}

void init(){
    ::init();
}
