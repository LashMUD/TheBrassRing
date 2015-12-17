#include <lib.h>

inherit LIB_DAEMON;

varargs mixed cmd(string args) {
    string *str;
    string fac;
    int x, y;
    int z = 0;
    object ob = this_player();

    if(!sizeof(ob->GetFacs())){
        write("You belong to no factions.");
        return 1;
    }

    str = ({"\nYou have been noted by the following factions:\n"});
    foreach(string key in ob->GetFacs()){
        fac = capitalize(key);
        x = ob->GetFactionLevel(key);
        y = ob->GetReputationLevel(key);
        if(!x){
            str += ({ sprintf("%s\n   Reputation %d\n",fac,y) });
        }else
        if(!x  && y<=0){
            str += ({ sprintf("%s\n   Level %d\n",fac,x) });
        }else
        if(x>=1 && y<=0){
            str += ({ sprintf("%s\n   Level %d\n",fac,x) });
        }
        else{
            str += ({ sprintf("%s\n   Level %d\n   Reputation  %d \n",fac,x,y) });
        }
        z++;
    }
    str += ({"A total of "+z+" factions have interest in you\n"});
    this_player()->eventPage(str, "factions");
    return 1;
}

string GetHelp(){
    return ("Syntax: factions\n\n"
            "This command lists any factions you may be associated with.\n");
}
