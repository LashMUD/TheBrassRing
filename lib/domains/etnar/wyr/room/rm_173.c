/* Modified by Lash (Christopher Coker) for use with:
 * The Dead Souls Mud Library version 2 and above
 * developed by Cratylus
 * http://www.dead-souls.net
 * this file creates the Fostaine Pyre object at a specific time
 * this MUD uses a 24 hr day cycle
 * last edited by lash 22/11/9 year/month/day
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
    SetShort("%^BOLD%^The Inn Room%^RESET%^");
    SetLong("   There are bedrolls and desks with chairs. "
            "As of now this is just a placeholder.");
    SetItems( ([ 
        ] ));
    SetInventory(([
        ]) );
    SetActionsMap( ([ 
        ]) );
    SetExits( ([
        "east" : "/domains/etnar/wyr/room/rm_172",
        ] ));
    set_heart_beat(1);
}

void heart_beat(){
    ::heart_beat();
}

void init(){
   ::init();
}
