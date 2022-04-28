from lib2to3.pytree import convert
from pkgutil import get_data
import subprocess
import serial


class Main:
    def __init__(self, comm, serialMonitor, time):
        self.comm = comm
        self.serialMonitor = serialMonitor
        self.time = time

    def getData(self):
        arduino = serial.Serial(
            self.comm, baudrate=self.serialMonitor, timeout=self.time)

        while 1:
            converted = 0

            data = arduino.readline()
            decoded_data = data.decode()
            print(decoded_data)

            if decoded_data:
                converted = int(str(decoded_data))

            if(converted == 1):
                subprocess.Popen(
                    'C:\Program Files\Google\Chrome\Application\chrome.exe')
            elif(converted == 2):
                subprocess.Popen(
                    'C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe')
            elif(converted == 3):
                subprocess.Popen(
                    'C:\Program Files\Sublime Text\sublime_text.exe')
            elif(converted == 4):
                subprocess.Popen(
                    'C:\Program Files\Oracle\VirtualBox\VirtualBox.exe')
            elif(converted == 5):
                subprocess.Popen('C:\Windows\explorer.exe')
            else:
                pass


Main('COM6', 9600, 1).getData()
