/* 
 * /domains/etnar/wyr/npc/fostaine_pyre.c.
 * The bard in the village of Wyr
 * based on The Dead Souls Mud Library
 * maintained by Cratylus http://www.dead-souls.net
 * for use in The Brass Ring Mud
 * this file works in conjunction with /domains/etnar/wyr/room/rm_174
 * where this object is created and moved into that room
 * at a specific time - this MUD is based on a 24 hour day cycle
 * 
 * last edited by lash 22/11/9 year/month/day
 */

#include <lib.h>
#include <objects.h>
#include <daemons.h>

inherit LIB_SENTIENT;

void time();
int *time_of_day;
int hour;
int minutes;

static string open_path =  "IL.";
static string close_path = "sbtwlf.";
static string path;

static int index;
static int movebool = 0;

int CheckEnv() {
    object env = environment();
    object *npc_env = all_inventory(this_object());
    time_of_day = SEASONS_D->GetMudTime();
    hour = time_of_day[0];
    minutes = time_of_day[1];

    //not supposed to be out of the lounge unless in combat
    if( env && env->GetShort() != "%^BOLD%^The Lounge%^RESET%^" &&
    this_object()->GetInCombat() == 0 ) {
        this_object()->eventForce("say Oh no!, I must get back to The Lounge!");
        tell_room(environment(this_object()),"Fostaine Pyre exits the room.", ({this_object()}));
        this_object()->eventMove("/domains/etnar/wyr/room/rm_174");
        tell_room(environment(this_object()),"%^BOLD%^%^GREEN%^Fostaine Pyre%^RESET%^ the " 
            "bard has arrived!", ({this_object()}));
    }
    //only supposed to be out between 6:00 pm and midnight
    if( hour < 18 || hour == 24 ) 
        this_object()->eventMove( load_object("/domains/etnar/room/furnace") );
}   

/* the commented sections here are left to show
   what happens when the code in /lib/body.c has a GetInComabat()
   function that has a SetAutoStand(1);. the body.c for this mudlib
   changed this behavior to use this_object()->eventForce("stand"); instead
   in /lib/body.c
*/ 
int CheckWielded() {
   object *env = all_inventory(environment());
   time_of_day = SEASONS_D->GetMudTime();
   hour = time_of_day[0];
   minutes = time_of_day[1];   
   
   if(!this_object()->GetInCombat()){
       /*foreach(object enemy in env) {
             if(this_object()->GetCurrentEnemy() != env){
                 this_object()->SetAutostand(0);
             }
          }*/    
       this_object()->eventForce("unwield lute");
       if(this_object()->GetAutoStand() == 0 && !this_object()->GetInCombat()) 
           this_object()->eventForce("sit on stool");
   }
   return 1;
}

int WieldLute() {
    if( present("lute",this_object()) && this_object()->GetInCombat() ){ 
        this_object()->eventForce("wield lute");
    }
    else{
        new("/domains/etnar/wyr/weap/fostaine_lute")->eventMove(this_object());
        tell_room(environment(),"%^BOLD%^%^RED%^Fostaine roars WHO STOLE MY LUTE! "
            "It's a good thing I carry a spare! Fostaine reaches into his oversized "
            "cloak and grabs a spare lute.%^RESET%^");
        this_object()->eventForce("wield lute");
    }
    return 1;
}

static void create() {
    sentient::create();
    SetKeyName("Fostaine Pyre");
    SetId(({"bard", "player"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("Fostaine Pyre");
    SetLong("Fostaine is a portly man with long curly hair sporting a thin moustache and goatee. "
        "He usually carries a lute which he uses to entertain the clientel at the Cyclops Inn."
    );
    SetClass("bard");
    SetRace("human");
    SetLevel(21);
    SetGender("male");
    SetCanBite(0);
    SetMorality(1500);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetPolyglot(1);
    SetAutoStand(0);
    SetWimpy(30);
    SetInventory( ([
        "/domains/etnar/wyr/weap/fostaine_lute" : "-1",
    ] ));
    SetActionsMap( ([
        ( ( :CheckWielded(): ) ) : 100,
        ( ( :CheckEnv(): ) ) : 100,
    ]) );
    SetCombatAction(100, ({ (: WieldLute :) }) ); 
    SetFactions( ([ "House Pyre" : ({20,20}),
                    "Fighters Guild" : ({20, 20}),
    ]) );    
    SetUnique(1);
    set_heart_beat(1);
}

void actions(){
   if(movebool == 0){
       return;
   }
   if( (hour == 18 &&  minutes >= 0) || (hour == 23 && minutes >= 58) ){
        switch (path[index]) {
           case 'I' : this_object()->eventForce("inventory");
                      break;
           case 'L' : tell_room(environment(this_object()), "%^BOLD%^%^GREEN%^Fostaine Pyre%^RESET%^ pulls an "
                      "expensive looking lute out of his oversized cloak.", ({this_object()}));
                      break;
           case 's' : this_object()->SetAutoStand(1);
                      this_object()->eventForce("stand");
                      break;
           case 'b' : this_object()->eventForce("bow");
                      break;
           case 't' : this_object()->eventForce("say Thank you all for coming to my little show! " 
                      "I must be on my way now."); 
                      break;
           case 'w' : this_object()->eventForce("wink");
                      break;
           case 'l' : this_object()->eventForce("put lute in bin");
                      break;
           case 'f' : tell_room(environment(this_object()),"With a flourish %^BOLD%^%^GREEN%^Fostaine "
                      "Pyre leaves the room.");
                      this_object()->eventDestruct();
                      break;
           case '.' : movebool=0;
                      break;
           default :  tell_room(environment(this_object()),"WHOOPS! Bug in fostaine pyre - please report",
                      ({this_object()}));
                      break;
        }
        index++;    
    }
}

void time(){
    time_of_day = SEASONS_D->GetMudTime();
    hour = time_of_day[0];
    minutes = time_of_day[1];

    if (hour == 18 && minutes == 0) {
        movebool = 1;
        path = open_path;
        index = 0;
    }
    if (hour == 23 && minutes == 58) {
        movebool = 1;
        path = close_path;
        index = 0;
    }
    actions();
}

void heart_beat(){
    ::heart_beat();
    time();
}

void init(){
    ::init();
}


