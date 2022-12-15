/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
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
        "east" : "/domains/etnar/wyr/wyr/room/rm_172",
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
