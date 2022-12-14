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
    if(present("dagger",this_object())){ 
        this_object()->eventForce("wield dagger");
    }
    else{
        new("/domains/etnar/wyr/weap/dagger_elvish")->eventMove(this_object());
        tell_room(environment(),"%^BOLD%^%^RED%^Gwendolyn usheaths her dagger"
            "and wields it with terrible fury!%^RESET%^");
        this_object()->eventForce("say By The hand of Balcor, I shall slay you!");
        this_object()->eventForce("wield club");
    }
    return 1;
}

static void create() {
    sentient::create();

    SetKeyName("gwendolyn trescott");
    SetId(({"gwendolyn", "gwen", "trescott", "tress"}));
    //SetAdjectives(({"non-player", "non player"}));
    SetShort("Gwendolyn Trescott");
    SetLong("A young woman in her mid-twenties, Gwendolyn has slightly longer "
            "than shoulder length black hair parted in the middle. Her hazel eyes "
            "keenly address you.");
    SetCanBite(0);
    SetRace("elf");
    SetClass("mage");
    SetLevel(8);
    SetGender("female");
    SetMorality(1500);
    AddCurrency("gold", 5);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetInventory( ([
        "/domains/etnar/wyr/npc/gwen/dagger_elvish" : "1",
        "/domains/etnar/wyr/npc/gwen/shield" : "wear shield",
        ] ));
    SetActionsMap( ([
        ]) );
    SetFactions( ([ "The Order of Ambrial" : ({5, 9}),
        ]) );
}

void init(){
    ::init();
}
