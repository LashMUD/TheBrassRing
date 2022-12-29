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

    SetKeyName("leather sleeves");
    SetId(({"sleeves", "leather sleeves"}));
    SetAdjectives(({"soft"}));
    SetShort("a pair of leather sleeves");
    SetLong("A pair of leather sleeves.");
    SetMass(5);
    SetBaseCost("gold",10);
    SetDamagePoints(500);
    SetProtection(BLUNT,2);
    SetProtection(BLADE,4);
    SetProtection(KNIFE,4);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs(({"right arm", "left arm"}));
}

void init(){
    ::init();
}
