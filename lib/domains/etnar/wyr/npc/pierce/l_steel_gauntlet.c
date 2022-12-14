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

    SetKeyName("steel gauntlet");
    SetId(({"gauntlet", "steel", "steel gauntlet" }));
    SetAdjectives(({"hard", "metal"}));
    SetShort("a steel gauntlet");
    SetLong("A steel gauntlet worn on the left hand.");
    SetBaseCost("gold",10);    
    SetMass(5);
    SetDamagePoints(4400);
    SetProtection(BLUNT,10);
    SetProtection(BLADE,10);
    SetProtection(KNIFE,10);
    SetFingers(5);
    SetArmorType(A_GLOVE);
    SetRestrictLimbs(({"left hand"}));
}

void init(){
    ::init();
}
