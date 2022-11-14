# BMP280
BMP280 Characteristics and Testing

This project consists of two parts: An investigation of the BMP280 component and testing the BMP280 chip.

In part 1, the core sensing principle, the wiring scheme, and some important characteristics of the BMP280 are determined from the datasheet and other sources. A testing regimen is determined for each characteristic. A document with this information is included in this repository.

I selected Range, Linearity, Sensitivity, Resolution, Accuracy, and Drift for testing via pressure chamber: a peanut butter jar with a bike tire stem and wiring through the lid, sealed by silicone RTV adhesive and plumber's tape. A bike pump is used to add pressure to the system. To test for temperature, an ice bath was used to cool the sensor (inside of the pressure chamber), and a hair dryer was used to heat the sensor (again inside the pressure chamber). Relative height change was tested by taking data on an elavator going up four floors.

In part 2, the tests were performed, and the data was analyzed and compared the the datasheet. I used a DPS310 sensor, which also senses pressure, temperature, and altitude as ground truth to compare the BMP280 data to; it has ten times the resolution and accuracy of the BMP280. The results were presented in a Powerpoint slideshow, which is included in this repository.
