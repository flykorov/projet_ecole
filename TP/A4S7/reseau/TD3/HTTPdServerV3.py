# TP3
# Guillaume Mathieu
# Victor Bouvier d'Acher

import socket
import sys

def page_HTML(port):

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


    try:
        s.bind(("0.0.0.0", int(port)))
        s.listen(5)
    except:
        print("le port est n'est pas libre")
        return
    while True:
        print()
    
        con, add = s.accept()

        with con:
            data = con.recv(1024)
            print(rep)

a=None
try:
    a = sys.argv[1]
except:
    print("pas d'argument pour le port")
    exit()

rep = page_HTML(a)
