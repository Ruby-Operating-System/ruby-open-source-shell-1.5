import json


with open("build.json", "r") as file:
    config = json.load(file)


print("OS Version:", config["os"]["version"])
