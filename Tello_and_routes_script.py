from djitellopy import Tello
from time import sleep
import numpy as np

tello = Tello()

tello.connect(False)
tello.send_command_with_return("takeoff", 3)

height = tello.send_read_command("height?")
height = height[:height.index('d')]
height = int(height)

if height < 200:
    tello.send_command_with_return("up " + str(200-height), 3)

tello.send_command_with_return("forward 70", 4)
tello.send_command_with_return("cw 180", 4)
tello.send_command_with_return("forward 70", 4) 

tello.land()
