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

    SetKeyName("leather pants");
    SetId(({"pants", "leather", "leather pants" }));
    SetAdjectives(({"soft"}));
    SetShort("a pair of leather pants");
    SetLong("A pair of leather pants.");
    SetBaseCost("gold",10);    
    SetMass(5);
    SetDamagePoints(500);
    SetProtection(BLUNT,2);
    SetProtection(BLADE,6);
    SetProtection(KNIFE,6);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs(({"left leg", "right leg"}));
}

void init(){
    ::init();
}
