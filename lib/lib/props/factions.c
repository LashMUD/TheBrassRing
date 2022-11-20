/*    /lib/lib/props/factions.c
 *    based on the Dead Souls Mud library
 *    maintained by Cratylus http://ww.dead-souls.net
 *    
 *    Based on /lib/props/properties.c
 *    Created by Descartes of Borg 961222
 *    Version: @(#) properties.c 1.1@(#)
 *    Last modified: 96/12/22
 *    
 *    created and modifed by lash (ccoker)
 *    for use in The Brass Ring mud
 *    last modified: 22/11/19 year/month/day
 */

#include <lib.h>
#include <daemons.h>

mapping Factions = ([]);
void CheckTimer();

//for npc's
mapping SetFactions(mapping fac){

    string faction;
    int *stat;
    
    foreach(faction, stat in fac){
        Factions[faction] = ([ "faction_level":stat[0],
            "reputation":stat[1] ]);
       }
    return fac;
}

//for players
mixed AddFactions(mapping fac){

    int flev = 1;
    int ltime = SEASONS_D->GetTime();
    int rlev = 1;
    int rtime = SEASONS_D->GetTime();
    string faction;

    if(!arrayp(fac)){
        return ("String(s) must be quoted in array format: AddFactions(({\"a\", \"b\", etc}))");
    }

    foreach(faction in fac){
        if(Factions[faction]) continue;
        Factions[faction] = (["faction_level":flev,"level_timer":ltime,
            "reputation":rlev,"reputation_timer": rtime ]);
    }
    return 1;
}
//returns mapping of Factions
mapping GetFactionsMap(){
    if(!Factions) Factions = ([]);
    return Factions;
}
//removes faction "string" from Factions mapping
int RemoveFaction(string fac){
    if( !stringp(fac) || !Factions[fac] || undefinedp(Factions[fac]) ){
        return 0;
    }
    else{
      map_delete(Factions, fac);
    }
    return 1;
}
//returns array of factions in Factions mapping
string *GetFacs(){
    return keys(Factions);
}
//returns the faction mapping of "string" faction in Factions mapping
mixed GetFaction(string fac){
    if( !stringp(fac) )
        return;
    if (Factions && Factions[fac])
        return Factions[fac];
}
//returns the faction level of "string" faction in Factions mapping
mixed GetFactionLevel(string fac){
    if( !stringp(fac) || !Factions || !Factions[fac])
        return;
    return Factions[fac]["faction_level"];
}
//changes the faction level of "string" faction in Factions mapping by val
mixed AddFactionLevel(string fac, int val){
    if( !stringp(fac) || !Factions[fac] ) 
        return;
    Factions[fac]["faction_level"] += val;
    Factions[fac]["level_timer"] = SEASONS_D->GetTime();
    return Factions[fac]["faction_level"];
}
//adds val to the faction level in the "string" faction in Factions mapping
mixed SetFactionLevel(string fac, int val){
    if( !stringp(fac) || !Factions[fac] ) 
        return;
    Factions[fac]["faction_level"] = val;
    Factions[fac]["level_timer"] = SEASONS_D->GetTime();
    return Factions[fac]["faction_level"];
}
//returns the faction timestamp set in "string" faction in Factions mapping 
mixed GetFactionTimer(string fac){
    if( !stringp(fac) || !Factions || !Factions[fac])
        return;
    return Factions[fac]["level_timer"];
}
//sets the faction "string" time stamp in the Factions mapping to the current time in the mud 
mixed AddFactionTimer(string fac, int val){
    if( !stringp(fac) || !Factions[fac] )
        return;
    Factions[fac]["level_timer"] += val;
    if( !val )
        Factions[fac]["level_timer"] = SEASONS_D->GetTime();
    return Factions[fac]["level_timer"];
}
//returns the reputation level of "string" faction in the Factions mapping 
mixed GetReputationLevel(string fac){
    if( !stringp(fac) || !Factions || !Factions[fac])
        return;
    return Factions[fac]["reputation"];
}
//adds val to the reputation level in the "string" faction in Factions mapping
mixed AddReputation(string fac, int val){
    if( !stringp(fac) || !Factions[fac] )
        return;
    Factions[fac]["reputation"] += val;
    Factions[fac]["reputation_timer"] = SEASONS_D->GetTime();
    return Factions[fac]["reputation"];
}
//sets the reputation level for "string" faction in Factions mapping
mixed SetReputation(string fac, int val){
    if( !stringp(fac) || !Factions[fac] )
        return;
    Factions[fac]["reputation"] = val;
    Factions[fac]["reputation_timer"] = SEASONS_D->GetTime();
    return Factions[fac]["reputation"];
}
//returns the reputation time stamp in "string" faction in the Factions mapping
mixed GetReputationTimer(string fac){
    if( !stringp(fac) || !Factions || !Factions[fac])
        return;
    return Factions[fac]["reputation_timer"];
}
//sets the time stamp for "string" faction in the Factions mapping to the current time in the mud 
mixed AddReputationTimer(string fac, int val){
    if( !stringp(fac) || !Factions[fac] )
        return;
    Factions[fac]["reputation_timer"] += val;
    if( !val )
        Factions[fac]["reputation_timer"] = SEASONS_D->GetTime();
    return Factions[fac]["reputation_timer"];
}
//the following should be a daemon
void CheckTimer(){
    string *str = keys(Factions);
    int x, y;
    y = HOUR_LENGTH * DAY_LENGTH * 30;

    if(inherits(LIB_NPC, this_object())) return;
    if(!str) return;
        
    for(x=0; x<sizeof(str); x++){
        
        //check reputation every 30 days, if no interaction with faction drop reputation by 1
        if (SEASONS_D->GetTime() >= (this_player()->GetReputationTimer(str[x])+y)) {
           this_player()->AddReputation(str[x], -1);
        }
        //reputation level is between -10 and 10
        if( this_player()->GetReputationLevel(str[x]) <= -10 ) {
            this_player()->SetReputation(str[x], -10);
        }
        
        if( this_player()->GetReputationLevel(str[x]) >= 10 )
            this_player()->SetReputation(str[x], 10);
        
        /*check every year, if no interaction with faction for a mudyear drop faction level by 1.
          if 0 kick out of faction*/          
        if (this_player()->GetFactionLevel(str[x])  >= 0
            && SEASONS_D->GetTime() >= (this_player()->GetFactionTimer(str[x])+
                SEASONS_D->GetYearLength())) {
            this_player()->AddFactionLevel(str[x], -1);
        }
        //faction level is 1 to 10
        if( this_player()->GetFactionLevel(str[x]) >= 10 ) 
            this_player()->SetFactionLevel(str[x], 10);
        //kick the bum out for not participating in a faction in a timely manner
        foreach(string faction in str) {
            if( this_player()->GetFactionLevel(str[x]) <= 0 ) {
                tell_player(this_player(), "\nYou have been derelict in fullfilling your duties "
                    "to "+faction+" and have been kicked out of the faction!");
                this_player()->RemoveFaction(faction);
            }
        }
    }
}
