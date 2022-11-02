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
#include <armor_types.h>
#include <damage_types.h>

inherit LIB_ARMOR;

static void create(){
    armor::create();
    
    SetKeyName("smithying cape");
    SetId(({"armor","leather","cape"}));
    SetAdjectives(({"soft"}));
    SetShort("a smithying cape");
    SetLong("A long black cape made out of soft leather. A pictogram of an "
        "anvil is emblazoned in red coloring on the back."
        );
    SetMass(50);
    SetBaseCost("gold",1000);
    SetDamagePoints(65);
    SetProtection(BLUNT,4);
    SetProtection(BLADE,35);
    SetProtection(KNIFE,50);
    SetArmorType(A_CLOAK);
}

void init(){
    ::init();
}
