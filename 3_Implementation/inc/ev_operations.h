/** 
* @file calculator_operations.h
* Calculator application with 4 mathematical operations
*
*/
#ifndef __EV_OPERATIONS_H__
#define __EV_OPERATIONS_H__


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
//s

//suj

//sas

int gearRatio = 12;
float radius = 0.2794;
float accelerationTiming = 7;
float Mass = 2746.8;
float pi = M_PI;
int Voltage = 48;
int CurrentCapacity = 100;
float Torque;
/**
*  adds the operand1 and operand2 and returns the result
* @param[in] operand1 
* @param[in] operand2 
* @return Result of operand1 + operand2
*/
int StartVehicle(int Start);

/**
*  subtracts the operand1, operand2 and returns the result
* @param[in] operand1 
* @param[in] operand2 
* @return Result of operand1 - operand2
*/int StopVehicle(int WRPM, bool Stop);

/**
*  multiply the operand1, operand2 and returns the result
* @param[in] operand1 
* @param[in] operand2 
* @return Result of operand1 * operand2
*/
float Fspeed(int WRPM, char Gear);


/**
* divides the operand1 by operand2 and returns the result 
* @param[in] operand1 
* @param[in] operand2 
* @return integer value of the operand1 / operand2
* @note returns 0 for divide by 0 error
*/
float Rspeed(int WRPM, char Gear);

char Neutral(char Gear);
float ForceAndTorqueCurrent(int WRPM, char Gear);
char GearIndicator(char Gear);
int MotorRPM(int WRPM);
void TemperatureIndicator(float Temp);
void ParkingSensor(float ParkingDistance);

#endif  /* #define __CALCULATOR_OPERATIONS_H__ */
