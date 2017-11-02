from socket import *
import base64

frommail = "xxx@126.com"  # 发送邮箱地址
tomail = "xxx@126.com"   # 接受邮箱地址

# Choose a mail server (e.g. Google mail server) and call it mailserver 
mailserver = "smtp.126.com"
# Create socket called clientSocket and establish a TCP connection with mailserver
clientSocket = socket(AF_INET,SOCK_STREAM)
clientSocket.connect((mailserver,25))

recv = clientSocket.recv(1024)
print recv
if recv[:3] != '220':
    print '220 reply not received from server.'

# Send HELO command and print server response.
helloCommand = 'HELO world\r\n'
clientSocket.send(helloCommand)
recv1 = clientSocket.recv(1024)
print recv1
if recv1[:3] != '250':
    print '250 reply not received from server.'

# Auth
auth = 'AUTH LOGIN\r\n'
clientSocket.send(auth)
recv1 = clientSocket.recv(1024)
print recv1


# Username
username = base64.b64encode(frommail)
clientSocket.send(username+"\r\n")
recv1 = clientSocket.recv(1024)
print recv1

# Password
password = base64.b64encode("123456t") # 这个密码不是发送邮箱的密码，而是其授权smtp的密码，需要在邮箱设置中设置
clientSocket.send(password+"\r\n")
recv1 = clientSocket.recv(1024)
print recv1


# MailFrom
mailfrom = "MAIL FROM:<"+frommail+">\r\n"
clientSocket.send(mailfrom)
recv1 = clientSocket.recv(1024)
print recv1

# RCPTTO
recptto = "RCPT TO:<"+tomail+">\r\n"
clientSocket.send(recptto)
recv1 = clientSocket.recv(1024)
print recv1

# DATA
data= "DATA\r\n"
clientSocket.send(data)
recv1 = clientSocket.recv(1024)
print recv1

# Message
message = 'Subject: Tes E-mail\r\n'
message += 'from:' + frommail + '\r\n'
message += 'to:' + tomail + '\r\n'
message += "Content-type:" + "text/plain" + "\r\n"
clientSocket.send(message)
# 发送正文前要加一个空行
clientSocket.send("\r\n Hello my name is Tang Liang\r\n")
clientSocket.send(".\r\n")
recv1 = clientSocket.recv(1024)
print recv1

# Quit
quitCommand = 'QUIT\r\n'
clientSocket.send(quitCommand)
recv1 = clientSocket.recv(1024)
print recv1

clientSocket.close()
 
