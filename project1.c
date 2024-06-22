/*
 * project1.c
 *
 *  Created on: Jul 31, 2023
 *      Author: hp
 */
#include <stdio.h>
#include <stdlib.h>
#include "project1.h"
#define ON   1
#define OFF  2
#define QUIT 3
#define WITH_ENGINE_TEMP_CONTROLLER 0
/**********************************************************************************************
 *                                 global variables
 *********************************************************************************************/
int speed=0;
int newTemp=0;
int newEngineTemp=0;
int AC=0;
int controller =0;
int Engine_State =0;

/********************************************************************************************
 *                                  functions_definition
 *****************************************************************************************/
int start(void)
{
	int choice;
	printf("1- Turn on the vehicle engine \n"
		   "2- Turn off the vehicle engine \n"
		   "3- Quit the system \n");
	fflush(stdout);
	scanf(" %d", &choice);
	return choice;
}
void quit (void)
{
	printf("QUIT");
	fflush(stdout);
	exit(0);
}
void  light (char traffic)
{

	if ( traffic == 'G')
	{
		speed = 100;
	}
	else if ( traffic == 'O')
	{
		speed = 30;
	}
	else if ( traffic == 'R')
	{
		speed = 0;
	}
}
void speedCheck(int speed)
{
	if (speed == 30)
	{
		if (AC == 0)
		{
			AC =1;
		}
		newTemp = newTemp * (5/4) + 1;
		if (controller == 0)
		{
			controller =1;
		}
		newEngineTemp = newEngineTemp * (5/4) + 1;
	}

}
void room_temp(int temp)
{
	if ( temp < 10)
	{
		AC = 1;
		newTemp = 20;
	}
	else if ( temp > 30)
	{
		AC = 1;
		newTemp = 20;
	}
	else
	{
		AC=0;
		newTemp=temp;
	}
}
void engine_temp(int engineTemp)
{


		if (engineTemp < 100)

	{
		controller =1;
		newEngineTemp = 125;
	}
	else if (engineTemp > 150)
	{
		controller =1;
		newEngineTemp = 125;
	}
	else
	{
		controller =0;
		newEngineTemp = engineTemp;
	}
}


void on ()
{
	Engine_State =1;
	int choose_on;
	char traffic;
	int temp;
	int engineTemp;
	printf ("sensors set menu \n");
	printf ("1- Turn off the engine. \n"
			"2- Set the traffic light color. \n"
			"3- Set the room temperature (Temperature Sensor) \n"
			"4- Set the engine temperature (Engine Temperature Sensor) \n");
	fflush(stdout);
	scanf(" %d",&choose_on);
	if ( choose_on == 1)
	{
		off();

	}
	else if ( choose_on == 2)
	{
		printf("please enter the traffic light");
		fflush(stdout);
		scanf(" %c",&traffic);
		light(traffic);
	}
	else if ( choose_on == 3)
	{
		printf ("please enter the room temp");
		fflush(stdout);
		scanf(" %d",&temp);
		room_temp (temp);
	}
	else if ( choose_on == 4)
	{
		if (WITH_ENGINE_TEMP_CONTROLLER == 1)
		{
	    printf("please enter the engine temp");
		fflush(stdout);
		scanf( "%d",&engineTemp);
		engine_temp(engineTemp);
	    }
		else
		{
			printf("error \n");
			fflush(stdout);
		}
    }


}
void off ()
{
	Engine_State =2;
	int res2;
	res2=start();
	if (res2 == QUIT)
	{
		printf("QUIT");
		quit();
	}
	else if (res2 == OFF)
	{
		printf("OFF");
	}
	else if (res2 == ON)
	{
		printf("ON");
		on();
	}
}
void display()
{
	if (Engine_State == 1)
	{
		printf("Engine State= ON \n");
		fflush(stdout);
	}
	else if (Engine_State == 2)
	{
		printf("Engine State= OFF \n");
		fflush(stdout);
	}
	printf("AC= %d \n",AC);
	printf("vehicle speed= %d \n",speed);
	printf("room temp= %d \n",newTemp);
	printf("Engine Temperature Controller State= %d \n",controller);
	printf("Engine Temp= %d",newEngineTemp);

}

/**********************************************************************************************
 *                                    main function
 *********************************************************************************************/
int main ()
{
	int res;
	res = start();
	if ( res == QUIT)
	{
		quit();
	}
	else if ( res == OFF)
	{
		off();
	}
	else if ( res == ON)
	{
		on();
		speedCheck(speed);
	}
	display();


}

