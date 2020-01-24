#!/usr/bin/python

import threading
import time
import smbus
import math
import time
import serial
import os

ser = serial.Serial(
     port='/dev/ttyACM0',
     baudrate = 9600,
     parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=1
)

def getValue(v):
        if(v >= 0):
                r = '1'
        else:
                r = '0'
        if(v < 10 and v > -10):
                r += '00'
        elif(v < 100 and v > -100):
                r += '0'
        r += str(abs(v))
        return r

def controle(speed, steer, limit):
    texto = getValue(speed)
    texto += ','
    texto += getValue(steer)
    texto += ','
    texto += getValue(limit)
    texto += ';'
    ser.write(str.encode(texto))
    time.sleep(0.05)

y = 0

def getValor():
	global y;
	print('Ligue o robo!')
	y = int(input('Digite 1 para finalizar a inicializacao: '))

x = threading.Thread(target=getValor)
x.start()
while y == 0:
	controle(-11,0,5)

print('Inicializacao terminada com sucesso!')
controle(-11,0,5)
os.system("python3 controle.py")

