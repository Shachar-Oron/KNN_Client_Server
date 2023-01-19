
all: Server Client

Server: Server.cpp Server.h
	g++ -std=c++11 -o Server.out Server.cpp Server.h CLI.cpp CLI.h Command.cpp Command.h DistancesCalcolators.cpp DistancesCalcolators.h Knn.cpp Knn.h LoadData.cpp LoadData.h Helpers.cpp Helpers.h StructHeader.cpp StructHeader.h

Client: Client.cpp Client.h
	g++ -std=c++11 -o Client.out Client.cpp Client.h Helpers.cpp Helpers.h

clean:
	rm Client Server