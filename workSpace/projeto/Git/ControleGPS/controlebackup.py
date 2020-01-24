#!/usr/bin/env python

import time
import subprocess
import serial

ser = serial.Serial(
     port='/dev/serial0',
     baudrate = 9600,
     parity=serial.PARITY_NONE,
 	stopbits=serial.STOPBITS_ONE,
 	bytesize=serial.EIGHTBITS,
 	timeout=1
 )

missao = open('/home/labiot/missaoGPS/missao.txt','r')

fileText = missao.readlines()

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

def frente():
    texto = getValue(100)
    texto += ','
    texto += getValue(0)
    texto += ','
    texto += getValue(25)
    texto += ';'
    ser.write(str.encode(texto))
    print(texto)
    print("frente")

def tras():
    texto = getValue(-100)
    texto += ','
    texto += getValue(0)
    texto += ','
    texto += getValue(25)
    texto += ';'
    ser.write(str.encode(texto))
    print(texto)
    print("tras")

def direitaFrente():
    texto = getValue(100)
    texto += ','
    texto += getValue(100)
    texto += ','
    texto += getValue(15)
    texto += ';'
    ser.write(str.encode(texto))
    print(texto)
    print("direitafrente")

def direitaTras():
    texto = getValue(-100)
    texto += ','
    texto += getValue(-100)
    texto += ','
    texto += getValue(15)
    texto += ';'
    ser.write(str.encode(texto))
    print(texto)
    print("direitatras")

def esquerdaFrente():
    texto = getValue(100)
    texto += ','
    texto += getValue(-100)
    texto += ','
    texto += getValue(15)
    texto += ';'
    ser.write(str.encode(texto))
    print(texto)
    print("esquerdafrente")

def esquerdaTras():
    texto = getValue(-100)
    texto += ','
    texto += getValue(100)
    texto += ','
    texto += getValue(15)
    texto += ';'
    ser.write(str.encode(texto))
    print(texto)
    print("esquerdatras")

def parar():
    texto = getValue(0)
    texto += ','
    texto += getValue(0)
    texto += ','
    texto += getValue(0)
    texto += ';'
    ser.write(str.encode(texto))
    print(texto)
    print("parar")

for lines in fileText:
    subprocess.call('/home/labiot/missaoGPS/./a.out')
    coord = open('/home/labiot/missaoGPS/coords.txt', 'r')
    temp = lines
    missaoLat = int(temp[0:7])
    missaoLong = int(temp[8:16])
    temp2 = coord.read()
    coord.close()
    coordLat = int(temp2[0:7])
    coordLong = int(temp2[8:16])

    if(coordLat != 9999999 and coordLong != 9999999):
    
        while(coordLat < missaoLat and coordLat != 9999999):
            subprocess.call('/home/labiot/missaoGPS/./a.out')
            tras()
            time.sleep(3)
            parar()
            coord = open('/home/labiot/missaoGPS/coords.txt', 'r')
            temp2 = coord.read()
            coord.close()
            coordLat = int(temp2[0:7])
            coordLong = int(temp2[8:16])
            print('CoordLat: ' + str(coordLat))
            print('CoordLong: ' + str(coordLong))
            print('MissaoLat: ' + str(missaoLat))
            print('MissaoLong: ' + str(missaoLong))
        while(coordLat > missaoLat and coordLat != 9999999):
            subprocess.call('/home/labiot/missaoGPS/./a.out')
            frente()
            time.sleep(3)
            parar()
            coord = open('/home/labiot/missaoGPS/coords.txt', 'r')
            temp2 = coord.read()
            coord.close()
            coordLat = int(temp2[0:7])
            coordLong = int(temp2[8:16])
            print('CoordLat: ' + str(coordLat))
            print('CoordLong: ' + str(coordLong))
            print('MissaoLat: ' + str(missaoLat))
            print('MissaoLong: ' + str(missaoLong))
        
        if(coordLong > missaoLong and coordLong != 9999999):
            esquerdaFrente()
            time.sleep(3)
            while(coordLong < missaoLong and coordLong != 9999999):
                subprocess.call('/home/labiot/missaoGPS/./a.out')
                frente()
                time.sleep(3)
                parar()
                coord = open('/home/labiot/missaoGPS/coords.txt', 'r')
                temp2 = coord.read()
                coord.close()
                coordLat = int(temp2[0:7])
                coordLong = int(temp2[8:16])
                print('CoordLat: ' + str(coordLat))
                print('CoordLong: ' + str(coordLong))
                print('MissaoLat: ' + str(missaoLat))
                print('MissaoLong: ' + str(missaoLong))
        if(coordLong > missaoLong and coordLong != 9999999):
            direitaFrente()
            time.sleep(3)
            while(coordLong > missaoLong and coordLong != 9999999):
                subprocess.call('/home/labiot/missaoGPS/./a.out')
                frente()
                time.sleep(3)
                parar()
                coord = open('/home/labiot/missaoGPS/coords.txt', 'r')
                temp2 = coord.read()
                coord.close()
                coordLat = int(temp2[0:7])
                coordLong = int(temp2[8:16])
                print('CoordLat: ' + str(coordLat))
                print('CoordLong: ' + str(coordLong))
                print('MissaoLat: ' + str(missaoLat))
                print('MissaoLong: ' + str(missaoLong))

    else:
        print("Erro Gps")

		

missao.close()
