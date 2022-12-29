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
    
    SetKeyName("leather jerkin");
    SetId(({"armor","leather","jerkin"}));
    SetAdjectives(({"soft"}));
    SetShort("a leather jerkin");
    SetLong("A leather jerkin.");
    SetMass(5);
    SetBaseCost("gold",20);
    SetDamagePoints(500);
    SetProtection(BLUNT,4);
    SetProtection(BLADE,10);
    SetProtection(KNIFE,10);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs( ({"torso"}) );
}

void init(){
    ::init();
}
