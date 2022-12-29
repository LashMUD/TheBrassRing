/*
 * Modified by Lash (Christopher Coker) for use with:
 *
 * The Dead Souls Mud Library
 * developed by Cratylus
 * http://www.dead-souls.net
 *
 * Based on Dirk and Radagast the Brown from the
 * Dead Souls default "town" Mudlib
 */


#include <lib.h>
#include <objects.h>
#include <daemons.h>

inherit LIB_TRAINER;

int eventHelp(object who, string unused);

void create(){
    int i;
    trainer::create();
    SetKeyName("Henli Zigil the Devout");
    SetId("guildmaster", "master", "Henli", "henli", "priest","cleric","trainer", "zigil");
    SetAdjectives(({"light","holy","pious"}));
    SetFactions( ([ "The Strike of Balcor" : ({20, 20}),
                    "The Order of Ambrial" : ({20,20}),
                    "House Zigil" : ({18,5}), //dwarf went to human village
    ]) );
    SetGender("male");
    SetRace("dwarf");
    SetClass("cleric");
    SetLevel(40);
    SetNoSpells(0);
    SetShort("Henli");
    SetLong("Henli is short and stout with silver hair and soft brown eyes. He wears "
        "the High Priests' black robes of Balcor the war god."); 
    SetSpellBook( ([ "healing" : 100, "whip" : 100, "fireball" : 100,
    "buffer" : 100
    ]) );
    SetProperty("no bump", 1);
    SetCanBite(0);
    SetAttackable(0);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetPolyglot(1);
    AddTrainingSkills( ({ "magic attack", "blade defense", "conjuring", 
        "magic defense", "faith"
    }) );
    SetConsultResponses( ([
        ({ "quests", "quest", "quest points" }) : "Quests are missions "+
            "you can try to complete that will usually reward you with "+
            "quest points if you solve them. Completing quests will "+
            "change your reputation among different factions and will "+
            "help raise your level within the faction from which the "+
            "quest was given." ,
    ]) );
    SetInventory( ([
        "/domains/etnar/wyr/wyr/npc/henli/key_shrine" : 1,
    ] ));
}

void init() {
    trainer::init();
    SetSmell(([  "default" : "The pungent odor of incense wafts from Henli's robes."]));
    SetListen(([  "default" : "Henli is mumbling prayers under his breath."]));
}

int eventHelp(object who, string unused){
    ::eventHelp(who);
    this_object()->eventForce("speak I may have some useful information about quests, too.");
    return 1;
}
