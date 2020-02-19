#include <avr/pgmspace.h>

String message = "JUSTIN CHEN";
byte refreshrate = 2;

int len = message.length();

// bytes that will hold the data for each cycle
// data1 will control pins 8-13(PORTB) and data2
// will control pins 0-7(PORTD)
byte data1 = 0;
byte data2 = 0;

int n;
int t;
int i;

// array that can be ran to test all LEDs are working
const boolean test[] PROGMEM= {
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
};



//The arrays containing the letters to be printed 
//stored in PROGMEM. Most are 7x10(WxH), but some
//characters like M,N,Q,W are 10x10.

const boolean letterA[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
};

const boolean letterB[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 0,
};

const boolean letterC[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1,
};

const boolean letterD[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 0, 0, 1, 1,
  1, 1, 1, 0, 0, 1, 1,
  1, 1, 1, 0, 0, 1, 1,
  1, 1, 1, 0, 0, 1, 1,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 0,
};

const boolean letterE[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
};


const boolean letterF[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 1, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
};

const boolean letterG[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 1, 1, 1,
  1, 1, 0, 0, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
};

const boolean letterH[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
};

const boolean letterI[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
};


const boolean letterJ[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 0, 0,
  1, 1, 0, 1, 1, 0, 0,
  1, 1, 0, 1, 1, 0, 0,
  1, 1, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 1, 0, 0,
};

const boolean letterK[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1, 1,
  1, 1, 1, 0, 1, 1, 0,
  1, 1, 0, 1, 1, 0, 0,
  1, 1, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 1, 1, 0,
  1, 1, 0, 0, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
};

const boolean letterL[] PROGMEM = {
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
};


const boolean letterM[] PROGMEM = {
  1, 1, 1, 0, 0, 0, 0, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 1, 1, 1, 1, 0, 1, 1,
  1, 1, 0, 0, 1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
};

const boolean letterN[] PROGMEM = {
  1, 1, 1, 0, 0, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 1, 1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1, 1, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 1, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
};

const boolean letterO[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
};

const boolean letterP[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
};


const boolean letterQ[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  1, 1, 1, 0, 1, 1, 1, 0, 0, 0,
  1, 1, 0, 0, 0, 1, 1, 0, 0, 0,
  1, 1, 0, 0, 0, 1, 1, 0, 0, 0,
  1, 1, 0, 0, 0, 1, 1, 0, 0, 0,
  1, 1, 0, 0, 0, 1, 1, 0, 0, 0,
  1, 1, 1, 0, 1, 1, 1, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 1, 0, 1, 1, 0,
};

const boolean letterR[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 0, 0,
  1, 1, 0, 1, 1, 1, 0,
  1, 1, 0, 0, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
};

const boolean letterS[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
};

const boolean letterT[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
};

const boolean letterU[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
};


const boolean letterV[] PROGMEM = {
  1, 0, 0, 0, 0, 0, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 0, 1, 1, 0,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 0, 0, 0,
};

const boolean letterW[] PROGMEM = {
  1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1, 0, 0, 1, 1,
  1, 1, 0, 1, 1, 1, 1, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 0, 0, 0, 0, 1, 1, 1,
};

const boolean letterX[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 0, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 1, 1, 0, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
};

const boolean letterY[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 0, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
};

const boolean letterZ[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1, 1,
  0, 0, 0, 0, 1, 1, 0,
  0, 0, 0, 1, 1, 0, 0,
  0, 0, 1, 1, 0, 0, 0,
  0, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
};

/////////////////////////////////////////////////////////////////////////////
//                     Function Declarations                               //
/////////////////////////////////////////////////////////////////////////////

// Function to print out standard size character to LEDs

void display7(boolean letter[]) { 
  // iterates through the 7 'columns' of data in the array
  for (t = 0; t < 7; t++) {
    
    // PORTB only controls 6 pins, so this iterates 6 times
    for (i = 0; i < 6; i++) {
    
      
      data1 = data1 << 1;
      
      
      data1 |= pgm_read_byte_near(letter + ((i * 7) + t));
    
    }
    // iterates through for remaining 4 pins
    for (i = 6; i < 10; i++) {
      
      // bit-shift left
      data2 = data2 << 1;
      
      // reads next value from character array and adds it to data2
      data2 |= pgm_read_byte_near(letter + ((i * 7) + t));
    }
   // populates rest of data2 with zeros
   for (i = 10; i < 14; i++) {
      data2 = data2 << 1;
      data2 |= 0;
    }

    // sends bytes to the ports to light up the correct LEDs
    PORTB = data1;
    PORTD = data2;

    // delays for the refresh rate set by user
    delay(refreshrate);

    // clears data stored in bytes data1 and data2
    data1 = 0;
    data2 = 0;
  }
}

