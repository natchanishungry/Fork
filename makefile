main : producer.o consumer.o main.o
	gcc -o main producer.o consumer.o main.o

producer.o: producer.c
	gcc -c producer.c

consumer.o: consumer.c
	gcc -c consumer.c

main.o: main.c
	gcc -c main.c
