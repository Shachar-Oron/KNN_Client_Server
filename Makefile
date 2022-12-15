a.out: main.o DistancesCalcolators.o Knn.o Helpers.o LoadData.o StructHeader.o
	g++ ./*.o -o a.out

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

DistancesCalcolators.o: DistancesCalcolators.cpp DistancesCalcolators.h
	g++ -std=c++11 -c DistancesCalcolators.cpp

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