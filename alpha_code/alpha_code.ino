// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int ZERO_button_press = 0;
int ONE_button_press = 0;
char store[16] = {};
int index  = 0;
String store_refined;
bool clear_switch = false;

void setup() {
  //Serial.begin(9600); // for debugging
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");

  // for the buttons
  pinMode(13,INPUT);
  pinMode(12,INPUT);
 
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  
  // buttons
  ZERO_button_press = digitalRead(12);
  ONE_button_press = digitalRead(13);

// within 10 seconds of typing the binary letter, display it

  if (ZERO_button_press == HIGH){
    // ZERO BUTTON IS PRESSED
    //lcd.print("0");
    store[index] = '0';
    index ++;
    lcd.print(store);

    delay(100);
    
  }

  if (ONE_button_press == HIGH){
    // ONE BUTTON IS PRESSED
    //lcd.print("1");
    store[index] = '1';
    index ++;
    lcd.print(store);

    delay(100);
  }
  
  
  store_refined = String(store);
  // check what has been typed
  if (store_refined.equals("0000")){
    lcd.print("hi");
    //clear_switch = true;
    lcd.clear();
    
    index = 0;    
    for(int i = 0; i < 16; i++){
      store[i] = '_';
    }

    store_refined = "";
    
    // need to clear store
    lcd.setCursor(0,1);
    lcd.print(" ");
  }

    
    
}
