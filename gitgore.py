from os import system, getenv
from time import sleep

try:
	sleep_time = int(open(".gitgore").read())/1000
except FileNotFoundError:
	open(".gitgore","w").write("10000")
	sleep_time = 10000/1000

cmd_index = 0

def new_loop():
	global cmd_index
	cmd_index = 0
	sleep(sleep_time)
	print("Updating...", end="\r")

def handle_cmd(s: str) -> bool:
	global cmd_index
	cmd_index += 1
	if system(s):
		print(f"[{cmd_index-1}] Failed: '{s}'", end="\r")
		return True
	return False
username = getenv('username')
try:
	while True:
		new_loop()
		if handle_cmd("git add * > .log"): continue
		if handle_cmd(f"git commit -m \"commit by {username}\" > .log"): continue
		if handle_cmd("git push --force > .log"): continue
		if handle_cmd("git pull > .log"): continue
except KeyboardInterrupt:
	open(".gitgore","w").write(str(sleep_time*1000))