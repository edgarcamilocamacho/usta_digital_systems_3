all: 01_one_thread 02_N_threads 03_openmp1 04_openmp2_nothreads 04_openmp2_threads

01_one_thread: 01_one_thread.cpp
	g++ -o 01_one_thread 01_one_thread.cpp -pthread

02_N_threads: 02_N_threads.cpp
	g++ -o 02_N_threads 02_N_threads.cpp -pthread

03_openmp1: 03_openmp1.cpp
	g++ -o 03_openmp1 03_openmp1.cpp -fopenmp

04_openmp2_nothreads: 04_openmp2_nothreads.cpp
	g++ -o 04_openmp2_nothreads 04_openmp2_nothreads.cpp

04_openmp2_threads: 04_openmp2_threads.cpp
	g++ -o 04_openmp2_threads 04_openmp2_threads.cpp -fopenmp