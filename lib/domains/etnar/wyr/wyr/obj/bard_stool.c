/*   Modified by lash (ccoker) for use with:
 *
 *   The Dead Souls Mud Library
 *   developed by Cratylus
 *   http://www.dead-souls.net
 */

#include <lib.h>
inherit LIB_BASE_DUMMY;
inherit LIB_SIT;
inherit LIB_SURFACE;

static void create() {
    base_dummy::create();
    surface::create();
    SetKeyName("stool");
    SetId("stool");
    SetAdjectives("wooden");
    SetShort("a small plain stool");
    SetLong("This is a simple stool that someone may sit upon to play an instrument.");
    SetMaxSitters(1);
    SetInvis(1);
    SetPreventGet("The stool does not budge.");
}

void init(){
   ::init();
}
