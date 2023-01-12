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
    SetShort("a silver long sword");
    SetLong("A sharp double edged long sword with a leather wound hilt and "
        "shiny silver blade");
    SetClass(24);
    SetDamageType(BLADE);
    SetWeaponType("blade");
    SetMass(12);
    SetBaseCost("gold", 1000);
    SetDamagePoints(12200);
    SetVendorType(VT_WEAPON);
    
}

void init(){
    ::init();
}
