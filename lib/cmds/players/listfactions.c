/*    /lib/cmds/players/listfactions.c
 *
 *    a command for players to list
 *    the factions to which they belong
 *    based on the Dead Souls mud library
 *    maintained by Cratylus http:www.dead-souls.net
 * 
 *    created by lash (ccoker)
 *    for use in the The Brass Ring mud
 *    last modified 22/12/10 year/month/day
 */

#include <lib.h>

inherit LIB_DAEMON;

varargs mixed cmd() {
    string *str;
    string fac;
    int x, y;
    int z = 0;
    object ob = this_player();

    if(!sizeof(ob->GetFacs())){
        write("You belong to no factions.");
        return 1;
    }
    if(sizeof(ob->GetFacs()) > 1) {  
        str = ({"\nYou have been noted by the following factions:\n"});
        } else {
        str = ({"\nYou have been noted by the following faction:\n"});
        }
    foreach(string key in ob->GetFacs()){
        fac = capitalize(key);
        x = ob->GetFactionLevel(key);
        y = ob->GetReputationLevel(key);
        
        str += ({ sprintf("%s\n   Level       %d\n   Reputation  %d \n",fac,x,y) });
        
        z++;
    }
    if(sizeof(ob->GetFacs()) > 1) {  
        str += ({"A total of "+z+" factions have interest in you\n"});
        }
    else {
        str += ({"A total of "+z+" faction has interest in you\n"});
    }
    this_player()->eventPage(str, "factions");
    return 1;
}

string GetHelp(){
    return ("Syntax: listfactions\n\n"
            "This command lists any factions you may be associated with.\n");
}
