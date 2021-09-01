compile:
	g++ -o tmp/Point.o Point.cpp -c
	g++ -o tmp/Unit.o Unit.cpp -c
	g++ -o tmp/Layout.o Layout.cpp -c
	g++ -o tmp/Moover.o Moover.cpp -c
	g++ -o tmp/Compass.o Compass.cpp -c
	g++ -o tmp/Navigator.o Navigator.cpp -c
	g++ -o tmp/IPoint.o interfaces/IPoint.cpp -c
	g++ -o tmp/ICompass.o interfaces/ICompass.cpp -c
	g++ -o tmp/IUnit.o interfaces/IUnit.cpp -c
	g++ -o tmp/ILayout.o interfaces/ILayout.cpp -c
	g++ -o tmp/IMoover.o interfaces/IMoover.cpp -c
	g++ -o tmp/IMoover4Navigator.o interfaces/IMoover4Navigator.cpp -c
	g++ -o tmp/INavigator.o interfaces/INavigator.cpp -c


test: compile
	g++ -o mainTest.exe tests/mainTest.cpp tmp/*.o && ./mainTest.exe
	rm mainTest.exe

testDetail: compile
	g++ -o mainTest.exe tests/mainTest.cpp tmp/*.o && ./mainTest.exe -s
	rm mainTest.exe

testLight:
	g++ -o mainTest.exe tests/mainTest.cpp tmp/*.o && ./mainTest.exe
	rm mainTest.exe 

coverage:
	g++ --coverage tests/mainTest.cpp tmp/*.o -o testCoverage.exe && ./testCoverage.exe
	lcov -t "testCoverage" -o testCoverage.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report testCoverage.info --rc lcov_branch_coverage=1

clear:
	rm ./tmp/*.o

all: compile
	g++ run.cpp tmp/*.o && ./a.exe

run:
	g++ run.cpp tmp/*.o && ./a.exe
	