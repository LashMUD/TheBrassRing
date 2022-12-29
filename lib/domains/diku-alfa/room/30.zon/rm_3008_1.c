/* Modified by Lash (Christopher Coker) for use with:
 * The Dead Souls Mud Library
 * developed by Cratylus
 * http://www.dead-souls.net
 * the room rented at the grinting boar inn
 * 
 * last edited by lash 22/12/29 year/month/day
 */ 

#include <lib.h>
#include <daemons.h>

inherit LIB_ROOM;

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Inn Room%^RESET%^");
    SetLong("   There are bedrolls and desks with chairs. "
            "As of now this is just a placeholder.");
    SetItems( ([ 
        ] ));
    SetInventory(([
        ]) );
    SetActionsMap( ([ 
        ]) );
    SetExits( ([
        "west" : "/domains/diku-alfa/room/30.zon/rm_3008",
        ] ));
}

void init(){
   ::init();
}

int CanReceive(object ob){
    if( ob && (!inherits(LIB_NPC, ob)) ){
        return 1;
    }
    else
        return 0;
}
