/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_ROOM;

int ReadSign();

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Village Supply Shop.%^RESET%^");
    SetLong("   You are inside what appears to be a small shop. Before you "
        "is a long counter containing various supplies; packs, torches, and "
        "lanterns. A sign hangs on the wall behind the counter. You notice a "
        "set of stairs, to your left, leading up.");
    SetItems( ([ 
        "west" : "",
        "up" : "Upstairs. You can see that the wooden stairs lead up to a "
             "doorway.",
        "down" : "",
        "sign" : "You can use these commands for trading:\n\n "

                 "Items available type:       ask <vendor> to list\n " 
                 "                            ask <vendor> to browse\n "
                 "                            ask <vendor> to browse <item(s)>\n\n "

                 "Buy an item type:           ask <vendor> to sell <item>/<item #>\n "
                 "                             or\n "
                 "                            buy <item>/<item #> from <vendor>\n\n " 
                 
                 "Value of item to sell type: ask <vendor> to appraise <item>\n\n "

                 "Sell item to vendor type:   ask <vendor> to buy <item>\n "
                 "                             or\n "
                 "                            sell <item> to vendor\n\n "
         ] ));
    SetInventory( ([
        
        ]) );
    SetRead( ([
            "sign" : (:ReadSign:),
    ]) ); 
    SetExits( ([
         "west" : "/domains/etnar/wyr/wyr/room/rm_107",
         "up" : "/domains/etnar/wyr/wyr/room/rm_126",
         "down" : "/domains/etnar/wyr/wyr/room/rm_125",
         ] ));
}

mixed ReadSign(){
    return (mixed)this_player()->eventPage("/domains/etnar/wyr/text/vendorsign.txt");
}

void init(){
   ::init();
}
