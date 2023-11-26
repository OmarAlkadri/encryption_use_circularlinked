hepsi: derle calistir
derle:
	g++ -I ./include/ -o ./lib/sifreleme.o -c ./src/sifreleme.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/sifreleme.o ./src/Test.cpp
calistir:
	./bin/Test