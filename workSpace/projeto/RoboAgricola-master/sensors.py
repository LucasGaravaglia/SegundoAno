#!/usr/bin/python

from threading import Thread
import time
import RPi.GPIO as GPIO

sensor_A_trig = 11
sensor_A_echo = 12

sensor_B_trig = 15
sensor_B_echo = 16

sensor_C_trig = 31
sensor_C_echo = 32


class sensor:
    def __init__(self):
        self.running = True
        self.distance_A = 0
        self.distance_B = 0
        self.distance_C = 0
        GPIO.setup(sensor_A_trig, GPIO.OUT)
        GPIO.setup(sensor_A_echo, GPIO.IN)
        GPIO.setup(sensor_B_trig, GPIO.OUT)
        GPIO.setup(sensor_B_echo, GPIO.IN)
        GPIO.setup(sensor_C_trig, GPIO.OUT)
        GPIO.setup(sensor_C_echo, GPIO.IN)

    def terminate(self):
        self.running = False

    def run(self):
        while self.running:
            self.read_sensors()

    def get_distance_a(self):
        return self.distance_A

    def get_distance_b(self):
        return self.distance_B

    def get_distance_c(self):
        return self.distance_C

    def read_sensors(self):
        self.read_sensor_a()
        self.read_sensor_b()
        self.read_sensor_c()

    def read_sensor_a(self):
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

    def read_sensor_b(self):
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

    def read_sensor_c(self):
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
    print('Dis A: ' + str(leitura.get_distance_a()) + ' Dis B: ' + str(leitura.get_distance_b) + ' Dis C: ' + str(leitura.get_distance_c()))

