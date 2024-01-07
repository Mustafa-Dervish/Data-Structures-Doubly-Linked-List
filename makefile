derlevecalistir:program calistir

program:IkiYonluBagliList.o main.o
	g++ ./lib/IkiYonluBagliList.o ./lib/main.o -o ./bin/program
IkiYonluBagliList.o:
	g++ -I "./include" -c ./src/IkiYonluBagliList.cpp -o ./lib/IkiYonluBagliList.o
main.o:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
calistir:
	./bin/program.exe