import socket

host=socket.gethostname()
port=2000
Addr=(host,port)

client_socket=socket.socket()
client_socket.connect((host,port))
message=input('-->')

while message!='':
    client_socket.send(message.encode())
    data=client_socket.recv(1024).decode()
    print('received from server:',data)
    message=input('-->')

client_socket.close()    
