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

mixed AddFaction(string fac, int flev, string faclev, string levtime, 
                 string rep, string reptime, int ltime, int rlev, int rtime){
    if(!flev) flev = 0;
    if(!ltime) ltime = 0;
    if(!rlev) rlev =0;
    if(!rtime) rtime =0;
    if( !stringp(fac) ) return 0;
    if( Factions[fac] ){
        flev += Factions[fac]["faction level"];
        ltime = SEASONS_D->GetTime();
    }
    else {
        Factions[fac] = flev;
        ltime = SEASONS_D->GetTime();
    }
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

mapping GetFactions(){
    if(!Factions) Factions = ([]);
    return Factions;
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

mixed GetFactionLevel(string fac){
    if( !stringp(fac) || !Factions || !Factions[fac]) return 0;
    return Factions[fac]["faction level"];
}

mixed GetFactionTimer(string fac){
    if( !stringp(fac) || !Factions || !Factions[fac]) return 0;
    return Factions[fac]["level_timer"];
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

/*function below mainly for NPC use*/
mapping SetFactions(mapping facs){
    if(sizeof(Factions)) return (Factions[facs] += facs);
    else return (Factions = facs);
}
