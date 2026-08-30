import discord
import logging
from message.message import Message
from logger.logger import Logger


class MyBot(discord.Client):
    def __init__(self, logger: Logger):
        super().__init__(intents=discord.Intents.all())
        self.log = logger

    async def on_ready(self):
        print("MON sAc est FAIT")
        self.log.infolog(f"{self.user} has connected to Discord!")

    async def on_message(self, message: discord.Message):
        if message.author == self.user:
            return

        self.log.infolog(f"{message.author} said: {message.content}")

        m = Message(message)

        rep = m.parsing()
        if rep:
            await message.channel.send(rep)