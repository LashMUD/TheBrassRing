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

    SetKeyName("leather cap");
    SetId(({"cap","leather", "leather cap" }));
    SetAdjectives(({"soft"}));
    SetShort("a leather cap");
    SetLong("A leather cap.");
    SetBaseCost("gold",10);    
    SetDamagePoints(500);
    SetMass(5);
    SetProtection(BLUNT,2);
    SetProtection(BLADE,6);
    SetProtection(KNIFE,6);
    SetArmorType(A_HELMET);
}

void init(){
    ::init();
}
