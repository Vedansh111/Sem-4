import socket

host=socket.gethostname()
port=3000
Addr=(host,port)

udp_client=socket.socket(type=socket.SOCK_DGRAM)

while True:
    data=input('Enter data:')
    if not data:
        break
        
    udp_client.sendto(data.encode(),Addr)
    print('ready to receive')
    
    data1,addr=udp_client.recvfrom(1024)
    if not data:
        break
    
    print('received',data1.decode())

udp_client.close()    
