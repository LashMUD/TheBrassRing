/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>
#include <vendor_types.h>
inherit LIB_BOOK;

void create(){
    ::create();
    SetKeyName("wyr history");
    SetId( ({"book", "history", "history book"}) );
    SetAdjectives( ({"old", "leather"}) );
    SetShort("a history book");
    SetLong("This is a short history of Wyr.");
    SetProperties(([
                "no steal" : 1,
                ]));
    SetMass(3);
    SetBaseCost("gold",10);
    SetVendorType(VT_TREASURE);
    SetTitle("A Short History of Wyr");
    SetSource("/domains/etnar/wyr/books/wyrhistory");
    SetDefaultRead("Try \"read chapter 1 in book\"");

}
void init(){
    ::init();
}
