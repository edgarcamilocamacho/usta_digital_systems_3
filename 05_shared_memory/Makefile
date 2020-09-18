all: 01_smem_producer 01_smem_consumer 02_pi 02_pi_parallel

01_smem_producer: 01_smem_producer.cpp
	g++ -o 01_smem_producer 01_smem_producer.cpp -lrt

01_smem_consumer: 01_smem_consumer.cpp
	g++ -o 01_smem_consumer 01_smem_consumer.cpp -lrt

02_pi: 02_pi.cpp
	g++ -o 02_pi 02_pi.cpp

02_pi_parallel: 02_pi_parallel.cpp
	g++ -o 02_pi_parallel 02_pi_parallel.cpp