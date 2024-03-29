// Based on Diku MUD Alfa.  Program and Concept created by
// Sebastian Hammer, Michael Seifert, Hans Henrik Staerfeldt,
// Tom Madsen, and Katja Nyboe.
// http://www.dikumud.com
//
// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_SENTIENT;

void Spells();

/*int AllowPass(object who, object what){
    if(!who) return 0;
    if(!objectp(who)) return 0;
    if(who->GetClass() == "mage" || adminp(who)) return 1; 
    return ::AllowPass(who, what);
}*/

static void create() {
    sentient::create();

    SetKeyName("the Sorcerer");
    SetId(({"npc","mob","character","mobile", "sorcerer"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("a Sorcerer");
    SetLong("He is an experienced mage who has specialized in the field of Combat Magic.\n"+
        "He is here to guard the Mage's Guild and his superior knowledge of offensive\n"+
        "as well as defensive spells make him a deadly opponent.");
    SetCanBite(0);
    SetRace("human");
    SetClass("mage");
    SetLevel(23);
    SetMelee(1);
    SetGender("male");
    SetMorality(2000);
    AddCurrency("gold", 2000); 
    SetProperty("no bump", 1);
    SetCombatAction(75, ( :Spells: ));
    //SetGuard("south" , "The guard humiliates you, and blocks your way.");
}

void init(){
    ::init();
}

void Spells(){
     "/powers/npc/magic_user.c"->SpellCombat(this_object());
}

/* Extra Information Original Diku Output
MALE MOB - Name : sorcerer [R-Number16], In room [3001] V-Number [3024]
Short description: the Sorcerer
Title: None
Long description: A sorcerer is guarding the entrance.
Monster Class: Normal   Level [23] Alignment[800]
Birth : [1317253374]secs, Logon [1317253374]secs, Played [0]secs
Age: [17] Years,  [0] Months,  [0] Days,  [0] Hours
Height [198]cm  Weight [200]pounds 
Hometown[0], Speaks[0/0/0], (STL[0]/per[19]/NSTL[0])
Str:[11/0]  Int:[11]  Wis:[11]  Dex:[11]  Con:[11]
Mana p.:[10/100+23]  Hit p.:[410/410+23]  Move p.:[50/50+23]
AC:[20/10], Coins: [2000], Exp: [80000], Hitroll: [18], Damroll: [12]
Position: Standing, Fighting: Nobody
Default position: Standing, NPC flags: SENTINEL ISNPC , Timer [0]
Mobile Special procedure : Exists
NPC Bare Hand Damage 1d8.
Carried weight: 0   Carried items: 0
Items in inventory: 0, Items in equipment: 0
Apply saving throws: [2] [2] [2] [2] [2]
Thirst: -1, Hunger: -1, Drunk: -1
Master is 'NOBODY'
Followers are:
Affected by: NOBITS
*/
