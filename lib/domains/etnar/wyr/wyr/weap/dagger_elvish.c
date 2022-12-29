/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

void create(){
    ::create();

    SetKeyName("dagger");
    SetAdjectives( ({"sharp", "wicked"}) );
    SetId( ({"dagger"}) );
    SetShort("an Elvish dagger");
    SetLong("An ebony handled dagger with a short gold colored blade.");
    SetClass(25);
    SetWeaponType("knife");
    SetDamageType(KNIFE);
    SetMass(10);
    SetBaseCost("gold", 125);
    SetVendorType(VT_WEAPON);
}

void init(){
    ::init();
}
