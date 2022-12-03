run: all
	./sigcheck

all:
	gcc -c -Wall aux/aux.c; gcc -c -Wall cheque/cheque.c; 
	gcc -c -Wall cliente/cliente.c; gcc -c -Wall lucro/lucro.c; 
	gcc -c -Wall movimentacao/movimentacao.c; gcc -c -Wall caixa/caixa.c; 
	gcc -c -Wall relatorio/relatorio.c; gcc -c -Wall main.c; gcc -o sigcheck *.o;

clean:
	rm *.o
