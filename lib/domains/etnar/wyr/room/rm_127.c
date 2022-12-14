/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_ROOM;

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^A  Bedroom%^RESET%^");
    SetLong("   You enter into a modest sized bedroom. A rather large ornate "
        "bed stands against the west wall. There is a pair of windows on the "
        "western wall and a large bureau on the southern wall.");
    SetItems( ([ 
        ({"bed", "ornate"}) : " A very comfortable looking bed indeed. Only a "
            "rich shopkeeper could afford such a nice piece of furniture. "
            "The goose feather and down pillows are large and lush. Silk "
            "sheets and a goose down comforter line the matress which is "
            "threaded with gold silk. The wood used in its construction "
            "is not native to the area. The bed frame and headboard are a "
            "deep rich black color and very sturdy. The headboard has a "
            "disturbing looking face carved into it.",
        ({"face", "disturbing"}) : " A bulbous flat topped head with peircing "
            "small red eyes stare back at you. Tentacles eminate from the "
            "nostrils and a thick salivating tongue hangs out of the mouth.",
        ({"window", "windows"}) : " You look out the windows and see "
            "the village of Wyr stretched out before you. You can pick out "
            "an elaborate and guarded building to the northwest and a small "
            "structure to the southwest that looks like a religious building "
            "of some sort.",
        "bureau" : " A beautiful piece finished from rich dark black heavy "
             "lumber that appears to be imported. Adamantine inlays show the "
             "relief of a squat bipedal creature with thick legs, two thick "
             "protruding arms accompanied by a second slender set of arms "
             "placed just above what would be shoulders. A tiny disk "
             "represents the head of the creature.  Drawers are half open and "
             "clothes thrown haphazardly in the vicinity. Evidently the owner "
             "of this room isn't concerned with tidiness.",
        ] ));
    SetExits( ([
        "west" : "/domains/etnar/wyr/room/rm_126",
        ] ));
}

void init(){
   ::init();
}
