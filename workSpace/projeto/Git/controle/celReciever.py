from http.server import BaseHTTPRequestHandler, HTTPServer

comando = None
request = None

class RequestHandler_httpd(BaseHTTPRequestHandler):
  def do_GET(self):
    global comando, request
    messagetosend = bytes('Dados Recebidos',"utf")
    self.send_response(200)
    self.send_header('Content-Type', 'text/plain')
    self.send_header('Content-Length', len(messagetosend))
    self.end_headers()
    self.wfile.write(messagetosend)
    request = self.requestline
    request = request[5 : int(len(request)-9)]
    print(request)
    return


comando = 'S'

server_address_httpd = ('192.168.43.225',8080)
httpd = HTTPServer(server_address_httpd, RequestHandler_httpd)
print('Start Server')
httpd.serve_forever()
