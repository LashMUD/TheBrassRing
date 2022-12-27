// Based on Diku MUD Alfa.  Program and Concept created by
// Sebastian Hammer, Michael Seifert, Hans Henrik Staerfeldt,
// Tom Madsen, and Katja Nyboe.
// http://www.dikumud.com
//
// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>
#include <daemons.h>

inherit LIB_ROOM;

int ReadSign();

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("The Reception");
    SetLong("  You are standing in the reception. The staircase leads down to the\n"+
        "entrance hall. There is a small sign on the counter.");
    SetItems ( ([
        "sign" : "Rooms are expensive but good! You may:\n\n"+
                 "   rent room - rooms are 50 gold pieces for a day.\n"
                 "               You will get fast healing when you\n"
                 "               sleep in the room to the east.\n",
        "down" : "You see the entrance hall.",
        ]) );
    SetRead ( ([
        ({"sign", "small", "small sign"}) : (:ReadSign:)
        ]) );    
    SetExits( ([
        "down" : "/domains/diku-alfa/room/30.zon/rm_3006",
        "east" : "/domains/diku-alfa/room/30.zon/rm_3008_1",
        ]) );
    SetInventory( ([
        "/domains/diku-alfa/room/30.zon/npc/3005_receptionist" : 1,
        ]) );
}

mixed ReadSign(){
    return (mixed)this_player()->eventPage("/domains/diku-alfa/room/30.zon/txt/reception.txt");
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
        if(this_player()->GetCurrency("gold") < 50) {
            tell_player(this_player(), "You don't have enough gold! Rooms are 50 gold pieces.\n");
            return 1;
        }
    foreach(string key in this_player()->GetRents()) { 
        if(key == "The Grunting Boar") {
            tell_player(this_player(), "You have already rented a room here! "
                "Don't you remember?\n");
            return 1;
        }
    }
    tell_player(this_player(), "Thank you. Enjoy your stay in the east room!\n");
    this_player()->AddCurrency("gold", -50);
    this_player()->SetRent( ([ "The Grunting Boar" : ({"/domains/diku-alfa/room/30.zon/rm_3008",
        "/domains/diku-alfa/room/30.zon/rm_3008_1",SEASONS_D->GetTime(),SEASONS_D->GetTime()+28800}) ]) );
    }
    return 1;
}      


/* Extra Information Original Diku Output 
Room name: The Reception, Of zone : 1. V-Number : 3008, R-number : 14
Sector type : Inside Special procedure : No
Room flags: INDOORS 
Description:
   You are standing in the reception.  The staircase leads down to the
entrance hall.  There is a small sign on the counter.

Extra description keywords(s): 
sign

------- Chars present -------
receptionist(MOB)

--------- Contents ---------

------- Exits defined -------
Direction down . Keyword : (null)
Description:
  You see the entrance hall.
Exit flag: NOBITS 
Key no: -1
To room (V-Number): 3006
*/
