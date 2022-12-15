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
    SetShort("a Falunite long sword");
    SetLong("A sharp double edged long sword with a leather wound hilt and "
        "deep red blade");
    SetClass(30);
    SetDamageType(BLADE);
    SetWeaponType("blade");
    SetMass(80);
    SetBaseCost("gold", 600);
    SetDamagePoints(50);
    SetVendorType(VT_WEAPON);
    
}

void init(){
    ::init();
}
