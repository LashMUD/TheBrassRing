// Based on Diku MUD Alfa.  Program and Concept created by
// Sebastian Hammer, Michael Seifert, Hans Henrik Staerfeldt,
// Tom Madsen, and Katja Nyboe.
// http://www.dikumud.com
//
// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2
// developed by Cratylus
// http://www.dead-souls.net
//
// Based on Dirk and Radagast the Brown from the
// Dead Souls default "town" Mudlib


#include <lib.h>
#include <objects.h>
#include <daemons.h>

inherit LIB_TRAINER;

int AdvanceDude(mixed arg);
mapping advancement, Levels;

void create(){
    int i;
    trainer::create();
    Levels = PLAYERS_D->GetLevelList();
    advancement = ([]);
    SetKeyName("erica");
    SetId("guildmaster", "master", "Erica", "erica", "wizard","mage","trainer");
    SetAdjectives(({"friendly","tall","thin","old"}));
    SetGender("female");
    SetRace("human");
    SetNoSpells(0);
    SetShort("Erica the Blue");
    SetLong("Even though your guildmaster looks old and tired, you can clearly see the\n"+
            "vast amount of knowledge she posesses. She is wearing fine magic clothing,\n"+
            "and you notice that she is surrounded by a blue shimmering aura."); 
    SetClass("mage");
    SetLevel(40);
    SetProperty("no bump", 1);
    SetAttackable(0);
    AddTrainingSkills( ({ "magic defense", "magic attack", "conjuring", "bargaining",
                          "blunt defense", "knife defense", "melee defense", "blunt attack",
                          "knife attack", "melee attack"
                     }) );
    SetSpellBook( ([ "buffer" : 100, "meditate" : 100, "missile" : 100, "fireball" : 100, "greater buffer" : 100,
                     "whip" : 100, "light" : 100, "greater fireball" : 100,]) );
    SetPolyglot(1);
    SetCustomXP(10);
    AddCommandResponses( ([ 
                "advance": (: AdvanceDude :) 
                ]) );
    SetConsultResponses( ([
                ({ "level", "levels", "leveling", "advancement", "advancing" }) :
                "To level, get some experience out there and then come back "+
                "and ask me to advance. For some levels you may need "+
                "some quest points to advance, not just experience.",
                ({ "xp", "XP", "experience" }) : "You can score experience "+
                "points by killing monsters or completing some quests. "+
                "Sometimes you'll get xp for completing some task you didn't "+
                "even know would give you points. Generally though, it's combat "+
                "that results in XP rewards, if you win.",
                ({ "points" }) : "It's how to keep track of your progress. The "+
                "kinds of points I care about are experience points and "+
                "quest points.",
                ({ "quests", "quest", "quest points" }) : "Quests are missions "+
                "you can try to complete that will usually reward you with "+
                "quest points if you solve them. "+
                "You'll need quest points to advance past a "+
                "certain level.",
                ]) );
    for(i=0;i<21;i++){
        advancement[i] = Levels[i];
    }
}

void init() {
    trainer::init();
    SetSmell(([  "default" : "Erica smells like a bouquet of fresh flowers."]));
    SetListen(([  "default" : "Erica seems to be constantly "+
                "humming a quiet tune to herself."]));
}

