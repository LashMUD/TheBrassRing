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

    SetKeyName("studded leather jerkin");
    SetId(({"leather", "jerkin", "studded", "studded leather jerkin"}));
    SetAdjectives(({""}));
    SetShort("a studded leather jerkin");
    SetLong("A studded leather jerkin.");
    SetMass(5);
    SetBaseCost("gold",40);
    SetDamagePoints(500);
    SetProtection(BLUNT,15);
    SetProtection(BLADE,15);
    SetProtection(KNIFE,15);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs( ({"torso"}) );
}

void init(){
    ::init();
}
