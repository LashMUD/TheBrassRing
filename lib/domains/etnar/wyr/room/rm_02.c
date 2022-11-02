// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2 and above
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_ROOM;
int ReadSign();
int ReadSheet();

static void create() {
    
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("The Wizard's Lounge");
    SetLong("  Say! Isn't this a nifty room?\n"+
        "You are standing in the workroom of the mighty Lash!\n"+
        "You can \"enter shrine\" to go to the Shrine Room in Wyr or "
        "\"enter altar\" to go to the Temple Altar in Midgaard.");
    SetItems( ([
        "altar" : "The Midgaard Temple altar room",
        "shrine" : "The Shrine Room of Balcor",
        ({"sign","hint","hints"}) : "A sign with hints for creators.",
        ({"sheet","reminder","reminders"}) : "A sheet with quick reminders "+
            "for creators.",
        ]) );
    SetRead( ([
        ({"sign","hint","hints"}) : (: ReadSign :),
        ({"sheet","reminder","reminders"}) : (: ReadSheet :)
        ]) );
    SetInventory( ([
        "/domains/diku-alfa/room/31.zon/obj/key_3133" : 1,
        "/domains/etnar/wyr/obj/chest" : 1,
        ]) );
    SetExits( ([
        "altar" : "/domains/diku-alfa/room/30.zon/rm_3054",
        "shrine" : "/domains/etnar/wyr/room/rm_100",
        ]) );
    SetNoModify(0);
}

int ReadSign(){
    this_player()->eventPage("/news/hints.txt");
    return 1;
}

/*int ReadSheet(){
    this_player()->eventPage("/news/reminders.txt");
    return 1;
}*/

void init(){
   ::init();
}

int CanReceive(object ob) {
    if(playerp(ob) && !adminp(ob)){
        return 0;
    }
    return 1;
}
