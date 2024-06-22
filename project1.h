/*
 * project1.h
 *
 *  Created on: Jul 31, 2023
 *      Author: hp
 */

#ifndef PROJECT1_H_
#define PROJECT1_H_
/**********************************************************************************************
 *                                   functions_prototype
 ********************************************************************************************/

/*
 * description: starting the program
 */
int start(void);

/*
 * description : quit the program
 */
void quit (void);

/*
 * description : turn on the vehicle engine
 */
void on ();

/*
 * description : turn off the vehicle engine
 */
void off ();

/*
 * description : based on traffic light set speed
 */
void  light (char traffic);
/*
 * description : based on room temp set AC and temp
 */
void room_temp(int temp);
/*
 *  description : based on engine temp set controller
 */
void engine_temp(int engineTemp);
/*
 * description: check speed
 */
void speedCheck(int speed);
/*
 * description: display the state of each
 */
void display();
#endif /* PROJECT1_H_ */
