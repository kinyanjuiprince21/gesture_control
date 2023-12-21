#define ENA   14          // Enable/speed motors Right        GPIO14(D5)
#define ENB   12          // Enable/speed motors Left         GPIO12(D6)
#define IN_1  13          // L298N in1 motors Rightx          GPIO15(D8)
#define IN_2  15          // L298N in2 motors Right           GPIO13(D7)
#define IN_3  0           // L298N in3 motors Left            GPIO2(D4)
#define IN_4  2           // L298N in4 motors Left            GPIO0(D3)

#include <ESP8266WiFi.h>
#include <espnow.h>
#include <math.h>


String command;             //String to store app command state.
int speedCar = 800;         // 400 - 1023.
int newSpeed = 600;
int speed_Coeff = 3;


typedef struct struct_message {
  float x;
  float y;
  float z;  
} struct_message;

struct_message received;

float direction = 0;

void setup() {
  //Motor Driver
  pinMode(ENA, OUTPUT);
 pinMode(ENB, OUTPUT);  
 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);
 pinMode(IN_3, OUTPUT);
 pinMode(IN_4, OUTPUT);

  //End Motor Driver
  
  Serial.begin(115200);

  
  //WIFI SETUP
  WiFi.mode(WIFI_STA);
  

// Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  //Set esp role & cb
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);

  Serial.println("Waiting...");
  // END WIFI
  stopCar();


}

void loop() {
  
  }


void  speedChange(float speed, float dirSpeed)
{
  if (dirSpeed < 400) {
    dirSpeed = 0;
    }
  speedCar = speed;
  newSpeed = dirSpeed;
}

void directionControl(float x, float y){
  
    if (x > 4.5)
    {
      speedChange(convertor(x), 0);
      forward();

      if (y > 4.5)
      {
        speedChange(speedCar, speedCar - convertor(y));
        forwardLeft();
      }
      else if (y < -4.5)
      {
        speedChange(speedCar, speedCar - convertor(y));
        forwardRight();
      }
      
    } 

    
    else if (x < -4.5)
    {
      speedChange(convertor(x), 0);
      back();

      if (y > 4.5)
      {
        speedChange(speedCar, speedCar - convertor(y));
        backLeft();
      }
      else if (y < -4.5)
      {
        speedChange(speedCar, speedCar - convertor(y));
        backRight();
      }
      
    }

    
    else 
    {
      speedChange(0, 0);
      stopCar();

      if (y > 4.5)
      {
        speedChange(0, convertor(y));
        forwardLeft();
      }
      else if (y < -4.5)
      {
        speedChange(0, convertor(y));
        forwardRight();
      }
      
    }

      //Debugs

      Serial.print("Speed: ");
      Serial.print(speedCar);
      Serial.print(", ");
      Serial.println(newSpeed);
      Serial.println("");
  }

void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&received, incomingData, sizeof(received));
  /*Serial.print("Bytes received: ");
  Serial.println(len);
  
  Serial.print("X: ");
  Serial.print(received.x);
  Serial.print(", ");
  Serial.print("Y: ");
  Serial.print(received.y);
  Serial.print(", ");
  Serial.print("Z: ");
  Serial.println(received.z);*/
 
  directionControl(received.x, received.y);
}

float convertor(int value){
  return map(abs(value), 4.5, 10, 400, 1010); //Min Pin value,max pin value, min pwm, max pwm
}

//Set Direction functions
void forward(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
  }

void back(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
  }

void forwardRight(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, newSpeed);
  }

void forwardLeft(){ 

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENA, newSpeed);
  }

  void backRight() {
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    analogWrite(ENA, newSpeed);
    
    }

void backLeft() {
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    analogWrite(ENA, newSpeed);
    
    }

void stopCar(){  

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
 }
//End contol functions
