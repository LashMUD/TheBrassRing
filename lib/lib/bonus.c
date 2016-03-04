/* /lib/bonus.c
 * from the dead souls mudlib http://www.dead-souls.net
 *
 * modified by Lash (ccoker) for use in The Brass Ring
 * bug fix: bonus object wasn't being destructed
 * 2014-12-12
 * added functionality for setting resistance
 * 2015-12-28
 */

#include <lib.h>
#include ROOMS_H
#include <damage_types.h>

inherit LIB_ITEM;

int SetBonuses();

mapping Skills = ([]);
mapping Stats = ([]);
mapping Points = ([]);

int Duration = 15;
string bonusname;
string brl = " ";
int brt = 0;

void create(){
    item::create();
    AddSave( ({ "Skills", "Stats", "Points", "Duration", "bonusname" }) );
    SetInvis(1);
    SetId("bonus_object");
    SetShort("bonus");
    SetLong("A bonus");
}

void init(){
    item::init();
    set_heart_beat(1);
    if(environment(this_object()) && living(environment(this_object()))) 
        SetBonuses();
}

void heart_beat(){
    if(Duration) Duration--;
    /* modified by Lash - bonus object wasn't being destructed */
    else this_object()->eventDestruct(); 
    /* end mod */
}

mapping SetStats(mapping arg){
    Stats = copy(arg);
    if(environment(this_object()) && living(environment(this_object())))
        SetBonuses();
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

int SetBonusDuration(int i){
    Duration = i;
}

int AddBonusDuration(int i){
    Duration += i;
    if(Duration < 0) Duration = 0;
    return Duration;
}

int GetBonusDuration(){
    return Duration;
}

int SetBonuses(){
    object env = environment();
    if(!env || ! living(env)) return 0;
    if(sizeof(Stats))
        foreach(string key, int val in Stats){
            env->AddStatBonus(key, val);
        }
    if(sizeof(Skills))
        foreach(string key, int val in Skills){
            env->AddSkillBonus(key, val);
        }
    if(sizeof(Points))
        foreach(string key, int val in Points){
            switch(key){
                case "HP" : env->AddHP(val);break;
                case "XP" : env->AddExperiencePoints(val);break;
                case "SP" : env->AddStaminaPoints(val);break;
                case "MP" : env->AddMagicPoints(val);break;
                case "poison" : env->AddPoison(val);break;
                case "caffeine" : env->AddCaffeine(val);break;
                case "food" : env->AddFood(val);break;
                case "drink" : env->AddDrink(val);break;
                default : break;
            }
        }
    if(sizeof(brt) && sizeof(brl)) env->SetResistance(brt,brl);
         
    return 1;
}

int RemoveBonuses(){
    object env = environment();
    if(!env || ! living(env)) return 0;
    if(sizeof(Stats))
        foreach(string key, int val in Stats){
            env->RemoveStatBonus(key);
        }
    if(sizeof(Skills))
        foreach(string key, int val in Skills){
            env->RemoveSkillBonus(key);
        }
    if(sizeof(brt) && sizeof(brl)) env->SetResistance(brt,"none");
        
    return 1;
}

int eventDestruct(){
    if(!valid_event(previous_object(), this_object())) return 0;
    RemoveBonuses();
    this_object()->eventMove(ROOM_FURNACE);
    return ::eventDestruct();
}

string GetBonusName(){
    return bonusname;
}

string SetBonusName(string name){
    return bonusname = name;
}

varargs string SetBonusResistance(int type, string level){
    brt = type;
    brl = level;
}

mixed CanGet(object who){ return 0; }
mixed CanGive(object who){ return 0; }
mixed CanSell(object who){ return 0; }
mixed CanDrop(object who){ return 0; }
mixed CanPut(object who){ return 0; }
