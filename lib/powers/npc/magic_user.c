#include <lib.h>
#include <damage_types.h>
#include "/powers/npc/include/magic_user.h"
#include "/lib/include/genetics.h"


int SpellCombat(object ob){

    object env = environment(ob);
    object array *targets;

    int chance1, chance2, level;
    int q;

    chance1 = random(2);
    level = ob->GetLevel();
    
    if(ob && (!ob->GetInCombat() || !ob->GetCurrentEnemy())) return 0;
    
    targets = filter(get_livings(env), (: (!$1->GetInCombat() && !$1->GetSleeping()) || ($1->GetInCombat() && !$1->GetSleeping()) :));
    targets -= ({ob}); //removes 'caster' from targets so it is not a target
    
    if( sizeof(targets) < 1 ){
        return 0;
    }
    if(ob->GetLevel() > 13 && sizeof(targets) >=1){
        chance2 = random(7);
            if(chance1 == 0 && chance2 == 0){
                say(ob->GetShort()+" utters the words %^BOLD%^%^CYAN%^'dilan oso'%^RESET%^");
                sleep(ob, targets);
                return 1; 
            }
    }
    if(ob->GetLevel() > 12){
        chance2 = random(6); //6
            if(chance1 == 0 && chance2 == 0){
                say(ob->GetShort()+" utters the words %^BOLD%^%^CYAN%^'gharia miwi'%^RESET%^");
                curse(ob);
                return 1; 
            }
    }
    if(ob->GetLevel() > 7){
        chance2 = random(5); //5
            if(chance1 == 0 && chance2 == 0){
                say(ob->GetShort()+" utters the words %^BOLD%^%^CYAN%^'koholian dia'%^RESET%^");
                blindness(ob);
                return 1; 
            }
    }    
    if(ob->GetLevel() > 12 && ob->GetMorality() <= -200){
        chance2 = random(8);//8
            if(chance1 == 0 && chance2 == 0){
                say(ob->GetShort()+" utters the words %^BOLD%^%^CYAN%^'ib er dranker'%^RESET%^");
                energy_drain(ob);
                return 1; 
            }
    }
    if(chance1 == 0){
      switch (level) {
        case 1: case 2: case 3: case 4: 
            say(ob->GetShort()+" utters the words %^BOLD%^%^CYAN%^'hahili duvini'%^RESET%^");
            magic_missile(ob);
            break;
        case 5: case 6: case 7: case 8: 
            say(ob->GetShort()+" utters the words %^BOLD%^%^CYAN%^'grynt oef'%^RESET%^", ({ob}));
            burning_hands(ob);
            break;
        case 9: case 10: 
            say(ob->GetShort()+" utters the words %^BOLD%^%^CYAN%^'sjulk divi'%^RESET%^", ({ob}));
            lightning_bolt(ob);
            break;
        case 11: case 12: case 13: case 14:
            say(ob->GetShort()+" utters the words %^BOLD%^%^CYAN%^'nasson hof'%^RESET%^", ({ob}));
            colour_spray(ob);
            break;
        default:  
            say(ob->GetShort()+" utters the word %^BOLD%^%^CYAN%^'tuborg'%^RESET%^");
            fireball(ob);
            break;
      }
    return 1;
    }
}

void sleep(object ob, object array targets){
  
    object env = environment(ob);
    object victim;
    int save, s_throw;

    foreach(victim in targets){
        save = victim->GetMagicResistance();
        s_throw = random(99)+1;
            
        if (s_throw <= save){
            tell_room(env, "\n"+capitalize(victim->GetShort())+" resists "+ob->GetKeyName()+"'s magic attack!\n", ({ ob, victim }));
            tell_object(victim, "\n%^BOLD%^%^YELLOW%^You resist being put to sleep by "+ob->GetKeyName()+"!%^RESET%^\n");
            victim->eventTrainSkill("magic defense",save,s_throw,1);
            return;
        }
        else{
            tell_player(victim, "\n%^BOLD%^%^GREEN%^You feel very sleepy ..... zzzzzz%^RESET%^\n");
            tell_room(env, "\n"+capitalize(victim->GetKeyName())+" goes to sleep.\n", ({ob, victim}));
            victim->eventForce("sleep");
        }
    }
}    

