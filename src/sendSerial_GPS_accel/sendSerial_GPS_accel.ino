// Include Libraries related to obtaining GPS data
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// Include Libraries related to obtaining accelerometer data
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>

/*
   This code reads in GPS and 3-axis aceelerometer data and sends it to a computer via USB serial.
      An Arduino Nano microcontroller with an ATmega328 chip runs the code.
      The GPS receiver used is a GP-735T from Sparkfun.
        DATA retrieved:
        - # of satellite signals acquired
        - GPS Latitude coordinate (degrees)
        - GPS Longitude coordinate (degrees)
        - Date (mm/dd/yyyy)
        - Time (hh:mm:ss)
         
      The 3-axis accelerometer used is a LSM303DLHC and part of an Adafruit 9 DOF Inertial Measurement Unit.
        DATA retrieved:
        - X acceleration (m/s^2)
        - Y acceleration (m/s^2)
        - Z acceleration (m/s^2)
*/

// Define the Arduino pins to be configured as RX and TX 
static const int RXPin = 3, TXPin = 4;
// Define GPS baud rate (recommended for GP-735T)
static const uint32_t GPSBaud = 9600;

void smartDelay(unsigned long ms);
void printFloat(float val, bool valid, int len, int prec);
void printInt(unsigned long val, bool valid, int len);
void printDateTime(TinyGPSDate &d, TinyGPSTime &t);

// Assign a unique ID to accel sensor at the same time 
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(12345);

// Instantiate TinyGPS++ object
TinyGPSPlus gps;

// Create serial connection to the GPS device using previously defined RX and TX pins
SoftwareSerial ss(RXPin, TXPin);

void setup() {
  // Set baud rates for Serial interface to computer and GPS
  Serial.begin(115200);
  ss.begin(GPSBaud);

  // Initialize accelerometer
  if(!accel.begin())
    {
      Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
      while(1);
    }

  Serial.println(F("                          GPS                                                  ACCELEROMETER"));
  Serial.println(F(" _____________________________________________________________          ____________________________"));
  Serial.println(F(" Sats   Latitude    Longitude    Date      Time   Date   Alt               X         Y         Z    "));
  Serial.println(F("        (deg)       (deg)                         Age    (m)            (m/s^2)   (m/s^2)   (m/s^2)"));
  Serial.println(F("--------------------------------------------------------------------------------------------------------"));
    
}

void loop() {

  // Create and get new sensor event
  sensors_event_t event;
  accel.getEvent(&event);

  Serial.print("  ");
  printInt(gps.satellites.value(), gps.satellites.isValid(), 5);
  printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
  printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
  printDateTime(gps.date, gps.time);
  printFloat(gps.altitude.meters(), gps.altitude.isValid(), 7, 2);
  Serial.print("          ");

  Serial.print(event.acceleration.x); Serial.print("      ");
  Serial.print(event.acceleration.y); Serial.print("      ");
  Serial.print(event.acceleration.z); Serial.print("      ");
  Serial.println();

  smartDelay(1000);

}

// Added custom DELAY and PRINT functions from TinyGPS++ example codes below 
//
void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

void printFloat(float val, bool valid, int len, int prec)
{
  if (!valid)
  {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  }
  else
  {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      Serial.print(' ');
  }
  smartDelay(0);
}

void printInt(unsigned long val, bool valid, int len)
{
  char sz[32] = "*****************";
  if (valid)
    sprintf(sz, "%ld", val);
  sz[len] = 0;
  for (int i=strlen(sz); i<len; ++i)
    sz[i] = ' ';
  if (len > 0) 
    sz[len-1] = ' ';
  Serial.print(sz);
  smartDelay(0);
}

void printDateTime(TinyGPSDate &d, TinyGPSTime &t)
{
  if (!d.isValid())
  {
    Serial.print(F("********** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d ", d.month(), d.day(), d.year());
    Serial.print(sz);
  }
  
  if (!t.isValid())
  {
    Serial.print(F("******** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d:%02d:%02d ", t.hour(), t.minute(), t.second());
    Serial.print(sz);
  }

  printInt(d.age(), d.isValid(), 5);
  smartDelay(0);
}
