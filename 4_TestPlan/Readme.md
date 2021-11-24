# TEST PLAN:

## Table no: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       |Speedometer                                                   |WheelRPM and Gear |Speed in KMPH|Speed in KMPH|Requirement based |
|  H_02       |Hand Break caution alarm. based on the WheelRPM and the Gear if gear in Neutral then the WheelRPM should be Zero if not the alarm gives caution                     |WheelRPM and Gear|CAUTION...! Hand Break Alarm |CAUTION...! Hand Break Alarm| Scenario based    |
|  H_03       |The Maximum reverse speed indicator                           |WheelRPM|Caution signal    |Caution signal|Boundary based    |

## Table no: Low level test plan

| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       |Speedometer                                                   |WheelRPM as 200 and Gear as F|10 kmph The speed is in limit|10 kmph The speed is in limit|Requirement based |
|  L_02       |When the vehicle is in neutral the WheelRPM should be zero or else error message should appear|WheelRPM as 2 and Gear as N|CAUTION...! Hand Break Alarm|CAUTION...! Hand Break Alarm|Scenario based    |
|  L_03       |The Maximum reverse speed is 20 KMPH which corresponds to WheelRPM as 380 |  WheelRPM as 390 and Gear as R|High Reverse Speed|High Reverse Speed|Boundary based    |
