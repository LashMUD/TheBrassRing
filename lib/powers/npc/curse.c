/*    /lib/powers/npc/curse.c
 *    based on the Dead Souls mud library
 *    maintained by Cratylus http:www.dead-souls.net
 *
 *    created by lash (ccoker) for use in
 *    The Brass Ring mud
 *     - functions to put a "curse" on an object
 *    last modified: 20/05/20
 */

class curse{
    object who;
    int duration;
    string *skills;
    string *stats;
    string endmsg;
}

    class curse Cursed = 0;

int GetCursed(){
    if(Cursed){
        return 1;
    }
    else{
        return 0;
    }
}

varargs mixed eventCurse(object ob, int time, int degree, string *skil,
  string *stat, string afmsg, string ndmsg)
{

    if(ob->GetCursed()) return 0;    
    
    Cursed = new(class curse);
    Cursed->who = ob;
    Cursed->duration = time;
    Cursed->skills = skil;
    Cursed->stats = stat;
    Cursed->endmsg = ndmsg;
    
    if(sizeof(skil)){
        foreach(string sk in skil){
            ob->AddSkillBonus(sk, degree);
        }
    if(sizeof(stat))
        foreach(string st in stat){
            ob->AddStatBonus(st, degree);
         }
    }
    if(stringp(afmsg)){
        tell_player(ob, afmsg);
    }
    else{
        ob->eventPrint("\nYou feel very uncomfortable.\n");
    }
    return 1; 
}

int RemoveCurse(){

    object ob = Cursed->who;
    string *skills = Cursed->skills;
    string *stats = Cursed->stats;
    string endmsg = Cursed->endmsg;
    
    Cursed = 0;

    if(sizeof(skills)){
        foreach(string skill in skills){
            ob->RemoveSkillBonus(skill);
         }
    if(sizeof(stats))
        foreach(string stat in stats){
            ob->RemoveStatBonus(stat);
         }
    }
    if(stringp(endmsg)){
        tell_player(ob, endmsg);
    }
    else{
        tell_player(ob, "\nYou feel well again.\n");
    }
    return 1;
}
