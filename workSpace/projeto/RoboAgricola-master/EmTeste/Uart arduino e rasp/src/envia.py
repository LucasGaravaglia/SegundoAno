#!/usr/bin/env python

import time
import serial

ser = serial.Serial(
    port='/dev/serial0',
    baudrate = 9600,
    parity=serial.PARITY_NONE,
	stopbits=serial.STOPBITS_ONE,
	bytesize=serial.EIGHTBITS,
	timeout=1
)

while 1:
	ser.write(str.encode('Frente\n'))
	ser.write(str.encode('Tras\n'))
	ser.write(str.encode('Direita\n'))
	ser.write(str.encode('Esquerda\n'))
	ser.write(str.encode('Velocidade: 100\n'))
	ser.write(str.encode('Direcao: 50\n'))
	time.sleep(1)
