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
void CheckPoison(object ob);
void Scavenge();

static void create() {
    sentient::create();
    SetKeyName("the green snake");
    SetId( ({"snake"}) );
    SetAdjectives(({"non-player", "non player", "evil", "slimy"}));
    SetShort("A large green snake, looks like a guardian for an evil force");
    SetLong("You see an evil creature.");
    SetRace("viper");
    SetLevel(30);
    SetMelee(1);
    SetGender("male");
    SetMorality(-1750);
    SetWander(5);
    SetEncounter( (:CheckNPC:) );
    SetCombatAction(100, (:CheckPoison:));
    SetAction(10, ( :Scavenge: ));
    SetInventory( ([
       "/domains/diku-alfa/room/41.zon/meals/4103_slime" :1,
       ]) );
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

void CheckPoison(object ob){

    int chance; 
    object env = environment(this_object());

    if(this_object()->GetInCombat()){
        ob = this_object()->GetCurrentEnemy();
        if(ob->GetPoison() > 0) return;     
        else { 
            chance = random(32)-this_object()->GetLevel();
            if(chance == 0){
                tell_room(env, "%^BOLD%^%^GREEN%^The Snake sinks its fangs into "+ob->GetShort()+"!%^RESET%^\n", ({this_object(), ob}) );
                tell_object(ob, "%^BOLD%^%^GREEN%^The Snake sinks its fangs into you!%^RESET%^\n");
                ob->AddPoison(5);
            }
        }
    }
}    

void Scavenge(){

    object env = environment(this_object());
    object *item, *cost;
    int s;
    
    item = filter(all_inventory(env), (: !living($1) && (inherits(LIB_ITEM, $1) || inherits(LIB_ARMOR, $1)):) );
    cost = sort_array(item->GetBaseCost(), -1);
    s = sizeof(cost);
    if(s>0){
        foreach(object thing in item){
            if(thing->GetBaseCost() == cost[0]){
                eventForce("get "+thing->GetKeyName());
                break;
            }
        }
    }
}    

/* Extra Information Original Diku Output 
MALE MOB - Name : snake [R-Number70], In room [3001] V-Number [4102]
Short description: the snake
Title: None
Long description: A large green snake, looks like a guardian for an evil force.
Monster Class: Normal   Level [10] Alignment[-700]
Birth : [1316471719]secs, Logon[1316471719]secs, Played[0]secs
Age: [17] Years,  [0] Months,  [0] Days,  [0] Hours
Height [198]cm  Weight [200]pounds 
Hometown[0], Speaks[0/0/0], (STL[0]/per[19]/NSTL[0])
Str:[11/0]  Int:[11]  Wis:[11]  Dex:[11]  Con:[11]
Mana p.:[10/100+10]  Hit p.:[76/76+10]  Move p.:[50/50+10]
AC:[50/10], Coins: [0], Exp: [9000], Hitroll: [12], Damroll: [2]
Position: Standing, Fighting: Nobody
Default position: Standing,NPC flags: SPEC SENTINEL SCAVENGER ISNPC AGGRESSIVE, Timer [0]
Mobile Special procedure : Exists
NPC Bare Hand Damage 2d5.
Carried weight: 0   Carried items: 0
Items in inventory: 0, Items in equipment: 0
Apply saving throws: [10] [10] [10] [10] [10]
Thirst: -1, Hunger: -1, Drunk: -1
Master is 'NOBODY'
Followers are:
Affected by: NOBITS
*/
