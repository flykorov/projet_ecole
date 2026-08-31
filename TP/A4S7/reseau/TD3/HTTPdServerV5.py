# TP3
# Guillaume Mathieu
# Victor Bouvier d'Acher

import socket
import sys

def ouvrir(data):
    if "iceweasel.html" in data: 
        with open("iceweasel.html", "r") as f:
            return f.read()
    else:
        with open("chromium.html", "r") as f:
            return f.read()



def page_HTML(port):

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        s.bind(("0.0.0.0", int(port)))
        s.listen(5)
    except:
        print("le port est n'est pas libre")
        return
    while True:
    
        con, add = s.accept()

        with con:
            data = con.recv(1024)
            con.send(bytes("HTTP/1.1 200 OK\n", "utf-8"))
            con.send(bytes("Content-Type: text/html\n", "utf-8"))
            con.send(bytes("\r\n", "utf-8"))            
            con.send(bytes(ouvrir(data.decode("utf-8")), "utf-8"))


a=None
try:
    a = sys.argv[1]
except:
    print("pas d'argument pour le port")
    exit()

page_HTML(a)