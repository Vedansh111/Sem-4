import socket

host=socket.gethostname()
port=3000
Addr=(host,port)

server_socket=socket.socket()
server_socket.bind(Addr)
server_socket.listen()
conn,addr=server_socket.accept()

print("Connected through ",str(addr))

while True:
    data=conn.recv(1024).decode()
    if not data:
        break
        
    data1=int(data)*int(data)
    conn.send(str(data1).encode())

    
conn.close()
