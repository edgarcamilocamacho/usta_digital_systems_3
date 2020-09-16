all: test_pipes_01 test_pipes_02 posix_process_1 posix_process_2 posix_process_3 multiple_children

test_pipes_01: test_pipes_01.cpp
	g++ -o test_pipes_01 test_pipes_01.cpp

test_pipes_02: test_pipes_02.cpp
	g++ -o test_pipes_02 test_pipes_02.cpp

run_pipes_test: test_pipes_01 test_pipes_02
	./test_pipes_01 | ./test_pipes_02

posix_process_1: posix_process_1.cpp
	g++ -o posix_process_1 posix_process_1.cpp

posix_process_2: posix_process_2.cpp
	g++ -o posix_process_2 posix_process_2.cpp

posix_process_3: posix_process_3.cpp
	g++ -o posix_process_3 posix_process_3.cpp

multiple_children: multiple_children.cpp
	g++ -o multiple_children multiple_children.cpp	