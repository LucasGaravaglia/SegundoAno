#!/usr/bin/env python
#-*- coding: utf-8 -*-

import time
import subprocess
from datetime import datetime

# ser = serial.Serial(
#     port='/dev/serial0',
#     baudrate = 9600,
#     parity=serial.PARITY_NONE,
# 	stopbits=serial.STOPBITS_ONE,
# 	bytesize=serial.EIGHTBITS,
# 	timeout=1
# )
CaminhoArquivoMissao = '/home/lucas/materiasfaculdade/projeto/ControleGPS/missao.txt'
CaminhoProgramaC = '/home/lucas/materiasfaculdade/projeto/ControleGPS/./a.out' 
CaminhoArquivoCoordenadas = '/home/lucas/materiasfaculdade/projeto/ControleGPS/coords.txt'
LogFile = '/home/lucas/materiasfaculdade/projeto/ControleGPS/Log.txt'
missao = open(CaminhoArquivoMissao,'r')
fileText = missao.readlines()
VetLat = []
VetLong = []
coordLat = 9999999
coordLong = 9999999
missaoLat = 0
missaoLong = 0
Data_Hora = datetime.now()
Data_Hora.strftime('%d/%m/%Y%H : %M')

def register(s):
    arquivo = open(LogFile, 'a')
    arquivo.write(s)
    arquivo.close()
#Divide em N pontos, a distancia atual, e o ponto da missao.
def sectorDefine(lines):
    global VetLat
    global VetLong
    global missaoLat
    global missaoLong
    QuantidadeQuadrantes = input('Dividir em quantos quadrantes? ')
    missaoLat = int(lines[0:7])
    missaoLong = int(lines[8:16])
    temp2 = headFilePoint()
    coordLatf = int(temp2[0:7])
    coordLongf = int(temp2[8:16])
    DistanciaQuadranteLat = (missaoLat - coordLatf) / QuantidadeQuadrantes
    DistanciaQuadranteLong = (missaoLong - coordLongf) / QuantidadeQuadrantes
    for i in range(0,QuantidadeQuadrantes,1):
        VetLat.append((DistanciaQuadranteLat*(QuantidadeQuadrantes+1))+coordLat)
        VetLong.append((DistanciaQuadranteLong*(QuantidadeQuadrantes+1))+coordLong)  
    return QuantidadeQuadrantes

#Recebe um inteiro, e transforma ele em string para enviar a placa.         
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
    texto += getValue(-14)
    texto += ','
    texto += getValue(25)
    texto += ';'
    #ser.write(str.encode(texto))
    # print(texto)
    print("frente")

def tras():
    texto = getValue(-100)
    texto += ','
    texto += getValue(0)
    texto += ','
    texto += getValue(25)
    texto += ';'
    #ser.write(str.encode(texto))
    # print(texto)
    print("tras")

def direitaFrente():
    texto = getValue(100)
    texto += ','
    texto += getValue(100)
    texto += ','
    texto += getValue(15)
    texto += ';'
    #ser.write(str.encode(texto))
    # print(texto)
    print("direitafrente")

def direitaTras():
    texto = getValue(-100)
    texto += ','
    texto += getValue(-100)
    texto += ','
    texto += getValue(15)
    texto += ';'
    #ser.write(str.encode(texto))
    # print(texto)
    print("direitatras")

def esquerdaFrente():
    texto = getValue(100)
    texto += ','
    texto += getValue(-100)
    texto += ','
    texto += getValue(15)
    texto += ';'
    #ser.write(str.encode(texto))
    # print(texto)
    print("esquerdafrente")

def esquerdaTras():
    texto = getValue(-100)
    texto += ','
    texto += getValue(100)
    texto += ','
    texto += getValue(15)
    texto += ';'
    #ser.write(str.encode(texto))
    # print(texto)
    print("esquerdatras")

#Recebe o tempo que ira executar o comando anterior antes de parar
def parar(r):
    time.sleep(r)
    texto = getValue(0)
    texto += ','
    texto += getValue(0)
    texto += ','
    texto += getValue(0)
    texto += ';'
    #ser.write(str.encode(texto))
    # print(texto)
    print("parar")

#Executa gera o arquivo com a posiçao atual, le o arquivo,
#e retorna uma string com a lat e longi.
def headFilePoint():
    subprocess.call(CaminhoProgramaC)
    coord = open(CaminhoArquivoCoordenadas, 'r')
    temp = coord.read()
    coord.close()
    return temp
def startArquivo():
    arquivo = open(LogFile, 'w')
    arquivo.close()
