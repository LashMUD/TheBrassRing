/*
 * Frankel Vogler the bandit
 * for use with:
 * The Dead Souls Mud Library
 * developed by Cratylus
 * http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_SENTIENT;

int CheckWielded();

int WieldSword(){
    if(present("sword",this_object())){ 
        this_object()->eventForce("wield sword");
    }
    else{
        new("/domains/etnar/wyr/wyr/weap/longsword")->eventMove(this_object());
        tell_room(environment(),"%^BOLD%^%^RED%^Frankel Vogler pulls out a sword "
            "from under his cloak and wields it with terrible fury!%^RESET%^");
        this_object()->eventForce("say You messed with the wrong guy, bub!");
        this_object()->eventForce("wield sword");
    }
    return 1;
}

static void create() {
    sentient::create();

    SetKeyName("frankel");
    SetId(({"frankle"}));
    //SetAdjectives(({"non-player", "non player"}));
    SetShort("Frankel Vogler");
    SetLong("A wiry man.");
    SetCanBite(0);
    SetRace("human");
    SetClass("fighter");
    SetLevel(21);
    SetGender("male");
    SetMorality(-2000);
    AddCurrency("gold", 5);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetInventory( ([
        "/domains/etnar/wyr/wyr/npc/flakner/longsword" : "1",
    ] ));
    SetCombatAction(100, ({ (: WieldSword :),
    }) );
}

int CheckWielded(){
    if(!this_object()->GetInCombat()){
        this_object()->eventForce("unwield sword");
    }
    return 1;
}

void init(){
    ::init();
}
