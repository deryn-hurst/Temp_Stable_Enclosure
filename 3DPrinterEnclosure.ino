# include <DHT.h>

DHT dht(A0, DHT11);
float temp;

# include <Adafruit_LEDBackpack.h>

Adafruit_7segment led_display1 = Adafruit_7segment();

void setup() {
  // put your setup code here, to run once:
    dht.begin();
    led_display1.begin(112);
    pinMode(A0, INPUT_PULLUP);
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   delay(20);
   temp = dht.readTemperature(true);
   Serial.println(temp);
   led_display1.println(temp);
   led_display1.writeDisplay();
   
   if(temp > 77) {
    digitalWrite(2, -10);
    digitalWrite(4, 10);
    }
    
    else {
    digitalWrite(2, 0);
    digitalWrite(4, 0);
    }
}
