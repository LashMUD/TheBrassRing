/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_ROOM;

void haunting();
void time();
int hour, minutes;
int *time_of_day;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^Sybil Klaknor's House%^RESET%^");
    SetLong("   The main room of Sybil Klaknor's house is sparsely furnished, "
        "but very clean. A round carpet is laid out on the wooden floor and "
        "a modest sofa is against the south wall next to a fireplace. Above "
        "the sofa hangs a clock in a wooden frame. In the corner by the sofa "
        "is a wooden cabinet with a glass door.");
    SetItems( ([ 
        "north" : "There is a bed in this room with a nightstand next to it.",
        "south" : "A small room with a table, a chair, and a small bookcase.",
        "west" : "A small kitchen is beyond the entrance.",
        ({"carpet", "rug"}) : "Probably the most expensive thing in the house. "
            "The rug has a red floral design woven into it.",
        ({"sofa", "couch"}) : "Well worn with some threads starting show.",
        "fireplace" : "Though not very big a fire here would be enough to heat "
            "the whole house.",
        "clock" : "It shows the correct time twice a day.",
        "cabinet" : "Through the glass doors you can see some trinkets sitting on "
            "three wooden shelves. The middle shelf has a small cloth doll sitting "
            "against the back of the cabinet.",
        ({"doll", "cloth doll"}) : "A raggedy doll with buttons for eyes and a nice "
            "little yellow dress. It smiles sweetly at you.",
        "trinkets" : "Little nick-nacks that are near worthless.",  
        ] ));
    SetInventory( ([
        "/domains/etnar/wyr/npc/sybil/sybil_klaknor" : 1,
        "/domains/etnar/wyr/virtual/dummy_sofa" : 1,
    ]) );
    SetExits( ([
         "east" : "/domains/etnar/wyr/room/rm_114",
         ] ));
    SetDoor("east", "/domains/etnar/wyr/doors/114_197");
    set_heart_beat(1);
}

void haunting() {
    
    object cab;
    time_of_day = SEASONS_D->GetMudTime();
    hour = time_of_day[0];
    minutes = time_of_day[1];
    
                    
    if( hour >= 0 && hour < 3 ) {
        
        AddItem("cabinet", "Through the glass doors you can see some trinkets sitting on "
                "three wooden shelves. The middle shelf has a small cloth doll standing "
                "against the glass door.");
        AddItem("doll", "A raggedy doll with buttons for eyes and a nice "
            "little yellow dress. It is banging softly on the glass cabinet door trying to get out.");
        AddItem("cloth doll", "A raggedy doll with buttons for eyes and a nice "
            "little yellow dress. It is banging softly on the glass cabinet door trying to get out.");
        
        SetActionsMap( ([ 
            "You here a banging on the cabinet door." : 1,
            "The dolls' eyes emit a %^BOLD%^%^RED%^red%^RESET%^ glow." : 1,
            "The dolls' head slowly spins around." : 1,
            "You hear a soft sobbing eminating from the cabinet." : 1,
            ]) );
    }
}

void heart_beat(){
    ::heart_beat();
    haunting();
}

void init(){
   ::init();
}
