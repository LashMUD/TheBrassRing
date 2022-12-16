/* /domains/etnar/wyr/wyr/npc/gate_guard_ab.c
 * Albert Derby - a gate guard in the village of Wyr
 * based on The Dead Souls Mud Library
 * maintained by Cratylus http://www.dead-souls.net
 * for use in The Brass Ring Mud
 * last edited by lash 20/05/21
 */

#include <lib.h>

inherit LIB_SENTIENT;

//object env = environment();
int counter;
void checkPrank();
int checkCombat();
int checkPlacement();
void GoHelp();
int eventNews();
string str = " ";

static void create() {
    sentient::create();
    SetKeyName("Pierce Pascal");
    SetId(({"gate guard", "guard", "captain", "pierce", "pascal"}));
    //SetAdjectives(({"non-player", "non player"}));
    SetShort("Pierce Pascal the Captain of the Wyr militia");
    SetLong("Pierce is tall with short brown hair and hazel eyes. ");
    SetCanBite(0);
    SetRace("human");
    SetClass("fighter");
    SetLevel(25);
    SetGender("male");
    SetMorality(2500);
    AddCurrency("gold", random(30)+1);
    SetLanguage("common",100);
    SetDefaultLanguage("common");
    SetInventory( ([
        "/domains/etnar/wyr/wyr/npc/pierce/falunite_sword" : "wield sword",
        "/domains/etnar/wyr/wyr/npc/pierce/l_steel_boot" : "wear boot",
        "/domains/etnar/wyr/wyr/npc/pierce/r_steel_boot" : "wear boot",
        "/domains/etnar/wyr/wyr/npc/pierce/r_steel_gauntlet" : "wear gauntlet",
        "/domains/etnar/wyr/wyr/npc/pierce/l_steel_gauntlet" : "wear gauntlet",
        "/domains/etnar/wyr/wyr/npc/pierce/steel_helmet" : "wear helmet",
        "/domains/etnar/wyr/wyr/npc/pierce/steel_breastplate" : "wear plate",
        "/domains/etnar/wyr/wyr/npc/pierce/l_steelgreave" : "wear greave on left leg",
        "/domains/etnar/wyr/wyr/npc/pierce/r_steelgreave" : "wear greave on right leg",
        ] ));
    SetActionsMap( ([ ( ( :checkPlacement(): ) ) : 1,
                      
        ]) ); 
    SetTalkResponses( ([  
        "we are under attack!" : ( :GoHelp: ),
        "waltin" : "Waltin is a good man, but lacks ambition.",
        ]) );
    SetRequestResponses( ([
        
        ]) );
    SetFactions( ([ "The Strike of Balcor":({10,10}),
        ]) );
}

void GoHelp(){

    object env = environment();

    if( env && !this_object()->GetInCombat()
            && env->GetShort() == "%^BOLD%^Outside the Guardhouse%^RESET%^" ) {
        this_object()->eventForce("say Not again! We're a peaceful village!");
        this_object()->eventForce("yell %^BOLD%^%^CYAN%^You better be gone before I get there%^RESET%^!");
        this_object()->eventForce("go south");
        checkCombat();
    }
}

int checkCombat() {

    object env = environment();
    object enemy;
    object array *npc = ({});

    npc = filter(get_livings(environment(this_object())), 
        (: $1->GetInCombat() :));
    
    if( !sizeof(npc) ) {
        counter = 0;
        return 0;
    }
    else {
        foreach(object thing in npc) {
            if( (thing->GetKeyName() == "waltin kelley" && thing->GetInCombat()) 
                || (thing->GetKeyName() == "albert derby" && thing->GetInCombat()) ) {
                enemy = thing->GetCurrentEnemy();
                break;
            }
        }
        this_object()->eventForce("kill "+enemy->GetKeyName());
    }
    return 1;
}

void checkPrank() {

    object env = environment();
    //tell_player("lash", "environment is "+env->GetShort());   

    if( env && env->GetShort() ==  "%^BOLD%^Outside the South Gates of the Village of Wyr%^RESET%^"
            && !this_object()->GetInCombat() )
    counter++;
    //tell_player("lash", "counter is "+counter);
    switch (counter) {
        case 1 : this_object()->eventForce("look");
                 break;
        case 2 : this_object()->eventForce("say Another false alarm! Damn pranksters!");
                 break;
        case 3 : this_object()->eventForce("frown");
                 break;
        case 4 : this_object()->eventForce("go north");
                 break;
    }
    if( counter >= 4 ) counter = 0;
}

int checkPlacement() {

    object env = environment();

    if( env && !this_object()->GetInCombat()
            && env->GetShort() != "%^BOLD%^Outside the Guardhouse%^RESET%^" ) { 
        this_object()->eventForce("say I've got to get back to my post.");
        tell_room(environment(this_object()),"Pierce Pascal exits.", ({this_object()}));
        this_object()->eventMove("/domains/etnar/wyr/wyr/room/rm_121");
        tell_room(environment(this_object()),"Pierce Pascal enters.", ({this_object()}));
    }
}

void heart_beat(){
    ::heart_beat();
    checkPrank();
}
    
void init(){
    ::init();
}
