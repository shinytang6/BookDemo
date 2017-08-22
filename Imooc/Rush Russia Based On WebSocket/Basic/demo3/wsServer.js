var ws = require("nodejs-websocket")
//客户端计数器
var clientCount = 0
// Scream server example: "hi" -> "HI!!!"
var server = ws.createServer(function (conn) {
    console.log("New connection")
    clientCount++
    conn.nickname = "user" + clientCount
    broadcast(conn.nickname + " comes in")
    conn.on("text", function (str) {
        console.log("Received "+str)
        broadcast(str)
    })
    conn.on("close", function (code, reason) {
        console.log("Connection closed")
        broadcast(conn.nickname + " left")
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