#!/usr/bin/python
import smbus
import math
import time
import serial
from http.server import BaseHTTPRequestHandler, HTTPServer


UART1 = serial.Serial(
     port='/dev/ttyUSB0',
     baudrate = 9600,
     parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=1
)

UART2 = serial.Serial(
     port='/dev/ttyUSB1',
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
    print('Comando enviado: ' + texto)
    UART1.write(str.encode(texto))
    UART2.write(str.encode(texto))
    print('passou')
    time.sleep(0.02)
    #print("-----------------------",texto)

request = None

class RequestHandler_httpd(BaseHTTPRequestHandler):
  def do_GET(self):
    messagetosend = bytes('Dados Recebidos',"utf")
    self.send_response(302)
    self.send_header('Content-Type', 'text/plain')
    self.send_header('Content-Length', len(messagetosend))
    self.end_headers()
    self.wfile.write(messagetosend)
    request = self.requestline
    request = request[5 : int(len(request)-9)]
    print(request)
    msg = str(request).split('.')
    controle(int(msg[0]),int(msg[1]),int(msg[2]))
    print(str(int(msg[0])) + ' ' + str(int(msg[1])) + ' ' + str(int(msg[2])))
    return


server_address_httpd = ('192.168.1.2',8080)
httpd = HTTPServer(server_address_httpd, RequestHandler_httpd)
print('Start Server')
httpd.serve_forever()

#a = int(input('vel: '))
#b = int(input('dir: '))
#while True:
#    controle(a,b,50)

