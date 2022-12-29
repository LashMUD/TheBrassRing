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

static void create() {
    armor::create();

    SetKeyName("shield");
    SetId( ({ "shield" }) );
    //SetAdjectives( ({ "metal","small" }) );
    SetShort("a small round metal shield");
    SetLong("This shield bears an image of the crimson moon Ambrial amidst a cloudy night sky.");
    //SetDamagePoints(90);
    SetMass(15);
    SetBaseCost("gold",500);
    SetArmorType(A_SHIELD);
    SetProtection(BLUNT, 20);
    SetProtection(BLADE, 15);
    SetProtection(KNIFE, 25);
}

void init(){
    ::init();
}
