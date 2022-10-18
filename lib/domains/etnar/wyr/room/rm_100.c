/*    /lib/domains/Etnar/Wyr/room/rm_100.c
 *    based on the Dead Souls mud library
 *    maintained by Cratylus http:www.dead-souls.net
 *
 *    created by lash (ccoker) for use in
 *    The Brass Ring mud
 *    last modified 20/05/20
 */

#include <lib.h>

inherit LIB_ROOM;

int acolyte_chamber();
int henli_chamber();

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("The Shrine Room");
    SetLong("   You are in a small semi-circular room. Pungent incense fills the air \n"+
        "and is wafting about from two lit candles located on top of a small \n"+
        "marble altar standing in the middle of the room. A sense of holiness \n"+
        "pervades throughout the area. There are some curtains hanging on the east \n"+
        "and west walls.");
    SetItems( ([
                "curtains" : "  The curtains flow from ceiling to floor on the eastern and western walls.\n"+
                    "The eastern curtains are a dark magenta color, while the western curtains are\n"+
                    "dark black. They appear to be covering entranceways.",
                ({"altar", "marble", "altar"}) : "  An irregularly shaped marble slab, situated on a stone pillar, stands about \n"+
                    "three feet from the floor. The slab has seen some use - tiny scratches and brown-red stains are noticeable.",
                ({"candle", "candles"}) : "  Wax drips down the tapered shafts.",
                ({"stain", "stains"}) : "  Of course they look like dried blood. What kind of sacrifices go on here?",
               ] ));
    SetExits( ([
                "south" : "/domains/Etnar/Wyr/room/rm_104",
               ] ));
    AddExit("east","/domains/etnar/wyr/room/rm_101", (:acolyte_chamber:));
    AddExit("west","/domains/etnar/wyr/room/rm_102", (:henli_chamber:));

}

acolyte_chamber(){
    object ob = this_player();

    tell_player(ob, "\n%^BOLD%^%^WHITE%^You move aside some %^BOLD%^%^MAGENTA%^magenta curtains%^RESET%^ and enter a small chamber.%^RESET%^\n");
    say(ob->GetName()+" %^BOLD%^%^WHITE%^moves aside some %^BOLD%^%^MAGENTA%^magenta curtains%^RESET%^ and enters the room beyond.%^RESET%^"); 
    return 1;
}

henli_chamber(){
    object ob = this_player();

    tell_player(ob, "\n%^BOLD%^%^WHITE%^You move aside some %^B_WHITE%^%^BOLD%^%^BLACK%^black curtains%^RESET%^ and enter a small chamber.%^RESET%^\n");
    say(ob->GetName()+" %^BOLD%^%^WHITE%^moves aside some %^B_WHITE%^%^BOLD%^%^BLACK%^black curtains%^RESET%^ and enters the room beyond.%^RESET%^"); 
    
    return 1;
}

void init(){
   ::init();
}


