/*    /lib/lib/lvs/level.c 
 *    based on the Dead Souls mud library
 *    maintained by cratylus http://www,dead-souls.net
 * 
 *    modified by lash (ccoker) for use in 
 *    The Brass Ring mud
 *     - added this header
 *     - added functions for skill advancement system
 *     - refined skill based adjustments for level changes
 *    last modified: 23/01/09 year/month/day
 */ 


#include <lib.h>
#include <daemons.h>

int collect_moduli(int mod, int *range){
    int ret, neg, big, little, i;
    ret = 0;
    if(range[0] > range[1]){
        neg = 1;
        big = range[0];
        little = range[1];
    }
    else {
        big = range[1];
        little = range[0];
    }

    for(i = big; i > little; i--){
        if(!(i  % mod)) ret++;
    }

    if(neg){
        ret = ret - (ret*2);
    }
    return ret;
}

varargs int ChangeLevel(int i){
    mapping skills, stats, moduli = ([]);
    int current_level, desired_level, delta_level, cs;
    object subject = this_object();

    current_level = subject->GetLevel();

    if(!i || i < 1){ 
        desired_level = current_level + 1;
    }
    else{
        desired_level = i;
    }

    for(i = 1; i < 5; i++){
        moduli[i] = collect_moduli(i, ({ current_level, desired_level }) );
    }

    skills = subject->GetSkillsMap();
    stats = subject->GetStatsMap();

    if(XP_ADVANCE){
    foreach(mixed key, mixed val in skills){
        if(skills[key]["class"] > 3) skills[key]["class"] = 4;
        subject->SetSkill(key, 
                skills[key]["level"] + moduli[skills[key]["class"]],
                skills[key]["class"]);
        }
        foreach(mixed key, mixed val in stats){
            if(stats[key]["class"] > 3) stats[key]["class"] = 4;
            subject->SetStat(key,
                    stats[key]["level"] + moduli[stats[key]["class"]],
                    stats[key]["class"]);
        }
        subject->SetLevel(desired_level);

        if(interactive() && find_object(INSTANCES_D)){
            INSTANCES_D->SendWhoUpdate(this_object()->GetKeyName());
        }
    }
    /* add customization points for level increase*/
    if(SKILL_ADVANCE && (desired_level > current_level)) {
        delta_level = desired_level - current_level;
        for(i = 0; i < delta_level; i++) {
           subject->AddCustomizationPoints();
        }
        
        subject->SetLevel(desired_level);
        if(interactive() && find_object(INSTANCES_D)){
            INSTANCES_D->SendWhoUpdate(this_object()->GetKeyName());
        }
    }
    /*decreasing stats for level loss*/
    if(SKILL_ADVANCE && (desired_level < current_level)) {
        foreach(mixed key, mixed val in stats){
            if(stats[key]["class"] > 3) stats[key]["class"] = 4;
            subject->SetStat(key,
                    stats[key]["level"] + moduli[stats[key]["class"]],
                    stats[key]["class"]);
        }
        /* if the player foolishly retained custom stat points
         * over levels they lose half as a penalty
         */  
        if(subject->GetCustomStats() >= 2) {
            cs = subject->GetCustomStats()/2;
            subject->AddCustomizationPoints(-cs);
        }            
        subject->SetLevel(desired_level);
        if(interactive() && find_object(INSTANCES_D)){
            INSTANCES_D->SendWhoUpdate(this_object()->GetKeyName());
        }
    }
    return 1;
}
