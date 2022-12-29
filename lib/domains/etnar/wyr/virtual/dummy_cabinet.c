#include <lib.h>

inherit LIB_BASE_DUMMY;
inherit LIB_STORAGE;

void create(){
    base_dummy::create();
    storage::create();
    SetKeyName("cabinet");
    SetId(({"cabinet"}));
    SetShort("cabinet");
    SetLong("Through the glass doors you can see some trinkets sitting on "
            "three wooden shelves. The middle shelf has a small cloth doll sitting "
            "against the back of the cabinet.");
    SetCanClose(1);
    SetClosed(1);
    SetCanLock(1);
    SetLocked(1);
}

mixed CanGet(object ob) { return "The cabinet is very heavy and affixed to the back wall.";}
