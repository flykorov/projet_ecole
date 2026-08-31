# TP3
# Guillaume Mathieu
# Victor Bouvier d'Acher

import socket

nb_port = 65535

def ScannerTCPv1(i):

	try:
		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		s.bind(("127.0.0.1", i+1))
	except:
		return True
	return False

for i in range(nb_port):	
	if ScannerTCPv1(i):
		print(f"serveur occupé sur le port {i+1}")
