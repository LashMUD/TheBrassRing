/* /domains/etnar/wyr/wyr/npc/gate_guard_ab.c
 * Albert Derby - a gate guard in the village of Wyr
 * based on The Dead Souls Mud Library
 * maintained by Cratylus http://www.dead-souls.net
 * for use in The Brass Ring Mud
 * last edited by lash 23/01/06 year/month/day
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_SENTIENT;

void Setpcounter();
void GoHelp();
void checkCombat();
void checkPrank();
void CheckGate();
int DisposeCorpse();
void checkPlacement();
object *pranksters = ({});
string *npcees = ({});
void eventNews(); //added later
int pcounter = 0; //prank counter
int hcounter = 0; //help counter
int ccounter = 0; //corpse counter
int hour, minutes;
int *time_of_day;
string msg = ""; //added later

static void create() {
    sentient::create();
    SetKeyName("Pierce Pascal");
    SetId(({"guard", "captain", "pierce", "pascal"}));
    SetAdjectives(({"non-player", "non player"}));
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
        "/domains/etnar/wyr/wyr/npc/pierce/key_wyr_south_gate" : "1",
        ] ));
    SetActionsMap( ([ ( ( :checkPlacement(): ) ) : 100,
        ]) ); 
    SetTalkResponses( ([  
        "we are under attack!" : ( :GoHelp: ),
        ]) );
    SetRequestResponses( ([
        
        ]) );
    SetFactions( ([ "The Strike of Balcor":({10,10}),
        ]) );
   set_heart_beat(1);
}

//reset pcounter to 0
void Setpcounter() {
     
    object env = environment();

    if( env 
        && env->GetShort() != "%^BOLD%^Outside the South Gates of the Village of Wyr%^RESET%^"
        && !this_object()->GetInCombat() ) {
            ccounter = 0; 
            pcounter = 0;
            pranksters = ({});
            npcees = ({});
    }

}

//used a call_out in conjunction with SetTalkResponses()
void GoHelp() {

    object env = environment();
        
    if( env->GetShort() == "%^BOLD%^Outside the Guardhouse%^RESET%^"
        && !this_object()->GetInCombat() )
    {     
        hcounter++;
        switch (hcounter) 
        {
            case 1 : eventForce("say Not again! We're a peaceful village!");
                     break;
            case 2 : eventForce("yell %^BOLD%^%^CYAN%^You better be gone before "
                         "I get there%^RESET%^!");
                     break;
            case 3 : eventForce("unlock gate with key");
                     break;
            case 4 : eventForce("open gate");
                     break;
            case 5 : eventForce("go south");
                     checkCombat();
                     break;
            default : eventPrint("error in pascal");
                      break;
        }
        
        if( hcounter > 5 ) {
            hcounter = 0;
        }
        call_out((: GoHelp :), 2); 
    }
}

void checkCombat() {

    object enemy;
    object array *npc = ({});

    npc = filter(get_livings(environment(this_object())), 
        (: $1->GetInCombat() :));
    
    if( !sizeof(npc) ) {
        return;
    }
    else {
        foreach(object thing in npc) {
            if( (thing->GetKeyName() == "waltin kelley" && thing->GetInCombat()) 
                || (thing->GetKeyName() == "albert derby" && thing->GetInCombat()) ) {
                enemy = thing->GetCurrentEnemy();
                break;
            }
        }
        eventForce("say attacking my guards, eh? I'll show you!");
        eventForce("kill "+enemy->GetKeyName());
    }
}

/* gate is a dummy object - don't know how
 * to check if locked or not, so check every hour
 */
CheckGate() {
    
    object env = environment();
    time_of_day = SEASONS_D->GetMudTime();
    hour = time_of_day[0];
    minutes = time_of_day[1];

    if (hour == 0 && minutes == 1 
        || hour == 1 && minutes == 1
        || hour == 2 && minutes == 1
        || hour == 3 && minutes == 1 
        || hour == 4 && minutes == 1
       )
    {
        eventForce("close gate");
        eventForce("lock gate with a small shiny key");
    }
     if (hour == 5 && minutes == 1) {
        eventForce("unlock gate with a small shiny key");
        eventForce("open gate");
     }
}

