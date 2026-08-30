class Message():
	def __init__(self, message):
		self.message = message.content

	def parsing(self):
		
		if self.message.startswith("!hello"):
			return "Hello!"

		if self.message.startswith("!help"):
			return "list des commandes\n!help\n!hello"

