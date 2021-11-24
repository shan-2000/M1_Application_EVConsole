#include <C:\Users\HAI\OneDrive\Documents\GitHub\M1_Application_EVConsole\3_Implementation\inc\ev_operations.h>


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
