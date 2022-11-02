// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_ROOM;

int ReadRunes();

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Magicians' Shop%^RESET%^");
    SetLong("   Shelves full of weird and arcane books, bottles, potions and "
        "spell ingredients cover the walls. In a back corner of the room is "
        "a large curtain covering a doorway. A youthful clerk stands here to "
        "assist you.");
    SetItems( ([ 
        ({"curtain", "curtains"}) : " An ancient and mysterious black silk curtain blocks the "
            "entrance to a small room. The fabric is covered with gold glowing "
            "runes.",
        ({"books","book" "bottles", "bottle", "potions", "potion", "spell",
            "ingredients", "ingredient"}) : " These are some of the items "
            "that the clerk is willing to sell.\n"
            "Type 'list' for further information.",
        ({"runes", "rune"}) : "The runes are indecipherable.\n"
        ] ));
     SetRead( ([
            ({"runes", "rune"}) : (:ReadRunes:),
        ]) );  
     SetExits( ([
        "north" : "/domains/etnar/wyr/room/rm_169",
        "south" : "/domains/etnar/wyr/room/rm_108",
        ] ));
}
mixed ReadRunes(){
    return (mixed)this_player()->eventPage("/domains/etnar/wyr/text/runes.txt");
}

void init(){
   ::init();
}