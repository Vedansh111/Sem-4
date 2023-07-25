import socket

host=socket.gethostname()
port=3000
Addr=(host,port)

udp_server=socket.socket(type=socket.SOCK_DGRAM)
udp_server.bind(Addr)

while True:
    print('waiting for message')
    data,addr=udp_server.recvfrom(1024)
    if not data:
        break
    print('received',data.decode())
    msg=input('->')
    udp_server.sendto(msg.encode(),addr)
    
udp_server.close()    
