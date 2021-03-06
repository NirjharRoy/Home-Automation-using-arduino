/*The following file has been written by 
1) Nandini Banerjee - Responsible for light on/off.
2) Nirjhar Roy       - Responsible for fanspeed control and alarm ringing.
*/




/*The following segment is used to initialize the hardware with default settings.
AUTHOR - NIRJHAR ROY
*/
int bulbPinop = 13;
int alarmPinip = 8;
int alarmPinop=7;
int fanPinop=4;
int prev;
boolean x= true;
int speedf=255;
int d=-1;
void setup() {
  
  // setup code put here, to run once:
  pinMode(bulbPinop,OUTPUT);
  pinMode(fanPinop,OUTPUT);
  pinMode(alarmPinop,OUTPUT);
  pinMode(alarmPinip,INPUT);
  prev= digitalRead(alarmPinip);
  digitalWrite(bulbPinop,HIGH);
  digitalWrite(alarmPinop,HIGH);
  Serial.begin(9600); 
}
//The above segment for initialization written by NIRJHAR ROY ends here.


void loop() 
{
  
  // main code put here, to run repeatedly:
 
    /*The following segment recieves a signal and sounds alarm.
    AUTHOR - NIRJHAR ROY
    */
    int current= digitalRead(alarmPinip);  
    //analogWrite(fanPinop,1);
    char bs;
    if(current!=prev )
    {
       
        
        soundAlarm();
        prev=digitalRead(alarmPinip);
        Serial.write('1');
        
    }
    //The above segment to sound alarm written by NIRJHAR ROY  ends here    

    




    
    
    bs=Serial.read();   

   
    /*The below segment recieves a light on/off signal and turns light on/off
    AUTHOR - NANDINI BANERJEE
    */  
    if(bs=='1')
    {
      digitalWrite(bulbPinop,LOW);
      
      
    }
    if(bs=='0')
    {
      digitalWrite(bulbPinop,HIGH);
      
    }
    //The above segment to turn light on/off written by NANDINI BANERJEE ends here




    

    /*The below segment recieves a fanspeed signal and sets the fan speed
    AUTHOR - NIRJHAR ROY
    */ 

    if( bs>='a' && bs<='z')
    {
        
        //Serial.println(bs);
        switch(bs)
        {
          case 'a': d=-1;
                    break;
          case 'b': d=25;
                    break;
          case 'c': d=35;
                    break;
          case 'd': d=65;
                    break;
          case 'e': d=90;
                    break;
          case 'f': d=0;
                    break;         
        }
        bs='\0';
        
    }
    
    
    if(d==-1)
        digitalWrite(fanPinop,HIGH);
    else
    {
        digitalWrite(fanPinop,HIGH);
        delay(d);
        digitalWrite(fanPinop,LOW);    
        delay(d);
    }
   // The above segment to control fan speed written by NIRJHAR ROY ends here
    
    
  }
  



    /*The below segment sounds alarm
    AUTHOR - NIRJHAR ROY
    */ 
  void soundAlarm()
  {
   
    digitalWrite(alarmPinop,LOW);
    delay(500);
    digitalWrite(alarmPinop,HIGH);
    
  }
//The above segment to sound alarm written by NIRJHAR ROY ends here
