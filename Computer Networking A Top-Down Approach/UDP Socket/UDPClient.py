from socket import *
serverName = "106.14.209.139"
serverPort = 10001
clientSocket = socket(AF_INET,SOCK_DGRAM)
message = raw_input("Input lowercase sentence:")
clientSocket.sendto(message,(serverName, serverPort))
modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
print serverAddress
print modifiedMessage
clientSocket.close()
