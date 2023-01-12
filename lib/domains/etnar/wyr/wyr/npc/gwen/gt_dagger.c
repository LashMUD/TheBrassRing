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
    SetBaseCost("gold", 300);
    SetVendorType(VT_WEAPON);
}

int eventStrike(object target) {
    string *races = ({ "kobold", "orc", "goblin", "bugbear", "troll", "hobgoblin" });
    if( member_array(target->GetRace(), races) == -1 ) return item::eventStrike(target);
    message("environment", "Gwendolyn's dagger %^BOLD%^%^BLUE%^glows blue%^RESET%^ as it hits its mark.",
            environment(target));
    return item::eventStrike(target) + random(20)+1;
}

void init(){
    ::init();
}
