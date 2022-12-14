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

    SetKeyName("lute");
    SetAdjectives( ({"wooden", "stringed", "finely crafted"}) );
    SetId( ({"lute"}) );
    SetShort("a beautifully crafted lute");
    SetLong("A beutifully crafted plucked string instrument with a neck and a "
            "deep round back and a sound hole in the body. It is unfretted and "
            "is played expertly by Fostaine Pyre when performing at the Cylops "
            "Inn.");
    SetClass(25);
    SetWeaponType("blunt");
    SetDamageType(BLUNT);
    SetMass(10);
    SetBaseCost("gold", 10000);
    SetVendorType(VT_WEAPON);
}

void init(){
    ::init();
}
