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

    SetKeyName("steel boot");
    SetId(({"boots", "steel", "steel boot" }));
    SetAdjectives(({"hard, metal"}));
    SetShort("a steel boot");
    SetLong("A steel boot worn on the left foot.");
    SetBaseCost("gold",10);    
    SetMass(10);
    SetDamagePoints(4400);
    SetProtection(BLUNT,10);
    SetProtection(BLADE,10);
    SetProtection(KNIFE,10);
    SetArmorType(A_BOOT);
    SetRestrictLimbs(({"left foot"}));
}

void init(){
    ::init();
}
