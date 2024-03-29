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

#include <lib.h>

inherit LIB_SENTIENT;

void CheckNPC();

static void create(){
    sentient::create();

    SetKeyName("sewer_mudmonster");
    SetId(({"mud", "monster", "mudmonster"}));
    SetAdjectives(({"", ""}));
    SetShort("The Horrifying Mudmonster");
    SetLong("A horrifying Mudmonster is slowly evolving from the mud ...");
    SetRace("blob"); //check for appropriate race
    SetClass("fighter");
    SetLevel(20);
    SetGender("neuter");
    SetMorality(-625);
    AddCurrency("gold" , 100); 
    SetWander(5);
    SetProperty("STAY_ZONE", 1);
    SetEncounter( (:CheckNPC:) );
}

void init(){
    ::init();
}

/*Do not attack other NPC's*/
void CheckNPC(object ob){
 
 object env=environment(this_object());
 if(ob && !inherits(LIB_NPC, ob)){
         eventForce("kill " +ob->GetKeyName());
 }
}

/* Extra Information Original Diku Output 
NEUTRAL-SEX MOB - Name : mud monster mudmonster [R-Number129], In room [3001] V-Number [7013]
Short description: The horrifying Mudmonster
Title: None
Long description: A horrifying Mudmonster is slowly evolving from the mud ...
Monster Class: Normal   Level [12] Alignment[-250]
Birth : [1313933094]secs, Logon[1313933094]secs, Played[0]secs
Age: [17] Years,  [0] Months,  [0] Days,  [0] Hours
Height [198]cm  Weight [200]pounds 
Hometown[0], Speaks[0/0/0], (STL[0]/per[19]/NSTL[0])
Str:[11/0]  Int:[11]  Wis:[11]  Dex:[11]  Con:[11]
Mana p.:[10/100+12]  Hit p.:[152/152+12]  Move p.:[50/50+12]
AC:[20/10], Coins: [1000], Exp: [15000], Hitroll: [11], Damroll: [1]
Position: Resting, Fighting: Nobody
Default position: Resting,NPC flags: ISNPC AGGRESSIVE STAY-ZONE ,Timer [0]
Mobile Special procedure : None
NPC Bare Hand Damage 2d7.
Carried weight: 0   Carried items: 0
Items in inventory: 0, Items in equipment: 0
Apply saving throws: [8] [8] [8] [8] [8]
Thirst: -1, Hunger: -1, Drunk: -1
Master is 'NOBODY'
Followers are:
Affected by: SNEAK 
*/
