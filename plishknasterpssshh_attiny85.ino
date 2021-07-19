 #include <SimpleTimer.h>
 #include <Morse.h>

 int WPM = 15; // 15!
 int flashPin = 0; // 0 for ATTINY85!
 int analogSeedPin = 2; // 2 is A1 it seems on attiny85
 int k;
 unsigned long breakTime = 120000; // 2 minutes

 // Class declaration
 Morse morse(flashPin, WPM);
 SimpleTimer timer;
 

 // Set the strings first
#include <avr/pgmspace.h>

// STRINGS HERE!
const char string_0[] PROGMEM = "kra kra = Crow calling = Malayalam / ";
const char string_1[] PROGMEM = "mu mu = Cow mooing = Portuguese / ";
const char string_2[] PROGMEM = "sis = Steam hissing = Afrikaans / ";
const char string_3[] PROGMEM = "kadaad = Lightning = Marathi / ";
const char string_4[] PROGMEM = "drip drop = Water = English / ";
const char string_5[] PROGMEM = "ho-hoo = Owl hooting = Swedish / ";
const char string_6[] PROGMEM = "ba-ji = Wet strike = Chinese, Mandarin / ";
const char string_7[] PROGMEM = "knetter = Fire = Dutch / ";
const char string_8[] PROGMEM = "kwaak kwaak = Frog croaking = Dutch / ";
const char string_9[] PROGMEM = "mur = Lion/tiger roaring = Finnish / ";
const char string_10[] PROGMEM = "gA gA = Goose calling = Polish / ";
const char string_11[] PROGMEM = "kva kva = Frog croaking = Lithuanian / ";
const char string_12[] PROGMEM = "awoo = Elephant trumpeting = Tagalog / ";
const char string_13[] PROGMEM = "beee = Sheep bleating = Polish / ";
const char string_14[] PROGMEM = "kra kra = Crow calling = Polish / ";
const char string_15[] PROGMEM = "plitsch = Water = German / ";
const char string_16[] PROGMEM = "rip-rop = Fire = Hungarian / ";
const char string_17[] PROGMEM = "baaa = Elephant trumpeting = Italian / ";
const char string_18[] PROGMEM = "ouah ah ah hein = Monkey chatting = French / ";
const char string_19[] PROGMEM = "petok-petok = Chicken clucking = Indonesian / ";
const char string_20[] PROGMEM = "zoem = Bee buzzing = Afrikaans / ";
const char string_21[] PROGMEM = "qiqliqo = Rooster crowing = Georgian / ";
const char string_22[] PROGMEM = "wing-wing = Wind blowing = Korean / ";
const char string_23[] PROGMEM = "hudry hudry = Turkey calling = Czech / ";
const char string_24[] PROGMEM = "klop klop = Horse trotting = Croatian / ";
const char string_25[] PROGMEM = "hu hu = Owl hooting = Croatian / ";
const char string_26[] PROGMEM = "tchibum = Wet strike = Portuguese / ";
const char string_27[] PROGMEM = "vau vau = Dog barking = Croatian / ";
const char string_28[] PROGMEM = "twit twit = Bird singing = Tagalog / ";
const char string_29[] PROGMEM = "muh = Cow mooing = Danish / ";
const char string_30[] PROGMEM = "mjau-mjau = Cat meowing = Albanian / ";
const char string_31[] PROGMEM = "nguing = Bee buzzing = Indonesian / ";
const char string_32[] PROGMEM = "ngok ngok = Pig grunting = Tagalog / ";
const char string_33[] PROGMEM = "miao= m = Cat meowing = Telugu / ";
const char string_34[] PROGMEM = "platty = Wet strike = Hungarian / ";
const char string_35[] PROGMEM = "karra-karra = Goose calling = Basque / ";
const char string_36[] PROGMEM = "mjau = Cat meowing = Norwegian / ";
const char string_37[] PROGMEM = "ga ga = Goose calling = Romanian / ";
const char string_38[] PROGMEM = "frou-frou = Wind blowing = French / ";
const char string_39[] PROGMEM = "sum sum = Bee buzzing = Norwegian / ";
const char string_40[] PROGMEM = "fas = Steam hissing = Romanian / ";
const char string_41[] PROGMEM = "kwak kwak = Duck calling = Tagalog / ";
const char string_42[] PROGMEM = "bho = Wind blowing = Bengali / ";
const char string_43[] PROGMEM = "gak gak = Goose calling = Dutch / ";
const char string_44[] PROGMEM = "tok tok tok = Chicken clucking = Dutch / ";
const char string_45[] PROGMEM = "ih-hi-i-i = Horse whinnying = Turkish / ";
const char string_46[] PROGMEM = "njihaa = Horse whinnying = Croatian / ";
const char string_47[] PROGMEM = "miaw = Cat meowing = Uropi / ";
const char string_48[] PROGMEM = "kap kap = Water = Croatian / ";
const char string_49[] PROGMEM = "kwi kwi = Pig squealing = Polish / ";
const char string_50[] PROGMEM = "rapak = Thunder = Batak / ";
const char string_51[] PROGMEM = "sip sip = Water = Turkish / ";
const char string_52[] PROGMEM = "xut = Owl hooting = Catalan / ";
const char string_53[] PROGMEM = "kukuriku = Rooster crowing = Croatian / ";
const char string_54[] PROGMEM = "aPPaP aPPaP baka baka = Frog croaking = Sinhalese / ";
const char string_55[] PROGMEM = "ting ting = Water = Thai / ";
const char string_56[] PROGMEM = "hsss = Snake hissing = Croatian / ";
const char string_57[] PROGMEM = "kaa kaa = Crow calling = Tamil / ";
const char string_58[] PROGMEM = "huhuu = Owl hooting = Finnish / ";
const char string_59[] PROGMEM = "cap-cap = Water = Bulgarian / ";
const char string_60[] PROGMEM = "croac croac = Frog croaking = Spanish / ";
const char string_61[] PROGMEM = "priang = Lightning = Thai / ";
const char string_62[] PROGMEM = "plin plin = Water = Italian / ";
const char string_63[] PROGMEM = "ciu-ciu = Bird singing = Albanian / ";
const char string_64[] PROGMEM = "krja krja = Duck calling = Russian / ";
const char string_65[] PROGMEM = "uu-u = Wind blowing = Russian / ";
const char string_66[] PROGMEM = "qarq-qarq = Crow calling = Kazakh / ";
const char string_67[] PROGMEM = "buss = Snake hissing = Telugu / ";
const char string_68[] PROGMEM = "klap klap = Horse trotting = Latvian / ";
const char string_69[] PROGMEM = "iii-haaa = Horse whinnying = Polish / ";
const char string_70[] PROGMEM = "kar kar = Crow calling = Russian / ";
const char string_71[] PROGMEM = "hav hav = Dog barking = Turkish / ";
const char string_72[] PROGMEM = "kikiriki = Rooster crowing = Slovene / ";
const char string_73[] PROGMEM = "gA gA = Goose calling = Latvian / ";
const char string_74[] PROGMEM = "phnosh = Snake hissing = Bengali / ";
const char string_75[] PROGMEM = "kykirikA = Rooster crowing = Czech / ";
const char string_76[] PROGMEM = "bAaAah = Sheep bleating = French / ";
const char string_77[] PROGMEM = "kuk-kuk = Owl hooting = Indonesian / ";
const char string_78[] PROGMEM = "huist = Lightning = Batak / ";
const char string_79[] PROGMEM = "cheh cheh = Bird singing = Hindi / ";
const char string_80[] PROGMEM = "croac croac = Frog croaking = Portuguese / ";
const char string_81[] PROGMEM = "moj = Wind blowing = Persian / ";
const char string_82[] PROGMEM = "ungaa = Cow mooing = Tagalog / ";
const char string_83[] PROGMEM = "kvaak kvaak = Duck calling = Finnish / ";
const char string_84[] PROGMEM = "kykkeliky = Rooster crowing = Norwegian / ";
const char string_85[] PROGMEM = "plo = Wet strike = Thai / ";
const char string_86[] PROGMEM = "hov hov = Dog barking = Slovene / ";
const char string_87[] PROGMEM = "kap kap = Water = Russian / ";
const char string_88[] PROGMEM = "vau vau = Dog barking = Hungarian / ";
const char string_89[] PROGMEM = "mu = Cow mooing = Slovene / ";
const char string_90[] PROGMEM = "plask = Wet strike = Danish / ";
const char string_91[] PROGMEM = "hau hau = Dog barking = Polish / ";
const char string_92[] PROGMEM = "fuuuu fuuuu = Wind blowing = Macedonian / ";
const char string_93[] PROGMEM = "sssss = Steam hissing = Tagalog / ";
const char string_94[] PROGMEM = "vak vak = Goose calling = Turkish / ";
const char string_95[] PROGMEM = "mee = Sheep bleating = Icelandic / ";
const char string_96[] PROGMEM = "bra bra = Duck calling = Icelandic / ";
const char string_97[] PROGMEM = "bep = Wet strike = Vietnamese / ";
const char string_98[] PROGMEM = "caw caw = Crow calling = English / ";
const char string_99[] PROGMEM = "bee = Goat bleating = Basque / ";

