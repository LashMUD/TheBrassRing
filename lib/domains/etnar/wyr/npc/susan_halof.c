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

int eventPoem();

void create(){
    int i;
    trainer::create();
    SetKeyName("Susan Halof of the Art");
    SetId("master", "Susan", "susan", "mystic", "trainer", "halof");
    SetAdjectives(({"whimsical","wise","aloof"}));
    SetFactions( ([ "House Halof" : ({20, 20}),
                    "Mystics Guild" : ({20,20}),
    ]) );
    SetGender("female");
    SetRace("elf");
    SetClass("mage");
    SetLevel(40);
    SetNoSpells(0);
    SetShort("Susan");
    SetLong("Susan is tall, slender, and whimsical. She has blonde hair and fair blue eyes."); 
    SetSpellBook( ([ "greater buffer" : 100, "greater fireball" : 100, "light" : 100,
        "meditate" : 100, "whip" : 100,
    ]) );
    SetProperty("no bump", 1);
    SetCanBite(0);
    SetAttackable(0);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetPolyglot(1);
    AddTrainingSkills( ({ "conjuring", "healing", "magic attack", "magic defense", 
        "psionic defense", "psionic attack",
    }) );
    SetConsultResponses( ([
        ({ "Mystics", "mystics", "Guild of the Mystics", "guild",
           "Guild", "guild of the mystics"  }) : "If you are qualified enough in the Mystical "+
           "arts I can grant you membership in the Guild if you like.",
        ({ "Edhellen", "edhellen" }) : "It is the language of the Elves. A very old language.",
           "poem"  : (:eventPoem:),
        ({ "Gast", "gast" }) : "I cannot speak about the horror that took place there.", 
    ]) );
    SetActionsMap( ([
                "Susan smiles at you." : 10,
                "Susan hums whimsically to herself." : 5,
                "Susan softly recites a poem in Edhellen" : 5,
                "Susan stares off into the past." : 4,
                "Susan quietly says, The land of Gast, so long ago..." : 1,
    ]) );
}

void init() {
    trainer::init();
    SetSmell(([  "default" : "The sweet smell of wildflowers and honeysuckle greet your senses."]));
    SetListen(([  "default" : "You can hear a soft tinkling sound in Susan's voice."]));
}

int eventHelp(object who, string unused){
    ::eventHelp(who);
    this_object()->eventForce("speak Would you be interested in joining the Guild of the Mystics?");
    return 1;
}

int eventPoem(){
     this_object()->eventForce("speak in edhellan The Fleeting\"\n"+ 
           "Springs rain softly falling\n" +
           "Winds play among the trees\n"+
           "Far away Ocean's calling\n"+
           "Souls singing to be free\n");
     this_object()->eventForce("speak That was the land of Elysa Serindor before it bacame "+
           "the land of Gast.");
     this_object()->eventForce("smile sadly");
     
     return 1;
}
    
