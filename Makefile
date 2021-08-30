compile:
	g++ -o tmp/Point.o Point.cpp -c
	g++ -o tmp/Unit.o Unit.cpp -c
	g++ -o tmp/Layout.o Layout.cpp -c
	g++ -o tmp/Moover.o Moover.cpp -c
	g++ -o tmp/Compass.o Compass.cpp -c
	g++ -o tmp/Navigator.o Navigator.cpp -c


test: compile
	g++ -o mainTest.exe tests/mainTest.cpp tmp/*.o && ./mainTest.exe
	rm mainTest.exe

testDetail: compile
	g++ -o mainTest.exe tests/mainTest.cpp tmp/*.o && ./mainTest.exe -s
	rm mainTest.exe	

coverage:
	g++ -std=c++20 --coverage MainTest.cpp tmp/*.o -o testCoverage.exe && ./testCoverage.exe
	lcov -t "testCoverage" -o testCoverage.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report testCoverage.info --rc lcov_branch_coverage=1

clear:
	rm ./tmp/*.o

all: compile
	g++ run.cpp tmp/*.o && ./a.exe

run:
	g++ run.cpp tmp/*.o && ./a.exe
	