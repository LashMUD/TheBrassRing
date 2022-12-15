/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>
#include <vendor_types.h>

inherit LIB_VENDOR;

static void create() {
    vendor::create();

    SetKeyName("Emma Kirkland");
    SetId( ({"emma", "kirkland", "clerk", "vendor"}) );
    //SetAdjectives(({""}));
    SetShort("Emma Kirkland the Mystics's clerk");
    SetLong("Emma is of medium height with brown hair drawn tight in a bun. Her "
            "soft brown eyes are nonetheless penetrating.\n");
    SetRace("human");
    SetClass("mage");
    SetLevel(12);
    SetCanBite(0);
    AddCurrency("gold", 100);
    SetSkill("bargaining", 1);
    SetLocalCurrency("gold");
    SetStorageRoom("/domains/etnar/wyr/wyr/room/rm_168_1");
    SetMaxItems(500);
    SetVendorType(VT_MAGIC);
    SetProperty("no bump", 1);
    SetAttackable(0);
    SetGender("female");
    SetMorality(2250);
    SetPolyglot(1);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
}

void init(){
    ::init();
}
