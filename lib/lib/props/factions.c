/*    /lib/props/factions.c
 *    From the Dead Souls Mud Library
 *    The factions property
 *    Based on /lib/props/properties.c
 *    Created by Descartes of Borg 961222
 *    Version: @(#) properties.c 1.1@(#)
 *    Last modified: 96/12/22
 *    ccoker modified for factions: 2015/12/08
 *
 */

#include <lib.h>
#include <daemons.h>

mapping Factions    = ([]);

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

/*function below mainly for NPC use*/
mapping SetFactions(mapping facs){
    if(sizeof(Factions)) return (Factions[facs] += facs);
    else return (Factions = facs);
}

/*called from /lib/genetics.c*/
int RepCountDown(){
    string *str = keys(Factions);
    int x;
    for(x=0; x<sizeof(str); x++){
        if(this_player()->GetReputationLevel(str[x]) <= 0
           && this_player()->GetFactionLevel(str[x])  >= 0
           && SEASONS_D->GetTime() >= this_player()->GetReputationTimer(str[x])+864000 )
           this_player()->AddReputation(str[x], 0);
        if (SEASONS_D->GetTime() >= this_player()->GetReputationTimer(str[x])+864000)
           this_player()->AddReputation(str[x], -1);
        if (this_player()->GetFactionLevel(str[x])  >= 0
            && SEASONS_D->GetTime() >= this_player()->GetFactionTimer(str[x])+9216000)
            this_player()->AddFactionLevel(str[x], -1);
            
    }  
}
