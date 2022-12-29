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

    SetKeyName("steel breast plate");
    SetId(({"steel", "plate", "steel breast plate"}));
    SetAdjectives(({""}));
    SetShort("a steel breast plate");
    SetLong("A steel breast plate. It is emblazoned with the Wyr coat of arms.");
    SetMass(50);
    SetBaseCost("gold",1000);
    SetDamagePoints(4400);
    SetProtection(BLUNT,30);
    SetProtection(BLADE,30);
    SetProtection(KNIFE,30);
    SetArmorType(A_BODY_ARMOR);
    SetRestrictLimbs( ({"torso"}) );
}

void init(){
    ::init();
}
