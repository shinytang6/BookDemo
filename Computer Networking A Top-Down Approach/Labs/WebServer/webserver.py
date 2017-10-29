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
        # 如果在浏览器输入http://106.14.209.139:3389/index.html，message会返回HTTP报文类似下面
        #GET /index.html HTTP/1.1
        #Accept: text/html, application/xhtml+xml, */*
        #Accept-Language: zh-CN
        #User-Agent: Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; rv:11.0) like Gecko
        #Accept-Encoding: gzip, deflate
        #Host: 106.14.209.139:3389
        #DNT: 1
        #Connection: Keep-Alive
        print messgae
        
        #有时候message会返回空，所以要检测一下，否则message.split()[1]会报错
        if(message):
            filename = message.split()[1]   # 正常的话取得"/index.html"                        
            f = open(filename[1:])
            outputdata = f.read()
            #Send one HTTP header line into socket         
            header = ' HTTP/1.1 200 OK\nConnection: close\nContent-Type: text/html\nContent-Length: %d\n\n' % (len(outputdata))
            connectionSocket.send(header.encode())

        #Send the content of the requested file to the client
        #这里其实不循环也可以，直接connectionSocket.send(outputdata)也可以
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
