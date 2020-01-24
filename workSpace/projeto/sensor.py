#!/usr/bin/python

from threading import Thread
import time
import RPi.GPIO as GPIO

global sensor_A_trig = 11
global sensor_A_echo = 12

global sensor_B_trig = 15
global sensor_B_echo = 16

global sensor_C_trig = 31
global sensor_C_echo = 32


class sensor:
    def _init_(self):
        self.running = True
        self.distance_A = 0
        self.distance_B = 0
        self.distance_C = 0
        GPIO.setup(sensor_A_trig,GPIO.OUT)
        GPIO.setup(sensor_A_echo,GPIO.IN)
        GPIO.setup(sensor_B_trig,GPIO.OUT)
        GPIO.setup(sensor_B_echo,GPIO.IN)
        GPIO.setup(sensor_C_trig,GPIO.OUT)
        GPIO.setup(sensor_C_echo,GPIO.IN)
	
    def terminate(self):
        self.renning = False

    def run(self):
        while self.running:
	    self.readSensors()
    def getDistanceA(self):
        return self.distance_A

    def getDistanceA(self):
	return self.distance_B

    def getDistanceA(self):
	return self.distance_C

    def readSensors(self):
	self.readSensorA()
        self.readSensorB()
        self.readSensorC()

    def readSensorA(self):
        GPIO.output(sensor_A_trig, GPIO.LOW)
   	    time.sleep(0.3)
    	GPIO.output(sensor_A_trig, GPIO.HIGH)
    	time.sleep(0.00001)
    	GPIO.output(sensor_A_trig, LOW)
    	while GPIO.input(sensor_A_echo) == 0:
       	    signaloff = time.time()
    	while GPIO.input(sensor_A_echo) == 1:
            signalon = time.time()
        timepassed = signalon - signaloff
    	distance = timepassed * 17000
    	self.distance_A = distance

    def readSensorB(self):
        GPIO.output(sensor_B_trig, GPIO.LOW)
   	    time.sleep(0.3)
    	GPIO.output(sensor_B_trig, GPIO.HIGH)
    	time.sleep(0.00001)
    	GPIO.output(sensor_B_trig, LOW)
    	while GPIO.input(sensor_B_echo) == 0:
       	    signaloff = time.time()
    	while GPIO.input(sensor_B_echo) == 1:
            signalon = time.time()
        timepassed = signalon - signaloff
    	distance = timepassed * 17000
    	self.distance_B = distance

    def readSensorC(self):
        GPIO.output(sensor_C_trig, GPIO.LOW)
   	    time.sleep(0.3)
    	GPIO.output(sensor_C_trig, GPIO.HIGH)
    	time.sleep(0.00001)
    	GPIO.output(sensor_C_trig, LOW)
    	while GPIO.input(sensor_C_echo) == 0:
       	    signaloff = time.time()
    	while GPIO.input(sensor_C_echo) == 1:
            signalon = time.time()
        timepassed = signalon - signaloff
    	distance = timepassed * 17000
        self.distance_C = distance


leitura = sensor()
leituraThread = Thread(target=leitura.run)
leituraThread.start()

while True:
    print('Dis A: ' + str(leitura.getDistanceA()) + ' Dis B: ' + str(leitura.getDistanceB()) + ' Dis C: ' + str(leitura.getDistanceC()))