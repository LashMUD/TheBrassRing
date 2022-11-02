/* /domains/etnar/wyr/npc/smith_cd.c.
 * Caltan Dowini - the village blacksmith in the village of Wyr
 * based on The Dead Souls Mud Library
 * maintained by Cratylus http://www.dead-souls.net
 * for use in The Brass Ring Mud
 * last edited by lash 20/06/07
 */

#include <lib.h>
#include <objects.h>
#include <daemons.h>

inherit LIB_TRAINER;

int eventHelp(object who, string unused);

void eventNews(object ob);
int CheckWielded();
object array *targets;

int WieldSword(){
    if(present("sword",this_object())){ 
        this_object()->eventForce("wield sword");
    }
    else{
        new("/domains/etnar/wyr/weap/caltan_sword")->eventMove(this_object());
        tell_room(environment(),"%^BOLD%^%^RED%^Caltan grabs his trusty Orcish long sword "
            "from the weapons rack and wields it with terrible fury!%^RESET%^");
        this_object()->eventForce("say I knew I should have stayed in Erias!");
        this_object()->eventForce("wield sword");
    }
    return 1;
}

static void create() {
    trainer::create();
    SetKeyName("Caltan Dowini");
    SetId(({"blacksmith", "smith"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("Caltan Dowini");
    SetLong("Caltan is an imposing man. He stands tall with rippling muscles "
        "that aid his daily work of smithing tools from raw metal."
    );
    SetRace("elf");
    SetStat("strength", 1);
    SetClass("fighter");
    SetLevel(18);
    SetGender("male");
    SetCanBite(0);
    SetMorality(1500);
    AddCurrency("gold", 500);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetPolyglot(1);
    AddTrainingSkills( ({ "blade attack", "blade defense", "blunt attack", "blunt defense",
        "multi hand", "multi weapon"
    }) );
    SetConsultResponses( ([
        ({ "Fighters", "fighters", "Fighters Guild", "guild",
           "Guild", "fighters guild"  }) : "If you are qualified enough in the arts "+
           "of comabat you can join the guild.",
    ]) );
    SetInventory( ([
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
    SetTalkResponses( ([  
        "erias" : "Once you weary of adventure and riches you may find it.",
        "falkner" : "Used to live up in Orgon, then became a loner living in "
            "the nearby mountains.",
        "orgon" : "The city up north near the Tempus mountains. I do some "
            "trading with those folks when the caravans come to town.",
        ({"mountains", "tempus"}) : "They say an old wizard tried to close "
            "the bay so he wouldn't have to sail across. It didn't really "
            "work. A massive earthquake happened and sent up huge mountain "
            "ranges on both shorelines.",
        "caravan" : "They come down about once a month and  pick up goods "
            "from the farmers and businessfolk here in Wyr to take back to "
            "the merchants in Orgon. I get my raw metals for smithing from them.", 
    ]) );
    AddRequestResponses( ([ 
        "news": (: eventNews :) 
    ]) );        
    SetFactions( ([ "The Seekers of Erias" : ({20,10}),
                    "Fighters Guild" : ({20, 20}),
    ]) );
}

int CheckWielded(){
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
}

int eventHelp(object who, string unused){
    ::eventHelp(who);
    this_object()->eventForce("speak Are you qualified to join the Fighters Guild? "
        "Ask me about the Guild!");
    return 1;
}

void init(){
    ::init();
}


