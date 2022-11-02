/*
 * Gate Guard for the village of Wyr
 * for use with:
 * The Dead Souls Mud Library
 * developed by Cratylus
 * http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_SENTIENT;

int checkCombat();

static void create() {
    sentient::create();

    SetKeyName("the Cityguard");
    SetId(({"cityguard", "guard"}));
    //SetAdjectives(({"non-player", "non player"}));
    SetShort("A Gate guard");
    SetLong("A big, strong, helpful, trustworthy guard.");
    SetCanBite(0);
    SetInventory( ([
        "/domains/etnar/wyr/weap/longsword" : "wield sword",
        ] ));
    SetRace("human");
    SetClass("fighter");
    SetLevel(10);
    SetMelee(1);
    SetGender("male");
    SetMorality(2500);
    AddCurrency("gold", 500);
}

void init(){
    ::init();
}
