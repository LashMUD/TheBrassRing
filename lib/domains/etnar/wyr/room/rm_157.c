// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_ROOM;

int ReadSign();

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Teamsters%^RESET%^");
    SetLong("   You enter a large building with many cages containing various "
        "animals ranging from mice to large dogs. The smell is almost "
        "overpowering but the place looks like it is kept in neat and orderly "
        "condition. There is a large sign hanging down from the roof.");
    SetItems( ([
        "east" : "",
        "sign" : "                          Pets for Sale\n"+
            "\n"+
            "                           Type 'List'\n"+
            "\n"+
            "Rules: 1. Name your pet on purchase.   Ex. Buy wolf Fang\n"+
            "       \n"+
            "       2. Order pets to do things.     Ex. order fang (or wolf) kill rat\n"+
            "       \n"+
            "       3. Some pets can wield weapons. Ex. order fang wield sword\n"+
            "       \n"+
            "       4. Pets will gain xp for killing mobs. Kill your pet to get\n"+
            "          the accumulated xp. Expect your pet to fight back though!\n",
            ] ));
       SetRead( ([
            "sign" : (:ReadSign:),
            ]) );      
       SetExits( ([
            "east" : "/domains/etnar/wyr/room/rm_118",
            ] ));
}

mixed ReadSign(){
    return (mixed)this_player()->eventPage("/domains/etnar/wyr/text/teamstersign.txt");
}

void init(){
   ::init();
}
