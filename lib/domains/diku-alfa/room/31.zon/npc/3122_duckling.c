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

    SetKeyName("the Duckling");
    SetId( ({"duck", "duckling", "bird", "fowl"}) );
    SetAdjectives(({"small", "cute"}));
    SetShort("a Duckling");
    SetLong("The duckling is adorable, it looks most of all like a tiny furball.");
    SetPosition(POSITION_SWIMMING);
    SetRace("bird");
    SetClass("fighter");
    SetLevel(1);
    SetGender("female");
    SetMorality(2500);
}

void init(){
    ::init();
}

/* Extra information Original Diku Output
NEUTRAL-SEX MOB - Name : duckling [R-Number43], In room [3001]
V-Number [3122]
Short description: the Duckling
Title: None
Long description: A duckling is swimming around in the pond.
Monster Class: Normal   Level [0] Alignment[1000]
Birth : [1316441841]secs, Logon[1316441841]secs, Played[0]secs
Age: [17] Years,  [0] Months,  [0] Days,  [0] Hours
Height [198]cm  Weight [200]pounds 
Hometown[0], Speaks[0/0/0], (STL[0]/per[19]/NSTL[0])
Str:[11/0]  Int:[11]  Wis:[11]  Dex:[11]  Con:[11]
Mana p.:[10/100+0]  Hit p.:[1/1+0]  Move p.:[50/50+0]
AC:[100/10], Coins: [0], Exp: [1], Hitroll: [0], Damroll: [0]
Position: Standing, Fighting: Nobody
Default position: Standing, NPC flags: SENTINEL ISNPC ,Timer [0]
Mobile Special procedure : None
NPC Bare Hand Damage 1d1.
Carried weight: 0   Carried items: 0
Items in inventory: 0, Items in equipment: 0
Apply saving throws: [20] [20] [20] [20] [20]
Thirst: -1, Hunger: -1, Drunk: -1
Master is 'NOBODY'
Followers are:
Affected by: NOBITS
*/
