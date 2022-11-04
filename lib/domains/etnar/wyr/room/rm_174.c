// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>
#include <daemons.h>

inherit LIB_ROOM;

void time();

int hour, minutes;
int *time_of_day;
object mon; 

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Lounge%^RESET%^");
    SetLong("   The lounge is smaller and more comfortable than the common room "
               "but still spacious. There are a few tables and chairs around. "
               "In the back wall behind a stage, there is a small fireplace with " 
               "a sitting stool nearby.");
    SetItems( ([ 
                "stage" : 
                    "The stage is a rough wooden platform about a foot above floor "
                    "level.",
                "fireplace" : 
                    "The fireplace is small enough to emit enough warmth for any "
                    "players on the stage.",
        ] ));
    SetInventory(([
        "/domains/etnar/wyr/obj/bard_stool" : 1,
        ]) );
    SetActionsMap( ([ 
                "%^RED%^The fire crackles merrily.%^RESET%^" : 5,
        ]) );
    SetExits( ([
        "northeast" : "/domains/etnar/wyr/room/rm_131",
        ] ));
    set_heart_beat(1);
}

void time(){
    object mon;
    object *env = get_livings(this_object());
    time_of_day = SEASONS_D->GetMudTime();
    hour = time_of_day[0];
    minutes = time_of_day[1];
                    
    if ((hour >= 18  && minutes >= 0) && (hour <=23 && minutes <=59) ) {
        if(present("bard")) {
            if(sizeof(env)){
                foreach(object thing in env){
                    if(thing->GetShort() == "Fostaine Pyre"){
                        mon = thing;
                        break;
                    }
                }
            }
            if(!mon->GetInCombat()) {
                mon->eventForce("sit on stool");
                return;
            }
        }
        if(!present("bard")) {
            mon = new("domains/etnar/wyr/npc/fostaine_pyre");
            mon->eventMove(this_object());
            eventPrint("%^BOLD%^%^GREEN%^Fostaine Pyre%^RESET%^ the bard has arrived!");
            mon->eventForce("sit on stool");
        }
    }
    else if (hour == 0 & minutes == 0) {
        if(!sizeof(env)) {
            return;
        }
        if(sizeof(env)){
            foreach(object thing in env){
                if(thing->GetShort() == "Fostaine Pyre"){
                    mon = thing;
                    break;
                }
            }
        }
    mon->eventForce("stand");
    mon->eventForce("bow");
    mon->eventForce("say Thank you all for coming to my little show! I must be on my way now.");
    mon->eventForce("wink");
    eventPrint("With a flourish %^BOLD%^%^GREEN%^Fostaine Pyre%^RESET%^ leaves the room...");
    mon->eventDestruct();
    }
}
        
void heart_beat(){
    ::heart_beat();
    time();
}


void init(){
   ::init();
}
