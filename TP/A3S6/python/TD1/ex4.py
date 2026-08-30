class Logger(object):
    def __init__(self, nom_fic):
        self.log_file = nom_fic

    def log_error(self, message):
        with open(self.log_file, 'a') as f:
            f.write(f"[ERROR] {message}\n")

    def log_warning(self, message):
        with open(self.log_file, 'a') as f:
            f.write(f"[WARNING] {message}\n")

    def log_info(self, message):
        with open(self.log_file, 'a') as f:
            f.write(f"[INFO] {message}\n")
        
with open("logs.txt", 'w') as f:
    pass
# create a logger object
logger = Logger("logs.txt")

# log an error message
logger.log_error("An error occurred while processing the request")

# log a warning message
logger.log_warning("Memory usage is reaching critical levels")

# log an info message
logger.log_info("Request processed successfully")

with open("logs.txt", "r") as file:
    content = file.read()
    print(content)
