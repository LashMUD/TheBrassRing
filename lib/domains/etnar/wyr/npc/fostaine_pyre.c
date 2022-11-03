/* /domains/etnar/wyr/npc/fostaine_pyre.c.
 * The bard in the village of Wyr
 * based on The Dead Souls Mud Library
 * maintained by Cratylus http://www.dead-souls.net
 * for use in The Brass Ring Mud
 * last edited by lash 22/11/02
 */

#include <lib.h>
#include <objects.h>
#include <daemons.h>

inherit LIB_SENTIENT;

int CheckWielded();

static void create() {
    sentient::create();
    SetKeyName("Fostaine Pyre");
    SetId(({"bard", "player"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("Fostaine Pyre");
    SetLong("Fostaine is a portly man with long curly hair sporting a thin moustache and goatee. "
        "He is carrying a loot which he uses to entertain the clientel at the Cyclops Inn."
    );
    SetClass("bard");
    SetRace("human");
    SetLevel(30);
    SetGender("male");
    SetCanBite(0);
    SetMorality(1500);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetPolyglot(1);
    SetAutoStand(0);
    SetInventory( ([
        "/domains/etnar/wyr/weap/fostaine_lute" : "1",
    ] ));
    SetActionsMap( ([
        ( ( :CheckWielded(): ) ) : 100,
    ]) );
    SetCombatAction(100, ({ (: CheckWielded :),
    }) );
         
    SetFactions( ([ "House Pyre" : ({20,20}),
                    "Fighters Guild" : ({20, 20}),
    ]) );
}

int CheckWielded(){
    if((!this_object()->GetInCombat()) && (present("lute",this_object()))){
        this_object()->eventForce("unwield lute");
        return 1;
    }    
    if(present("lute",this_object()) && this_object()->GetInCombat()){
        this_object()->eventForce("wield lute");
        return 1;
    }
    else{
        if(this_object()->GetInCombat()){
            new("/domains/etnar/wyr/weap/fostaine_lute")->eventMove(this_object());
            tell_room(environment(),"%^BOLD%^%^RED%^Fostaine grabs his trusty lute "
                "and wields it with terrible fury!%^RESET%^");
            this_object()->eventForce("say Attack a Nobleman, will you?");
            this_object()->eventForce("wield lute");
            return 1;
        }
    }
    if(!this_object()->GetInCombat()){
        this_object()->eventForce("unwield lute");
    }
    return 1;
}

void init(){
    ::init();
}


