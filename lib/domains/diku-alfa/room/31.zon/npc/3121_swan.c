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
#include <position.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();

    SetKeyName("the Swan");
    SetId( ({"swan", "bird", "fowl"}) );
    SetAdjectives(({"white"}));
    SetShort("a Swan");
    SetLong("The white swan is very elegant.");
    SetRace("bird");
    SetClass("fighter");
    SetLevel(1);
    SetPosition(POSITION_SWIMMING);
    SetGender("female");
    SetMorality(2500);
}

void init(){
    ::init();
}

/* Extra information Original Diku Output
NEUTRAL-SEX MOB - Name : swan [R-Number42], In room [3001]
V-Number [3121]
Short description: the Swan
Title: None
Long description: A swan is swimming around in the pond.
Monster Class: Normal   Level [1] Alignment[1000]
Birth : [1316441753]secs, Logon[1316441753]secs, Played[0]secs
Age: [17] Years,  [0] Months,  [0] Days,  [0] Hours
Height [198]cm  Weight [200]pounds 
Hometown[0], Speaks[0/0/0], (STL[0]/per[19]/NSTL[0])
Str:[11/0]  Int:[11]  Wis:[11]  Dex:[11]  Con:[11]
Mana p.:[10/100+1]  Hit p.:[20/20+1]  Move p.:[50/50+1]
AC:[90/10], Coins: [0], Exp: [100], Hitroll: [0], Damroll: [0]
Position: Standing, Fighting: Nobody
Default position: Standing, NPC flags: SENTINEL ISNPC ,Timer [0]
Mobile Special procedure : None
NPC Bare Hand Damage 1d5.
Carried weight: 0   Carried items: 0
Items in inventory: 0, Items in equipment: 0
Apply saving throws: [19] [19] [19] [19] [19]
Thirst: -1, Hunger: -1, Drunk: -1
Master is 'NOBODY'
Followers are:
Affected by: NOBITS
*/
