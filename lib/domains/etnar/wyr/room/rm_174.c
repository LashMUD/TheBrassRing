/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

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
        "/domains/etnar/wyr/obj/trash" : 1,
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

    time_of_day = SEASONS_D->GetMudTime();
    hour = time_of_day[0];
    minutes = time_of_day[1];
                    
    if( (hour >= 18 && minutes >= 0) && uptime() > 0 && (hour <= 23 && minutes <= 58) ) {
        if(present("bard")) return;
        if(!present("bard")) {
            mon = new("domains/etnar/wyr/npc/fostaine/fostaine_pyre");
            mon->eventMove(this_object());
            eventPrint("%^BOLD%^%^GREEN%^Fostaine Pyre%^RESET%^ the bard has arrived!");
            return;
        }
    }
}
void heart_beat(){
    ::heart_beat();
    time();
}

void init(){
   ::init();
}
