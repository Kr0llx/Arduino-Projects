/*
#############################################################################################
Autor: Sören Krollmann
[04.12.2012]
cycles through the 8 channels and a multiplexer and changes the outputs sequentially to HIGH
A0-A2 connected to Pin 8-10 on the Arduino
#############################################################################################
*/

const int a0 = 8; // A0 MX-Adress to Pin 8
const int a1 = 9; // A1 MX-Adress to Pin 9
const int a2 = 10; // A2 MX-Adress to Pin 10


void setup()
{ 
  delay(1000); //Start Delay

  pinMode(a0, OUTPUT); // set Pin 8 to output
  pinMode(a1, OUTPUT); // set Pin 9 to output
  pinMode(a2, OUTPUT); // set Pin 10 to output
 

  // Reset all (LOW)
  digitalWrite(a0, LOW);  
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
}

void loop()
{
   int oPins[] = {a0, a1, a2}; // Array for Output-Pins

  int mxChannel[8][3]= // Array for Channels
  {
    {0,0,0}, //output pin layouts for Channel 0
    {1,0,0}, //...Channel 1
    {0,1,0}, //...Channel 2
    {1,1,0}, //...Channel 3
    {0,0,1}, //...Channel 4
    {1,0,1}, //...Channel 5
    {0,1,1}, //...Channel 6
    {1,1,1}, //...Channel 7
   };
  
  for(int channel=0; channel<8; channel ++) //Flip through all channels
  {
    for(int counter = 0; counter < 3; counter ++) //for writing the 3 Bit Adresses of each channel
    {
      digitalWrite(oPins[counter], mxChannel[channel][counter]); //Output Pin, Bit
    }
    delay(500); //Blink Delay
  }
}
