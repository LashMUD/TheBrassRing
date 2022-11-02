// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_ROOM;

int shrine_room();

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Acolytes Chamber%^RESET%^");
    SetLong("   There are only the bare necessities for living. Some "
        "makeshift beds line the eastern wall and a large table, with a few "
        "chairs around it, sits in the middle of the room."
        );
    SetProperty("nopeer",1);
    SetItems( ([ 
        ({"curtains", "curtain"}) : " Some curtains block the entranceway.",
        ({"bed", "beds"}) : " The beds lining the wall are made of "
            "straw. Blankets are arranged neatly on the floor.",
        ({"wall", "walls"}) : " The walls are barren and are simply the "
            "inner face of the stone blocks used to construct the Shrine.",
        "table" : " The round table is rather large and fills most of the "
            "room. The four chairs encircling the table are simply made yet "
            "sturdy. The table has been used quite extensively. There are some "
            "small scratches in the surface and some papers strewn about.",
        ({"paper", "papers"}) : " The wriribg on the papers indicates that "
            "they contain uninteresting notes relating to theology teachings.",
        ]) );
    SetInventory( ([
        "/domains/etnar/wyr/npc/acolyte" : 1,
        ]) );
    AddExit("west","/domains/etnar/wyr/room/rm_100", (:shrine_room:));
}

int shrine_room(){
    object ob = this_player();

    tell_player(ob, "\n%^BOLD%^%^WHITE%^You move aside some "
        "%^BOLD%^%^MAGENTA%^magenta curtains%^RESET%^ and enter a small "
        "shrine room.%^RESET%^\n");
    say(ob->GetName()+" %^BOLD%^%^WHITE%^moves aside some "
        "%^BOLD%^%^MAGENTA%^magenta curtains%^RESET%^ and enters the room "
        "beyond.%^RESET%^"); 
    return 1;
}

void init(){
   ::init();
}
