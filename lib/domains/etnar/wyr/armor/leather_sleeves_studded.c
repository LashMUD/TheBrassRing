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

    SetKeyName("studded leather sleeves");
    SetId(({"sleeves", "studded" "studded leather sleeves"}));
    SetAdjectives(({""}));
    SetShort("a pair of studded leather sleeves");
    SetLong("A pair of studded leather sleeves.");
    SetMass(5);
    SetBaseCost("gold",20);
    SetDamagePoints(500);
    SetProtection(BLUNT,6);
    SetProtection(BLADE,6);
    SetProtection(KNIFE,6);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs(({"right arm", "left arm"}));
}

void init(){
    ::init();
}
