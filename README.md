<a name="br1"></a> 



<a name="br2"></a> 

**INTRODUCTION**

Robot cars, including gesture-controlled models, represent a remarkable fusion of cutting-edge

technology and automation. These vehicles are often powered by microcontrollers like the

Arduino Uno, which serve as the brains behind their operation. Arduino Uno is a versatile and

widely-used microcontroller that enables precise control and coordination of various components

in these robotic systems. In the context of gesture-controlled cars, the Arduino Uno processes

data from sensors like accelerometers and gyroscopes, interpreting the user's gestures in real-

time and translating them into actionable commands for the vehicle. This seamless integration of

microcontroller technology with the world of robotics opens up exciting possibilities, from

innovative educational tools to entertainment devices, providing a glimpse into the future of

human-robot interaction and autonomous vehicles.

**BILL OF MATERIALS**

**Component**

Arduino Uno

ESP8266

**Quantity**

**Price**

1

1

2

2

2

4

2

4

\-

\-

\-

MPU 6050

L2930

800

500

Wheel Motor Adapter

Wheels

400

800

Battery Pack

Batteries

100

200

Jumper Wires

Breadboard

**Total**

\-

1

\-

**Kshs 3,200.00**



<a name="br3"></a> 

**HOW IT WORKS**

In this project, we're building a gesture-controlled robot using Arduino, the MPU6050

accelerometer and gyroscope, and ESP 32 . This robotic system is divided into two parts: the

Transmitter and the Receiver. The Transmitter comprises MPU6050 sensor, and ESP 32

module, while the Receiver consists of another Arduino Uno, ESP 8266 module, two DC motors,

and an L293D motor driver. The Transmitter is essentially a remote control, and the Receiver is

the robot that responds to the gestures made by the user.

In the Transmitter part, the MPU6050 accelerometer continuously sends data to the Receiver via

an Arduino and the ESP32 . In the Receiver part, the ESP 8266 accepts the transmitted data and

processes it , subsequently instructing the motor driver to control the direction and movement of

the robot based on the received gestures.

The MPU6050 sensor captures the X and Y coordinates, which are sent to the ESP 32.. The ESP

8266 processes the data, directing the motor driver to move the robot as per the user's gestures.



<a name="br4"></a> 

**RECEIVER**

**CIRUIT DIAGRAM OF RECEIVER:**



<a name="br5"></a> 

**REALIZED CIRCUIT:**



<a name="br6"></a> 

**TRANSMITTER**

**CIRCUIT DIAGRAM OF TRANSMITTER:**



<a name="br7"></a> 

**REALIZED CIRCUIT**



<a name="br8"></a> 

**BOTH TRANSMITTER AND RECEIVER:**



<a name="br9"></a> 

**MOTOR DRIVER:**



<a name="br10"></a> 

**DISCUSSION**

In the course of developing our gesture-controlled robot using Arduino, MPU6050, and ESP32,

several noteworthy aspects came to light, influencing the performance and functionality of the

system.

**OBSERVATIONS**

1\. **Communication Efficiency:** The choice of using ESP32 modules in the Transmitter

greatly improved communication efficiency. The ESP32's advanced wireless capabilities

facilitated reliable and quick data transmission to the Receiver, creating a responsive

interaction between the user's gestures and the robot's movements.

2\. **Role of ESP8266 in Gesture Interpretation:** The ESP8266 module on the Receiver side

played a crucial role in accepting and processing the transmitted data. Its efficiency in

interpreting gestures and subsequently instructing the motor driver highlighted its

importance in the seamless execution of user commands.

3\. **Integration Challenges:** While the integration of multiple components, including the

MPU6050, ESP32, and ESP8266, allowed for a comprehensive gesture control system, it

also presented challenges in terms of calibration and synchronization. Achieving optimal

coordination between these components required careful tuning and adjustment.

4\. **Real-time Responsiveness:** The continuous data flow from the MPU6050 to the ESP32

and the subsequent processing by the ESP8266 showcased the real-time responsiveness

of the system. This feature is essential for creating a natural and intuitive user experience.

5\. **Motor Control Precision:** The L293D motor driver, under the influence of the ESP8266,

demonstrated precise control over the two DC motors. This precision is critical for

accurately translating gesture inputs into fluid and controlled robot movements.

**CONCLUSION**

Our project successfully demonstrated the potential of gesture control in robotics, leveraging

Arduino, MPU6050, and ESP32 technologies. The enhanced communication efficiency afforded

by the ESP32 modules, coupled with the gesture interpretation capabilities of the ESP8266,

contributed to the overall success of the system.

The challenges encountered during integration underscored the importance of careful calibration

and highlighted areas for potential improvement in future iterations of the project. The real-time

responsiveness and motor control precision achieved provide a solid foundation for expanding

the capabilities of gesture-controlled robots in various applications.



<a name="br11"></a> 

**REFERENCES**

1\. Adarsh Kumar. (2018). Gesture Controlled Robot Us1.ing Accelerometer and

Gyroscope**)**

2\. https://www.electromaker.io/project/view/make-wi-fi-controller-car-using-esp8266