#Faz o carrinho apontar para o norte,
#retorna True quando estiver para o norte,
#ou False caso houver erro na leitura de arquivo.
def turnNorth():
    register(Data_Hora)
    register('Ajsutando o norte.')
    print("Ajustando o norte")
    while True:
        temp2 = headFilePoint()
        coordLat = int(temp2[0:7])
        coordLong = int(temp2[8:16])

        if(coordLat != 9999999 or coordLong != 9999999):
            oldcoordLat = coordLat
            oldcoordLong = coordLong
            frente()
            parar(3)
            temp2 = headFilePoint()
            coordLat = int(temp2[0:7])
            coordLong = int(temp2[8:16])
            tras()
            parar(2)
            if(oldcoordLat > coordLat and oldcoordLong > coordLong):#ponto 2
                esquerdaFrente()
                parar(1)
            elif(oldcoordLat < coordLat and oldcoordLong == coordLong):#ponto 3
                esquerdaFrente()
                parar(1.5)
            elif(oldcoordLat > coordLat and oldcoordLong < coordLong):#ponto 4
                esquerdaFrente()
                parar(2)
            elif(oldcoordLat == coordLat and oldcoordLong < coordLong):#ponto 5
                direitaFrente()
                parar(3)
            elif(oldcoordLat < coordLat and oldcoordLong < coordLong):#ponto 6
                direitaFrente()
                parar(2)
            elif(oldcoordLat < coordLat and oldcoordLong == coordLong):#ponto 7
                direitaFrente()
                parar(1.5)
            elif(oldcoordLat < coordLat and oldcoordLong > coordLong):#ponto 8
                direitaFrente()
                parar(1)
            else:#ponto 1
                register('Terminou de ajustar o norte')
                print("Terminou de ajustar o norte")
                return True
        else:
            return False

#Printa os valores da coordenada atual, e aonde deve chegar
def printDebug():
    global coordLat
    global coordLong
    global missaoLat
    global missaoLong
    register('CoordLat:  ' + str(coordLat) + ' CoordLong:  ' + str(coordLong))
    register('MissaoLat: ' + str(missaoLat) + ' MissaoLong: ' + str(missaoLong))
    print('CoordLat:  ' + str(coordLat) + ' CoordLong:  ' + str(coordLong))
    print('MissaoLat: ' + str(missaoLat) + ' MissaoLong: ' + str(missaoLong))

#Atribui o valor da llatitude e longitude nas variaveis, a partir do GPS
def atribuiCoord():
    global coordLat
    global coordLong
    temp = headFilePoint()
    coordLat = int(temp[0:7])
    coordLong = int(temp[8:16])

startArquivo()
for lines in fileText:
    QuantidadeQuadrantes = sectorDefine(lines)
    for i in range(0,QuantidadeQuadrantes,1):
        flag = False
        if(turnNorth()):
            register("Indo para o Quadrante: " + str(i))
            print("Indo para o Quadrante: " + str(i))
            atribuiCoord()
            while(coordLat != VetLat[i] and coordLong != VetLong[i]):
                if(coordLat < VetLat[i] and coordLat != 9999999):
                    flag = True
                    printDebug()
                    direitaFrente()
                    parar(3)
                    atribuiCoord()
                while((coordLat > missaoLat and coordLat != 9999999) or flag):
                    printDebug()
                    frente()
                    parar(3)
                    atribuiCoord()
                if(flag):
                    if(coordLong < missaoLong and coordLong != 9999999):
                        direitaFrente()
                        parar(1.5)
                        while(coordLong > missaoLong and  coordLong != 9999999):
                            printDebug()
                            frente()
                            parar(3)
                            atribuiCoord()
                    if(coordLong > missaoLong and coordLong != 9999999):
                        esquerdaFrente()
                        parar(1.5)
                        while(coordLong < missaoLong and coordLong != 9999999):
                            printDebug()
                            frente()
                            parar(3)
                            atribuiCoord()
                else:
                    if(coordLong < missaoLong and coordLong != 9999999):
                        esquerdaFrente()
                        parar(1.5)
                        while(coordLong < missaoLong and coordLong != 9999999):
                            printDebug()
                            frente()
                            parar(3)
                            atribuiCoord()
                    if(coordLong > missaoLong and coordLong != 9999999):
                        direitaFrente()
                        parar(1.5)
                        while(coordLong > missaoLong and coordLong != 9999999):
                            printDebug()
                            frente()
                            parar(3)
                            atribuiCoord()
        else:
            register('Erro na leitura de arquivo')
            print('Erro na leitura de arquivo')
        register('Quadrante ' + str(i) + ' finalizado.')
        print('Quadrante ' + str(i) + ' finalizado.')
		
missao.close()
register('Missao concluida!' + Data_Hora)
print('Missao concluida!')