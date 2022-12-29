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

    SetKeyName("hard leather cap");
    SetId(({"cap","leather", "hard leather cap" }));
    SetAdjectives(({""}));
    SetShort("a hard leather cap");
    SetLong("A hard leather cap.");
    SetBaseCost("gold",20);    
    SetDamagePoints(500);
    SetMass(5);
    SetProtection(BLUNT,9);
    SetProtection(BLADE,9);
    SetProtection(KNIFE,9);
    SetArmorType(A_HELMET);
}

void init(){
    ::init();
}
