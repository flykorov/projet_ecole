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

def ScannerTCPv2(i):

	exp_port = "127.0.0.1"
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
