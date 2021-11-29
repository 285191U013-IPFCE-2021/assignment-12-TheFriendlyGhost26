#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include "../include/duration.hpp"

int Duration::getDuration(){

    return time;    
   
}

Duration::Duration()
{
    time = 0;
    alarm = -1; // default value for alarm
    alarmHasBeenSet = false;
}

Duration::Duration(int t)
{
    assert(t >= 0);

    time = t;
    alarm = -1; //start value
    alarmHasBeenSet = false; //start value
}

Duration::~Duration()
{}


bool Duration:: tick()
{
    time++; //adds one like a clock counts seconds

    return checkAndUpdateAlarm();
}

// adds an amount, dt, to time
bool Duration:: tick(int dt)
{
    assert(dt >= 0); //using assert to ensure that the amount added is greater than zero
    time += dt;

   return checkAndUpdateAlarm();
}

void Duration:: setAlarm(int t)
{   
//if the user make an input to alarm
    if(t > time)
    {
        alarm = t;
        alarmHasBeenSet = true;
    }

    return;
}


bool Duration:: checkAndUpdateAlarm()
{
    //when time equals alarm it goes off
    if (time >= alarm)
    {
        //alarm is reset
        alarm = -1; 

        //so is the boolean value from true to false
        alarmHasBeenSet = false;

        return true;
    }
    
    return false;
}

bool Duration:: HasAlarmBeenSet()
{
    return alarmHasBeenSet;
}