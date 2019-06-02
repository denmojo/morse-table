//
// Simple Arduino Morse Beacon
// Originally written by Mark VandeWettering K6HX - k6hx@arrl.net
// https://brainwagon.org
//


struct t_mtab { char c, pat; } ;

struct t_mtab morsetab[] = {
  	{'.', 106},
	{',', 115},
	{'?', 76},
	{'/', 41},
	{'A', 6},
	{'B', 17},
	{'C', 21},
	{'D', 9},
	{'E', 2},
	{'F', 20},
	{'G', 11},
	{'H', 16},
	{'I', 4},
	{'J', 30},
	{'K', 13},
	{'L', 18},
	{'M', 7},
	{'N', 5},
	{'O', 15},
	{'P', 22},
	{'Q', 27},
	{'R', 10},
	{'S', 8},
	{'T', 3},
	{'U', 12},
	{'V', 24},
	{'W', 14},
	{'X', 25},
	{'Y', 29},
	{'Z', 19},
	{'1', 62},
	{'2', 60},
	{'3', 56},
	{'4', 48},
	{'5', 32},
	{'6', 33},
	{'7', 35},
	{'8', 39},
	{'9', 47},
	{'0', 63}
} ;

#define N_MORSE  (sizeof(morsetab)/sizeof(morsetab[0]))

#define SPEED  (12)
#define DOTLEN  (1200/SPEED)
#define DASHLEN  (3*(1200/SPEED))

int LEDpin = 13 ;

void
dash()
{
  digitalWrite(LEDpin, HIGH) ;
  delay(DASHLEN);
  digitalWrite(LEDpin, LOW) ;
  delay(DOTLEN) ;
}

void
dit()
{
  digitalWrite(LEDpin, HIGH) ;
  delay(DOTLEN);
  digitalWrite(LEDpin, LOW) ;
  delay(DOTLEN);
}

void
send(char c)
{
  int i ;
  if (c == ' ') {
    Serial.print(c) ;
    delay(7*DOTLEN) ;
    return ;
  }
  for (i=0; i<N_MORSE; i++) {
    if (morsetab[i].c == c) {
      unsigned char p = morsetab[i].pat ;
      Serial.print(morsetab[i].c) ;

      while (p != 1) {
          if (p & 1)
            dash() ;
          else
            dit() ;
          p = p / 2 ;
      }
      delay(2*DOTLEN) ;
      return ;
    }
  }
  /* if we drop off the end, then we send a space */
  Serial.print("?") ;
}

void
sendmsg(char *str)
{
  while (*str)
    send(*str++) ;
  Serial.println("");
}

void setup() {
  pinMode(LEDpin, OUTPUT) ;
  Serial.begin(9600) ;
  Serial.println("Simple Arduino Morse Beacon v0.1") ;
  Serial.println("") ;
}

void loop() {
  sendmsg("VVV DE AD6DM/B CM98HB") ;
  delay(3000) ;
}
