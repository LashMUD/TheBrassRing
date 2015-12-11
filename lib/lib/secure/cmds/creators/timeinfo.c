/*
 *  /lib/secure/cmds/creators
 *  Some info about some variables associated
 *  with timekeeping in the Mud
 *  version 1.0 2011/10/13
 *  Added by Lash (ccoker) and modified 2015/12/03
 *  for use in The Brass Ring
 */


#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd() {
    int *mudtime;
    int integer, hours, minutes;
    string meridiem = " am";
    string nulle = "";
    int daynum = query_date();

    if(!archp(previous_object())) return 0;
    write("\ntime() is "+time()+"\n");
    write("ctime() is "+ctime()+"\n");
    write("GetTickTock() is "+SEASONS_D->GetTickTock()+"\n");
    //write("GetPhaseName() of the moon is "+SEASONS_D->GetPhaseName()+"\n");
    write("GetTime(time()) is "+SEASONS_D->GetTime(time())+"\n");
    write("GetTime(time()) % (DAY_LENGTH * HOUR_LENGTH) is "+SEASONS_D->GetTime(time()) % (DAY_LENGTH * HOUR_LENGTH)+"\n");
    write("GetTime(time())/(DAY_LENGTH * HOUR_LENGTH) is "+SEASONS_D->GetTime(time())/(DAY_LENGTH * HOUR_LENGTH)+"\n");
    write("GetCurrentTime() is "+SEASONS_D->GetCurrentTime()+"\n");
    write("GetHour(time()) is "+SEASONS_D->GetHour(time())+"\n");
    write("GetMinutes(time()) is "+SEASONS_D->GetMinutes(time())+"\n");
    write("DAY_LENGTH is "+DAY_LENGTH+" and HOUR_LENGTH is "+HOUR_LENGTH+"\n");
    write("DAY_LENGTH * HOUR_LENGTH is "+DAY_LENGTH * HOUR_LENGTH+"\n");
        
    mudtime = SEASONS_D->GetMudTime();
    hours = mudtime[0];
    minutes = mudtime[1];

    if(hours >= 12  && hours != 24) {
        if(hours != 12) hours -= 12;
        meridiem = " pm";
    }

    if(!hours || hours == 0) hours = 12;

    if(minutes < 10) nulle = "0";

    write("In the MUD, the time is "+hours+":"+nulle+minutes+meridiem+".\n");
    write("It is "+query_day_name()+", "+daynum+ordinal(daynum)+" day of "+
            query_month()+", in "+query_season()+" in the year "+query_year()+".\n"); 

    return 1;

}

string GetHelp(){
    return ("Syntax: timeinfo \n\n"
            "Gives the current state of some of the variables\n"+
            "used in time functions.");
}
