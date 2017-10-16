from socket import *
serverName = "106.14.209.139"
serverPort = 3389
clientSocket = socket(AF_INET,SOCK_STREAM)
clientSocket.connect((serverName,serverPort))
sentence = raw_input("Input lowercase sentence:")
clientSocket.send(sentence)
modifiedSentence = clientSocket.recv(1024)
print modifiedSentence
clientSocket.close()