void curse(object ob){

    object target = ob->GetCurrentEnemy();
    object env = environment(ob);
    int save = target->GetMagicResistance();
    int s_throw = random(99)+1;
   
    if(target->GetCursed()){
        return;
    }
    if(s_throw <= save){
        tell_room(env, "\n"+capitalize(target->GetShort())+" resists "+ob->GetKeyName()+"'s magic attack!\n", ({ ob, target }));
        tell_object(target, "\n%^BOLD%^%^YELLOW%^You resist the curse from "+ob->GetKeyName()+"!%^RESET%^\n");
        target->eventTrainSkill("magic defense",save,s_throw,1);
        return;
    }
    target->eventCurse(target, 100, -10, 
                      ({"blade attack", "blade defense", "blunt attack",      "blunt defense",
                        "multi-hand",   "multi-weapon",  "melee attack",      "melee defense",
                        "knife attack", "knife defense", "projectile attack", "projectile defense",
                        "magic attack", "magic defense", "conjuring",         "stealth",     
                        "faith",        "healing",       "stealing",          "detection",
                        "concealment",  "murder",
                           }),
                           ({"luck"}),
                           "\n%^BOLD%^%^GREEN%^You feel very uncomfortable.%^RESET%^\n",
                           "\n%^BOLD%^%^YELLOW%^You feel well again.%^RESET%^\n");
        tell_room(env, capitalize(target->GetShort())+" briefly reveals a red aura!", ({ob, target}));
}
    
void blindness(object ob){

    object target = ob->GetCurrentEnemy();
    object env = environment(ob);
    int save = target->GetMagicResistance();
    int s_throw = random(99)+1;

    if(target->GetBlind()){
    return;
    }
    if (s_throw <= save){
        tell_room(env, "\n"+capitalize(target->GetShort())+" resists "+ob->GetKeyName()+"'s magic attack!\n", ({ ob, target }));
        tell_object(target, "\n%^BOLD%^%^YELLOW%^You resist being blinded by "+ob->GetKeyName()+"!%^RESET%^\n");
        target->eventTrainSkill("magic defense",save,s_throw,1);
        return;
    }
    else{
    target->eventBlind(target, 100, ({"\n%^BOLD%^%^GREEN%^You have been blinded!%^RESET%^\n","\n%^BOLD%^%^YELLOW%^You can see again!%^RESET%^\n"}) );
    tell_room(env, "\n"+capitalize(target->GetShort())+" seems to be blinded!\n", ({ob, target}));
    }
}

void energy_drain(object ob){

    object target = ob->GetCurrentEnemy();
    object env = environment(ob);
    int range, xpdrain, dam;
    int save = target->GetMagicResistance();
    int s_throw = random(99)+1;

    if (s_throw <= save){
        tell_room(env, "\n"+capitalize(target->GetShort())+" resists "+ob->GetKeyName()+"'s magic attack!\n", ({ ob, target }));
        tell_object(target, "\n%^BOLD%^%^YELLOW%^You resist being drained by "+ob->GetKeyName()+"!%^RESET%^\n");
        target->eventTrainSkill("magic defense",save,s_throw,1);
        return;
    }
    else{
        range = (ob->GetLevel()) - (ob->GetLevel()/2);
        xpdrain = random(range) * 100; //in Diku it is 1000, but that is too much
        dam = random(9)+1;
        target->AddExperiencePoints(-xpdrain);
        target->AddMagicPoints(-(target->GetMagicPoints()/10));
        target->AddStaminaPoints(-(target->GetStaminaPoints()/10));
        target->eventReceiveDamage(ob, MAGIC, dam, 1,);
        tell_player(target, "\n%^BOLD%^%^GREEN%^Your life energy is drained!%^RESET%^\n");
        tell_room(env, "\n"+capitalize(ob->GetShort())+" drains "+target->GetKeyname()+" - what a waste of energy !\n", ({ob, target}));
        
    }
}

