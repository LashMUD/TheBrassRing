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
 *    last modified: 15-12-08
 */

#include <lib.h>
#include <daemons.h>

mapping Factions    = ([]);
void CheckTimer();

mixed AddFaction(string fac){

    int flev = 1;
    int ltime = SEASONS_D->GetTime();
    int rlev = 1;
    int rtime = SEASONS_D->GetTime();
    
    if( !stringp(fac) ) return 0;
    if( Factions[fac] ) return 0;
    Factions[fac] = (["faction level":flev,"level_timer":ltime,"reputation":rlev,
                      "reputation_timer": rtime ]);
    return Factions[fac];
}

mixed GetFaction(string fac){
    if( !stringp(fac) ) return 0;
    if(Factions && Factions[fac])
        return Factions[fac];
    else return 0;
}

int RemoveFaction(string fac){
    if( !stringp(fac) ) return 0;
    if(undefinedp(Factions[fac]) ){
        return 1;
    }
    else {
        map_delete(Factions, fac);
    }
    return !Factions[fac];
}

mixed AddFactionLevel(string fac, int val){
    if( !stringp(fac) || !Factions[fac] ) return 0;
     if( Factions[fac] ){
        val +=Factions[fac]["faction level"];
    }
    else {
        Factions[fac]["faction level"] = val;
    }
    Factions[fac]["faction level"] = val;
    Factions[fac]["level_timer"] = SEASONS_D->GetTime();
    return Factions[fac];
}

mixed GetFactionLevel(string fac){
    if( !stringp(fac) || !Factions || !Factions[fac]) return 0;
    return Factions[fac]["faction level"];
}

mixed GetFactionTimer(string fac){
    if( !stringp(fac) || !Factions || !Factions[fac]) return 0;
    return Factions[fac]["level_timer"];
}

mixed AddFactionTimer(string fac, int val){
    if( !stringp(fac) || !Factions[fac] ) return 0;
     if( Factions[fac] ){
        val +=Factions[fac]["level_timer"];
    }
    else {
        Factions[fac]["level_timer"] = val;
    }
    Factions[fac]["level_timer"] = val;
    return Factions[fac];
}

mixed AddReputation(string fac, int val){
    if( !stringp(fac) || !Factions[fac] ) return 0;
     if( Factions[fac] ){
        val +=Factions[fac]["reputation"];
    }
    else {
        Factions[fac]["reputation"] = val;
    }
    Factions[fac]["reputation"] = val;
    Factions[fac]["reputation_timer"] = SEASONS_D->GetTime();
    return Factions[fac];
}

mixed GetReputationLevel(string fac){
    if( !stringp(fac) || !Factions || !Factions[fac]) return 0;
    return Factions[fac]["reputation"];
}

mixed GetReputationTimer(string fac){
    if( !stringp(fac) || !Factions || !Factions[fac]) return 0;
    return Factions[fac]["reputation_timer"];
}

mixed AddReputationTimer(string fac, int val){
    if( !stringp(fac) || !Factions[fac] ) return 0;
     if( Factions[fac] ){
        val +=Factions[fac]["reputation_timer"];
    }
    else {
        Factions[fac]["reputation_timer"] = val;
    }
    Factions[fac]["reputation_timer"] = val;
    return Factions[fac];
}

mapping GetFactions(){
    if(!Factions) Factions = ([]);
    return Factions;
}

string *GetFacs(){
    return keys(Factions);
}

void CheckTimer(){
    string *str = keys(Factions);
    int x, y;
    y = HOUR_LENGTH * DAY_LENGTH * 30;

    if(inherits(LIB_NPC, this_object())) return;
    if(!str) return;
        
    for(x=0; x<sizeof(str); x++){
        if(this_player()->GetReputationLevel(str[x]) <= 0
           && this_player()->GetFactionLevel(str[x])  >= 0
           && SEASONS_D->GetTime() >= (this_player()->GetReputationTimer(str[x])+y))
           this_player()->AddReputation(str[x], 0);
        if (SEASONS_D->GetTime() >= (this_player()->GetReputationTimer(str[x])+y))
           this_player()->AddReputation(str[x], -1);
        if (this_player()->GetFactionLevel(str[x])  >= 0
            && SEASONS_D->GetTime() >= (this_player()->GetFactionTimer(str[x])+SEASONS_D->GetYearLength()))
            this_player()->AddFactionLevel(str[x], -1);
            
    }
}
