# Wall-Painting-Bot
## ABSTRACT

Wall painting bot is a fully automatic robot capable of sketching images on the wall upto dimensions 90cm x 120cm (approx). 
The bot will take image through a laptop and will convert the image into 5 colors. 
The bot will automatically change the color according to the image and will sketch on the wall.

## Image

![PIC UNAVAILABLE CHECK PLEASE](https://user-images.githubusercontent.com/32795030/55216696-731b1b00-5223-11e9-8c1d-5d85e18e1284.jpeg)
 
![PIC UNAVAILABLE CHECK PLEASE](https://user-images.githubusercontent.com/32795030/55216879-06545080-5224-11e9-8536-9d109ee3f588.jpeg)


 ## Acknowledgements
 

We would like to express our special thanks to Alok Gupta sir , Prashant Sir , Abhimanyu Sir , Nikhil sir for helping us throughout the journey.

## Mechanical Components-

1. Nut-bolts

2. Washers

3. Steel rod(2 qts of 1m each)

4. Simple wheels(2)

5. Castor wheels(3)

6. Linear bearing(6mm diameter compatible with steel rods)

7. Plywood with a rectangular cut of 60cm x 40cm 

8. Chassis of dimensions 90cm x 60cm 

9. Gears 

10. Hinge 

11. L Brackets

## Electronics Components-

1. Arduino Mega

2. Raspberri pi

3. Motor Drivers(2)

4. Cytron(1)

5. Rotary encoders(2)

6. Simple DC motors(2)

7. Stepper motor(1)</p>


## Software-

### Arduino software-

The movement of both the dc motors and the stepper motor is controlled by the arduino code with the help of the feedback from the rotary encoders.



### Python(OpenCV Library)-

The image/design to be drawn is processed in python using opencv library. Image processing includes compressing the image, converting into 5 colors and then finding the coordinates of the color pixels and sending it to the arduino.

## Working-

first we provide image in the format of JPEG.We map the image pixel values with corresponding sketch value. The image is divided into a range of pixel colors and converted into our corresponding pixel values. We then obtain the corresponding color value and x and y coordinates. Then the values are sent to arduino with help of raspberry pi. We iterate on x keeping y constant and then move to next y value. The stepper motor will rotate the markers according to colors.The DC motors will move the bot in x and y direction according to values. We provide the input values according to encoder value comparison between current value and image desired value.

## Applications-

-This bot can be used to sketch on any image on wall in houses, offices, etc.

-It is very easy to use and fully portable.

-It can paint any image in 5 different colors.


## Limitations-

We couldn't get exact accuracy as that of image due to inaccuracy of motors.

The dimensions of painting is constrained due to physical limitations in vertical dimension.

Drawing speed is slow and it took about 2 hours for sketching.

We are able to sketch the image in only 5 colors and we couldn't sketch all the shades available from the image.

The resolution of sketch is low.

## Team Members-

1. Adarsh Agrawal

2. Atharva Mule

3. Deepak Haridas

4. Purvi Agarwal

5. Vikash Kumar

## Mentors-

1. Alok Gupta

2. Prashant Kumar

3. Abhimanyu Bambhaniya

4. Pratham Meena


## References-

1. Extended concept of Graffiti Bot-[Graffiti Bot 2.0](https://github.com/marsiitr/Grafitti-Bot-2.0)



2. DC Motor Code Reference- [DC motor Code](https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/)


3. Stepper motor-  [Stepper motor-](https://circuitdigest.com/microcontroller-projects/arduino-stepper-motor-control-tutorial)


4. Rotary encoder- [Rotary encoder-](https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/)





