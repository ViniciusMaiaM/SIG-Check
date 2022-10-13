<h1 align = "center">SIG-Check</h1>

## Descrição do Repositório 

Repositório criado para o projeto desenvolvido durante a disciplina de programação.

## Proposta geral do projeto

O presente projeto tem como objetivo desenvolver um programa de computador que realize o cadastro e o acompanhamento de cheque pré-datados, auxiliando o controle financeiro de uma empresa.

### Membros
| Nome            | Perfil                                          |
|-----------------|-------------------------------------------------|
| Thamiris Borges |[Thami03](https://github.com/Thami03)            |
| Vinicius Maia   |[ViniciusMaiaM](https://github.com/ViniciusMaiaM)|


### Compilação

- Caso possua a ferramente de automação make, apenas digite o comando a seguir para a compilação e execução do código:
`make`


- Se sua maquina não possuir a ferramenta, apenas copie e cole os seguintes comandos em seu terminal:
`gcc -c -Wall aux/aux.c; gcc -c -Wall cheque/cheque.c; gcc -c -Wall cliente/cliente.c; gcc -c -Wall lucro/lucro.c; gcc -c -Wall movimentacao/movimentacao.c; gcc -c -Wall main.c; gcc -o sigcheck *.o;`