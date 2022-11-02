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

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("key_wjk");
    SetId( ({ "key", "wyr jail room key", "key to the wyr jail house" }) );
    SetAdjectives( ({ "small", "metal", "dull" }) );
    SetShort("a small dull metal key");
    SetLong("This key is used to lock the doors of the jail cells in Wyr.");
    SetMass(1);
    SetBaseCost("gold",2);
    SetDisableChance(100);
}

void init(){
    ::init();
}
