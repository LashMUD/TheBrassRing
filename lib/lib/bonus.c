/*    /lib/bonus.c
 *    from the Dead Souls mud library
 *    maintained by Cratylus http://www.dead-souls.net
 *
 *    modified by Lash (ccoker) for use in The Brass Ring
 *     - bug fix: bonus object wasn't being destructed
 *     - 2014-12-12
 *     -added functionality for setting resistances
 *     - 15/12/28
 *     - changed functionality to use mappings
 *     last modified: 20/06/02
 */

#include <lib.h>
#include ROOMS_H
#include <damage_types.h>

inherit LIB_ITEM;

int SetBonuses();

mapping Skills = ([]);
mapping Stats = ([]);
mapping Points = ([]);
mapping Resistance = ([]);
int Duration = 15;
string bonusname;
object whom;

void create(){
    item::create();
    AddSave( ({ "Skills", "Stats", "Points", "Duration", "Resistance", "bonusname" }) );
    SetInvis(0);
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
    if(Duration){
        Duration--;
    }
    else {
        this_object()->eventDestruct();
    }
    if(whom && environment() != whom){
        this_object()->eventDestruct();
    }
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
    whom = environment();
    if(!whom || ! living(whom)) return 0;
    if(sizeof(Stats))
        foreach(string key, int val in Stats){
            whom->AddStatBonus(key, val);
        }
    if(sizeof(Skills))
        foreach(string key, int val in Skills){
            whom->AddSkillBonus(key, val);
        }
    if(sizeof(Resistance))
        foreach(int val, string key in Resistance){
            switch(key){
                case "none" : whom->SetResistance(val, "none"); break;
                case "low" : whom->SetResistance(val, "low"); break; 
                case "medium" : whom->SetResistance(val, "medium"); break;
                case "high" : whom->SetResistance(val, "high"); break;
                case "immune" : whom->SetResistance(val, "immune"); break;
                default : break;
            }
        }
    if(sizeof(Points))
        foreach(string key, int val in Points){
            switch(key){
                case "HP" : whom->AddHP(val);break;
                case "XP" : whom->AddExperiencePoints(val);break;
                case "SP" : whom->AddStaminaPoints(val);break;
                case "MP" : whom->AddMagicPoints(val);break;
                case "poison" : whom->AddPoison(val);break;
                case "caffeine" : whom->AddCaffeine(val);break;
                case "food" : whom->AddFood(val);break;
                case "drink" : whom->AddDrink(val);break;
                default : break;
            }
        }
    return 1;    
}

int RemoveBonuses(){
    
    if(!whom && environment()) whom = environment();
    if(!whom || !living(whom)) return 0;
    if(sizeof(Stats))
        foreach(string key, int val in Stats){
            whom->RemoveStatBonus(key);
        }
    if(sizeof(Skills))
        foreach(string key, int val in Skills){
            whom->RemoveSkillBonus(key);
        }
    if(sizeof(Resistance))
        foreach(int val, string key in Resistance){
            switch(key){
                case "none" : whom->SetResistance(val, "none"); break;
                case "low" : whom->SetResistance(val, "none"); break; 
                case "medium" : whom->SetResistance(val, "none"); break;
                case "high" : whom->SetResistance(val, "none"); break;
                case "immune" : whom->SetResistance(val, "none"); break;
                default : break;
            }
        }
    return 1;
}

int eventMove(mixed dest){
    int ret;
    if(whom && environment() == whom){
        RemoveBonuses();
        whom = 0;
    }
    ret = ::eventMove(dest);
    return ret;
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

mixed CanGet(object who){ return 0; }
mixed CanGive(object who){ return 0; }
mixed CanSell(object who){ return 0; }
mixed CanDrop(object who){ return 0; }
mixed CanPut(object who){ return 0; }
