/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

void read_scroll();

void create(){
    ::create();
    SetKeyName("scroll");
    SetId(({"scroll of recall", "recall", "scroll"}));
    SetAdjectives(({"none"}));
    SetShort("a scroll of recall to Wyr");
    SetLong("The scroll has written a formulae of 'Word of Recall' upon it. "
            "read 'recall on scroll' and you will be transported to a four "
            "way intersection in the village of Wyr." );
    SetMass(1);
    SetBaseCost("gold", 500);
    SetVendorType(VT_MAGIC);
    SetRead( ([
        "recall" : (:read_scroll:)
        ]) );
    SetLanguage("common");
    SetProperty("magic item", 1);
}

void init(){
    ::init();
}

void read_scroll(){
    
    tell_player(this_player(), "\nThe scroll crumbles into dust...\n");
    this_player()->eventMoveLiving("/domains/etnar/wyr/room/rm_116",
                                   this_player()->GetName()+" disappears!", 
                                   this_player()->GetName()+" appears in the middle of the intersection.");
    this_object()->eventDestruct();
}
