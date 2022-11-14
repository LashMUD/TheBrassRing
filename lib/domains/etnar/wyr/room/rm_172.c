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

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Reception%^RESET%^");
    SetLong("   This is the reception where you can rent a room for your conveniance. "
            "As of now this is just a placeholder.");
    SetItems( ([ 
        ] ));
    SetInventory(([
        ]) );
    SetActionsMap( ([ 
        ]) );
    SetExits( ([
        "west" : "/domains/etnar/wyr/room/rm_173",
        "southwest" : "/domains/etnar/wyr/room/rm_131",
        ] ));
    set_heart_beat(1);
}

void heart_beat(){
    ::heart_beat();
}

void init(){
    ::init();
    add_action("rent","rent");
}

int rent(string str) {
    object ob = this_object();
    int x = SEASONS_D->GetTime() + 20;
    //x+=20; // 1 mud day 28800
    
    if(!str || (str && str !="room")) {
        tell_player(this_player(), "\nRent what?\n");
        return 1;
    }
    if(str && str =="room") {
        if(this_player()->GetCurrency("gold") < 20) {
            tell_player(this_player(), "You don't have enough gold! Rooms are 20 gold pieces.\n");
            return 1;
        }
    if(this_player()->GetProperty("Cyclops Inn") ) { 
        tell_player(this_player(), "You have already rented a room here! Don't you remember?\n");
        return 1;
    }
    tell_player(this_player(), "Thank you. Enjoy!\n");
    this_player()->AddCurrency("gold", -20);
    this_player()->AddProperty("Cyclops Inn", x);
    }
    return 1;
}       
