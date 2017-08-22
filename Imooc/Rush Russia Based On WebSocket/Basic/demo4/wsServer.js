var ws = require("nodejs-websocket")
//客户端计数器
var clientCount = 0
// Scream server example: "hi" -> "HI!!!"
var server = ws.createServer(function (conn) {
    console.log("New connection")
    clientCount++
    conn.nickname = "user" + clientCount

    var mes = {}
    mes.type = "enter"
    mes.data = conn.nickname + " comes in"
    broadcast(JSON.stringify(mes))
    conn.on("text", function (str) {
        console.log("Received "+str)
        var mes = {}
        mes.type = "message"
        mes.data = conn.nickname + " says:" + str
        broadcast(JSON.stringify(mes))
    })
    conn.on("close", function (code, reason) {
        console.log("Connection closed")
        var mes = {}
        mes.type = "leave"
        mes.data = conn.nickname + " left"
        broadcast(JSON.stringify(mes))
    })
    conn.on("error",function(err){
        console.log("handle err:" + err)
    })
}).listen(8001)

function broadcast(str){
    //取到server下的所有连接，然后调用sendText方法广播
    //connections这个变量保存着server所有的连接
    server.connections.forEach(function(connection){
        connection.sendText(str)
    })
}