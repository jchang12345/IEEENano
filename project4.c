#define Button1 7
#define Button2 8
#define LED1 5
#define LED2 6
#define R 9 
#define G 11 // p1
#define B 10 // p2
//#include <time.h>
#define DOWN 0
//#include <elapsedMillis.h>
#define UP 1
#define interval 1000
//elapsedMillis timer0;
//time checker

 unsigned long startTimer;
 //long prevTimer=0;
 //long interval=1000;
// max brightness
const double MAX_BRIGHTNESS = 255.0;


// random push amount goal
int randoNum;

// push counters
int player1PushCounter, player2PushCounter;

// simulate levels of brightness 
double brightnessPartition, currentBrightness1, currentBrightness2; //bp=brightnessPartition

// button pressed
bool isPlayer1ButtonPressed, isPlayer2ButtonPressed;
unsigned long CurrentTime;
// timers
//time_t player1Seconds, player2Seconds;

// winning player
int winnerNum;
int ElapsedTime;

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
  //startTimer=millis(); //start timer
  //CurrentTime = millis();
    // generating a random int from 15 to 30
    randoNum = random(30);
    while(randoNum<15)
    {
      delay(100);
        randoNum=random(30);
    }
    //rr until u get a number between 15 and 30, ill double check that w/ a serial print
   //got me randoNum=10;//comment this out later
    Serial.println(randoNum);
    Serial.println(" is your random #");
    // analog value change of each button push
    brightnessPartition = MAX_BRIGHTNESS / randoNum;

    // push counters
    player1PushCounter = 0;
    player2PushCounter = 0;

    //elapsedTime
    ElapsedTime=0;
    // button pressed
    isPlayer1ButtonPressed = false;
    isPlayer2ButtonPressed = false;
}


void loop() { //i need to check if they paused before they went and if they paused for 1 sec, that if they had won, then give them a winner statement 
    // put your main code here, to run repeatedly:
    //Serial.println(timer+ " is timer");
    isPlayer1ButtonPressed = digitalRead(Button1), isPlayer2ButtonPressed = digitalRead(Button2);
    //check for winners here
   // player1Seconds = time(0);
    //player2Seconds = time(0);
   //  timer = millis();
 
   //if(CurrentTime>interval)
   //{
//CurrentTime=CurrentTime-interval;
//}
  //prints time since program started
  //if(timer - prevTimer >interval)
  
    if(player1PushCounter==randoNum)
          {
           // int ElapsedTime = 0;
           // while(ElapsedTime<=900)
          //  {
             //how to start actual timer?
           // Serial.println("ET is");
            ElapsedTime+=10;
            //delay(100);
            Serial.println(ElapsedTime); //currently always reads 0.
           //  CountUpDownTimer(DOWN);
  // wait a second so as not to send massive amounts of data
 
   if(isPlayer1ButtonPressed&&ElapsedTime<900)
  {
    Serial.println("You made a mistkae, didn't wait that whole second, Player 1, you restart again. Player 1"); // losing message
          analogWrite(LED1, 0); // turn off led
          player1PushCounter=0;
          currentBrightness1=0;
          ElapsedTime=0;
          //break;
  }
  if(ElapsedTime>=900)
  {
            winnerNum = 1;
  }
          }//should all be digital write or read of some sort, but that's what they want you to think with the digital ports
        // }
          
          
          
          if(player2PushCounter == randoNum)
          {
           
            //int ElapsedTime = 0;
          //  while(ElapsedTime<900)
            //{
            ElapsedTime+=10;
          //  delay(100);
            Serial.println(ElapsedTime);
           // timer0-=interval
  //prints time since program started
  //Serial.println(timer);
  // wait a second so as not to send massive amounts of data
  //delay(1000);


  
  if(isPlayer2ButtonPressed&&ElapsedTime<900)
  {
    Serial.println("You made a mistkae, didn't wait that whole second, Player 1, you restart again. Player 1"); // losing message
          analogWrite(LED2, 0); // turn off led
          player2PushCounter=0;
          currentBrightness2=0;
          ElapsedTime=0;
          //break;
  }
  if(ElapsedTime>=900)
            winnerNum = 2;
          }
        // }
    //actually, can use PWM (Pulse width modulation) which says that you can use analog for digital ports : 3,5,6,9,10,11





    
    if(winnerNum == 0 && isPlayer1ButtonPressed)
    {   
        
        player1PushCounter++;
        delay(225);
       // Serial.println(player1PushCounter);
        //if currentbrightness is 255, we want to check if delay is 1000 before we deem player winner
        if(player1PushCounter == randoNum+1)
        {
          Serial.println("You made a mistkae, didn't wait that whole second, Player 1, you restart again. Player 1"); // losing message
          analogWrite(LED1, 0); // turn off led
          player1PushCounter=0;
          currentBrightness1=0;
        }
        else
        {
          //gives u "levels of brightness"
          currentBrightness1 += brightnessPartition;
          analogWrite(LED1,currentBrightness1); 
          Serial.println(player1PushCounter);
          Serial.println("How many times P1 you have pushed");
         // if(currentBrightness1 == MAX_BRIGHTNESS && player1Seconds > 1)
         // {
          //  winnerNum = 1;
          //}
        }      
    }

    if(winnerNum == 0 && isPlayer2ButtonPressed)
    {
       // player2Seconds = time(0);
        player2PushCounter++;
      delay(225);
        //if currentbrightness is 255, we want to check if delay is 1000 before we deem player winner
        if(player2PushCounter == randoNum+1)
        {
          Serial.println("You made a mistkae, didn't wait that whole second, Player 2, you restart again.");
          player2PushCounter=0;
          analogWrite(LED2, 0);
          currentBrightness2=0;
          //break; //break is only for loops, need diff alg for breaking out of an if statement
        }
        else
        {
          //gives u "levels of brightness"
          currentBrightness2 += brightnessPartition;
          analogWrite(LED2,currentBrightness2); 
          Serial.println(player2PushCounter);
          Serial.println("How many times P2 you have pushed");
        
        //  if(currentBrightness2 == MAX_BRIGHTNESS && player2Seconds > 1) //player has "waited" a second in this line
          //{
           // winnerNum = 2;
          //}
        }     
    }
//delay(1000);
    switch (winnerNum)
    {
      case 1:
        Serial.println("WINNER WINNER WINNER: Player 1");
        digitalWrite(G,HIGH);
        exit(0);
        break;
      case 2:
        Serial.println("WINNER WINNER WINNER: Player 2");
        digitalWrite(B,HIGH);
        exit(0);
        break;
    }
}

