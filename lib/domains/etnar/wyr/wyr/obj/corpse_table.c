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

inherit LIB_TABLE;

void create() {
    ::create();

    SetKeyName("corpse table");
    SetId( ({"corpse table", "table"}) );
    SetAdjectives( ({ "black"}) );
    SetShort("a big wooden table in the shape of a coffin");
    SetLong("This is the corpse table where Pierce Pascal lays out the victims of his guards.");
    SetBaseCost("silver",1);
    SetMaxCarry(10000);
    SetMass(100);
}

void init(){
    ::init();
}

mixed CanGet(object ob) { return "You can't take that";}

/* Extra Information Original Diku Output
Object name: [desk drawer], R-number: [81], V-number: [3130] Item type: CONTAINER
Short description: the desk
Long description:
A desk is set against the western wall.
Extra description keyword(s):
----------
drawer
----------
Can be worn on :NOBITS
Set char bits  :NOBITS
Extra flags: NOBITS
Weight: 100, Value: 0, Cost/day: 100000, Timer: 0
In room: 3001 ,In object: None ,Carried by:Nobody
Max-contains : 34
Locktype : 15
Corpse : No
Equipment Status: NONE
Special procedure : No
Contains : Nothing
Can affect char :
    Affects : NONE By 0
    Affects : NONE By 0
*/
