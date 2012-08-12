all:client server #all规则，它依赖client和server规则

client:tcp_process.o tcp_client.o
	gcc -o client tcp_process.o tcp_client.o

server:tcp_process.o tcp_server.o
	gcc -o server tcp_process.o tcp_server.o

clean:
	rm -fr client server *.o

