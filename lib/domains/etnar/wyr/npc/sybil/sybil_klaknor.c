/* Sybil Klaknor a grieving widow in the village of Wyr
 * for use with:
 * The Dead Souls Mud Library
 * developed by Cratylus
 * http://www.dead-souls.net
 *
 * last modified by lash (ccoker) 22/11/23 year/month/day
 */

#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();

    SetKeyName("sybil klaknor");
    SetId(({"Sybil", "sybil", "Klaknor", "klaknor"}));
    SetAdjectives(({"non-player", "non player"}));
    SetShort("Sybil Klaknor");
    SetLong("Sybil is an elderly woman. Her long silver hair contrasts with her bright blue eyes.");
    SetCanBite(0);
    SetRace("human");
    SetClass("explorer");
    SetLevel(1);
    SetGender("female");
    SetMorality(1000);
    AddCurrency("gold", 5);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetInventory( ([
        "/domains/etnar/wyr/npc/sybil/key_sybil_klaknor" : "1",
    ] ));
    SetActionsMap( ([
        "!say Ohhh...I do hope Irwin is okay." : 10,
        "!say Irwin has been gone for about two weeks now!" : 8,
        "Sybil wrings her hands earnestly." : 6,
    ]) );
    SetTalkResponses( ([  
        ({"Irwin", "irwin"}) : "He's my husband and has been gone for awhile now. Said he was off "
            "to find a fortune for us so we could move to Orgon.",
        ({"where", "where did he go"}) : "A ruined castle in the Vexwood forest south of here.",
        ({"orgon", "Orgon"}) : "He wanted to move to Orgon because of the raids that have been "
            "happening to the caravans lately.",
        "raids" : "Some filthy bandit has been raiding the caravans that go between here and Orgon!",
    ]) );
}

void init(){
    ::init();
}
