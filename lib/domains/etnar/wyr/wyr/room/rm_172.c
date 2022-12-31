/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_ROOM;

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
        "west" : "/domains/etnar/wyr/wyr/room/rm_173",
        "southeast" : "/domains/etnar/wyr/wyr/room/rm_131",
        ] ));
}

void init(){
    ::init();
    add_action("rent","rent");
}

int rent(string str) {
    object ob = this_player();
            
    if(!str || (str && str !="room")) {
        tell_player(this_player(), "\nRent what?\n");
        return 1;
    }
    if(str && str =="room") {
        if(this_player()->GetCurrency("gold") < 20) {
            tell_player(this_player(), "You don't have enough gold! Rooms are 20 gold pieces.\n");
            return 1;
        }
    foreach(string key in this_player()->GetRents()) { 
        if(key == "The Cyclops Inn") {
            tell_player(this_player(), "You have already rented a room here! "
                "Don't you remember?\n");
            return 1;
        }
    }
    tell_player(this_player(), "Thank you. Enjoy your stay in the west room!\n");
    this_player()->AddCurrency("gold", -20);
    this_player()->SetRent( ([ "The Cyclops Inn" : ({"/domains/etnar/wyr/wyr/room/rm_172",
        "/domains/etnar/wyr/wyr/room/rm_173",SEASONS_D->GetTime(),SEASONS_D->GetTime()+28800}) ]) );
    }
    return 1;
}      
