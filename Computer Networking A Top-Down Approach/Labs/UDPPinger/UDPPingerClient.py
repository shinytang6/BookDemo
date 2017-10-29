from socket import *
import time
serverName = "106.14.209.139"
serverPort = 10001
clientSocket = socket(AF_INET,SOCK_DGRAM)
clientSocket.settimeout(1) # 设置套接字超时值1秒
for i in range(0,10):
    cur = time.time()
    message = "Ping %d %s"%(i+1,cur)
    try:
        clientSocket.sendto(message,(serverName, serverPort))
        modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
        rtt = time.time() - cur  # 计算往返时间
        print "Sequence %d: Request's RTT is %ss"%(i+1,rtt)
    except Exception:
        print "Sequence %d: Request timed out"%(i+1)

clientSocket.close()
