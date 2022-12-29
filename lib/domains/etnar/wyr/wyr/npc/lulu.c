#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("Lulu");
    SetId(({"goat"}));
    SetAdjectives(({"wooly", "non player"}));
    SetShort("Lulu the goat");
    SetLong("A small, rambunctious goat with a small bell hanging around its "
        "neck wanders the yard munching on the grass. She wears a small "
        "nametag that reads 'LuLu'."
        );
    SetLevel(1);
    SetRace("goat");
    SetGender("female");
    SetAction(15, ({
        "LuLu quietly munches on some grass.",
        "LuLu shakes her head tinkling the small bell around her neck.",
        "LuLu looks at you with inquisitive eyes.",
    }) );
        
}
void init(){
    ::init();
}
