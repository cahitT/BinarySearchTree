hepsi:	derle	calistir

derle:
	g++ -I ./include/ -o ./lib/Agac.o -c ./src/Agac.cpp
	g++ -I ./include/ -o ./lib/AgacDugum.o -c ./src/AgacDugum.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Liste.o -c ./src/Liste.cpp
	g++ -I ./include/ -o ./lib/Islem.o -c ./src/Islem.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Agac.o ./lib/AgacDugum.o ./lib/Dugum.o ./lib/Liste.o ./lib/Islem.o ./src/Test.cpp
calistir:
	./bin/Test