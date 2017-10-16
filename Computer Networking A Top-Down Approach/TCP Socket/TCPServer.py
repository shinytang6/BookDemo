from socket import *
serverPort = 3389
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind(("",serverPort))
serverSocket.listen(1)
print "The server is ready to receive"
while 1:
        connectionSocket, addr = serverSocket.accept()
        sentence = connectionSocket.recv(1024)
        capital = sentence.upper()
        connectionSocket.send(capital)
        connectionSocket.close()
