#a.out: main.o DistancesCalcolators.o Knn.o Helpers.o LoadData.o StructHeader.o Client.o Server.o
#	g++ ./*.o -o a.out
a.out:  DistancesCalcolators.o Knn.o Helpers.o LoadData.o StructHeader.o Client.o Server.o
	g++ ./*.o -o a.out
#main.o: main.cpp
#	g++ -std=c++11 -c main.cpp

Client.o: Client.cpp Client.h
	g++ -std=c++11 -c Client.cpp

Client.o: Client.cpp Client.h
	g++ -std=c++11 -c Client.cpp

Server.o: Server.cpp Server.h
	g++ -std=c++11 -c Server.cpp

Knn.o: Knn.cpp Knn.h
	g++ -std=c++11 -c Knn.cpp

LoadData.o: LoadData.cpp LoadData.h
	g++ -std=c++11 -c LoadData.cpp

Helpers.o: Helpers.cpp Helpers.h
	g++ -std=c++11 -c Helpers.cpp

StructHeader.o: StructHeader.cpp StructHeader.h
	g++ -std=c++11 -c StructHeader.cpp

clean:
	rm *.o a.out