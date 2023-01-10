/* /domains/etnar/wyr/npc/gate_guard_ab.c
 * Albert Derby - a gate guard in the village of Wyr
 * based on The Dead Souls Mud Library
 * maintained by Cratylus http://www.dead-souls.net
 * for use in The Brass Ring Mud
 * last edited by lash 22/12/25
 */

#include <lib.h>
//#include <position.h>

inherit LIB_SENTIENT;

int checkCombat();
int Chat(string str);
int eventNews();
string str = "";

static void create() {
    sentient::create();
    SetKeyName("Albert Derby");
    SetId(({"gate guard", "guard"}));
    //SetAdjectives(({"non-player", "non player"}));
    SetShort("Albert Derby the Gate guard");
    SetLong("Albert is of medium height for a human, with black hair and green eyes. ");
    SetCanBite(0);
    SetRace("human");
    SetClass("fighter");
    SetLevel(14);
    SetGender("male");
    SetMorality(2500);
    AddCurrency("gold", 500);
    SetLanguage("common",100);
    SetDefaultLanguage("common");
    SetInventory( ([
        "/domains/etnar/wyr/wyr/npc/albert/longsword" : "wield sword",
        "/domains/etnar/wyr/wyr/npc/albert/leather_boots_hard" : "wear boots",
        "/domains/etnar/wyr/wyr/npc/albert/leather_pants_studded" : "wear pants",
        "/domains/etnar/wyr/wyr/npc/albert/leather_jerkin" : "wear jerkin",
        "/domains/etnar/wyr/wyr/npc/albert/leather_sleeves_studded" : "wear sleeves",
        "/domains/etnar/wyr/wyr/npc/albert/leather_gloves" : "wear gloves",
    ] ));
    SetTalkResponses( ([  
        "orgon" : ( :Chat("orgon"): ),
        "guards" : ( :Chat("guards"): ),
        "ashlyn" : ( :Chat("ashlyn"): ),
        "vexwood" : ( :Chat("vexwood"): ),
        "caravans" : ( :Chat("caravans"): ),
        ({"goblin", "goblins"}) : ( :Chat("goblins"): ),
        ({"trade routes", "trade", "routes"}) : "Not safe these days. Reports "+
            "of whole caravans gone missin'.",
        ({"bandit", "falkner"}) : ( :Chat("bandit"): ),
        "waltin" : ( :Chat("waltin"): ),
    ]) );
    SetActionsMap( ([ ( :checkCombat: ) : 100,
        ]) );
    SetCombatAction(30, ({"yell We are under attack!"})
        );
    SetRequestResponses( ([
        ({"news"}) : (:eventNews:),
    ]) );
    SetFactions( ([ "The Strike of Balcor":({8,10}),
    ]) );
}
 
void init(){
    ::init();
}

int checkCombat(){
    object enemy;
    object array env;
    env = (get_livings(environment(this_object())));
    
    if(!this_object()->GetInCombat()) {
        /*find out if there are any combatants in the surrounding environment*/
        if(sizeof(env)) {
            foreach(object thing in env) {
                if((thing->GetInCombat()) && thing->GetKeyName() == "waltin kelley" ) {
                    enemy = thing->GetCurrentEnemy();
                    break;
                }
            }
        }
    
        if( enemy ){
            this_object()->eventForce("say Really? I've got your back Waltin!"); 
            this_object()->eventForce("kill "+enemy->GetKeyName());
        }
        return 1;
    }
}

int Chat(string str)
{
    object ob = this_player();
    object env = environment(this_object());
    object *things;
    things = all_inventory(env);

    if( !present("waltin") && !present("pierce") )
    {
        eventForce("say I ain't sayin' nothin' 'bout nothin'!\nWhere's "
            "Waltin? He should have been back by now!");
        return 1;
    }
    
    switch(str)
    {
        case "bandit" :  
           if(!inherits(LIB_NPC, ob))
           {
               eventForce("say Yeah, this guy named Falkner, he's trying to "+
                   "get some nasty goblins to join his band and make "+
                   "a name for himself!");
                eventForce("laugh");
                return 1;
            }
            else
            {
                eventForce("say Ha! Falkner and his tribe of goblins striking "+ 
                    "fear into the hearts of many...");
                eventForce("spit");
                return 1;
            };
        break;
        case "orgon" : 
           if(!inherits(LIB_NPC, ob))
           {
                eventForce("say The city up northwest. They sent some guards down here "+ 
                    "for reinforcements while the new wall is being built. They "+ 
                    "think they own the place");
                return 1;
            }
            else
            {
               eventForce("say Yeah, those Orgonians are pretty uppity.");
                return 0;
            };
        break;
        case "vexwood" :  
            if(!inherits(LIB_NPC, ob))
            {
                eventForce("say Vexwood forest off to the south. The old hero, "+
                    "Eflam, had a keep there once. It's now in ruins. "+
                    "Lots of unusual creatures in that wood.");  
                return 1;

            }
            else
            {
                 return 0;                
            };
        break;
        case "ashlyn" : 
            if(!inherits(LIB_NPC, ob))
            {
                return 0;
            }
            else
            {
                eventForce("say And that Innkeeper. What does she see in him anyways?");
                return 1;                
            };
        break;
        case "caravans" :
            if(!inherits(LIB_NPC, ob))
            {
                eventForce("say Traders traveling back and forth between Wyr and Orgon "+
                    "in covered wagons and teams of mules. It's getting harder to hire "+
                    "mercenaries for protection. I know I won't go, even though the pay "+
                    "is pretty good.");
                eventForce("shrug");
                return 1;
            }
            else
            {
                 eventForce("say It's pretty sketchy these days.");
                 return 1;
            }
        break;
        case "guards" :
           if(!inherits(LIB_NPC, ob))
           {
                eventForce("say They came from the city of Orgon up northwest. You know, "+
                    "city types.");
                eventForce("frown");
                return 1;
           }
           else
           {
                return 0;
           };
        break;
        case "goblins" :
           if(!inherits(LIB_NPC, ob))
           {
                eventForce("say Small little green buggers. They've been roaming "+
                    "the Vexwood for years. Usually not more than just a nuisance. "+
                    "They're nasty, brutish, and short.");
                eventForce("cackle");
                return 1;
           }
           else
           {
                return 0;
           }
        break;
        default : break;    
    }
}


int eventNews(){
    int x;
    int y;
    
    x=file_length("/domains/etnar/wyr/wyr/text/news/albert/news.txt");
    y=random(x);
    eventForce("speak "+read_file("/domains/etnar/wyr/wyr/text/news/albert/news.txt",y,1)); 

    return 1;
}
