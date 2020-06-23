/*    from the Dead Souls mud library
 *    maintained by Cratylus http://www,dead-souls.net 
 *
 *    modified by lash (ccoker) for use in
 *    The Brass Ring mud
 *     - added SetResistance() function
 *     - added this header
 *     - added mappimgs for functionality
 *    last modified: 20/06/02
 */

#include <lib.h>
#include <damage_types.h>

inherit LIB_MEAL;

mapping Skills = ([]);
mapping Stats = ([]);
mapping Resistance = ([]);
mapping Points = ([]);
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

mapping SetResistance(mapping arg){
    Resistance = copy(arg);
    return copy(Resistance);
}

mapping GetResistance(){
    return copy(Resistance);
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

mixed eventDrink(object who){
    object ob=new(LIB_BONUS);
    ob->SetPoints(Points); 
    ob->SetStats(Stats); 
    ob->SetSkills(Skills);
    ob->SetResistance(Resistance);
    ob->SetBonusDuration(Duration);
    ob->eventMove(who);
    return meal::eventDrink(who);
}

mixed eventEat(object who){
    object ob=new(LIB_BONUS);
    ob->SetPoints(Points);
    ob->SetStats(Stats);
    ob->SetSkills(Skills);
    ob->SetResistance(Resistance);
    ob->SetBonusDuration(Duration);
    ob->eventMove(who);
    return meal::eventEat(who);
}
