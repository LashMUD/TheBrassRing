/*    /lib/lib/props/rent.c
 *    based on the Dead Souls Mud library
 *    maintained by Cratylus http://ww.dead-souls.net
 *    
 *    Based on /lib/props/properties.c
 *    Created by Descartes of Borg 961222
 *    Version: @(#) properties.c 1.1@(#)
 *    Last modified: 96/12/22
 *    
 *    created and modified by lash (ccoker)
 *    for use in The Brass Ring mud
 *    last modified: 22/11/18 year/month/day
 *    
 *     EXAMPLE for using SetRent in a file:
 *     this_player()->SetRent( ([ "The Cyclops Inn" : ({"/domains/etnar/wyr/room/rm_172",
 *          "/domains/etnar/wyr/room/rm_173",SEASONS_D->GetTime(),SEASONS_D->GetTime()+28800}) ]) );
 *     
 *      NOTE: 28800 is one day in The Brass Ring mud
 */

#include <lib.h>
#include <daemons.h>

mapping Rent = ([]);
void CheckTimer();

mapping SetRent(mapping rent) {

    string place;
    string *setting;
    
    foreach(place, setting in rent) {
        
        Rent[place] = ([ "renting_room" : setting[0], "effective_room" : setting[1],
        "rent_time" : setting[2], "rent_end" : setting[3] ]);
    }
    return rent;
}

// returns entire mapping of Rent
mapping GetRentMap() {
    if(!Rent) Rent = ([]);
    return Rent;
}

//removes a rented "place" mapping
int RemoveRent(string place){
    if( !stringp(place) || !Rent[place] || undefinedp(Rent[place]) ){
        return 0;
    }
    else{
    map_delete(Rent, place);
    }
    return 1;
}

//returns all rented places in Rent
string *GetRents(){
    return keys(Rent);
}

//returns the "place" mapping in Rent
mixed GetRent(string place){
    if( !stringp(place) )
        return;
    if (Rent && Rent[place])
        return Rent[place];
}

//returns the renting room (usually a reception area of some sort)
mixed GetRentingRoom(string place){
    if( !stringp(place) || !Rent || !Rent[place])
        return;
    return Rent[place]["renting_room"];
}

//returns the room that should affect the player while renting (in) the room
mixed GetEffectiveRoom(string place){
    if( !stringp(place) || !Rent || !Rent[place])
        return;
    return Rent[place]["effective_room"];
}

// returns the time the room was rented
mixed GetRentTime(string place, int val){
    if( !stringp(place) || !Rent || !Rent[place])
        return; 
    return Rent[place]["rent_time"];
}

//returns the time the rent period ends
mixed GetRentEnd(string place, int val){
    if( !stringp(place) || !Rent || !Rent[place])
        return; 
    return Rent[place]["rent_end"];
}

void CheckTimer(){
    object ob = environment(this_player());
    string env = base_name(environment());
    string *str = this_player()->GetRents();
    int x, y, z;
   
    if(!sizeof(str)) {
        return;
    }
    
    for( x=0; x<sizeof(str); x++ ) {
        y = this_player()->GetRentEnd(str[x]);
        z = SEASONS_D->GetTime();
        
        //player gets something for the money they spent to rent the room
        foreach(string key in this_player()->GetRents(str[x])) {
            if( z < y && this_player()->GetSleeping() > 0 
                && (strcmp(env,  Rent[key]["effective_room"])) == 0) {
                this_player()->AddHP(5); 
            } 
            
            //let the player know their rent has run out at a rented location
            if( z >= y && this_player()->GetSleeping() >= 0 
                && (strcmp(env, Rent[key]["effective_room"])) != 0) {
                tell_player(this_player(), "\nYour rented room at "+key+
                    " has expired.\n");
                this_player()->RemoveRent(key);
            }
            
            //if the player is sleeping they are escorted to the renting room (reception)
            if( z >= y && this_player()->GetSleeping() > 0 
                && (strcmp(env,  Rent[key]["effective_room"])) == 0) {
                tell_player(this_player(), "\nYour rented room at "+key+
                    " has expired.");
                tell_player(this_player(), "You are aware of being hauled off "
                    "to the reception by someone.\n");
                tell_room(env, "\nThe bouncer picks up "+
                    this_player()->GetShort()+" and hauls "
                    "them to the reception room.\n", this_player());
            this_player()->eventMove(Rent[key]["renting_room"]);
            this_player()->RemoveRent(key);
            }
            
            //if the player is not sleeping they are still escorted to the renting room (reception)
            else if( z >= y && (strcmp(env,  Rent[key]["effective_room"])) == 0) {
                tell_player(this_player(), "\nYour rented room at "+key+
                    " has expired.");
                tell_player(this_player(), "The bouncer escorts you to the reception.\n");
                tell_room(env, "\nThe bouncer boisterously hauls "+
                    this_player()->GetShort()+" to the reception room.\n", this_player());
                this_player()->eventMove(Rent[key]["renting_room"]);
                this_player()->RemoveRent(key);
            }
        }
    }   
}       
