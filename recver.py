import socket
import os,sys,pygame
pygame.init()
size = (300,500)
screen = pygame.display.set_mode(size)
pygame.display.set_caption("web cam")
pygame.display.flip()
svrsocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
svrsocket.bind(('127.0.0.1',1234))
while 1:
  data,address = svrsocket.recvfrom(80000)
  if data:
    camshot = pygame.image.frombuffer(data, size, "RGB")
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
          sys.exit()
    screen.blit(camshot, (0,0))
    pygame.display.update()
