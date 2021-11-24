#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

//Global Variable
int gearRatio = 12;
float radius = 0.2794;
float accelerationTiming = 7;
float Mass = 2746.8;
float pi = M_PI;
int Voltage = 48;
int CurrentCapacity = 100;
float Torque;


//function declarations
int StartVehicle(int Start);
int StopVehicle(int WRPM, bool Stop);
float Fspeed(int WRPM, char Gear);
float Rspeed(int WRPM, char Gear);
char Neutral(char Gear);
float ForceAndTorqueCurrent(int WRPM, char Gear);
char GearIndicator(char Gear);
int MotorRPM(int WRPM);
void TemperatureIndicator(float Temp);
void ParkingSensor(float ParkingDistance);

//main function
void main()
{
   int VehicleCondition, WheelSpeed, Temperature;
   char InputGear;
   float PDistance;
   printf("Enter the Vehicle state 1(Start) or 0(Stop) : ");
   scanf("%d", &VehicleCondition);
   // printf("\n\n\n %d", VehicleCondition);
   
   // printf("  %d", Condition);
   if (VehicleCondition==1)
   {
      int Condition= StartVehicle(VehicleCondition);
      printf("\nEnter the gear (F N R): ");
      scanf("%s",&InputGear);
      char SelectedGear = GearIndicator(InputGear);
      printf("%c",SelectedGear);

      if (SelectedGear == 'F')
      {
         printf("\nEnter the Wheel Speed in RPM : ");
         scanf("%d",&WheelSpeed);
         float FVehicleSpeed = Fspeed(WheelSpeed, SelectedGear);
         printf("\n\n The forward speed of the vehicle is : %0.2f", FVehicleSpeed);
      }
      else if(SelectedGear == 'R')
      {
         printf("\nEnter the Wheel Speed in RPM : ");
      scanf("%d",&WheelSpeed);
         float RVehicleSpeed = Rspeed(WheelSpeed, SelectedGear);
         printf("\n\n The reverse speed of the vehicle is : %0.2f", RVehicleSpeed);

      }
      else
      {
         Neutral(SelectedGear);

      }

      printf("\nTo calculate force- \n ");
      ForceAndTorqueCurrent(WheelSpeed, SelectedGear);

      printf("\n\nDisplaying the Motor Speed\n");
      MotorRPM(WheelSpeed);

      printf("\n\nDisplaying the Temperature\n");
      printf("\nEnter the temperature : ");
      scanf("%d",&Temperature);
      TemperatureIndicator(Temperature);


      printf("\n\nDisplaying Parking Sensor\n");
      scanf("%0.2f",&PDistance); 
      ParkingSensor(PDistance);

   }
   else    
   {
      printf("\n\nEnter the Wheel Speed in RPM : ");
         scanf("%d",&WheelSpeed);
      StopVehicle(WheelSpeed,VehicleCondition);
   }
  
}

int StartVehicle(int Start)//Start takes 1 or 0 where 1 means vehicle is started and 0 meand vehicle is off
{
   printf("\n Car is started \n");
   return Start;
}

int StopVehicle(int WRPM, bool Stop)//Start takes 1 or 0 where 1 means vehicle is started and 0 meand vehicle is off
{
   printf("\nCar is stopped\n");
   if(WRPM !=0)
   {
      printf("CAUTION...! Please apply hand break");
   }
   return Stop;
}


float Fspeed(int WRPM, char Gear)
{
   if (Gear == 'F')
   {
      float FVehicleSpeed = 0.1885 * WRPM * radius;
      printf("%0.2f kmph", FVehicleSpeed);
      //return FVehicleSpeed; //kmph
      if (FVehicleSpeed > 40)
      {
         printf(" CAUTION...!  The Speed if the vehicle is HIGH");
      }
      else if(FVehicleSpeed< 40)
      {
         printf("\nThe Speed is in the limit");
      }
      return FVehicleSpeed;
   }

   
}
//function for Reverse speed calculation
float Rspeed(int WRPM, char Gear)
{
   if (Gear == 'R' && WRPM<=380)//Maximum rever speed is 380RPM
   {
      float RVehicleSpeed = 0.1885 * WRPM * radius;
      printf("%0.2f Rspeed", RVehicleSpeed);
      printf("\n The vehicle is ");
      return RVehicleSpeed;
   }
   
}
char Neutral(char Gear)
{
   if (Gear == 'N' )
   {
      float NVehicleSpeed = 0.0;
      printf("\nThe vehicle is in neutral ");
   }
   
}
float ForceAndTorqueCurrent(int WRPM, char Gear)
{
   if (Gear == 'F' || Gear == 'R')
   {
   
      float LSpeed = 0.1047 * WRPM * radius;
      printf("speed in m/s : %0.2f\n",LSpeed);
      float Acceleration = LSpeed/accelerationTiming;
      printf("%0.2f Accel\n", Acceleration);
      float Force = Mass * Acceleration;
      printf("%0.2f force\n", Force);

      float Torque = Force * radius;
      float power = (2 * pi * WRPM * Torque) / 60;
      float Current = power / Voltage;
      float StateOfCharge = Current/CurrentCapacity;
      printf("%0.2f %0.2f",Current, StateOfCharge );
      printf("%0.2f torque\n", Torque);

   }
   else
   {
      printf("vehicle is in neutral"); //for neural
   }
  
}
char GearIndicator(char Gear)
{
   switch (Gear)
   {
   case 'F':
   {
      return Gear;
      break;
   }
   case 'R':
   {
      return Gear;
      break;
   }
   default:
   {
   if(Gear != 'F' && Gear !='R' && Gear =='N')
   {
      return Gear;
      break;
   }
   else
   {
      printf("\nError - Incorrect input");
   }
   }
   }
   
}

int MotorRPM(int WRPM)
{
   int MRPM = WRPM * gearRatio;
   printf("%d", MRPM);
   return MRPM;
}

void TemperatureIndicator(float Temp)
{
  if (Temp<=70)
  {
     printf("The system temperature is %0.2f Degree /n", Temp);
  }
  else if(Temp>70)
  {
     printf("CAUTION...! %0.2f is High Temperature", Temp);
  }  
}

void ParkingSensor(float ParkingDistance)
{ 
   printf("%0.2f", ParkingDistance);
   if(ParkingDistance <=2)
   {
      printf("CAUTION...! Parking Alarm");
   }
   else
   {
      printf("No obstacle");
   }
}
