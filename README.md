TETRIS IFB

1.Descrição

O jogo Tetris implementado em linguagem de programação C e utilizando a biblioteca ncurses foi desenvolvido como parte de um trabalho acadêmico. 
O objetivo do jogo é desafiar os jogadores a empilhar blocos de diferentes formas de maneira estratégica, a fim de completar linhas horizontais e 
evitar que a pilha de blocos alcance o topo da tela.

A implementação do Tetris em C com a biblioteca ncurses permite criar uma interface gráfica simples no terminal, 
onde os blocos caem verticalmente na tela. Os jogadores têm a capacidade de controlar a posição e a rotação dos blocos à medida que eles descem, 
com o objetivo de encaixá-los perfeitamente na pilha existente. Quando uma linha horizontal é completada, ela é eliminada, liberando espaço e concedendo pontos ao jogador. 

2.Instalação

1.Abra um terminal no seu sistema operacional Linux de preferência.
2.Faça o download do arquivo do jogo Tetris IFB, nomeado como "tetris.c".
3.Certifique-se de ter a biblioteca ncurses instalada no seu sistema operacional. Caso não tenha, você pode instalá-la executando o seguinte comando no terminal: sudo apt-get install libncurses-dev (para distribuições baseadas em Debian, como Ubuntu).
4.No terminal, navegue até o diretório onde o arquivo "tetris.c" está localizado.
5.Execute o seguinte comando no terminal para compilar o jogo Tetris IFB: gcc -o tetris tetris.c -lncurses.
6.Assim que o jogo for compilado com sucesso, será criado um arquivo executável chamado "tetris".
7.Para iniciar o jogo, digite o seguinte comando no terminal: ./tetris.
8.Agora você está pronto para jogar o Tetris IFB! Divirta-se e boa sorte!

Certifique-se de seguir as instruções com atenção para garantir uma instalação correta do jogo Tetris IFB no seu sistema operacional Linux.

Para facilitar a instalação do jogo Tetris IFB no sistema operacional Windows, aqui estão instruções aprimoradas:

1.Abra um terminal ou prompt de comando no seu sistema operacional Windows.
2.Faça o download do arquivo do jogo Tetris IFB, nomeado como "tetris.c".
3.Certifique-se de ter um compilador C instalado no seu sistema, como o GCC (GNU Compiler Collection). Você pode usar o MinGW ou o Cygwin, que fornecem o GCC para o ambiente Windows.
4.Verifique se o compilador C está configurado corretamente no seu sistema e adicionado ao PATH do sistema.
5.No terminal ou prompt de comando, navegue até o diretório onde o arquivo "tetris.c" está localizado.
6.Execute o seguinte comando para compilar o jogo Tetris IFB: gcc -o tetris tetris.c -lncurses.
7.Assim que o jogo for compilado com sucesso, será criado um arquivo executável chamado "tetris.exe".
8.Para iniciar o jogo, digite o seguinte comando no terminal ou prompt de comando: tetris.exe.
9.Agora você está pronto para jogar o Tetris IFB! Divirta-se e boa sorte!

3.Como Jogar
ara jogar o Tetris IFB, siga as seguintes instruções:

1.Certifique-se de que o jogo Tetris tenha sido compilado e esteja sendo executado no seu terminal, conforme as instruções de instalação fornecidas anteriormente.
2.Assim que o jogo for iniciado, você verá a tela do Tetris com um campo de jogo vazio.
3.Use as seguintes teclas para controlar o jogo:

Setas direcionais (para baixo, para esquerda, para direita): movem o tetrimino na direção correspondente.
Seta direciona para cima: gira o tetrimino no sentido horário.
Tecla ESC: enecerra o jogo.
4.O objetivo é empilhar os tetriminos de forma estratégica para completar linhas horizontais. Quando uma linha é completada, ela será eliminada, e você receberá pontos.
5.O jogo continuará até que a pilha de tetriminos atinja o topo da tela. Quando isso acontecer, o jogo termina e será exibida a sua pontuação final.

4.Controles

Setas direcionais (para baixo, para a esquerda e para a direita): movem o tetrimino na respectiva direção.
Setas direcional para cima: gira o tetrimino no sentido horário.
Tecla "ESC" : encerra o jogo.

5.Estrutura do Projeto

O codigo está estruturado da seguinte forma :

-Inclusão das bibliotecas necessárias: stdio.h, ncurses.h, stdlib.h, time.h e sys/time.h.

-Definição de constantes como MAP_X e MAP_Y para o tamanho do mapa do jogo, bem como as constantes TRUE e FALSE.

-Declaração de variáveis globais, incluindo a matriz map que representa o mapa do jogo, as variáveis max_y e max_x para armazenar as dimensões do terminal, borda para representar o caractere usado para desenhar a borda do mapa, score para armazenar a pontuação do jogador, GameOn para indicar se o jogo está em andamento, e timer para controlar o tempo entre os movimentos dos tetriminos.

-Definição da struct Tetramino que representa cada peça do jogo Tetris. A struct armazena um array bidimensional que representa a forma da peça, sua largura e sua posição no mapa.

-Declaração de um array TetraminoForma que contém as sete formas de tetriminos possíveis no jogo Tetris.

-Implementação de uma função CopiaTetramino que faz uma cópia de uma struct Tetramino.

-Implementação de uma função LimparCopiaTetramino para liberar a memória alocada para uma struct Tetramino.

-Implementação de uma função Checarposicao que verifica se uma posição é válida para um tetrimino no mapa.

-Implementação de uma função NovoTetramino para gerar um novo tetrimino aleatoriamente.

-Implementação de uma função RodarTetramino para girar um tetrimino no sentido horário.

-Implementação de uma função FixarTetramino para fixar um tetrimino no mapa.

-Implementação de uma função ChegagemdePontos para verificar se existem linhas completas no mapa e aumentar a pontuação do jogador.

-Implementação de uma função CriacaoMapa para criar e exibir o mapa do jogo na tela.

-Implementação de uma função MovimentacaoTetramino para lidar com os movimentos do tetrimino com base nos comandos de entrada do jogador.

-Implementação da função main, que é o ponto de entrada do programa. A função inicia o ambiente ncurses, inicializa variáveis, cria o primeiro tetrimino, exibe o mapa e entra em um loop principal que continua enquanto o jogo estiver em andamento. O loop lida com os comandos de entrada do jogador, atualiza o jogo, verifica a colisão, verifica se há linhas completas, exibe o novo estado do jogo e repete até que o jogo termine. 
Em seguida, exibe a mensagem "Game Over" e oferece ao jogador a opção de jogar novamente ou sair do jogo.

6.Contribuição
Ingrid Cristina Pereira da Silva(https://www.linkedin.com/in/ingrid-c-silva-b788461b8/)
Josué Felipe Vieira Klich(https://www.linkedin.com/in/josu%C3%A9-vieira-493768224/)