mixed GetPranksters() {
    
    if( sizeof(pranksters) )
        return pranksters;
}


mixed GetNpcees() {
    
    if( sizeof(npcees) )
        return npcees;
}

void checkPrank()
{

    object albert;
    object waltin;
    object env = environment();
    pranksters = all_inventory(env);

    if( ccounter > 0 ) DisposeCorpse();                  

    if( sizeof(pranksters) )
    {
        foreach(object thing in pranksters)
        {
            npcees += ({ thing->GetKeyName() });
            if( thing->GetKeyName() == "albert derby" )
            {
                albert = thing;
            }
            if( thing->GetKeyName() == "waltin kelley" )
            {
                waltin = thing;
            }
        }
    }

    //pierce is in the correct room, and not in combat
    if( env->GetShort() == "%^BOLD%^Outside the South Gates of the Village of Wyr%^RESET%^" 
        && !this_object()->GetInCombat() ) 
    {
        //case 1: albert and waltin are present, not corpses, and not in combat
        if( present("albert")
            && present("waltin")
            && base_name(albert) != LIB_CORPSE 
            && base_name(waltin) != LIB_CORPSE 
            && !albert->GetInCombat() 
            && !waltin->GetInCombat() 
          )
            
        {
            pcounter++;
            switch (pcounter) 
            {
                case 1 : if( waltin->GetCurrentEnemy() != 0
                             || albert->GetCurrentEnemy() != 0) 
                             pcounter = 5;
                         break;
                case 2 : eventForce("look");
                         break;
                case 3 : eventForce("say Another false alarm! Damn pranksters!");
                         break;
                case 4 : eventForce("frown");
                         break;
                case 5 : eventForce("go north");
                         break;
                case 6 : eventForce("say Waltin! Keep on looking for "
                             +capitalize(waltin->GetCurrentEnemy()));
                         break;
                case 7 : eventForce("say you know, Albert, keep on looking for "
                             +capitalize(albert->GetCurrentEnemy()) );
                         break;
                case 8 : pranksters = get_livings(env);
                         if( albert->GetCurrentEnemy() != 0 
                             && present(albert->GetCurrentEnemy()->GetKeyName())
                             && member_array(albert->GetCurrentEnemy()->GetKeyName(), pranksters) == -1 ) 
                         {
                             eventForce("say Hey Albert, looks like "
                                 +capitalize(albert->GetCurrentEnemy()->GetKeyName())+ 
                                 " won't be bothering anyone anymore!");
                             eventForce("cackle");
                         }
                         break;
                case 9 : eventForce("get "+albert->GetCurrentEnemy()->GetKeyName());
                         break;
                case 10 : eventForce("put corpse on table");
                         if( albert->GetCurrentEnemy() == waltin->GetCurrentEnemy() ) 
                             {
                               albert->SetCurrentEnemy();
                               waltin->SetCurrentEnemy();
                             }
                             else  albert->SetCurrentEnemy();
                         break;
                case 11 : pranksters = get_livings(env);
                          if( waltin->GetCurrentEnemy() != 0
                             && waltin->GetCurrentEnemy()->GetKeyName()
                             && present(waltin->GetCurrentEnemy()->GetKeyName())
                             && member_array(waltin->GetCurrentEnemy(), pranksters) == -1 ) 
                         {
                             eventForce("say Hey Waltin, looks like "
                                 +capitalize(waltin->GetCurrentEnemy())+ 
                                 " won't be bothering anyone anymore!");
                             eventForce("cackle");
                          }
                          break;
                case 12 : eventForce("get "+waltin->GetCurrentEnemy());
                          break;
                case 13 : eventForce("put corpse on table");
                          if(waltin->GetCurrentEnemy() == albert->GetCurrentEnemy() ) 
                          {
                            waltin->SetCurrentEnemy();
                            albert->SetCurrentEnemy();
                          }
                          else  waltin->SetCurrentEnemy();
                          break;
                case 14 : eventForce("unlock gate with key");
                          eventForce("open gate");
                          break;
                case 15 : eventForce("go north");
                          break;
                default : eventPrint("error in Pascal");
                          break;
            }             
        }
       
        //case 2: albert is a corpse, waltin is present, not a corpse, and not in combat
        if( base_name(albert) == LIB_CORPSE
            && present("waltin")
            && base_name(waltin) != LIB_CORPSE
            && !waltin->GetInCombat() 
          ) 
            
        {
            pcounter++;
            switch (pcounter)
            {
                case 1 : eventForce("look");
                         break;
                case 2 : eventForce("frown");
                         break;
                case 3 : eventForce("say Oh my goodness! Waltin, what happened "
                             "to Albert?");
                         break;
                case 4 : if(!waltin->GetCurrentEnemy())
                         waltin->eventForce("shrug");
                         if(waltin->GetCurrentEnemy())
                         pcounter = 6;
                         break;
                case 5 : if(!waltin->GetCurrentEnemy())                        
                         eventForce("shake");
                         break;
                case 6 : if(!waltin->GetCurrentEnemy())
                         eventForce("say I don't know if you're ready to be "
                             "a gate guard just yet");
                          pcounter = 11;
                          break;
                case 7 : if(waltin->GetCurrentEnemy())
                         waltin->eventForce("say Last person I was fighting was "
                             +capitalize(waltin->GetCurrentEnemy()->GetKeyName()));
                         break;
                case 8 : if( waltin->GetCurrentEnemy() 
                             && !present(waltin->GetCurrentEnemy()->GetKeyName()) ) 
                             eventForce("say well, keep an eye out for this "+
                                capitalize(waltin->GetCurrentEnemy())+" character.");
                         break;
                case 9 : pranksters = get_livings(env);
                         if( waltin->GetCurrentEnemy() != 0
                             && waltin->GetCurrentEnemy()->GetKeyName()
                             && present(waltin->GetCurrentEnemy()->GetKeyName())
                             && member_array(waltin->GetCurrentEnemy(), pranksters) == -1 ) 
                         {
                             eventForce("say Hey Waltin, looks like "
                                 +capitalize(waltin->GetCurrentEnemy())+ 
                                 " won't be bothering anyone anymore!");
                             eventForce("cackle");
                          }
                          break;
                case 10 : eventForce("get "+waltin->GetCurrentEnemy()->GetKeyName());
                          break;
                case 11 : eventForce("put corpse on table");
                          waltin->SetCurrentEnemy();
                          break;
                case 12 : eventForce("say I'm going to miss Albert. He was one "
                             "of the good ones!");
                          break;
                case 13 : eventForce("get albert");
                          ccounter = 1;
                          break;
                default : eventPrint("error in Pascal");
                          break;
            }
        }

        //case 3: albert is a corpse and waltin is not present
        if( base_name(albert) == LIB_CORPSE
            && !present("waltin")
            && member_array("waltin kelly", npcees) == -1
          ) 
        {
            pcounter++;
            switch (pcounter)
            {
                case 1 : eventForce("look");
                         break;
                case 2 : eventForce("frown");
                         break;
                case 3 : eventForce("say What the hell happened here?");
                         break;
                case 4 : eventForce("sigh");
                         break;
                case 5 : eventForce("say back to the drawing board.");
                         break;
                case 6 : eventForce("say I'm going to miss Albert. He was one "
                             "of the good ones!");
                case 7 : eventForce("get albert");
                          ccounter = 1;
                          break;
                default : eventPrint("error in pascal");
                          break;
            }
        } 
    
        //case 4: waltin is a corpse, albert is present, not a corpse, and not in combat
        if( base_name(waltin) == LIB_CORPSE
            && present("albert")
            && base_name(albert) != LIB_CORPSE 
            && !albert->GetInCombat()
          ) 
        {
            pcounter++;
            switch (pcounter) 
            {
                case 1 : if(albert->GetCurrentEnemy()) pcounter = 2;
                         else eventForce("look");
                         break;
                case 2 : eventForce("say Another false alarm! Damn pranksters!");
                         break;
                case 3 : eventForce("frown");
                         break;
                case 4 : eventForce("ask albert what happened to Waltin?");
                         break;
                case 5 : if(!albert->GetCurrentEnemy())
                         {
                         albert->eventForce("say It happened so fast I didn't have time to "
                             "even get in the fight!");
                              pcounter = 9;
                         }
                         else {
                         albert->eventForce("say we were fighting "
                             +capitalize(albert->GetCurrentEnemy()->GetKeyName()));
                         }
                         break;
                case 6 : if(albert->GetCurrentEnemy() 
                            && !present(albert->GetCurrentEnemy()->GetKeyName()) ) 
                             eventForce("say Well, it looks like you chased "
                                 +capitalize(albert->GetCurrentEnemy()->GetKeyName())+" %^BOLD%^%^CYAN%^off. " 
                                 "Good job. Let me know if they come back to the area%^RESET%^");
                         break;
                case 7 : pranksters = get_livings(env);
                         if( albert->GetCurrentEnemy() 
                             && present(albert->GetCurrentEnemy()->GetKeyName())
                             && member_array(albert->GetCurrentEnemy()->GetKeyName(), pranksters) == -1 ) 
                         {
                             eventForce("say Hey Albert, looks like "
                                 +capitalize(albert->GetCurrentEnemy()->GetKeyName())+ 
                                 " won't be bothering anyone anymore!");
                             eventForce("cackle");
                         }
                         break;
                case 8 : eventForce("get "+albert->GetCurrentEnemy()->GetKeyName());
                         break;
                case 9 : eventForce("put corpse on table");
                         if( albert->GetCurrentEnemy() == waltin->GetCurrentEnemy() ) 
                             {
                               albert->SetCurrentEnemy();
                               waltin->SetCurrentEnemy();
                             }
                             else  albert->SetCurrentEnemy();
                         break;
                case 10 : eventForce("look at sky");
                          break;
                case 11 : eventForce("say Waltin, you were a good man, but only a mediocre " 
                             "gate guard.");
                          break;
                case 12 : eventForce("get waltin");
                          ccounter = 1;
                default : eventPrint("error in Pascal");
                          break; 
            }
        }
    
        //case 5: waltin is a corpse and albert is not present
        if( base_name(waltin) == LIB_CORPSE
            && !present("albert")
            && member_array("albert derby", npcees) == -1
          ) 
        {
            pcounter++;
            switch (pcounter)
            {
                case 1 : eventForce("look");
                         break;
                case 2 : eventForce("frown");
                         break;
                case 3 : eventForce("say What the hell happened here?");
                         break;
                case 4 : eventForce("sigh");
                         break;
                case 5 : eventForce("say whelp, back to the drawing board!");
                         break;
                case 6 : eventForce("look at sky");
                         break;
                case 7 : eventForce("say Mister Kelley, you were a good man, " 
                              "but only a mediocre gate guard.");
                         break;
                case 8 : eventForce("get waltin");
                         ccounter = 1;  
                         break;
                default : eventPrint("error in pascal");
                          break;   
            }
        }
        //case 6: albert is present, not a corpse, not in combat, and waltin is not present
        if( present("albert")
            && base_name(albert) != LIB_CORPSE 
            && !albert->GetInCombat()
            && member_array("waltin kelley", npcees) == -1
          )
        {
            pcounter++;
            switch (pcounter) 
            {
                case 1 :eventForce("look");
                         break;
                case 2 : eventForce("frown");
                         break;
                case 3 : eventForce("say albert, what happened to waltin?");
                         break; 
                case 4 : albert->eventForce("say humph! Been wondering myself, actually.");
                         break;
                case 5 : eventForce("say yeah, he's kind of a slacker...");
                         if( !albert->GetCurrentEnemy() ) pcounter = 8;
                         break; 
                case 6 : pranksters = get_livings(env);
                         if( albert->GetCurrentEnemy() 
                             && present(albert->GetCurrentEnemy()->GetKeyName())
                             && member_array(albert->GetCurrentEnemy()->GetKeyName(), pranksters) == -1 ) 
                         {
                             eventForce("say Hey Albert, looks like "
                                 +capitalize(albert->GetCurrentEnemy()->GetKeyName())+ 
                                 " won't be bothering anyone anymore!");
                             eventForce("cackle");
                         }
                         break;
                case 7 : eventForce("get "+albert->GetCurrentEnemy()->GetKeyName());
                         break;
                case 8 : eventForce("put corpse on table");
                         albert->SetCurrentEnemy();
                         break;
                case 9 : eventForce("unlock gate with key");
                         eventForce("open gate");
                         break;
                case 10 : eventForce("go north");
                          break; 
                default : eventPrint("error in Pascal");
                          break;
            }         
        }

        //case 7: waltin is present, not a corpse, not in combat, and albert is not present
        if( present("waltin")
            && base_name(waltin) != LIB_CORPSE 
            && !waltin->GetInCombat()
            && member_array("albert derby", npcees) == -1
          ) 
        {
            pcounter++;
            switch (pcounter) 
            {
                case 1 : eventForce("look");
                         break;
                case 2 : eventForce("frown");
                         break;
                case 3 : eventForce("say waltin, what happened to albert?");
                         break; 
                case 4 : waltin->eventForce("shrug");
                         break;
                case 5 : waltin->eventForce("say i don't know.");
                         break; 
                case 6 : eventForce("say could you even be less than useless?");
                         break;
                case 7 : eventForce("unlock gate with key");
                         eventForce("open gate");
                         break;
                case 8 : eventForce("go north");
                         break;
                default : eventPrint("error in pascal");
                          break;
            }         
        }
        
        //case 8: albert is not present and waltin is not present 
        if( !present("albert")
            && member_array("albert derby", npcees) == -1
            && !present("waltin")
            && member_array("waltin kelley", npcees) == -1
          )
        {
            pcounter++;
            switch (pcounter) 
            {
                case 1 : eventForce("look");
                         break;
                case 2 : eventForce("frown");
                         break;
                case 3 : eventForce("say where the heck are my guards?");
                         break; 
                case 4 : eventForce("say i need to find better recruits!");
                        break;
                case 5 : eventForce("unlock gate with key");
                         eventForce("open gate");
                         break;
                case 6 : eventForce("go north");
                         break; 
                default : eventPrint("error in pascal");
                          break;
            }         
        }
    
        //case 9: albert and waltin are corpses
        if( base_name(albert) == LIB_CORPSE 
            && base_name(waltin) == LIB_CORPSE
            
          )
        {
            pcounter++;
            switch (pcounter) 
            {
                case 1 : eventForce("look");
                         break;
                case 2 : eventForce("frown");
                         break;
                case 3 : tell_room(env,"%^BOLD%^CYAN%^Pierce Pascal slaps his forehead in "
                             "dismay!%^RESET%^",this_object());
                         break; 
                case 4 : eventForce("say by the hand of Balcor I shall slay your assailants!");
                         break;
                case 5 : eventForce("say I shall ask Henil the High Priest to pray for your souls.");
                         break;
                case 6 : eventForce("say the trash bin will have to be your final resting place.");
                         break;
                case 7 : eventForce("get waltin");
                         eventForce("get albert");
                         ccounter = 1;
                         break;
                default : eventPrint("error in pascal");
                          break;
            }
        }
    }   
}

