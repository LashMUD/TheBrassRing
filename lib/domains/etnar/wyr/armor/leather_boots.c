/*
 * Modified by Lash (Christopher Coker) for use with:
 *
 * The Dead Souls Mud Library
 * developed by Cratylus
 * http://www.dead-souls.net
 */

#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>

inherit LIB_ARMOR;

static void create(){
    armor::create();

    SetKeyName("leather boots");
    SetId(({"boots", "leather", "leather boots" }));
    SetAdjectives(({"soft"}));
    SetShort("a pair of leather boots");
    SetLong("A pair of leather boots.");
    SetBaseCost("gold",10);    
    SetMass(30);
    SetDamagePoints(59);
    SetProtection(BLUNT,2);
    SetProtection(BLADE,4);
    SetProtection(KNIFE,4);
    SetArmorType(A_CUSTOM);
     SetRestrictLimbs(({"left foot", "right foot"}));
}

void init(){
    ::init();
}