void magic_missile(object ob){

    object target = ob->GetCurrentEnemy();
    object env = environment(ob);
    int range, roll, dam;
    int level = ob->GetLevel();
    int *dam_each =  
        ({ 0, 3, 3, 4, 4, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
          6, 6, 6, 6, 6, 6, 6, 6, 6, 6
        });
    int save = target->GetMagicResistance();
    int s_throw = random(99)+1;
    
    if(ob->GetLevel() == 0 || ob->GetLevel() >= 31){
        return;
    }
    range = dam_each[level] - dam_each[level]/2;
    roll = random(range);
    dam = dam_each[level]/2 + roll;
    tell_player(target, "\n%^BOLD%^%^GREEN%^You stagger as a magic missile from "+capitalize(ob->GetKeyName())+" hits you.%^RESET%%^\n");
    tell_room(env, "\n"+capitalize(ob->GetKeyName())+" throws a magic missile at "+target->GetKeyName()+" who staggers under the blow\n", ({ob, target}));
    if (s_throw <= save){
        tell_room(env, "\n"+capitalize(target->GetShort())+" partially resists "+ob->GetKeyName()+"'s magic attack!\n", ({ ob, target }));
        tell_object(target, "\n%^BOLD%^%^YELLOW%^You partially resist the missile thrown by "+ob->GetKeyName()+"!%^RESET%^\n");
        dam = dam/2;
        target->eventTrainSkill("magic defense",save,s_throw,1);
    }
    target->eventReceiveDamage(ob, MAGIC | BLUNT, dam, 0, ({"torso"}));
}

void burning_hands(object ob){

    object target = ob->GetCurrentEnemy();
    object env = environment(ob);
    int range, roll, dam;
    int level = ob->GetLevel();
    int *dam_each =
        ({ 0, 0, 0, 0, 0, 19, 17, 20, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
          19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19
        });
    int save = target->GetMagicResistance();
    int s_throw = random(99)+1;

   if(ob->GetLevel() <= 4 || ob->GetLevel() >= 31){
        return;
    }    
    range = dam_each[level] - dam_each[level]/2;
    roll = random(range);
    dam = dam_each[level]/2 + roll;
    tell_player(target, "\n%^BOLD%^%^GREEN%^You cry out in pain as "+capitalize(ob->GetKeyName())+" burns you.%^RESET%^\n");
    tell_room(env, "\n"+capitalize(target->GetKeyName())+" cries out as "+capitalize(ob->GetKeyName())+" burns "+nominative(target)+".\n", ({ob, target}));
    if (s_throw <= save){
        tell_room(env, "\n"+capitalize(target->GetShort())+" partially resists "+ob->GetKeyName()+"'s magic attack!\n", ({ ob, target }));
        tell_object(target, "\n%^BOLD%^%^YELLOW%^You partially resist being burnt by "+ob->GetKeyName()+"'s hands!%^RESET%^\n");
        dam = dam/2;
        target->eventTrainSkill("magic defense",save,s_throw,1);
    }
  target->eventReceiveDamage(ob, MAGIC | HEAT, dam, 0, ({"torso"}));
}

