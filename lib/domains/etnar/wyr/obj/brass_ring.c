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
    SetKeyName("ring");
    SetId(({"ring","brass ring"}));
    SetAdjectives( ({"plain", "battered"}) );
    SetShort("a plain brass ring");
    SetLong("The ring is unadorned and heavily tarnished.");
    SetMass(1);
    SetBaseCost("gold",1);
    SetDamagePoints(1000000);
    SetProtection(BLUNT,1);
    SetArmorType(A_RING);
}

void init(){
    ::init();
}
