require 'socket'

PORT = 3010
socket = TCPServer.new('0.0.0.0',PORT)

optval = socket.getsockopt(SOCKET::SOL_SOCKET,Socket::SO_SNDBUF);
optval = optval.unpack "i"
puts "SNDBUF Early Option : #{optval}"
socket.setsockopt(Socket::SOL_SOCKET, Socket::SO_SNDBUF, 5342);
optval = socket.getsockopt(Socket::SOL_SOCKET, Socket::SO_SNDBUF);
optval = optval.unpack "i"
puts "SNDBUF after Edit :  #{optval}" 
