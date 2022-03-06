#include <DHT.h> // by Adafruit - The best
#include <DHT_U.h>

#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;


void setup() {  
    Serial.begin(9600);
    Serial.println("DHTxx test!");
    dht.begin();
    // RGB 
    pinMode(red_light_pin, OUTPUT);
    pinMode(green_light_pin, OUTPUT);
    pinMode(blue_light_pin, OUTPUT);
}

void loop() {
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Failed to read from DHT");
  } 
  else
  {
    if(t < 21){
      RGB_color(0, 255, 255); // Cyan
      Serial.print("\n Temperatura: ");
      Serial.print(t);
    }
    else if (t >= 21 && t <= 27.9){
      RGB_color(0, 0, 255); // Blue
      Serial.print("\n Temperatura: ");
      Serial.print(t);
    }
    else if (t >= 28 && t < 29.9){
      RGB_color(255, 255, 0); // Yellow
      Serial.print("nTemperatura: ");
      Serial.print(t); 
    }else{
      RGB_color(255, 0, 0); // Red
      Serial.print("\n Temperatura: ");
      Serial.print(t); 
    }
    Serial.print(" %t");
    Serial.print("\n Humidade: ");
    Serial.print(h);
    delay(10000);
  }
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
