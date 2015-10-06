require 'socket'

server = TCPServer.open(1025)
loop{

client = server.accept
client.puts(Time.now.ctime)
client.puts "Closing the connection. BYE!"
client.close

}
