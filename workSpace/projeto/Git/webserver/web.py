from http.server import BaseHTTPRequestHandler, HTTPServer

MyRequest = None

class RequestHandler_httpd(BaseHTTPRequestHandler):
    def do_GET(self):
        global MyRequest
        print("You Got this request:")
        print(self.requestline)
        MyRequest = self.requestline
        print("Your cleanned Request:")
        MyRequest = MyRequest[5 : int(len(MyRequest) - 9)]
        print(MyRequest)
        messagetosend = bytes("Welcome to the Pi Server", "utf")
        self.send_response(200)
        self.send_header("Content-Type", "text/pain")
        self.send_header("Content-Lenght", len(messagetosend))
        self.wfile.write(messagetosend)
        return

server_address_httpd = ("192.168.1.2", 8080)
httpd = HTTPServer(server_address_httpd, RequestHandler_httpd)
print("Start the Server: ")
httpd.serve_forever()
