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
void time();

int hour, minutes;
int *time_of_day;
object mon;

static void create() {
    sentient::create();
    SetKeyName("Fostaine Pyre");
    SetId(({"bard", "player"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("Fostaine Pyre");
    SetLong("Fostaine is a portly man with long curly hair sporting a thin moustache and goatee. "
        //"He usually carries a lute which he uses to entertain the clientel at the Cyclops Inn."
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
    SetFactions( ([ "House Pyre" : ({20,20}),
                    "Fighters Guild" : ({20, 20}),
    ]) );
    set_heart_beat(1);
}

void time(){
    object mon;
    object env = environment();
    time_of_day = SEASONS_D->GetMudTime();
    hour = time_of_day[0];
    minutes = time_of_day[1];

    if ((hour >= 0  && minutes >= 1)/* && ((hour <= 23  & minutes <= 59))*/ ){
        
        if(env && env->GetShort() == "%^BOLD%^The Lounge%^RESET%^") {
                        
            if((!this_object()->GetInCombat()) && (present("lute",this_object()))) {
                this_object()->eventForce("unwield lute");
                this_object()->eventForce("sit on stool");
                return;
            }    
            if((this_object()->GetInCombat()) && (present("lute",this_object()))) {
                this_object()->eventForce("wield lute");
                return;
            }
            if((this_object()->GetInCombat()) && (!present("lute",this_object()))) {
                new("/domains/etnar/wyr/weap/fostaine_lute")->eventMove(this_object());
                tell_room(environment(),"%^BOLD%^%^RED%^Fostaine grabs a trusty lute "
                    "from his oversized cloak and wields it with terrible fury!%^RESET%^");
                this_object()->eventForce("say Attack a Nobleman, will you?");
                this_object()->eventForce("wield lute");
                return;
            }
        }
    }
    if(env && env->GetShort() != "%^BOLD%^The Lounge%^RESET%^") {
        this_object()->eventForce("say Oh no!, I must get back to The Lounge!"); 
        this_object()->eventMove("/domains/etnar/wyr/room/rm_174");
    }
}   

void heart_beat(){
    ::heart_beat();
    if( !this_object()->GetInCombat()) SetAutoStand(0);
    time();
}
void init(){
    ::init();
}


