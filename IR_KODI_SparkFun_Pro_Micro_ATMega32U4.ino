/*
*
*   KODI IR Remote Controll
*
 */
 
#include <Keyboard.h>
#include <IRremote.h>

 int IR_VCC   = 7; //VCC
 int IR_GND   = 6; //GND
 int RECV_PIN = 5; //Senzor Pin

 int LED_PIN  = 2;

IRrecv irrecv(RECV_PIN);
decode_results results;

//////////////////////////// V I P E R - I R - R E M O T E////////////////////////////

#define TVWind             0x10EF1AE5    //  Key  > h                   // TV     ponuka kanalov s epg
#define ChLP               0x10EF9867    //  Key  > 0 null              // 2 P/C  predosly program
#define Channels           0x10EF609F    //  Key  > c                   // text   ponuka kanalov
#define Info               0x10EF58A7    //  Key  > i                   // i+     info
#define EPG                0x10EF6A95    //  Key  > e                   //        reproduktor links
#define Back               0x10EF807F    //  Key  > backspace           // tools  naspet
#define ESC                0x10EF8A75    //  Key  > esc                 // exit
#define OSD                0x10EF8877    //  Key  > m                   // menu
#define PLAY               0x10EFD02F    //  Key  > space               // gelb
//#define Stop               0x10EF926D    //  Key  > x                   // rec
#define Stop                0x10EF18E7    //  Key  > x                   // off
#define VOLUME_UP          0x10EFC03F    //  Key  > +  (f10)            // v+
#define VOLUME_DN          0x10EF827D    //  Key  > -  (f9)             // v-
#define OK                 0x10EFE817    //  Key  > return              // OK
#define UP                 0x10EFD827    //  Key  > up Arrow            // hore
#define DWN                0x10EFC837    //  Key  > Down Arrow          // dole
#define LFT                0x10EFAA55    //  Key  > Left Arrow          // vlavo
#define RHT                0x10EFA857    //  Key  > Right Arrow         // vpravo
#define Mute               0x10EF5AA5    //  Key  > f8                  // mute
#define FW                 0x10EF906F    //  Key  > f                   // blau   dopredu
#define RW                 0x10EF10EF    //  Key  > r                   // grün   dozadu
//#define OFF                0x10EF18E7    //  Key  > s                   // off
#define  n1                0x10EF4AB5    //  Key  > num1
#define  n2                0x10EF0AF5    //  Key  > num2
#define  n3                0x10EF48B7    //  Key  > num3
#define  n4                0x10EF728D    //  Key  > num4
#define  n5                0x10EF32CD    //  Key  > num5
#define  n6                0x10EF708F    //  Key  > num6
#define  n7                0x10EF52AD    //  Key  > num7
#define  n8                0x10EF12ED    //  Key  > num8
#define  n9                0x10EF50AF    //  Key  > num9
#define  ChanUp            0x10EFBA45    //  Key  > pageup              // chan +
#define  ChanDown          0x10EF42BD    //  Key  > pagedown            // chan -
#define  PVRInfo           0x10EFA05F    //  Key  > o            // i


///////////////////////////  MEDIA PLAYER HOT KEYS   /////////////////////////////////
// COMMANDS   press, write, releaseAll  

