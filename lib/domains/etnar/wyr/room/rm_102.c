/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_ROOM;

int revealed;
int shrine_room();
int go_south();

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^A Priests Humble Quarters%^RESET%^");
    SetLong("   This is a rather large room compared to the rest of "
        "the Shrine. Bookcases filled with heavy tomes and parchment scrolls "
        "line the eastern wall. A small wooden bed juts out from the "
        "southeastern corner of the room. A table and an ornate chair are "
        "situated in front of the bookcases. The room is simple in design "
        "and construction - the walls are unadorned, except for a tapestry "
        "on the south wall."
        );
    SetProperty("nopeer",1);
    SetItems( ([ 
        "bed" : " Although neat in appearance, the bed is nothing more than "
            "a crudely constructed wooden box filled with some straw and "
            "blankets.",
        ({"bookcases", "cases", "case"}) : " These cases are barely able to "
        "support the huge tomes and scrolls that they contain.",
        "table" : " An old yet sturdy table with many ink "
            "blotches on the surface.",
        "blotches" : " Spilled dried out ink stains.",
        ({"scratches", "scratch"}) : " Some faded lettering in the native "
             "language is etched in the stone. The words are appear to be "
             "gibberish.",
        "chair" : " A very simple and not very comfortable looking "
            "construction.",
        ({"tomes", "tome"}) : " Most of the writings are in a language that is"
            "indecipherable. The readable text describes the teachings of "
            "Balcor, the war god.",
        ({"scroll", "scrolls"}) : " Many of the scrolls are so old that the "
            "writing has faded. Some are written in indecipherable One scroll "
            "of note describes what appears to be the beginnings of a plan "
            "for the construction of a huge monastery somewhere north of Wyr "
            "in the middle of a forest.",
        ({"edge", "worn", "worn edge"}) : " This portion of the tapestry "
            "looks like it gets handled quite often.", 
        ] ));
    SetInventory( ([
        "/domains/etnar/wyr/wyr/npc/henli/henli_zigil" : 1,
        "/domains/etnar/wyr/wyr/obj/tapestry" : 1,
        ]) );
    revealed = 0;
    AddExit("east","/domains/etnar/wyr/wyr/room/rm_100", (:shrine_room:));
}

shrine_room(){
    object ob = this_player();
    tell_player(ob, "\n%^BOLD%^%^WHITE%^You move aside some "
        "%^B_WHITE%^%^BOLD%^%^BLACK%^black curtains%^RESET%^ and enter a small "
        "shrine room.%^RESET%^\n");
    say(ob->GetName()+" %^BOLD%^%^WHITE%^moves aside some "
        "%^B_WHITE%^%^BOLD%^%^BLACK%^black curtains%^RESET%^ and enters the "
        "room beyond.%^RESET%^"); 
    return 1;
}

int TellRevealed(){
    if(revealed) return revealed;
    else return 0;
}

int RevealDoor(){
    if(!present("henli")) revealed = 1;
    if(present("henli") && !GetExit("south")){
        write("Henli %^BOLD%^%^RED%^smashes%^RESET%^ you as you fiddle with the "
            "tapestry!");
        say("Henli %^BOLD%^%^RED%^smashes%^RESET%^ "+this_player()->GetName()+" as "+
        nominative(this_player())+" fiddles with the tapestry hanging on the "
        "wall!"); 
        this_player()->AddHP(-(random(10)));
        revealed = 0;
        return 0;
    }
    if(revealed == 1 && !present("henli")){
        tell_room(this_object(),"A secret compartment to the south is revealed "
        "behind the black tapestry!");
        AddExit("south","/domains/etnar/wyr/wyr/room/rm_103", (:go_south:));
        return 1;
    }
}

int go_south(){
    if(!present("henli")) return 1;
    write("Henli %^BOLD%^%^RED%^smashes%^RESET%^ you as you try to go south!");
    say("Henli %^BOLD%^%^RED%^smashes%^RESET%^ "+this_player()->GetName()+" as "+
        nominative(this_player())+" pokes around the tapestry on the south "
        "wall!"); 
    this_player()->AddHP(-(random(10)));
    RemoveExit("south");
    revealed = 0;
    return 0;
}
    
void init(){
   ::init();
}
