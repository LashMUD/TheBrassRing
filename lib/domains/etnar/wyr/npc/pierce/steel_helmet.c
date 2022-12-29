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

    SetKeyName("steel helmet");
    SetId(({"helmet","steel", "steel helmet" }));
    SetAdjectives(({"hard","metal"}));
    SetShort("a steel helmet");
    SetLong("A steel helmet. On the crest is emblazoned the coat of arms of the village of Wyr. ");
    SetBaseCost("gold",10);    
    SetDamagePoints(4400);
    SetMass(10);
    SetProtection(BLUNT,10);
    SetProtection(BLADE,10);
    SetProtection(KNIFE,10);
    SetArmorType(A_HELMET);
}

void init(){
    ::init();
}
