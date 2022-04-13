#include<SoftwareSerial.h>

#define SER 8
#define LATCH 9
#define CLK 10

//Bluetooth serial 
const int txpin = 5;       
const int rxpin = 6;


SoftwareSerial blue(txpin, rxpin);
String Led_name  ;


void setup() {

   blue.begin(9600);
  blue.setTimeout(10);
 
}

void loop() {

while(blue.available()){
     char character = blue.read(); // Receive a single character from the software serial port
        Led_name.concat(character); // Add the received character to the receive buffer
        if (character == '#')//If end of message character recieved, move on.
        {
       
            if(Led_name == "20#"){
            Target_Led(B00000000,B00000000,B01000000); //Led_one
            blue.println("Led Name : "+Led_name+" is on");        
            }

            if(Led_name == "40#"){
            Target_Led(B00000000,B00000000,B00100000); //Led_two
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "60#"){
            Target_Led(B00000000,B00000000,B00010000); //Led_three
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "80#"){
            Target_Led(B00000000,B00000000,B00001000); //Led_foure
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "100#"){
            Target_Led(B00000000,B00000000,B00000100); //Led_five
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "120#"){
            Target_Led(B00000000,B00000000,B00000010); //Led_six
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "140#"){
            Target_Led(B00000000,B00000000,B00000001); //Led_seven
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "160#"){
            Target_Led(B00000000,B01000000,B00000000); //Led_eight
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "180#"){
            Target_Led(B00000000,B00100000,B00000000); //Led_nine
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "-180#"){
            Target_Led(B00000000,B00010000,B00000000); //Led_ten
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "-160#"){
            Target_Led(B00000000,B00001000,B00000000); //Led_eleven
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "-140#"){
            Target_Led(B00000000,B00000100,B00000000); //Led_twelve
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "-120#"){
            Target_Led(B00000000,B00000010,B00000000); //Led_thirteen
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "-100#"){
            Target_Led(B00000000,B00000001,B00000000); //Led_fourteen
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "-80#"){
            Target_Led(B01000000,B00000000,B00000000); //Led_fifteen
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "-60#"){
            Target_Led(B00100000,B00000000,B00000000); //Led_sixteen
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "-40#"){
            Target_Led(B00010000,B00000000,B00000000); //Led_seventeen
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            if(Led_name == "-20#"){
            Target_Led(B00001000,B00000000,B00000000); //Led_eighteen
            blue.println("Led Name : "+Led_name+" is on"); 
            }

            
           Led_name =""; //clear the buffer/message
           Serial.println();
           delay(1000);
      
  }
  
}
 
 
 

  
}


void Target_Led (byte Row1,byte Row2,byte Row3){
    pinMode(SER,OUTPUT);
    pinMode(LATCH,OUTPUT);
    pinMode(CLK,OUTPUT);
    digitalWrite(LATCH,LOW);
  shiftOut(SER,CLK,LSBFIRST,Row1);
  shiftOut(SER,CLK,LSBFIRST,Row2);
  shiftOut(SER,CLK,LSBFIRST,Row3);
  digitalWrite(LATCH,HIGH);
}
