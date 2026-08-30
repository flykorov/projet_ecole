from bot.bot import*
from argparse import ArgumentParser, Namespace
import json

def parse_args() -> Namespace:
	parser = ArgumentParser()
	parser.add_argument("-c", "--config", help="Config file", required=True, dest="config")
	return parser.parse_args()

def get_config(config_file: str) -> dict:
	with open(config_file, "r") as f:
		config = json.load(f)
	return config


def main(config: dict) -> bool:
	token = config["token"]
	log = Logger(config["log_config"])
	mybot = MyBot(log)
	mybot.run(token)
	pass


args = parse_args()

# print(args.config)
config = get_config(args.config)
main(config)


