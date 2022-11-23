/* An acolyte for Henli in the shrine of Wyr
 * for use with:
 * The Dead Souls Mud Library
 * developed by Cratylus
 * http://www.dead-souls.net
 *
 * last modified by lash (ccoker) 22/11/23 year/month/day
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
        tell_room(environment(),"%^BOLD%^%^RED%^Winifred pulls out a club "
            "from under her robes and wields it with terrible fury!%^RESET%^");
        this_object()->eventForce("say By The hand of Balcor, I shall slay you!");
        this_object()->eventForce("wield club");
    }
    return 1;
}

static void create() {
    sentient::create();

    SetKeyName("Winifred Barton");
    SetId(({"winifred", "Winifred", "barton", "Barton", "acolyte"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("Winifred Barton");
    SetLong("A pious young acolyte of Balcor, the wargod, stands before you. "
        "Her curly brown hair is cropped short and contrasts her green eyes. " 
        "Winifred is earnest in her studies of the teachings of battlemastery. "
        "She wears light magenta robes depicting the image of Balcor holding "
        "a lightning bolt in his hand.");
    SetCanBite(0);
    SetRace("human");
    SetClass("cleric");
    SetLevel(5);
    SetGender("female");
    SetMorality(1500);
    AddCurrency("gold", 5);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetInventory( ([
        "/domains/etnar/wyr/weap/wooden_club" : "1",
        ] ));
    SetActionsMap( ([
        ( ( :CheckWielded(): ) ) : 50,
        "!say I hope I gain favor in the eyes of Balcor." : 10,
        "!say I can't wait to confront and convert Falkner to the ways of Balcor myself!" : 8,
        "!say Henli should be ready to advance me with all the studying I've done!" : 5,
        ]) );
    SetCombatAction(100, ({ (: WieldClub :),
        }) );
    SetFactions( ([ "The Strike of Balcor" : ({5, 5}),
        ]) );
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
