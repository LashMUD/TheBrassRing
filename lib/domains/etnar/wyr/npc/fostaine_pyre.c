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

static void create() {
    sentient::create();
    SetKeyName("Fostaine Pyre");
    SetId(({"bard", "player"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("Fostaine Pyre");
    SetLong("Fostaine is a portly man with long curly hair sporting a thin moustache and goatee. "
        "He is carrying a loot which he uses to entertain the clientel at the Cyclops Inn."
    );
    SetRace("human");
    SetClass("bard");
    SetLevel(18);
    SetGender("male");
    SetCanBite(0);
    SetMorality(1500);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetPolyglot(1);
    SetAutoStand(0);
    /*SetInventory( ([
        "/domains/etnar/wyr/armor/smithying_cape" : "wear cape",
        "/domains/etnar/wyr/obj/brass_ring" : "wear ring",
        "/domains/etnar/wyr/weap/caltan_sword" : "1",
    ] ));
    SetActionsMap( ([
        ( ( :CheckWielded(): ) ) : 100,
        "Caltan hums a smithing dirge to keep tempo with his work." : 20,
        "Caltan forges away on a red-hot piece of metal." : 20,
        "!say If you want to buy something see the apprentice." : 10,
        "!say For peace and tranquility seek Erias..." : 1,
    ]) );
    SetCombatAction(100, ({ (: WieldSword :),
    }) );
         
    SetFactions( ([ "The Seekers of Erias" : ({20,10}),
                    "Fighters Guild" : ({20, 20}),
    ]) );*/
}

/*int CheckWielded(){
    if(!this_object()->GetInCombat()){
        this_object()->eventForce("unwield sword");
    }
    return 1;
}

void eventNews(object ob){

    object env = environment(ob);
    targets = filter(get_livings(env), ( :!$1->GetSleeping(): ));
    targets -= ({ob});
        
    if(member_array("The Seekers of Erias",ob->GetFacs()) == -1){
       eventForce("say Haven't heard a thing lately...");
    }
    else{
        eventForce("tell "+ob->GetName()+" You won't be able to find Erias "
            "unless you have one of these..");
        eventForce("show brass ring to "+ob->GetName());
        tell_room(targets, this_object()->GetShort()+" tells something to "+
            ob->GetName()+".");
        ob->AddReputationTimer("The Seekers of Erias");
        ob->AddFactionTimer("The Seekers of Erias");
        
    }
}*/

void init(){
    ::init();
}