void display10(boolean letter[]) { 
  // iterates through the 10 'columns' of data in the array
  for (t = 0; t < 10; t++) {
    
    // PORTB only controls 6 pins, so this iterates 6 times
    for (i = 0; i < 6; i++) {
    
      
      data1 = data1 << 1;
      
      
      data1 |= pgm_read_byte_near(letter + ((i * 10) + t));
    
    }
    // iterates through for remaining 4 pins
    for (i = 6; i < 10; i++) {
      
      // bit-shift left
      data2 = data2 << 1;
      
      // reads next value from character array and adds it to data2
      data2 |= pgm_read_byte_near(letter + ((i * 10) + t));
    }
   // populates rest of data2 with zeros
   for (i = 10; i < 14; i++) {
      data2 = data2 << 1;
      data2 |= 0;
    }

    // sends bytes to the ports to light up the correct LEDs
    PORTB = data1;
    PORTD = data2;

    // delays for the refresh rate set by user
    delay(refreshrate);

    // clears data stored in bytes data1 and data2
    data1 = 0;
    data2 = 0;
  }
}

void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
  // setting all of the port pins to be outputs
  // '0xFF' is equivalent to '0b11111111' which
  // sets all the pins to be outputs
  DDRB = 0xFF;
  DDRD = 0xFF;

  for (t = 0; t < 10; t++) {
    
    // PORTB only controls 6 pins, so this iterates 6 times
    for (i = 0; i < 6; i++) {
    
      
      data1 = data1 << 1;
      
      
      data1 |= pgm_read_byte_near(test + ((i * 10) + t));
    
    }
    // iterates through for remaining 4 pins
    for (i = 6; i < 10; i++) {
      
      // bit-shift left
      data2 = data2 << 1;
      
      // reads next value from character array and adds it to data2
      data2 |= pgm_read_byte_near(test + ((i * 10) + t));
    }
   // populates rest of data2 with zeros
   for (i = 10; i < 14; i++) {
      data2 = data2 << 1;
      data2 |= 0;
    }

    // sends bytes to the ports to light up the correct LEDs
    PORTB = data1;
    PORTD = data2;

    // delays for the refresh rate set by user
    delay(100);

    // clears data stored in bytes data1 and data2
    data1 = 0;
    data2 = 0;
  }
  PORTB = data1;
  PORTD = data2;


}

void loop() {
  int delayconst=1;
  int user = analogRead(A0);
  
 
  Serial.println(user);
  if(user<=60){
    refreshrate=4;
    delayconst=18;
  }
  else if(user>60 && user<=200){
    refreshrate=3;
    delayconst=20;
  }
  else if(user>200 && user<=1023){
    refreshrate=2;
    delayconst=20;
  }
  // space at beginning of message
  PORTB = 0;
  PORTD = 0;
  delay(refreshrate * 3);

  for (n = 0; n < len; n++) { //go through each character of message and call function display7 to display letter
    int x = analogRead(A5);
  //Serial.println(x);
      if(x>=370){
    delay(10*delayconst);
    }
   else if (message.charAt(n) == 'A') {
      display7(letterA);
    }
    else if (message.charAt(n) == 'B') {
      display7(letterB);
    }
    else if (message.charAt(n) == 'C') {
      display7(letterC);
    }
    else if (message.charAt(n) == 'D') {
      display7(letterD);
    }
    else if (message.charAt(n) == 'E') {
      display7(letterE);
    }
    else if (message.charAt(n) == 'F') {
      display7(letterF);
    }
    else if (message.charAt(n) == 'G') {
      display7(letterG);
    }
    else if (message.charAt(n) == 'H') {
      display7(letterH);
    }
    else if (message.charAt(n) == 'I') {
      display7(letterI);
    }
    else if (message.charAt(n) == 'J') {
      display7(letterJ);
    }
    else if (message.charAt(n) == 'K') {
      display7(letterK);
    }
    else if (message.charAt(n) == 'L') {
      display7(letterL);
    }
    else if (message.charAt(n) == 'M') {
      display10(letterM);
    }
    else if (message.charAt(n) == 'N') {
      display10(letterN);
    }
    else if (message.charAt(n) == 'O') {
      display7(letterO);
    }
    else if (message.charAt(n) == 'P') {
      display7(letterP);
    }
    else if (message.charAt(n) == 'Q') {
      display10(letterQ);
    }
    else if (message.charAt(n) == 'R') {
      display7(letterR);
    }
    else if (message.charAt(n) == 'S') {
      display7(letterS);
    }
    else if (message.charAt(n) == 'T') {
      display7(letterT);
    }
    else if (message.charAt(n) == 'U') {
      display7(letterU);
    }
    else if (message.charAt(n) == 'V') {
      display7(letterV);
    }
    else if (message.charAt(n) == 'W') {
      display10(letterW);
    }
    else if (message.charAt(n) == 'X') {
      display7(letterX);
    }
    else if (message.charAt(n) == 'Y') {
      display7(letterY);
    }
    else if (message.charAt(n) == 'Z') {
      display7(letterZ);
    }

    else if (message.charAt(n) == ' ') {
      PORTB = 0;
      PORTD = 0;
      // turns off LEDs for 3 cycles to create a space in the message
      delay(refreshrate * 3); 
    }
    // creates a small space between each character
    PORTB = 0;
    PORTD = 0;
    delay(refreshrate);
  }

  // creates a space at the end of the message
  PORTB = 0;
  PORTD = 0;
  PORTC = 0;
  delay(refreshrate * 3);




}
