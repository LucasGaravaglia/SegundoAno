#!/usr/bin/env python

import rospy
import RPi.GPIO as gpio
import time
from std_msgs.msg import String
from std_msgs.msg import Int64

gpio.setwarnings(False)
gpio.setmode(gpio.BOARD)
gpio.setup(40,gpio.OUT)
gpio.setup(38,gpio.OUT)
gpio.setup(36,gpio.OUT)
gpio.setup(32,gpio.OUT)

controleMotor = gpio.PWM(40,100)
controlePolaridade = gpio.PWM(38,100)
controleMotor2 = gpio.PWM(36,100)
controlePolaridade2 = gpio.PWM(32,100)

controleMotor.start(0)
controleMotor2.start(0)
controlePolaridade.start(0)
controlePolaridade2.start(0)

cicloMotor = 95

while True:
	controleMotor.ChangeDutyCycle(cicloMotor)
	controleMotor2.ChangeDutyCycle(cicloMotor)
	
	print ("Potencia: {0}".format(cicloMotor))
	time.sleep(0.3)
	cicloMotor = cicloMotor + 1
	if(cicloMotor == 96):
		cicloMotor = 93
	i = not i