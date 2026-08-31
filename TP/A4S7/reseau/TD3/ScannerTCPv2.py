# TP3
# Guillaume Mathieu
# Victor Bouvier d'Acher

import socket

nb_port = 65535

def ScannerTCPv2(i):

	exp_port = "10.8.93.93"
	try:
		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		s.settimeout(1)
		s.connect((exp_port, i+1))
	except:
		return False
	return True


for i in range(nb_port):
	# print(i)
	if ScannerTCPv2(i):
		print(f"serveur à l'écoute sur le port {i+1}")
