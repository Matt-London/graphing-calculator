Main: buildPath ../build/Main.o ../build/objects/Cartesian.o ../build/objects/Coordinate.o ../build/objects/Function.o ../build/objects/Linear.o ../build/objects/Polynomial.o ../build/objects/Quadratic.o
	g++ ../build/Main.o ../build/objects/Cartesian.o ../build/objects/Coordinate.o ../build/objects/Function.o ../build/objects/Linear.o ../build/objects/Polynomial.o ../build/objects/Quadratic.o -o Main

../build/Main.o: Main.cpp
	g++ -c Main.cpp -o ../build/Main.o

../build/objects/Cartesian.o: objects/Cartesian.cpp ../include/objects/Cartesian.hpp
	g++ -c objects/Cartesian.cpp -o ../build/objects/Cartesian.o

../build/objects/Coordinate.o: objects/Coordinate.cpp ../include/objects/Coordinate.hpp
	g++ -c objects/Coordinate.cpp -o ../build/objects/Coordinate.o

../build/objects/Function.o: objects/Function.cpp ../include/objects/Function.hpp
	g++ -c objects/Function.cpp -o ../build/objects/Function.o

../build/objects/Linear.o: objects/Linear.cpp ../include/objects/Linear.hpp
	g++ -c objects/Linear.cpp -o ../build/objects/Linear.o

../build/objects/Polynomial.o: objects/Polynomial.cpp ../include/objects/Polynomial.hpp
	g++ -c objects/Polynomial.cpp -o ../build/objects/Polynomial.o

../build/objects/Quadratic.o: objects/Quadratic.cpp ../include/objects/Quadratic.hpp
	g++ -c objects/Quadratic.cpp -o ../build/objects/Quadratic.o

buildPath:
	mkdir -p ../build/objects


clean:
	rm ../build/*.o ../build/objects/*.o