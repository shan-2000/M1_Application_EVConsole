#include <C:\Users\HAI\OneDrive\Documents\GitHub\M1_Application_EVConsole\3_Implementation\inc\ev_operations.h>

/* Status of the operation requested */
#define VALID   (1)
#define INVALID (0)

/* Calculator operation requested by user*/
unsigned int ev_operation = 0;

/* Operands on which calculation is performed */
//Global Variable



/* Display the menu of operations supported */

/* Verifies the requested operations validity */


/* Start of the application */
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
