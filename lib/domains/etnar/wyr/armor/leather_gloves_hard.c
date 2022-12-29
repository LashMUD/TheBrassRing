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
    SetId(({"gloves", "hard", "hard leather gloves" }));
    SetAdjectives(({""}));
    SetShort("a pair of hard leather gloves");
    SetLong("A pair of hard leather gloves.");
    SetBaseCost("gold",20);    
    SetMass(5);
    SetDamagePoints(500);
    SetProtection(BLUNT,6);
    SetProtection(BLADE,6);
    SetProtection(KNIFE,6);
    SetFingers(5);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs(({"left hand", "right hand"}));
}

void init(){
    ::init();
}
