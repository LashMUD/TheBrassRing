/* /domains/etnar/wyr/wyr/etc/pierce_pascal_functions.c
 * functions for pierce pascal
 * based on The Dead Souls Mud Library
 * maintained by Cratylus http://www.dead-souls.net
 * for use in The Brass Ring Mud
 * last edited by lash 22/12/19 year/month/day
 */

void Setpcounter();
void checkCombat();
void checkPrank();
void CheckGate();
int DisposeCorpse();
void checkPlacement();
void GoHelp();
void FillMembers();
object *pranksters = ({});
string *members = ({});
void eventNews(); //added later
int pcounter = 0; //prank counter
int hcounter = 0; //help counter
int hour, minutes;
int *time_of_day;
string msg = ""; //added later

//reset pcounter to 0
void Setpcounter() {
    
    object env = environment();

    if( env 
        && env->GetShort() != "%^BOLD%^Outside the South Gates of the Village of Wyr%^RESET%^"
        && !this_object()->GetInCombat() ) { 
            pcounter = 0;
            //tell_player("lash", "pcounter in Setpcounter() is "+pcounter);
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
                //tell_player("lash", "\nthing is "+thing->GetKeyName()+"\n");
                enemy = thing->GetCurrentEnemy();
                break;
            }
        }
        this_object()->eventForce("say attacking my guards, eh? I'll show you!");
        this_object()->eventForce("kill "+enemy->GetKeyName());
    }
}

mixed GetPranksters() {
    return pranksters;
}

mixed GetPinv() {
    return pinv;
}

int SetPcounter(int x) {
    if(!x) return;
    else pcounter = x;
}

