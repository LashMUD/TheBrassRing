/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>

inherit LIB_ARMOR;

static void create(){
    armor::create();

    SetKeyName("studded leather pants");
    SetId(({"pants", "leather", "studded", "studded leather pants" }));
    SetAdjectives(({""}));
    SetShort("a pair of studded leather pants");
    SetLong("A pair of studded leather pants.");
    SetBaseCost("gold",20);    
    SetMass(5);
    SetDamagePoints(500);
    SetProtection(BLUNT,9);
    SetProtection(BLADE,9);
    SetProtection(KNIFE,9);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs(({"left leg", "right leg"}));
}

void init(){
    ::init();
}
