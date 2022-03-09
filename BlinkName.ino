//Blink LED of a first name using morse code

//Morse code:
//Dot: blink for 1 unit (1s)
//Dash: blink for 3 units (3s)
//space between parts of the same letter: 1 unit (1s)
//space between letters: 3 units (3s)
//space between words: 7 units (7s)

//set pin D7 as LED output

#include <string>
#include <cctype>

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

void morse_code(char c)
{
    switch(c)
    {
        case 'A': dot(); dash();break;
        case 'B': dash(); dot(); dot(); dot(); break;
        case 'C': dash(); dot(); dash();dot();break;
        case 'D': dash(); dot(); dot();break;
        case 'E': dot();short_space();break;
        case 'F': dot();dot();dash();dot();break;
        case 'G': dash(); dash();dot();break;
        case 'H': dot();dot();dot();dot();break;
        case 'I': dot();dot();break;
        case 'J': dot(); dash();dash();dash();break;
        case 'K': dash();dot();dash();break;
        case 'L': dot(); dash(); dot(); dot();break;
        case 'M': dash(); dash();break;
        case 'N': dash(); dot();break;
        case 'O': dash();dash();dash();break;
        case 'P': dot();dash();dash();dot();break;
        case 'Q': dash();dash();dot();dash();break;
        case 'R': dot();dash();dot();break;
        case 'S': dot();dot();dot();break;
        case 'U': dot();dot();dash();break;
        case 'V': dot();dot();dot();dash();break;
        case 'W': dot();dash();dash();break;
        case 'X': dash();dot();dot();dash();break;
        case 'Y': dash();dot();dash();dash();break;
        case 'Z': dash();dash();dot();dot();break;
        default: break;
    }
}
//blink the first name
void loop() 
{
    
    char firstName[] = "josh";
    for (int i = 0; i < sizeof(firstName); i ++)
    {
        char c = toupper(firstName[i]);
        morse_code(c);
        short_space();
    }
}
