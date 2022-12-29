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

    SetKeyName("steel greave");
    SetId(({"greave", "steel", "steel greave" }));
    SetAdjectives(({"hard", "metal"}));
    SetShort("a steel greave");
    SetLong("A steel greave worn on the right leg.");
    SetBaseCost("gold",10);    
    SetMass(10);
    SetDamagePoints(4400);
    SetProtection(BLUNT,10);
    SetProtection(BLADE,10);
    SetProtection(KNIFE,10);
    SetArmorType(A_CUSTOM);
    SetRestrictLimbs(({"right leg"}));
}

void init(){
    ::init();
}
