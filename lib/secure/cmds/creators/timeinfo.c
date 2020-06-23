/*    /lib/secure/cmds/creators/timeinfo.c
 *    based on the Dead Souls mud library
 *    maintained by Cratylus http://www.dead-souls.net
 * 
 *    created by lash (ccoker) for use in
 *    The Brass Ring mud
 *     - Some info about some variables associated
 *       with timekeeping in the Mud
 *    modified: 11/10/13
 *     - added more varables to the output
 *    last modified: 20-05-20  
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
    write("\nctime(0) is "+ctime(0)+"\n");
    write("ctime() is "+ctime()+"\n");
    write("time() is "+time()+" seconds since "+ctime(0)+"\n");
    write("DAY_ONE of "+mud_name()+" is "+DAY_ONE+" ; "+ctime(DAY_ONE)+"\n");
    write("DAY_ONE of Dead Souls is 720550800"+" ; "+ctime(720550800)+"\n");
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
    write("GetYear() is "+SEASONS_D->GetYear()+"\n");
    write("GetYearString is "+SEASONS_D->GetYearString()+"\n"); 
        
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
