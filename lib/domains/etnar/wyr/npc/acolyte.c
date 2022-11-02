/*
 * Gate Guard for the village of Wyr
 * for use with:
 * The Dead Souls Mud Library
 * developed by Cratylus
 * http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_SENTIENT;

int CheckWielded();

int WieldClub(){
    if(present("club",this_object())){ 
        this_object()->eventForce("wield club");
    }
    else{
        new("/domains/etnar/wyr/weap/wooden_club")->eventMove(this_object());
        tell_room(environment(),"%^BOLD%^%^RED%^The Acolyte pulls out a club "
            "from under his robes and wields it with terrible fury!%^RESET%^");
        this_object()->eventForce("say By The hand of Balcor I shall slay you!");
        this_object()->eventForce("wield club");
    }
    return 1;
}

static void create() {
    sentient::create();

    SetKeyName("the Acolyte");
    SetId(({"acolyte"}));
    //SetAdjectives(({"non-player", "non player"}));
    SetShort("An Acolyte");
    SetLong("A pious acolyte.");
    SetCanBite(0);
    SetRace("human");
    SetClass("cleric");
    SetLevel(5);
    SetMelee(1);
    SetGender("male");
    SetMorality(2500);
    AddCurrency("gold", 5);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetInventory( ([
        "/domains/etnar/wyr/weap/wooden_club" : "1",
       ] ));
    SetCombatAction(100, ({ (: WieldClub :),
       }) );
}

int CheckWielded(){
    if(!this_object()->GetInCombat()){
        this_object()->eventForce("unwield club");
    }
    return 1;
}

void init(){
    ::init();
}
