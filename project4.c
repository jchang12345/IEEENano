#define Button1 7
#define Button2 8
#define LED1 5
#define LED2 6
#define R 9
#define G 11
#define B 10
#include <time.h>
void setup() {
    // put your setup code here, to run once:
    randomSeed(analogRead(0));
    Serial.begin(9600);
    pinMode(Button1,INPUT);
    pinMode(Button2,INPUT);
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(R,OUTPUT);
    pinMode(G,OUTPUT);
    pinMode(B,OUTPUT);
    
    
}

void loop() {
    // put your main code here, to run repeatedly:
    int randoNum= random(30);
    while(randoNum<15)
    {
        randoNum=random(30);
    }
    //rr until u get a number between 15 and 30, ill double check that w/ a serial print
    Serial.println(randoNum);
    int andy=255;
    bool isbuttonPressed2=digitalRead(Button2), isbuttonPressed=digitalRead(Button1);
    int pushcounter1=0, pushcounter2=0;
    andy=andy/randoNum;
    int currentBrightness;
    
    //should all be digital write or read of some sort, but thats what they want you to think with the digital ports
    //actually, can use PWM (Pulse width modulation) which says that you can use analog for digital ports : 3,5,6,9,10,11
    if(isbuttonPressed)
    { //if pcurrentbrightness is 255, we want to check if delay is 1000 before we deem player winner
        
        pushcounter1++;
        //gives u 15 "levels of brightness"
        
        currentBrightness+=andy;
        analogWrite(LED1,currentBrightness);
        
    }
    else
    {
        analogWrite(LED1,LOW);
    }
    if(isbuttonPressed2)
    {
        analogWrite(LED2,currentBrightness);
        pushcounter2++;
    }
    else
    {
        analogWrite(LED2,LOW);
    }
    
}