#define TVWind_FUN         Keyboard.press('h');              Keyboard.releaseAll(); 
#define ChLP_FUN           Keyboard.press('0');              Keyboard.releaseAll();  // null
#define Channels_FUN       Keyboard.press('c');              Keyboard.releaseAll();
#define Info_FUN           Keyboard.press('i');              Keyboard.releaseAll();
#define EPG_FUN            Keyboard.press('e');              Keyboard.releaseAll(); 
#define Back_FUN           Keyboard.press(KEY_BACKSPACE);    Keyboard.releaseAll();
#define ESC_FUN            Keyboard.press(KEY_ESC);          Keyboard.releaseAll();  
#define OSD_FUN            Keyboard.press('m');              Keyboard.releaseAll();
#define PLAY_FUN           Keyboard.press(' ');              Keyboard.releaseAll();
#define Stop_FUN           Keyboard.press('x');              Keyboard.releaseAll();
#define VOLUME_UP_FUN      Keyboard.write(KEY_F10);                                  // or + 0x5D
#define VOLUME_DN_FUN      Keyboard.write(KEY_F9);                                   // or - 0x2F
#define OK_FUN             Keyboard.press(KEY_RETURN);       Keyboard.releaseAll(); 
#define UP_FUN             Keyboard.write(KEY_UP_ARROW);
#define DWN_FUN            Keyboard.write(KEY_DOWN_ARROW); 
#define LFT_FUN            Keyboard.press(KEY_LEFT_ARROW);   Keyboard.releaseAll(); 
#define RHT_FUN            Keyboard.press(KEY_RIGHT_ARROW);  Keyboard.releaseAll(); 
#define Mute_FUN           Keyboard.press(KEY_F8);           Keyboard.releaseAll();
#define FW_FUN             Keyboard.press('f');              Keyboard.releaseAll();
#define RW_FUN             Keyboard.press('r');              Keyboard.releaseAll();
//#define OFF_FUN            Keyboard.press('s');              Keyboard.releaseAll();
#define n1_FUN             Keyboard.press('1');              Keyboard.releaseAll();
#define n2_FUN             Keyboard.press('2');              Keyboard.releaseAll();
#define n3_FUN             Keyboard.press('3');              Keyboard.releaseAll();
#define n4_FUN             Keyboard.press('4');              Keyboard.releaseAll();
#define n5_FUN             Keyboard.press('5');              Keyboard.releaseAll();
#define n6_FUN             Keyboard.press('6');              Keyboard.releaseAll();
#define n7_FUN             Keyboard.press('7');              Keyboard.releaseAll();
#define n8_FUN             Keyboard.press('8');              Keyboard.releaseAll();
#define n9_FUN             Keyboard.press('9');              Keyboard.releaseAll();
#define ChanUp_FUN         Keyboard.press(KEY_PAGE_UP);      Keyboard.releaseAll();
#define ChanDown_FUN       Keyboard.press(KEY_PAGE_DOWN);    Keyboard.releaseAll();
#define PVR_Info           Keyboard.press('o');              Keyboard.releaseAll();

///////////////////////////  SETUP //////////////////////////////////////
void setup()
{
  pinMode(IR_VCC, OUTPUT);
  pinMode(IR_GND, OUTPUT);
   
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_PIN, OUTPUT);
  Keyboard.begin();
}
////////////////////////// main prog ////////////////////////////////////
void loop() {
  digitalWrite(IR_VCC, HIGH);
  digitalWrite(IR_GND, LOW);
  
  if (irrecv.decode(&results))
    {
     digitalWrite(LED_PIN,1); 
     
 /////////////////// ADD YOUR FUNCTIO0N HERE //////////////////////////      
  
  if      (results.value==TVWind)     {TVWind_FUN;   }
  else if (results.value==ChLP)       {ChLP_FUN;     }  
  else if (results.value==Channels)   {Channels_FUN; }
  else if (results.value==Info)       {Info_FUN;     }  
  else if (results.value==EPG)        {EPG_FUN;      }
  else if (results.value==Back)       {Back_FUN;     }
  else if (results.value==ESC)        {ESC_FUN;      }   
  else if (results.value==OSD)        {OSD_FUN;      }
  else if (results.value==PLAY)       {PLAY_FUN;     }   
  else if (results.value==Stop)       {Stop_FUN;     }   
  else if (results.value==VOLUME_UP)  {VOLUME_UP_FUN;}
  else if (results.value==VOLUME_DN)  {VOLUME_DN_FUN;}  
  else if (results.value==OK)         {OK_FUN;       }
  else if (results.value==UP)         {UP_FUN;       } 
  else if (results.value==DWN)        {DWN_FUN;      } 
  else if (results.value==LFT)        {LFT_FUN;      }
  else if (results.value==RHT)        {RHT_FUN;      }
  else if (results.value==Mute)       {Mute_FUN;     }
  else if (results.value==FW)         {FW_FUN;       }
  else if (results.value==RW)         {RW_FUN;       }   
  //else if (results.value==OFF)        {OFF_FUN;      } 
  else if (results.value==n1)         { n1_FUN;      }
  else if (results.value==n2)         { n2_FUN;      }
  else if (results.value==n3)         { n3_FUN;      }
  else if (results.value==n4)         { n4_FUN;      }
  else if (results.value==n5)         { n5_FUN;      }
  else if (results.value==n6)         { n6_FUN;      }
  else if (results.value==n7)         { n7_FUN;      }
  else if (results.value==n8)         { n8_FUN;      }
  else if (results.value==n9)         { n9_FUN;      }
  else if (results.value==ChanUp)     { ChanUp_FUN;  }                                    
  else if (results.value==ChanDown)   { ChanDown_FUN;}
  else if (results.value==PVRInfo)    { PVR_Info;    }
   
   Serial.println(results.value, HEX);                                            
   delay(100); 
   digitalWrite(LED_PIN,0); 
   irrecv.resume();    
    }
 }