void checkPrank()
{

    object albert;
    object waltin;
    object env = environment();
    //pranksters = get_livings(env); forces pierces routines to quit
    pranksters = all_inventory(env);
    pinv = all_inventory(this_object());
        
    //tell_player("lash", "pcounter start of checkPrank() is "+pcounter);
    if(pcounter > 15) DisposeCorpse();
    if( sizeof(pranksters) )
    {
        foreach(object thing in pranksters)
        {
            if( thing->GetKeyName() == "albert derby" )
            {
                thing->eventMove
                albert = thing;
                //tell_player("lash", "\nthing is "+thing->GetKeyName()+"\n");
            }
            if( thing->GetKeyName() == "waltin kelley" )
            {
                waltin = thing;
                //tell_player("lash", "\nthing is "+thing->GetKeyName()+"\n");
            }
        }
    }
    
    
    //pierce is in an environment, in the correct room, and not in combat
    if( env 
        && env->GetShort() == "%^BOLD%^Outside the South Gates of the Village of Wyr%^RESET%^" 
        && !this_object()->GetInCombat() ) 
    {
        //albert and waltin are present and not corpses
        if( present("albert")
            && present("waltin")
            && base_name(albert) != LIB_CORPSE 
            && base_name(waltin) != LIB_CORPSE 
            && !albert->GetInCombat() 
            && !waltin->GetInCombat() )
            
        { 
            //tell_player("lash", "pcounter in checkPrank() before addition and both present is "+pcounter);
            pcounter++;
            //tell_player("lash", "pcounter in checkPrank() after addition and both present is "+pcounter);
            switch (pcounter) 
            {
                case 1 : if( waltin->GetCurrentEnemy() != 0 || albert->GetCurrentEnemy() != 0)
                         pcounter+=4;
                         break;
                case 2 : this_object()->eventForce("look");
                         DisposeCorpse();
                         break;
                case 3 : this_object()->eventForce("say Another false alarm! Damn pranksters!");
                         break;
                case 4 : this_object()->eventForce("frown");
                         break;
                case 5 : this_object()->eventForce("go north");
                         break;
                case 6 : this_object()->eventForce("say Waltin! Keep on looking for "
                                 +capitalize(waltin->GetCurrentEnemy()->GetKeyName()) );
                         this_object()->eventForce("say you know Albert, keep on looking for "
                                 +capitalize(albert->GetCurrentEnemy()->GetKeyName()) );
                         break;
                case 7 : if(present(albert->GetCurrentEnemy()->GetKeyName()) 
                            || present(waltin->GetCurrentEnemy()->GetKeyName())) 
                         {
                             eventForce("say they're here now!");
                             eventForce( "kill "+albert->GetCurrentEnemy()->GetKeyName() );
                         }
                         break;
                case 8 : this_object()->eventForce("go north");
                         break;
                default : eventPrint("error in pascal");
                          break;
            }             
        }
       
        //albert is a corpse and waltin is not a corpse and present and not in combat
        if( base_name(albert) == LIB_CORPSE
            && base_name(waltin) != LIB_CORPSE
            && present("waltin")
            && !waltin->GetInCombat() ) 
            
        {  
            //tell_player("lash","pcounter in checkPrank() before addition and albert dead is "+pcounter);
            pcounter++;
            tell_player("lash","pcounter in checkPrank() after addition and albert dead is "+pcounter);
            switch (pcounter)
            {
                case 1 : this_object()->eventForce("look");
                         break;
                case 2 : this_object()->eventForce("frown");
                         break;
                case 3 : this_object()->eventForce("say Oh my goodness! Waltin, what happened "
                             "to Albert?");
                         break;
                case 4 : if(!waltin->GetCurrentEnemy())
                         waltin->eventForce("shrug");
                         if(waltin->GetCurrentEnemy())
                         pcounter = 6;
                         break;
                case 5 : if(!waltin->GetCurrentEnemy())                        
                         this_object()->eventForce("shake");
                         break;
                case 6 : if(!waltin->GetCurrentEnemy())
                         this_object()->eventForce("say I don't know if you're ready to be "
                             "a gate guard just yet");
                          pcounter = 10;
                          break;
                case 7 : if(waltin->GetCurrentEnemy())
                         waltin->eventForce("say I think Albert got killed by "
                                 +waltin->GetCurrentEnemy()->GetShort());
                         break;
                case 8 : if(waltin->GetCurrentEnemy())
                         this_object()->eventForce("say Well keep an eye out for this "
                             +waltin->GetCurrentEnemy()->GetShort());
                         break;
                case 9 : if( present(waltin->GetCurrentEnemy()->GetKeyName())) 
                         eventForce("say they're here now!");
                         break;
                case 10 : if( present(waltin->GetCurrentEnemy()->GetKeyName()))
                          eventForce( "kill "+albert->GetCurrentEnemy()->GetKeyName() );
                          break;
                case 11 : eventForce("say I'm going to miss Albert. He was one "
                             "of the good ones!");
                          pcounter = 15;
                          break;
                case 12 : eventForce("get corpse");
                          pcounter = 15;
                          break;
                default : eventPrint("error in pascal");
                          break;
            }
        }

        //albert is a corpse and waltin is not present
        if( base_name(albert) == LIB_CORPSE
            && !present("waltin") ) 
        {  
            /*tell_player("lash","pcounter in checkPrank() before addition and albert dead "
                  "and waltin not present is "+pcounter);*/
            pcounter++;
            /*tell_player("lash","pcounter in checkPrank() after addition and albert dead "
                  "and waltin not present is "+pcounter);*/
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
                          pcounter = 15;
                          break;
                default : eventPrint("error in pascal");
                          break;
            }
        } 
    
        //waltin is a corpse and albert is not a corpse and present and not in combat
        if( base_name(waltin) == LIB_CORPSE
            && base_name(albert) != LIB_CORPSE 
            && present("albert")
            && !albert->GetInCombat() ) 
               
        {
            //tell_player("lash","pcounter in checkPrank() before addition and waltin dead is "+pcounter);
            pcounter++;
            tell_player("lash","pcounter in checkPrank() after addition and waltin dead is "+pcounter);
            switch (pcounter) 
            {
                case 1 : this_object()->eventForce("look");
                         break;
                case 2 : this_object()->eventForce("say Another false alarm! Damn pranksters!");
                         break;
                case 3 : this_object()->eventForce("frown");
                         break;
                case 4 : eventForce("ask albert what happened to Waltin?");
                         break;
                case 5 : if(!albert->GetCurrentEnemy())
                         {
                             albert->eventForce("say It happened so fast I didn't have time to "
                                 "even get in the fight!");
                          }
                         else {
                             albert->eventForce("say we were fighting "
                                 +albert->GetCurrentEnemy()->GetShort());
                         }
                         if( present(albert->GetCurrentEnemy()->GetKeyName())) 
                         {
                             eventForce("say they're here now!");
                             eventForce( "kill "+albert->GetCurrentEnemy()->GetKeyName() );
                         }
                         break;
                case 6 : if( !present(albert->GetCurrentEnemy()) ) 
                         {
                             this_object()->eventForce("say Well, it looks like you chased "
                                 +albert->GetCurrentEnemy()->GetShort()+" %^BOLD%^%^CYAN%^off. " 
                                 "Good job. Let me know if they come back to the area%^RESET%^");
                         }
                         break;
                case 7 : eventForce("look at sky");
                         break;
                case 8 : eventForce("say Mister Kelley, you were a good man, " 
                              "but only a mediocre gate guard.");
                         break;
                case 9 : eventForce("get waltin");
                         pcounter = 15;
                         break;
                default : eventPrint("error in pascal");
                          break; 
            }
        }
    
        //waltin is a corpse and albert is not present
        if( base_name(waltin) == LIB_CORPSE
            && !present("albert") ) 
        {  
            //tell_player("lash","pcounter in checkPrank() before addition and waltin dead "
            //      "and albert not present is "+pcounter);
            pcounter++;
            tell_player("lash","pcounter in checkPrank() after addition and waltin dead "
                  "and waltin not present is "+pcounter);
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
                case 6 : eventForce("look at sky");
                         break;
                case 7 : eventForce("say Mister Kelley, you were a good man, " 
                              "but only a mediocre gate guard.");
                         eventForce("get waltin");
                         pcounter = 15;  
                         break;
                default : eventPrint("error in pascal");
                          break;   
            }
        }
    
        //albert and waltin are not present and not corpses
        if( !present("albert")
            && !present("waltin") 
            && base_name( waltin ) != LIB_CORPSE
            && base_name( albert) != LIB_CORPSE  )
        {
            //tell_player("lash","pcounter in checkPrank() before addition and both absent is "+pcounter);
            pcounter++;
            //tell_player("lash","pcounter in checkPrank() after addition and both absent is "+pcounter);
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
                case 5 : eventForce("go north");
                        break;
                default : eventPrint("error in pascal");
                          break;
            }         
        }
    
        //albert and waltin are corpses
        if( base_name(albert) == LIB_CORPSE 
            &&  base_name(waltin) == LIB_CORPSE )
              
        {
            //tell_player("lash","pcounter in checkPrank() before addition and both dead is "+pcounter);
            pcounter++;
            tell_player("lash","pcounter in checkPrank() after addition and both dead is "+pcounter);
            switch (pcounter) 
            {
                case 1 : this_object()->eventForce("look");
                         break;
                case 2 : this_object()->eventForce("frown");
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
                         //eventForce("put corpses in trash");
                         //eventForce("go north");
                         pcounter = 15;
                         break;
                default : eventPrint("error in pascal");
                          break;
            }
        }
    }   
}    

