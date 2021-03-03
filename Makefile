
bowling: ./src/game.cpp ./test/gameTest.cpp
	@mkdir -p bin
	@g++ -std=c++14 -o ./bin/tests ./src/game.cpp ./test/gameTest.cpp -Isrc/
	echo "Running test suite"
	@./bin/tests
