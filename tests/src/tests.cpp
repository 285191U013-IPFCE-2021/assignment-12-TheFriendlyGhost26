#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.hpp"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 
TEST_CASE("Duration")
{
    //Duration() is 0
    Duration clock = Duration();
    REQUIRE(clock.getDuration() == 0); 

    //Duration(int t) = 10
    clock = Duration(10);
    REQUIRE(clock.getDuration() == 10);

    // test if we set time back, set to 3
    clock = Duration(3);
    REQUIRE(clock.getDuration() == 3);
}

TEST_CASE("tick")
{
    Duration clock = Duration(); //starts at 0
    clock.tick(); //adds 1, 0 -> 1
    REQUIRE(clock.getDuration() == 1);
    clock.tick(0); //should stay at 1 since we are adding 0
    REQUIRE(clock.getDuration() == 1);
    clock.tick(10); //should be 11 when adding 10
    REQUIRE(clock.getDuration() == 11);
}

TEST_CASE("alarm")
{
    Duration clock = Duration(); //starts at 0
    REQUIRE(clock.HasAlarmBeenSet() == false); //should by default be false
    clock.setAlarm(10);
    REQUIRE(clock.HasAlarmBeenSet() == true);
    clock.tick(10); 
    REQUIRE(clock.getDuration() == 10); // test if time = 10
    REQUIRE(clock.HasAlarmBeenSet() == false); //when the alarm goes off as true, it should reset to false afterwards 
    
    // test: if user tries to set alarm value to a value in the past
    clock.setAlarm(1);
    REQUIRE(clock.HasAlarmBeenSet() == false);
}