
#include "ARDroneAPI.h"
#include "compat.h"
#include <iostream>

using namespace std;

#define SPEED 0.1

void vision_test_cbc();
void connect_takeoff();
void land_disconnect();
void takeoff_test(int hover_time);
void move_test(double speed, int movement_time);
void navdata_test();
void emergency_test();
void flying_mode_test(int flying_time);

int main(int argc, char** argv)
{
	connect_takeoff();
	
    drone_hover();
    float alt;
    
    for(int i=0; i<5000; i++){
        alt = drone_get_z();
        drone_move(0,0,0,0);
        printf("Alitude = %f\n", alt);
        sleep(.5);
    }
	
	land_disconnect();
	
	return 0;
}
//This function wraps the connect takeoff and initial hover for me
void connect_takeoff()
{
	drone_connect();
    
	drone_takeoff();
	drone_takeoff();
	drone_takeoff();
	drone_hover();
	sleep(4); //sleep to ensure drone is up before moving
}

//this function wraps the land and disconnect for me
void land_disconnect()
{
	drone_land();
	drone_disconnect();
}
