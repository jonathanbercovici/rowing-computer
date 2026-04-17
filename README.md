# Rowing Computer

This is my attempt at building a custom rowing computer to help during training and races.

The goal of this project is to give the cox useful, real-time data so they can make better calls while rowing. I’m aiming to get a working version ready in time for a race on the 21st of March.

## Overview

The computer is designed to display key rowing metrics:

- Split (pace)
- Distance
- Stroke rate
- Averages of all of the above

All of this will be calculated using just two sensors:
- An IMU (for motion and stroke detection)
- A GPS (for positioning and speed)

To improve accuracy, I’m planning to use **sensor fusion**, combining IMU and GPS data to get more reliable speed readings. The IMU will also be used to calculate stroke rate.

The data will be shown on a screen for the cox, and also transmitted over WiFi to a coach’s phone for live feedback during training.

## Web Interface

This is the online web portal that allows coaches to access the data:

https://github.com/user-attachments/assets/baca7985-2ced-4ace-9917-ff74679708b6

Here’s an example of what the display looks like:

<img width="595" height="521" alt="Web interface" src="https://github.com/user-attachments/assets/fd4bdd1c-6f6e-4c29-9350-0efa9b376a15" />

<img width="464" height="1033" alt="Display example" src="https://github.com/user-attachments/assets/555d2b23-7ef9-4f4d-b65f-c5dc252c9627" />

You can also view a timelapse of the project here:
https://lapse.hackclub.com/timelapse/Rufa2XrtfnKe

## Electronics

To build the computer, the plan is to use:
- 8x M3 screws
- A perfboard for the circuit (to keep costs down)
- A fair amount of hot glue for sealing

Hot glue is being used mainly to waterproof the electronics, which is pretty important for something going in a boat.

Here’s the schematic:

<img width="925" height="774" alt="Schematic" src="https://github.com/user-attachments/assets/b325c3ea-4d38-4ae2-ad20-b2bff9d9dbf8" />

Even though this schematic is shown here, the actual build will likely be done on perfboard rather than a custom PCB.

## Enclosure Design

Below are some exploded views of the enclosure:

<img width="485" height="465" alt="Exploded view 1" src="https://github.com/user-attachments/assets/55b11062-422b-4514-8f63-d6032a0df1c3" />

<img width="548" height="465" alt="Exploded view 2" src="https://github.com/user-attachments/assets/c6d8e521-4d6f-4482-a33b-f242e4693ccf" />

<img width="466" height="368" alt="Exploded view 3" src="https://github.com/user-attachments/assets/a609d1a4-415b-4c48-9a8c-9319fd7006aa" />

And here’s the case without any components inside:

<img width="666" height="456" alt="Empty case" src="https://github.com/user-attachments/assets/7c365bc2-d700-4bb3-a380-544416f4d5d8" />

## Notes


- Sensor fusion (IMU + GPS) is the main challenge and will likely need tuning.
- Waterproofing is a key focus, especially for real-world use on the water.


---

If you’re interested in building something similar or improving on this idea, feel free to use the designs and experiment with it.
