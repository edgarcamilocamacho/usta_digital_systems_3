all: 01_smem_producer 01_smem_consumer 02_pi 02_pi_parallel 03_shmem_flag_tx 03_shmem_flag_rx 04_queue_producer 04_queue_consumer

01_smem_producer: 01_smem_producer.cpp
	g++ -o 01_smem_producer 01_smem_producer.cpp -lrt

01_smem_consumer: 01_smem_consumer.cpp
	g++ -o 01_smem_consumer 01_smem_consumer.cpp -lrt

02_pi: 02_pi.cpp
	g++ -o 02_pi 02_pi.cpp

02_pi_parallel: 02_pi_parallel.cpp
	g++ -o 02_pi_parallel 02_pi_parallel.cpp

03_shmem_flag_tx: 03_shmem_flag_tx.cpp
	g++ -o 03_shmem_flag_tx 03_shmem_flag_tx.cpp -lrt

03_shmem_flag_rx: 03_shmem_flag_rx.cpp
	g++ -o 03_shmem_flag_rx 03_shmem_flag_rx.cpp -lrt

04_queue_consumer: 04_queue_consumer.cpp
	g++ -o 04_queue_consumer 04_queue_consumer.cpp -lrt

04_queue_producer: 04_queue_producer.cpp
	g++ -o 04_queue_producer 04_queue_producer.cpp -lrt