void checkPlacement() {

    object env = environment();

    if( env && !this_object()->GetInCombat()
            && env->GetShort() != "%^BOLD%^Outside the Guardhouse%^RESET%^"
            && env->GetShort() != "%^BOLD%^Outside the South Gates of the Village of Wyr%^RESET%^") 
    { 
        this_object()->eventForce("say I've got to get back to my post.");
        tell_room(environment(this_object()),"Pierce Pascal exits.", ({this_object()}));
        this_object()->eventMove("/domains/etnar/wyr/wyr/room/rm_121");
        tell_room(environment(this_object()),"Pierce Pascal enters.", ({this_object()}));
    }
}

//used a call_out in conjunction with SetTalkResponses()
void GoHelp() {

    object env = environment();
     
    if( env && env->GetShort() == "%^BOLD%^Outside the Guardhouse%^RESET%^"
        && !this_object()->GetInCombat() )
    {     
        hcounter++;
        //tell_player("lash", "hcounter in GoHelp before addition is "+hcounter);
        switch (hcounter) 
        {
            case 1 : this_object()->eventForce("say Not again! We're a peaceful village!");
                     break;
            case 2 : this_object()->eventForce("yell %^BOLD%^%^CYAN%^You better be gone before "
                         "I get there%^RESET%^!");
                     break;
            case 3 : this_object()->eventForce("unlock gate with key");
                     break;
            case 4 : this_object()->eventForce("open gate");
                     break;
            case 5 : this_object()->eventForce("go south");
                     checkCombat();
                     break;
        }
        
        if( hcounter > 5 ) {
            hcounter = 0;
        }
        //tell_player("lash", "hcounter in GoHelp after addition is "+hcounter);
        call_out((: GoHelp :), 2); 
    }
    
}
void DisposeCorpse() {

    object albert;
    object waltin;
    object env = environment();    

    //tell_player("lash", "in DisposeCorpse");
    if( env && env->GetShort() == "%^BOLD%^Outside the South Gates of the Village of Wyr%^RESET%^"
        && pcounter >=15 ) 
    {
    //tell_player("lash", "pcounter in DisposeCorpse before addition is "+pcounter);
    pcounter++;
    tell_player("lash", "pcounter in DisposeCorpse after addition is "+pcounter);
        switch (pcounter) 
        {
            case 16 : eventForce("get corpse");
                      break;
            case 17 : eventForce("put corpse in trash");
                      break;
            case 18 : eventForce("put corpse in trash");
                      break;
            case 19 : eventForce("say see you in the halls of Balcor!");
                      break;
            case 20 : eventForce("go north");
                      break;
        }
    }
}

void heart_beat(){
    ::heart_beat();
    checkPrank();
    Setpcounter();
    DisposeCorpse();
}
