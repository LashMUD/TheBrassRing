#include <lib.h>
#include <damage_types.h>

inherit LIB_MEAL;

mapping Skills = ([]);
mapping Stats = ([]);
mapping Points = ([]);
string brl = " ";
int brt = 0;

int Duration;

void create(){
    meal::create();
}

mapping SetStats(mapping arg){
    Stats = copy(arg);
    return copy(Stats);
}

mapping GetStats(){
    return copy(Stats);
}

mapping SetSkills(mapping arg){
    Skills = copy(arg);
    return copy(Skills);
}

mapping GetSkills(){
    return copy(Skills);
}

mapping SetPoints(mapping arg){
    Points = copy(arg);
    return copy(Points);
}

mapping GetPoints(){
    return copy(Points);
}

int SetDuration(int i){
    Duration = i;
    return Duration;
}

int GetDuration(){
    return Duration;
}

varargs string SetBonusResistance(int type, string level){
    brt = type;
    brl = level;
    tell_player("lash", "brt is "+brt+" brl is "+brl+" in potion\n");
}

mixed eventDrink(object who){
    object ob=new(LIB_BONUS);
    ob->SetPoints(Points); 
    ob->SetStats(Stats); 
    ob->SetSkills(Skills); 
    ob->SetBonusDuration(Duration);
    ob->SetBonusResistance(brt,brl);
    ob->eventMove(who);
    return meal::eventDrink(who);
}

mixed eventEat(object who){
    object ob=new(LIB_BONUS);
    ob->SetPoints(Points);
    ob->SetStats(Stats);
    ob->SetSkills(Skills);
    ob->SetBonusDuration(Duration);
    ob->SetBonusResistance(brt,brl);
    ob->eventMove(who);
    return meal::eventEat(who);
}
