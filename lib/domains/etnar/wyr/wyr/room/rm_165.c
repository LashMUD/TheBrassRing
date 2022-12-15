/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>

inherit LIB_ROOM;

static void create() {
 
    object ob;

    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("%^BOLD%^The Town Hall%^RESET%^");
    SetLong("   You enter the Town Hall. Although modest in size, the place "
        "is very busy. A huge bulletin board dominates the room and you can "
        "see townspeople busily writing or reading messages. This board "
        "serves as a local gossip forum. If you look at the board you will "
        "find instructions for its use.");
    ob = new("/lib/bboard");
    ob->SetKeyName("bulletin board");
    ob->SetId( ({ "board", "bulletin", "dusty board", "bulletin board" }) );
    ob->set_board_id("wyr_town_hall_general_board");
    ob->set_max_posts(30);
    ob->SetShort("a bulletin board");
    ob->SetLong("A large bulletin board is mounted on a wall here.\n"+
                "It is a board for reading and posting messages. To read the\n"+
                "first message: read 1\nTo post a message: post <message title>\n");
    ob->eventMove(this_object());
    SetItems( ([ 
        "west" : "The main Road through the Village of Wyr running north and south.",
        ] ));
    SetExits( ([
        "west" : "/domains/etnar/wyr/wyr/room/rm_114",
        ] ));
}

void init(){
   ::init();
}