void DisposeCorpse() {

    object env = environment();    

    if( env->GetShort() == "%^BOLD%^Outside the South Gates of the Village of Wyr%^RESET%^"
        && ccounter >= 1 ) 
    {
    ccounter++;
    switch (ccounter) 
        {
            case 2 : eventForce("say see you in the halls of Balcor!");
                     break;
            case 3 : eventForce("put corpse in trash");
                     eventForce("put corpse in trash");
                     break;
            case 4 : eventForce("unlock gate with key");
                     break;
            case 5 : eventForce("open gate");
                     break;
            case 6 : eventForce("go north");
                     break;
            default : eventForce("go north");
                      break;           
        }
    }
}    

void checkPlacement() {

    object env = environment();

    if( !this_object()->GetInCombat()
        && env->GetShort() != "%^BOLD%^Outside the Guardhouse%^RESET%^"
        && env->GetShort() != "%^BOLD%^Outside the South Gates of the Village of Wyr%^RESET%^") 
    { 
        eventForce("say I've got to get back to my post.");
        tell_room(environment(this_object()),"Pierce Pascal exits the room.", ({this_object()}));
        eventMove("/domains/etnar/wyr/wyr/room/rm_121");
        tell_room(environment(this_object()),"Pierce Pascal enters the room", ({this_object()}));
    }
}

void heart_beat(){
    ::heart_beat();
    checkPrank();
    Setpcounter();
    DisposeCorpse();
    CheckGate();
}
    
void init(){
    ::init();
}
