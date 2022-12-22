/* /domains/etnar/wyr/wyr/npc/waltin_kelley
 * Waltin Kelley- a gate guard in the village of Wyr
 * based on The Dead Souls Mud Library
 * maintained by Cratylus http://www.dead-souls.net
 * for use in The Brass Ring Mud
 * last edited by lash 22/12/22 year/month/day
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_SENTIENT;

void checkChat();
int checkCombat();
void time();
static int index;
static int movebool = 0;
int hour;
int *time_of_day;
object array *targets;
int counter = 0;

void eventNews(object ob);

static void create() {
    sentient::create();

    SetKeyName("Waltin Kelley");
    SetId(({"gate guard", "guard"}));
    //SetAdjectives(({"non-player", "non player"}));
    SetShort("Waltin Kelley the Gate guard");
    SetLong("Waltin is tall, with brown hair and blue eyes. ");
    SetCanBite(0);
    SetRace("human");
    SetClass("fighter");
    SetLevel(10);
    SetGender("male");
    SetMorality(2500);
    AddCurrency("gold", 500);
    SetLanguage("common",100);
    SetDefaultLanguage("common");
    SetInventory( ([
        "/domains/etnar/wyr/wyr/npc/waltin/longsword" : "wield sword",
        "/domains/etnar/wyr/wyr/npc/waltin/leather_boots_hard" : "wear boots",
        "/domains/etnar/wyr/wyr/npc/waltin/leather_pants_studded" : "wear pants",
        "/domains/etnar/wyr/wyr/npc/waltin/leather_jerkin" : "wear jerkin",
        "/domains/etnar/wyr/wyr/npc/waltin/leather_sleeves_studded" : "wear sleeves",
        "/domains/etnar/wyr/wyr/npc/waltin/leather_gloves" : "wear gloves",
        "/domains/etnar/wyr/wyr/npc/waltin/key_wyr_south_gate" : 1,
        "/domains/etnar/wyr/wyr/npc/waltin/key_waltin_house" : 1,
        ] ));
    SetAction(3, ({ ( :checkChat: )
        }));
    SetActionsMap( ([ ( :checkCombat: ) : 50,
        ]) );
    SetCombatAction(30, ({"yell We are under attack!"})
        );
    SetTalkResponses( ([  
        ({"trade routes","trade","routes"}) : "The raids on the caravans are "+
            "getting worse and worse.",
        "forest" : "I have a wife and children to support...I don't go "+
            "into the forest these days!",
        "ashlyn" : "Pretty mysterious. She comes down about once a month to "+
            "see Blake, the proprietor of the Cyclops Inn here in town, but "+
            "talks to no one else. She could do a lot better.",
    ]) );
    AddRequestResponses( ([ 
        "news": (: eventNews :) 
    ]) );        
    SetFactions( ([ "The Strike of Balcor":({10,10}),
    ]) );
}

checkChat() {

    int x = random(3);
    object env = environment(this_object());
    object *things;
    things = all_inventory(env);

    if(env) 
    {
       foreach(object thing in things)
       {
           if (thing && base_name(thing) == LIB_CORPSE && thing->GetKeyName() == "albert derby" )
           {
              eventForce("say Albert's dead!");
              eventForce("cry");
              eventForce("look at albert");
              return;
           }
       }           
    }
    if( !present("albert") ) eventForce("say where's Albert?");
        return;
    
    switch (x) {
        case 0 : this_object()->eventForce("say I wish those guards from Orgon would go "
                  "back to where they came from!");
                 break;
        case 1 : this_object()->eventForce("say What about that bandit that's hiding out "
                  "in the Vexwood?");
                 break;
        case 2 : this_object()->eventForce("say I think there's something funny about Ashlyn. "
                  "She keeps to herself too much.");
                 break;
        default : eventPrint("bug in waltin - please report");
                  break;
    }
} 

    

int checkCombat(){
    object enemy;
    object array env;
    env = (get_livings(environment(this_object())));
    
    if(!this_object()->GetInCombat()) {
        /*find out if there are any kobold combatants in the surrounding environment*/
        if(sizeof(env)) {
            foreach(object thing in env) {
                if((thing->GetInCombat()) && thing->GetKeyName() == "albert derby" ) {
                    enemy = thing->GetCurrentEnemy();
                    break;
                }
            }
        }
    
        if( enemy ){
            this_object()->eventForce("say I'll save you, Albert!"); 
            this_object()->eventForce("kill "+enemy->GetKeyName());
        }
        return 1;
    }
}

void eventNews(object ob){

    object env = environment(ob);
    targets = filter(get_livings(env), ( :!$1->GetSleeping(): ));
    targets -= ({ob});
        
    if(member_array("The Strike of Balcor",ob->GetFacs()) == -1 || 
       this_player()->GetQuest("Finding Irwin Quest")){
       eventForce("tell "+ob->GetName()+" Haven't heard a thing lately...");
       tell_room(targets, this_object()->GetShort()+" tells something to "+
            ob->GetName()+".");
       eventForce("shrug");
    }
    else{
        eventForce("tell "+ob->GetName()+" Sybil Klakner's husband has gone "+
            "missing. Maybe you can ask her for the details.");
        tell_room(targets, this_object()->GetShort()+" tells something to "+
            ob->GetName()+".");
        ob->AddReputationTimer("The Strike of Balcor");
        ob->AddFactionTimer("The Strike of Balcor");
    }
}
    
void time(){
    time_of_day = SEASONS_D->GetMudTime();
    hour = time_of_day[0];
   
   if(hour == 5) {
        eventForce("unlock gate with a small shiny key");
        eventForce("open gate");
    }
    else if(hour == 0) {
        eventForce("close gate");
        eventForce("lock gate with a small shiny key");
    }
}

void heart_beat(){
    ::heart_beat();
    time();
}

void init(){
    ::init();
}
