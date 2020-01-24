#!/usr/bin/python
import rospy
import RPi.GPIO as GPIO
import time
           
Stop = 0
#V controla motor
#Z controla polaridade
PIN_DIR_V = 40
PIN_DIR_Z = 38
PIN_ESQ_V = 36
PIN_ESQ_Z = 32
cicloMotor = 95

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(PIN_DIR_V,GPIO.OUT)
GPIO.setup(PIN_DIR_Z,GPIO.OUT)
GPIO.setup(PIN_ESQ_V,GPIO.OUT)
GPIO.setup(PIN_ESQ_Z,GPIO.OUT)

controleMotorDir = GPIO.PWM(PIN_DIR_V,100)
controlePolaridadeDir = GPIO.PWM(PIN_DIR_Z,100)
controleMotorEsq = GPIO.PWM(PIN_ESQ_V,100)
controlePolaridadeEsq = GPIO.PWM(PIN_ESQ_Z,100)

controleMotorDir.start(0)
controleMotorEsq.start(0)
controlePolaridadeDir.start(0)
controlePolaridadeEsq.start(0)

# def goAhead(): 
#     controleMotorDir.ChangeDutyCycle(cicloMotor)
#     controleMotorEsq.ChangeDutyCycle(cicloMotor)
# 	cicloMotor = 93
# 	while True:
# 	    print ("Potencia: {0}".format(cicloMotor))
# 	    time.sleep(0.4)
# 	    cicloMotor = cicloMotor + 1
# 	    if(cicloMotor == 96):
# 	    	break
# 	    i = not i

def stopRobot():
    controleMotorDir.ChangeDutyCycle(Stop)
    controleMotorEsq.ChangeDutyCycle(Stop)
    print ("Potencia: {0}".format(cicloMotor))
    time.sleep(0.4)

def goRight(cicloMotor):
	while True:
    	controleMotorDir.ChangeDutyCycle(0)
    	controleMotorEsq.ChangeDutyCycle(cicloMotor)
    	print ("Potencia: {0}".format(cicloMotor))
    	time.sleep(0.4)
    	cicloMotor = cicloMotor + 1
    	if(cicloMotor == 96):
    		break
    	i = not i

def goLeft(cicloMotor):
	while True:
    	controleMotorEsq.ChangeDutyCycle(0)
    	controleMotorDir.ChangeDutyCycle(cicloMotor)
    	print ("Potencia: {0}".format(cicloMotor))
    	time.sleep(0.4)
    	cicloMotor = cicloMotor + 1
    	if(cicloMotor == 96):
			break
    	i = not i
      

try:
	cicloMotor = 93

    while time.sleep(3):
        goAhead(cicloMotor)

    while time.sleep(3):
		goLeft(cicloMotor)

    while time.sleep(3):
		goRight(cicloMotor)


finally:
    GPIO.cleanup()