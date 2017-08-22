var app = require('http').createServer()
var io = require('socket.io')(app);

app.listen(8001);
//客户端计数器
var clientCount = 0

io.on('connection', function (socket) {
    clientCount++
    socket.nickname = "user" + clientCount
    //注意：如果调用socket.emit表示对应的一个客户端，而直接调用io.emit就表示对所有客户端实行广播
    io.emit("enter",socket.nickname + " comes in")
    socket.on("message",function(str){
        io.emit("message",socket.nickname +" says:" + str)
    })
    //客户端断开事件
    socket.on("disconnect",function(){
        io.emit("leave",socket.nickname + " left")
    })
});




