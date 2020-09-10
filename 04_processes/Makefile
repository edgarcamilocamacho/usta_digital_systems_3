all: test_pipes_01 test_pipes_02 posix_process_1

test_pipes_01: test_pipes_01.cpp
	g++ -o test_pipes_01 test_pipes_01.cpp

test_pipes_02: test_pipes_02.cpp
	g++ -o test_pipes_02 test_pipes_02.cpp

posix_process_1: posix_process_1.cpp
	g++ -o posix_process_1 posix_process_1.cpp

run_pipes_test: test_pipes_01 test_pipes_02
	./test_pipes_01 | ./test_pipes_02