# TP3
# Guillaume Mathieu
# Victor Bouvier d'Acher

import socket
nb_port = 65535

def ScannerUDPv1(i):
	try:
		s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
		s.bind(("127.0.0.1", i+1))
	except:
		return True
	return False

for i in range(nb_port):
	if ScannerUDPv1(i):
		print(f"un serveur est à l'écoute sur le port {i+1}")
