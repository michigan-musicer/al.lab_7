vector: vector.c 
	gcc vector.c vector.h -o vector
	./vector

vector_example: vector_example.cpp
	g++ vector_example.cpp -o vector_example
	./vector_example