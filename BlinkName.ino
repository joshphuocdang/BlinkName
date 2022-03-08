//Blink LED of a first name using morse code

//Morse code:
//Dot: blink for 1 unit (1s)
//Dash: blink for 3 units (3s)
//space between parts of the same letter: 1 unit (1s)
//space between letters: 3 units (3s)
//space between words: 7 units (7s)

//set pin D7 as LED output
const pin_t MY_LED = D7;

SYSTEM_THREAD(ENABLED);

// setup
void setup() 
{
	pinMode(MY_LED, OUTPUT);
}

//dot signal
void dot()
{
    digitalWrite(MY_LED, HIGH);
    delay(1s);
    digitalWrite(MY_LED, LOW);
    delay(1s);
}


//dash signal
void dash()
{
    digitalWrite(MY_LED, HIGH);
    delay(3s);
    digitalWrite(MY_LED, LOW);
    delay(1s);
}

//space between letters
void short_space()
{
    delay(2s);
}

//space between words
void long_space()
{
    delay(6s);
}

//blink the first name
void loop() 
{
    //signalling 'J': * - - - 
    dot();
    dash();
    dash();
    dash();
    short_space();
    
    //signalling 'O':- - -
    
    dash();
    dash();
    dash();
    short_space();
    
    //signalling 'S': * * *
    dot();
    dot();
    dot();
    short_space();
    
    //signalling 'H': * * * *
    dot();
    dot();
    dot();
    dot();
    
    //end of the word
    long_space();
}
