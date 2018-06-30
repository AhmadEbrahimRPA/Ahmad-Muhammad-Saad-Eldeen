# Ahmad-Muhammad-Saad-Eldeen
XIOT task
* what I wanted to accomplish with my application?
I made a time triggerd system checks keypress every 50ms and toggle LED, also every 3s sends data comes from temperature sensor. Time triggerd system done by one interrupt every 50ms.
The system perform tasks every tick time.
The system has 3 tasks : 
1- SW_Update : its period every 50ms (every tick), it updates switch samples and switcj state (period >= bouncing time).
2- Control : its period every 50ms (every tick), it checks keypress then toggle the LED and send “pressed” to the serial monitor only one time also send the LED states ”ON” or “OFF”.
3- sensor_update: its period every 3000ms (every 60 ticks), it reads temperature sensor reading using ADC then send it.

*what I learned in the process?
 I gained more experience in embedded developing, I also lernt how to use github and upload my projects
 
 *how much experience I have with the C language and framework I chose?
 I have +3 years experience in C programming and +2 years in Embedded developing and software design
