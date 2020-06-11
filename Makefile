Main: Main.o objects/Cartesian.o objects/Coordinate.o objects/Function.o objects/Linear.o objects/Polynomial.o objects/Quadratic.o
	g++ Main.o objects/Cartesian.o objects/Coordinate.o objects/Function.o objects/Linear.o objects/Polynomial.o objects/Quadratic.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp -o Main.o

objects/Cartesian.o: objects/Cartesian.cpp objects/Cartesian.hpp
	g++ -c objects/Cartesian.cpp -o objects/Cartesian.o

objects/Coordinate.o: objects/Coordinate.cpp objects/Coordinate.hpp
	g++ -c objects/Coordinate.cpp -o objects/Coordinate.o

objects/Function.o: objects/Function.cpp objects/Function.hpp
	g++ -c objects/Function.cpp -o objects/Function.o

objects/Linear.o: objects/Linear.cpp objects/Linear.hpp
	g++ -c objects/Linear.cpp -o objects/Linear.o

objects/Polynomial.o: objects/Polynomial.cpp objects/Polynomial.hpp
	g++ -c objects/Polynomial.cpp -o objects/Polynomial.o

objects/Quadratic.o: objects/Quadratic.cpp objects/Quadratic.hpp
	g++ -c objects/Quadratic.cpp -o objects/Quadratic.o

clean:
	rm *.o objects/*.o Main