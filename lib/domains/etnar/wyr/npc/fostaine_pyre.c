/* /domains/etnar/wyr/npc/fostaine_pyre.c.
 * The bard in the village of Wyr
 * based on The Dead Souls Mud Library
 * maintained by Cratylus http://www.dead-souls.net
 * for use in The Brass Ring Mud
 * last edited by lash 22/11/02
 */

#include <lib.h>
#include <objects.h>
#include <daemons.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("Fostaine Pyre");
    SetId(({"bard", "player"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("Fostaine Pyre");
    SetLong("Fostaine is a portly man with long curly hair sporting a thin moustache and goatee. "
        "He is carrying a loot which he uses to entertain the clientel at the Cyclops Inn."
    );
    SetRace("human");
    SetClass("bard");
    SetLevel(18);
    SetGender("male");
    SetCanBite(0);
    SetMorality(1500);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetPolyglot(1);
    SetAutoStand(0);
}

void init(){
    ::init();
}


