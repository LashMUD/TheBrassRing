// Based on Diku MUD Alfa.  Program and Concept created by
// Sebastian Hammer, Michael Seifert, Hans Henrik Staerfeldt,
// Tom Madsen, and Katja Nyboe.
// http://www.dikumud.com
//
// Modified by Lash (Christopher Coker) for use with:
//
// The Dead Souls Mud Library version 2
// developed by Cratylus
// http://www.dead-souls.net

#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();

    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("The Lair");
    SetLong("On the floor you see a lot of human decay, like bones and skulls. You also\n"+
        "see a lot of slime. On the wall is a torch sitting in its sconce.");
    SetItems( ([ 
        "north" : "You see another part of the lair.",
        "east" : "You see another part of the lair.",
        "south" : "You see the lair entrance.",
        ({"skull", "skulls", "bones", "decay"}) : "On all the skulls you notice that there is a three inch hole in the \n"+
            "forehead. All the bones are broken and old.",
        "slime" : "The slime is slimy and uninteresting.",
        ({"torch", "sconce"}) : "The torch is bolted to the sconce and the sconce to the wall.",
        ] ));
    SetExits( ([
        "north" : "/domains/diku-alfa/room/72.zon/rm_7203",
        "east" : "/domains/diku-alfa/room/72.zon/rm_7207",
        "south" : "/domains/diku-alfa/room/72.zon/rm_7208",
        ] ));
SetDoor("south", "/domains/diku-alfa/room/doors/7204_7208"); 
}

void init(){
   ::init();
}

/* Extra Information Original Diku Output 
Room name: The Lair, Of zone : 16. V-Number : 7204, R-number : 486
Sector type : City Special procedure : No
Room flags: INDOORS 
Description:
On the floor you see a lot of human decay, like bones and skulls. You also
see a lot of slime. On the wall is a torch sitting in its sconce.
Extra description keywords(s): 
torch sconce
slime
skull skulls bones decay

------- Chars present -------

--------- Contents ---------

------- Exits defined -------
Direction north . Keyword : (null)
Description:
  You see another part of the lair.
Exit flag: NOBITS 
Key no: -1
To room (V-Number): 7203

Direction east . Keyword : (null)
Description:
  You see another part of the lair.
Exit flag: NOBITS 
Key no: -1
To room (V-Number): 7207

Direction south . Keyword : door wooden
Description:
  You see the lair entrance.
Exit flag: IS-DOOR  
Key no: -1
To room (V-Number): 7208
*/