int numOfStrings = 100;

const char * const string_table[] PROGMEM =
{
string_0,
string_1,
string_2,
string_3,
string_4,
string_5,
string_6,
string_7,
string_8,
string_9,
string_10,
string_11,
string_12,
string_13,
string_14,
string_15,
string_16,
string_17,
string_18,
string_19,
string_20,
string_21,
string_22,
string_23,
string_24,
string_25,
string_26,
string_27,
string_28,
string_29,
string_30,
string_31,
string_32,
string_33,
string_34,
string_35,
string_36,
string_37,
string_38,
string_39,
string_40,
string_41,
string_42,
string_43,
string_44,
string_45,
string_46,
string_47,
string_48,
string_49,
string_50,
string_51,
string_52,
string_53,
string_54,
string_55,
string_56,
string_57,
string_58,
string_59,
string_60,
string_61,
string_62,
string_63,
string_64,
string_65,
string_66,
string_67,
string_68,
string_69,
string_70,
string_71,
string_72,
string_73,
string_74,
string_75,
string_76,
string_77,
string_78,
string_79,
string_80,
string_81,
string_82,
string_83,
string_84,
string_85,
string_86,
string_87,
string_88,
string_89,
string_90,
string_91,
string_92,
string_93,
string_94,
string_95,
string_96,
string_97,
string_98,
string_99,
};

// set max characters. 65 characters per sentence.
char buffer[65];

 // a function to be executed periodically
 void repeatMe(){
   morse.update();
 }

int repeatTimer;

 void setup()
 { 
    randomSeed(analogRead(analogSeedPin));
    repeatTimer = timer.setInterval(1, repeatMe);
    delay(1000);
 }

 void loop() {
   timer.run();
   // if the board is not busy, send next message
   
  if (k < 4) {
       if (morse.busy == 0) {
          strcpy_P(buffer, (char*)pgm_read_word(&(string_table[random(numOfStrings)]))); // Necessary casts and dereferencing, just copy.
          morse.send(buffer); 
          k++;
       }
  }

  else {
      delay(breakTime);
      k = 0;
      timer.restartTimer(repeatTimer);
  }
   
 }
