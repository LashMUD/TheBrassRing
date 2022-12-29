#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_WORN_STORAGE;

static void create(){
    ::create();
    SetKeyName("cloak");
    SetId(({"cloak"}));
    SetShort("a cloak");
    SetLong("This is a large cloak that belongs to Fostaine Pyre the bard.");
    SetProperties(([
                "no steal" : 1,
        ]));
    SetCanClose(1);
    SetMaxCarry(5000);
    SetMass(200);
    SetBaseCost("gold",100);
    SetDamagePoints(100);
    SetArmorType(A_CLOAK);
}

void init(){
    ::init();
}
