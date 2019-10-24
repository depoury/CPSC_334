import socket

UDP_IP = "192.168.1.1"
UDP_PORT = 57222

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
#sock.bind((UDP_IP, UDP_PORT))
Off = 'Stop!'
On = 'Start!'
S_Off = 'Speaker Off'
S_On = 'Speaker On'
L_Off = 'Lights Off'
L_On = 'Lights On'
Test = "Test"

sock.sendto(Off, (UDP_IP, UDP_PORT))
#sock.sendto(On, (UDP_IP, UDP_PORT))
#sock.sendto(L_Off, (UDP_IP, UDP_PORT))
#sock.sendto(L_On, (UDP_IP, UDP_PORT))
#sock.sendto(Test, (UDP_IP, UDP_PORT))