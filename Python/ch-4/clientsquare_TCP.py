import socket

host=socket.gethostname()
port=3000
Addr=(host,port)

client_socket=socket.socket()
client_socket.connect((host,port))
message=input('enter number u want to square of:')

while message!='':
    client_socket.send(message.encode())
    data=client_socket.recv(1024).decode()
    print('received from server:',data)
    message=input('enter number u want to square of:')

client_socket.close() 
