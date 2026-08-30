# TP2 client.py
# Victor Bouvier d'Acher

import requests
from PyQt5.QtWidgets import (
	QApplication,
	QWidget,
	QMainWindow,
	QPushButton,
	QLineEdit,
	QLabel,
	QMessageBox,
)
from PyQt5.Qt import QUrl, QDesktopServices
import sys

class MainWindow(QWidget):
	def __init__(self):
		super().__init__()
		self.initUI()

	def initUI(self):
		self.setWindowTitle("Client")
		self.setFixedSize(500, 500)
		self.label1 = QLabel("hostname:", self)
		self.label1.move(10, 0)
		self.label2 = QLabel("Answer:", self)
		self.label2.move(10, 200)
		self.text = QLineEdit(self)
		self.text.move(10, 20)
		self.text2 = QLineEdit(self)
		self.text2.move(10, 70)
		self.text3 = QLineEdit(self)
		self.text3.move(10, 120)
		self.label3 = QLabel("ip:", self)
		self.label3.move(10, 50)
		self.label4 = QLabel("api_key:", self)
		self.label4.move(10, 100)
		self.button = QPushButton("Send", self)
		self.button.move(30, 160)

		self.button.clicked.connect(self.on_click)
		self.button.pressed.connect(self.on_click)

		self.show()

	def on_click(self):
		hostname = self.text.text()
		ip = self.text2.text()
		api_key = self.text3.text()

		if ip == "" or api_key == "" or hostname == "":
			QMessageBox.about(self, "Error", "Please fill the field")
		else:
			res = self.__query(ip, hostname, api_key)
			if res:

				self.label2.setText("Answer:\nIP : %s\nOrganisation : %s\nCountry : %s\nLontitude : %s\nLatitude : %s" % (res["IP"], res["Organisation"], res["Country"], res["Longitude"], res["Latitude"]))
				self.label2.adjustSize()
				self.show()
				# print(res)
				# https://www.openstreetmap.org/?mlat=<lat>&mlon=<long>#map=12

				url = "https://www.openstreetmap.org/?mlat=%s&mlon=%s#map=12" % (res["Latitude"], res["Longitude"])
				QDesktopServices.openUrl(QUrl(url))

	def __query(self, ip, hostname, api_key):
		url = "http://%s/ip/%s?key=%s" % (hostname, ip, api_key)
		r = requests.get(url)
		if r.status_code == requests.codes.NOT_FOUND:
			QMessageBox.about(self, "Error", "IP not found")
		if r.status_code == requests.codes.OK:
			return r.json()


if __name__ == "__main__":
	app = QApplication(sys.argv)
	main = MainWindow()
	app.exec_()