void lightning_bolt (object ob){

    object target = ob->GetCurrentEnemy();
    object env = environment(ob);
    int range, roll, dam;
    int level = ob->GetLevel();
    int *dam_each =
        ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
           36, 36, 36, 36, 36, 36, 36, 38, 39, 46, 59
        });
    int save = target->GetMagicResistance();
    int s_throw = random(99)+1;

    if(ob->GetLevel() <= 8 || ob->GetLevel() >= 31){
        return;
    }    
    range = dam_each[level] - dam_each[level]/2;
    roll = random(range);
    dam = dam_each[level]/2 + roll;
    tell_player(target, "\n%^BOLD%^%^GREEN%^You are hit by lightning by "+capitalize(ob->GetKeyName())+", ouch.%^RESET%^\n");
    tell_room(env, "\n"+capitalize(target->GetKeyName())+" screams in pain as lightning from "+
                   capitalize(ob->GetKeyName())+" penetrates "+nominative(target)+".\n", ({ob, target}));
    if (s_throw <= save){
        tell_room(env, "\n"+capitalize(target->GetShort())+" partially resists "+ob->GetKeyName()+"'s magic attack!\n", ({ ob, target }));
        tell_object(target, "\n%^BOLD%^YELLOW%^You partially resist the lightning bolt conjured by "+ob->GetKeyName()+"!%^RESET%^\n");
        dam = dam/2;
        target->eventTrainSkill("magic defense",save,s_throw,1);
    }
    target->eventReceiveDamage(ob, MAGIC | SHOCK, dam, 0, ({"torso"}));
}

void colour_spray (object ob){
  
    object target = ob->GetCurrentEnemy();
    object env = environment(ob);
    int range, roll, dam;
    int level = ob->GetLevel();
    int *dam_each =
        ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44,
           44, 44, 44, 44, 44, 47, 51, 57, 60, 79
        });
    int save = target->GetMagicResistance();
    int s_throw = random(99)+1;

    if(ob->GetLevel() <= 10 || ob->GetLevel() >= 31){
        return;
    }
    range = (dam_each[level]+20) - (dam_each[level]-20);
    roll = random(range);
    dam = dam_each[level]-20 + roll;
    tell_player(target, "\n%^BOLD%^%^GREEN%^A sudden burst of colours sends you reeling.%^RESET%^\n");
    tell_room(env, "\n"+capitalize(ob->GetKeyName())+" throws colours at "+capitalize(target->GetKeyName())+
                   " who in vain tries to escape.\n", ({ob, target}));
    if (s_throw <= save){
        tell_room(env, "\n"+capitalize(target->GetShort())+" partially resists "+ob->GetKeyName()+"'s magic attack!\n", ({ ob, target }));
        tell_object(target, "\n%^BOLD%^YELLOW%^You partially resist being coulour sprayed by "+ob->GetKeyName()+"!%^RESET%^\n");
        dam = dam/2;
        target->eventTrainSkill("magic defense",save,s_throw,1);
    }
    target->eventReceiveDamage(ob, MAGIC | EMOTIONAL, dam, 0, ({"torso"}));
}

void fireball(object ob){

    object target = ob->GetCurrentEnemy();
    object env = environment(ob);
    int range, roll, dam;
    int level = ob->GetLevel();
    int *dam_each =
        ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 71, 71, 71, 77, 71, 71,
           71, 71, 71, 71, 71, 71, 77, 88, 105, 143
        });
    int save = target->GetMagicResistance();
    int s_throw = random(99)+1;

    if(ob->GetLevel() <= 14 || ob->GetLevel() >= 31){
        return;
    }
    range = (dam_each[level]+20) - (dam_each[level]-20);
    roll = random(range);
    dam = dam_each[level]-20 + roll;
    dam = dam_each[level]/2 + roll;
    tell_player(target, "\n%^BOLD%^%^GREEN%^You are enveloped in flames from a fireball sent by "+capitalize(ob->GetKeyName())+" - OUCH%^RESET%^\n");
    tell_room(env, "\n"+capitalize(ob->GetKeyName())+" smirks as "+possessive(ob)+
                   " fireball explodes into the face of "+capitalize(target->GetKeyName())+".\n", ({ob, target}));
    if (s_throw <= save){
        tell_room(env, "\n"+capitalize(target->GetShort())+" partially resists "+ob->GetKeyName()+"'s magic attack!\n", ({ ob, target }));
        tell_object(target, "\n%^BOLD%^%^YELLOW%^You partially resist being fireballed by "+ob->GetKeyName()+"!%^RESET%^\n");
        dam = dam/2;
        target->eventTrainSkill("magic defense",save,s_throw,1);
    }
    target->eventReceiveDamage(ob, MAGIC | HEAT, dam, 0, ({"torso"}));
}
