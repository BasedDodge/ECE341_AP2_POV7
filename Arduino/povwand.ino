// setup
String povtext = "HELLO WORLD";//PUT YOUR MESSAGE HERE!!- must be in all caps, spaces are fine, no punctuation
byte refresh = 1;//delay time for pixels to refresh in milliseconds- experiment with different values



//get length of string povtext
int dimtext = povtext.length();

//letterArray to make sure firmare is loaded correctly- each led should light up in order upon turning on
boolean load[] = {
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
};

int n; //variable for loops
int t; //variable for loops
byte l; //variable for loops



//The letters of the alphabet- edit the look of these if you want, just make sure the letters m and w are 15 pixels wide and the rest are 12 pixels
const boolean letterA[] PROGMEM = {
  0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
};

const boolean letterB[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
};

const boolean letterC[] PROGMEM = {
  0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const boolean letterD[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  };

const boolean letterE[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const boolean letterF[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
};

const boolean letterG[] PROGMEM = {
  0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
};

const boolean letterH[] PROGMEM = {
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
};

const boolean letterI[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const boolean letterJ[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
  0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
};

const boolean letterK[] PROGMEM = {
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
};

const boolean letterL[] PROGMEM = {
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const boolean letterM[] PROGMEM = {
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
};

const boolean letterN[] PROGMEM = {
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
};

const boolean letterO[] PROGMEM = {
  0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
};

const boolean letterP[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
};

const boolean letterQ[] PROGMEM = {
  0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1,
};

const boolean letterR[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
};

const boolean letterS[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const boolean letterT[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
};

const boolean letterU[] PROGMEM = {
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
};

const boolean letterV[] PROGMEM = {
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
};

const boolean letterW[] PROGMEM = {
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0,
};

const boolean letterX[] PROGMEM = {
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
};

const boolean letterY[] PROGMEM = {
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
  0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
};

const boolean letterZ[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0,
  0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

void send12(const boolean letter[]) {
  // loop that iterates through the twelve 'columns' of each character array
  for (t = 0; t < 12; t = t + 1) {


    //loop that iterates through the first 13 'rows' of the character array, setting the digital out pins
    for (int LED = 0; LED < 13; LED = LED + 1) {

      if (letter[(LED* 12) + t])
        digitalWrite(LED, HIGH);
      else
        digitalWrite(LED, LOW);

    }

    if (letter[(14 * 12) + t])
      digitalWrite(A5, HIGH);
    else
      digitalWrite(A5, LOW);

    if (letter[(15 * 12) + t])
      digitalWrite(A4, HIGH);
    else
      digitalWrite(A4, LOW);

    if (letter[(16 * 12) + t])
      digitalWrite(A3, HIGH);
    else
      digitalWrite(A3, LOW);

    if (letter[(17 * 12) + t])
      digitalWrite(A2, HIGH);
    else
      digitalWrite(A2, LOW);

    delay(refresh);
  }
}

void send15(const boolean letter[]) {
  // loop that iterates through the 15 'columns' of the character arrays for 'W' and 'M'
  for (t = 0; t < 15; t = t + 1) {


    //loop that iterates through the first 13 'rows' of the character array, setting the digital out pins
    for (int LED = 0; LED<14; LED = LED + 1) {

      if (letter[(LED* 15) + t])
        digitalWrite(LED, HIGH);
      else
        digitalWrite(LED, LOW);

    }

    if (letter[(14 * 15) + t])
      digitalWrite(A5, HIGH);
    else
      digitalWrite(A5, LOW);

    if (letter[(15 * 15) + t])
      digitalWrite(A4, HIGH);
    else
      digitalWrite(A4, LOW);

    if (letter[(16 * 15) + t])
      digitalWrite(A3, HIGH);
    else
      digitalWrite(A3, LOW);

    if (letter[(17 * 15) + t])
      digitalWrite(A2, HIGH);
    else
      digitalWrite(A2, LOW);

    delay(refresh);
  }
}

void setup() {
  // put your setup code here, to run once:
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    
    for (int LED=0; LED<14; LED= LED+1){
        pinMode(LED, OUTPUT);
      }

// Loading LED sequence to ensure all LEDs are working properly
    for (int LED=0; LED<14; LED= LED+1){
        digitalWrite(LED, HIGH);
        delay(100);
        digitalWrite(LED, LOW);
       }

    digitalWrite(A5, HIGH);
    delay(100);
    digitalWrite(A5,LOW);
    
    digitalWrite(A4, HIGH);
    delay(100);
    digitalWrite(A4,LOW);
    
    digitalWrite(A3, HIGH);
    delay(100);
    digitalWrite(A3,LOW);
    
    digitalWrite(A2, HIGH);
    delay(100);
    digitalWrite(A2,LOW);      
}


    
void loop() {
  // put your main code here, to run repeatedly:
  for (n=0; n<dimtext; n++) {
    switch (povtext.charAt(n)){
   case 'A':
      send12(letterA);
      break;
      
    case 'B':
      send12(letterB);
      break;
      
    case 'C':
      send12(letterC);
      break;
      
    case 'D':
      send12(letterD);
      break;
      
    case 'E':
      send12(letterE);
      break;
      
    case 'F':
      send12(letterF);
      break;
      
    case 'G':
      send12(letterG);
      break;
      
    case 'H':
      send12(letterH);
      break;
      
    case 'I':
      send12(letterI);
      break;
    
    case 'J':
      send12(letterJ);
      break;
      
    case 'K':
      send12(letterK);
      break;
      
    case 'L':
      send12(letterL);
      break;
      
    case 'M':
      send15(letterM);
      break;
      
    case 'N':
      send12(letterN);
      break;
      
    case 'O':
      send12(letterO);
      break;
      
    case 'P':
      send12(letterP);
      break;
    
    case 'Q':
      send12(letterQ);
      break;
    
    case 'R':
      send12(letterR);
      break;
      
    case 'S':
      send12(letterS);
      break;
    
    case 'T':
      send12(letterT);
      break;
      
    case 'U':
      send12(letterU);
      break;
      
    case 'V':
      send12(letterV);
      break;
      
   case 'W':
      send15(letterW);
      break;
      
    case 'X':
      send12(letterX);
      break;
      
    case 'Y':
      send12(letterY);
      break;
      
    case 'Z':
      send12(letterZ);
      break;
      
    case ' ':
      delay(refresh*3);//off for 3 pixels
      break;
    }
   delay(refresh);
  }

}