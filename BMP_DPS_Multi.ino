#include <Adafruit_BusIO_Register.h>  // BusIO library set
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>

#include <Adafruit_Sensor.h>  // Adafruit Unified Sensor library

#include <Adafruit_BMP280.h>  // BMP280 library
#include <Adafruit_DPS310.h>  // DPS310 library


// Object Definition for BMP280
Adafruit_BMP280 bmp;

// Object definition for DPS310
#define Adafruit
Adafruit_DPS310 dps;


void setup() {
  Serial.begin(9600); // Sets baud rate for both sensors
  
  // Checks to see if BMP280 is set up properly
  if(!bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID)) {
    Serial.println("BMP280 Error!");
    while (1);
  }

// Sampling modes for BMP280
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                  Adafruit_BMP280::SAMPLING_X2,
                  Adafruit_BMP280::SAMPLING_X16,
                  Adafruit_BMP280::FILTER_X16,
                  Adafruit_BMP280::STANDBY_MS_500);

// Checks to see if DPS310 is set up properly
  if (!dps.begin_I2C()) {
    Serial.println("DPS310 Error!");
    while (1);
  }

// Sampling modes for DPS310
  dps.configurePressure(DPS310_64HZ, DPS310_64SAMPLES);
  dps.configureTemperature(DPS310_64HZ, DPS310_64SAMPLES);
  
}

void loop() {
  sensors_event_t temp_event, pressure_event; // Creates variables temp_event and pressure_event
  dps.getEvents(&temp_event, &pressure_event);  // Reads and assigns temp and presure to the variables temp_event and presure_event
  float altitude_dps = dps.readAltitude(1013.25);

  float pressure = bmp.readPressure() / 100;  // Creates and assigns pressure variable in units of hPa
  float temperature = bmp.readTemperature();  // Creates and assigns temperature variable in deg. C
  float altitude = bmp.readAltitude(1013.25); // Creates and assigns altitude varaible in m

// Prints BMP280 pressure reading
  Serial.print("BMP Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

// Prints DPS310 pressure reading
  Serial.print("DPS Pressure: ");
  Serial.print(pressure_event.pressure);
  Serial.println(" hPa");
  Serial.println("");
  

// Prints BMP280 temoperature reading
  Serial.print("BMP Temperature: ");
  Serial.print(temperature);
  Serial.println(" deg. C");

// Prints DPS310 temperature reading
  Serial.print("DPS Temperature: ");
  Serial.print(temp_event.temperature);
  Serial.println(" deg. C");
  Serial.println("");


// Prints BMP280 altitude reading
  Serial.print("BMP Altitude: ");
  Serial.print(altitude);
  Serial.println(" m");

// Prints DPS310 altitude reading
  Serial.print("DPS Altitude: ");
  Serial.print(altitude_dps);
  Serial.println(" m");

  Serial.println("");
  Serial.println("");

  delay(1000);  // Delays one second, so the chips' oversampling process has time to occur

}