int AdvanceDude(mixed arg){
    int level,dlev,xp,qp,totpoints;
    int desired_level,required_xp,required_qp;
    mixed *statlist;
    mapping this_stat;
    int statclass, statlevel, i;
    string str;
    string *ptmp = ({});
    string *stmp = ({});
    string *mtmp = ({});
    int *plevels = ({});
    int *slevels = ({});
    int *mlevels = ({});
    int *psorted, *ssorted, *msorted;

    statlist = this_player()->GetStats();


    if(this_player()->GetKeyName() == "guest"){
        this_object()->eventForce("say I don't promote temporary players.");
        return 1;
    }

    if(!level = this_player()->GetLevel()){
        this_object()->eventForce("say You are confusing me.");
        return 1;
    }
    if(adminp(this_player()) || creatorp(this_player())){
        this_object()->eventForce("say Do you really NEED to be promoted?");
        this_object()->eventForce("shake");
        return 1;
    }
    if(level > 19){
        this_object()->eventForce("say Whoa there, big "
                "stuff. Advancement past level 20 is the "
                "purview of the Trans-Human Elder Guild. "
                "I'm sorry but I can't help you.");
        return 1;
    }

    if(XP_ADVANCE){
        xp = this_player()->GetExperiencePoints();
        if(!qp = this_player()->GetQuestPoints()) qp = 0;
        desired_level = level+1;
        required_xp = advancement[desired_level]["xp"];
        if(!required_qp = advancement[desired_level]["qp"]) required_qp = 0;
        if(!REQUIRE_QUESTING) required_qp = 0;
        this_object()->eventForce("say Level "+desired_level+" "
                "with the title of \""+advancement[desired_level]["title"]+"\" "
                "requires "+required_xp+" experience points and "+
                required_qp+" quest points.");

        if( xp > required_xp-1 && qp > required_qp-1){
            this_object()->eventForce("say Congratulations! "
                    "You are promoted to level "+desired_level+" and "
                    "have earned the name "+this_player()->GetName()+" "
                    +advancement[desired_level]["title"]+".");

            this_player()->ChangeLevel(desired_level);
            this_player()->AddTrainingPoints(desired_level);
            this_player()->AddTitle(advancement[desired_level]["title"]);
            this_player()->RemoveTitle(advancement[desired_level-1]["title"]);

            this_player()->save_player(this_player()->GetKeyName());

            if(level == MAX_NEWBIE_LEVEL){
                write("\nDirk raises his hand and sternly points to you.\n");
                say("\nDirk raises his hand and sternly points to "+
                        this_player()->GetName()+".\n");
                this_object()->eventForce("say "+this_player()->GetName()+","+
                        " you are no longer a newbie. From now on, you will need"+
                        " a light source to see in the dark. From now on, you will"+
                        " not understand languages you haven't learned. You have"+
                        " earned this promotion, and now face the future as a"+
                       " real adventurer.");
            }
    
            return 1;
        }

        else this_object()->eventForce("say I'm sorry, "+
                this_player()->GetName()+", but you have not "
                "fulfilled all the requirements of level "+
                desired_level+". Please come back and try "
                "again once you have fulfilled them.");
        return 0;
    }

    if(SKILL_ADVANCE){
        /*total number of skill points required 
          to advance to the next level - change as you see fit */
        level = this_player()->GetLevel() * 15;
        dlev = (this_player()->GetLevel())+1;
                
        if(!this_player() || !playerp(this_player()) || !this_player()->GetSkills()){
            return 0;
        }
        /* get and sort primary skills and levels */
        ptmp = this_player()->GetPrimarySkills();
        foreach(str in ptmp){
            plevels += ({this_player()->GetBaseSkillLevel(str)});
        }
        plevels = sort_array(plevels,-1);
        /* get and sort secondary skills and levels */
        stmp = this_player()->GetSecondarySkills();
        foreach(str in stmp){
            slevels += ({this_player()->GetBaseSkillLevel(str)});
        }    
        slevels = sort_array(slevels,-1);
        /* get and sort minor skills and levels */
        mtmp = this_player()->GetMinorSkills();
        foreach(str in mtmp){
            mlevels += ({this_player()->GetBaseSkillLevel(str)});
        }
        mlevels = sort_array(mlevels,-1);
        totpoints = plevels[0] + plevels[1] + plevels[2] + plevels[3] + plevels[4] + plevels[5] +
                    slevels[0] + slevels[1] + slevels[2] +
                    mlevels[0] + mlevels[1] + mlevels[2] + mlevels[3];
        }                
        if(totpoints >= level){
            this_object()->eventForce("say Congratulations! "
            "You are promoted to level "+dlev+" and "
            "have earned the name "+this_player()->GetName()+" "
            +advancement[dlev]["title"]+".");

            this_player()->ChangeLevel(dlev);
            this_player()->AddTrainingPoints(dlev);
            this_player()->AddTitle(advancement[dlev]["title"]);
            this_player()->RemoveTitle(advancement[dlev-1]["title"]);

            this_player()->save_player(this_player()->GetKeyName());
        return 1;
        }
        else
            this_object()->eventForce("tell "+this_player()->GetName()+" I'm sorry, "+
            this_player()->GetName()+", but you need to "
            "earn at least "+(level-totpoints)+" more skill points "
            "before you can advance to level "+dlev+". "
            "Please come back and try again once you get "
            "more skill points.");
        return 0;
}

string GetLevelTitle(int level){
    if(!level) level = 1;
    return advancement[level]["title"];
}

int eventHelp(object who, string unused){
    ::eventHelp(who);
    this_object()->eventForce("speak You may ADVANCE in level by asking me 'to advance'. Get some "+
                              "information by asking me about levels.");
    return 1;
}
