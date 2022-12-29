/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
inherit LIB_PRESS;
inherit "/lib/events/manipulate";

int MoveTapestry();
int PushTapestry();
void create(){
    ::create();
    SetKeyName("black tapestry");
    SetId( ({"tapestry", "black"}) );
    SetShort("a black tapestry");
    SetLong("This black tapestry with a gold outline covers the wall and features the \n"+
        "symbol of Balcor - an ambossed black rearing stallion against a lightning \n"
        "filled sky.\n"+
        "One of the edges is worn a bit more than the rest of the material.");
    SetManipulate( ([ "default" : (: MoveTapestry :) ]) );
    SetPress( ([ "default" : (: PushTapestry :) ]) );
}

mixed CanGet(object ob){ 
    return "The tapestry appears to be attached to the wall.";
}

int MoveTapestry(){
    send_messages("move", "$agent_name $agent_verb the tapestry.",
        this_player(), 0, environment(this_player()));
    environment(this_object())->RevealDoor();
    return 1;
}

int PushTapestry(){
    send_messages("move", "$agent_name $agent_verb the tapestry.",
        this_player(), 0, environment(this_player()));
    environment(this_object())->RevealDoor();
    return 1;
}

void init(){
    ::init();
}
