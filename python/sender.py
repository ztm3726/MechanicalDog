import socket

from VideoCapture import Device
cam = Device()
cam.setResolution(1280,720)
clisocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while 1:
  im = cam.getImage()
  im = im.resize((300,500))
  da = im.tobytes()
  clisocket.sendto(da, ("127.0.0.1", 1234))

