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

    SetKeyName("leather gloves");
    SetId(({"gloves", "leather", "leather gloves" }));
    SetAdjectives(({"soft"}));
    SetShort("a pair of leather gloves");
    SetLong("A pair of leather gloves.");
    SetBaseCost("gold",10);    
    SetMass(5);
    SetDamagePoints(500);
    SetProtection(BLUNT,2);
    SetProtection(BLADE,4);
    SetProtection(KNIFE,4);
    SetFingers(5);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs(({"left hand", "right hand"}));
}

void init(){
    ::init();
}
