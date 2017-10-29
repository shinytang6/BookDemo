#import socket module
from socket import *
serverSocket = socket(AF_INET, SOCK_STREAM) 
#Prepare a sever socket 
#Fill in start
serverPort = 3389
serverSocket.bind(("",serverPort))
serverSocket.listen(1)
#Fill in end 
while True:     
    #Establish the connection    
    print 'Ready to serve...'     
    connectionSocket, addr =  serverSocket.accept()
    try:         
        message =  connectionSocket.recv(1024)   
        # ��������������http://106.14.209.139:3389/index.html��message�᷵��HTTP������������
        #GET /index.html HTTP/1.1
        #Accept: text/html, application/xhtml+xml, */*
        #Accept-Language: zh-CN
        #User-Agent: Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; rv:11.0) like Gecko
        #Accept-Encoding: gzip, deflate
        #Host: 106.14.209.139:3389
        #DNT: 1
        #Connection: Keep-Alive
        print messgae
        
        #��ʱ��message�᷵�ؿգ�����Ҫ���һ�£�����message.split()[1]�ᱨ��
        if(message):
            filename = message.split()[1]   # �����Ļ�ȡ��"/index.html"                        
            f = open(filename[1:])
            outputdata = f.read()
            #Send one HTTP header line into socket         
            header = ' HTTP/1.1 200 OK\nConnection: close\nContent-Type: text/html\nContent-Length: %d\n\n' % (len(outputdata))
            connectionSocket.send(header.encode())

        #Send the content of the requested file to the client
        #������ʵ��ѭ��Ҳ���ԣ�ֱ��connectionSocket.send(outputdata)Ҳ����
            for i in range(0, len(outputdata)):
                connectionSocket.send(outputdata[i])
            connectionSocket.close()
    except IOError:
        #Send response message for file not found
        header = ' HTTP/1.1 404 Found'
        connectionSocket.send(header.encode())
    
        #Close client socket
        connectionSocket.close()        
    serverSocket.close()
