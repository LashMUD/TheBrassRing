/*    /verbs/players/score.c
 *    from the Dead Souls Library http://www.dead-souls.net
 *    Displays a list of score and related info
 *    created by Blitz@Dead Souls
 *
 *    /lib/cmds/players
 *    modified by Lash (ccoker)  
 *    for use in The Brass Ring mud
 *     - modified output to look differently
 *       than in the original file
 *    last modified 23/01/09 to show xp's
 *  
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;
inherit LIB_HELP;

varargs mixed eventScore();

static void create() {
    daemon::create();
    SetNoClean(1);
    SetHelp("Syntax: score\n\n"
            "Displays information about your character.\n"
            "See also: stat, status, env");
}

static string *FoodDegree =
({ "starving!", "very hungry",
 "hungry", "partially hungry",
 "feeling full", "quite full" });

static string *DrunkDegree =
({ "sober", "tipsy", "drunk", "blitzed",
 "three sheets to the wind", "FUBAR" });

static string *DrinkDegree =
({ "parched", "extremely thirsty", "very thirsty", "thirsty",
 "somewhat thirsty", "unthirsty" });

mixed cmd(string arg) {
    eventScore(arg);
    return 1;
}

varargs mixed eventScore(string arg) {
    string *str;
    int birth, age, b, x, y, z, qp, xp;
    string *tmp;
    mapping lev;
    object who;
    string prn, haben, be, poss;
    string past, qual, cnj, yrstr;
    
    if(!arg || !creatorp(this_player()) || !(who = find_player(arg))){
        who = this_player();
        haben = "have";
        be = "are";
        poss = "your";  
        prn = "you";
        past = "were";
        qual = "qualify";
        cnj = "";
    }

    else {
        haben = "has";
        be = "is";
        poss = possessive(who);
        prn = nominative(who);
        past = "was";
        qual = "qualifies";
        cnj = "s";
    }
    /* revised by Lash */
    str  = ({ "\nName              "+who->GetShort()});
    str += ({ sprintf("Level             Level %d %s%s %s",
              who->GetLevel(), ( who->GetUndead() ? "undead " : ""), capitalize(who->GetRace() || "nothing"),
              capitalize(who->GetClass() || "commoner")) });
    str += ({ "XP                "+who->GetExperiencePoints() }); 
    str += ({ "Money             "+who->GetCurrency("gold")+" Gold Coins" });
    str += ({ "Morality          "+who->GetMoralityDescription()+" "+"("+who->GetMorality()+")" });               
    str += ({ "Faith             "+(who->GetReligion() ||"Agnostic") + "\nNative Town       "+who->GetTown() });
    str += ({ sprintf("Quests Solved     %s\nTitles            %s",
                consolidate(sizeof(who->GetQuests()),
                    "one quest"),
                consolidate(sizeof(who->GetTitles()),
                    "one title") ) });
    birth = who->GetBirth();
    b = query_year(birth);
    if(b < 0) yrstr = (2037+b) + " Old Calendar";
    else yrstr = b + "";
    age = ( query_year(time()) - query_year(birth) );
    str += ({ sprintf("Birth Date        %d%s day of %s, year %s (%d years old)", query_date(birth), ordinal(query_date(birth)),
                query_month(birth), yrstr, age) });
    if( who->GetWimpy() )
        str += ({ "Wimpy             On "+"("+who->GetWimpy()+"%)" }); 
        else str+= ({ "Wimpy             Off" });
    if( who->GetPoison() > 0 )
        str += ({ "Poison Status     Yes!" });
    x = who->GetFood() / 17;
    if( x > sizeof(FoodDegree) - 1 ) x = (sizeof(FoodDegree) - 1);
    y = who->GetDrink() / 17;
    if( y > sizeof(DrinkDegree) - 1 ) y = (sizeof(DrinkDegree) - 1);
    z = who->GetAlcohol();
    if(z) z = (z/17) + 1;
    if( z > sizeof(DrunkDegree) - 1 ) z = (sizeof(DrunkDegree) - 1);
    str += ({ "Hunger            "+FoodDegree[x] });
    str += ({ sprintf("Thirst            %s and %s", DrinkDegree[y], DrunkDegree[z]) });
    x = who->GetCustomStats();

    tmp = ({});
    qp = who->GetQuestPoints();
    xp = who->GetExperiencePoints();
    lev = PLAYERS_D->GetLevelList()[(who->GetLevel()) + 1];

    if(x){
        str += ({ "Custom Points     "+x+
                " customization points left. Type: help customize" });
    }

    if(lev){
        if(REQUIRE_QUESTING){
            qp = lev["qp"] - qp;
            if(qp > 0) tmp += ({"Quest Points      "+capitalize(prn)+" require"+cnj+" "+
                    comma(qp)+" more quest points to advance."});
        }
    }
    if( x = who->GetTrainingPoints() < 1 ) {
        y = who->GetLevel() + 1 + (x / -4);
        str += ({ "Training points   "+(who == this_player() ? "Available" :
                    objective(who))+" at level " + y + "." });
    }
    else str += ({ "Training Points   "+capitalize(prn)+" "+haben+" " + consolidate(
                who->GetTrainingPoints(),
                "one training point") + "." });

    
    this_player()->eventPage(str, "info");
    return 1;
}
