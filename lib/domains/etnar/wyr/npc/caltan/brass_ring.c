#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create(){
    item::create();
    SetKeyName("ring");
    SetId(({"ring","brass ring"}));
    SetAdjectives( ({"plain", "battered"}) );
    SetShort("a plain brass ring");
    SetLong("The ring is unadorned, tarnished and pitted.");
    SetMass(1);
    SetBaseCost("gold",0);
    SetNoCondition(1);
    SetArmorType(A_RING);
}

void init(){
    ::init();
}
