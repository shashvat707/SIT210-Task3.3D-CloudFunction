//Task 3.3D - Particle - Buddy System

#define BLINK_TIMES 3

int led = D6; 

void ledBlinkControl(int times, int delayms)
{
    for(int i = 0; i < times; i++){
        digitalWrite(led,HIGH);
        delay(delayms);
        
        digitalWrite(led,LOW);
        delay(delayms);
    }
}

void setup() 
{
    pinMode(led, OUTPUT); // LED pin as output
    
    // Recieves pat and wave events
    Particle.subscribe("Shashvat_Joshi_SIT210", myLedHandler);
}

void loop() {
 // Nothing here
}

// Called when cloud tell us if an event is published
void myLedHandler(const char *event, const char *data)
{
    // LED pat and wave
    if (strcmp(data, "wave")==0) {
        ledBlinkControl(BLINK_TIMES, 300); // Wave Signal
    }
    else if (strcmp(data,"pat")==0) {
        ledBlinkControl(BLINK_TIMES+1, 150); // Pat Signal
    }
    else {
        // Nothing
    }
}