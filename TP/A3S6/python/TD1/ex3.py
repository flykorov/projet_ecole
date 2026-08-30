import json

def parse_json_file(name):
	with open(name, 'r') as f:
		fic = json.load(f)
	return fic

fichier = parse_json_file('request.json')
print(fichier)