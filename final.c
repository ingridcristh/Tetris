#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MAP_X 20
#define MAP_Y 25
#define TRUE 1
#define FALSE 0

char map[MAP_X][MAP_Y] = {0};
int max_y, max_x;
char borda = '*';
int score = 0;
char GameOn = TRUE;
double timer = 500000; //meio segundo

//Struct para representar cada peça do jogo
typedef struct{
    char **array;
    int largura, pos_x,pos_y;
}Tetramino;
Tetramino tetramino_atual;

const Tetramino TetraminoForma[7]={
    //1 representam as partes da peça e os 0 representam espaços vazios
    {(char *[]){(char []){0,1,1},(char []){1,1,0}, (char []){0,0,0}}, 3},//S    
    {(char *[]){(char []){1,1,0},(char []){0,1,1}, (char []){0,0,0}}, 3},//Z    
    {(char *[]){(char []){0,1,0},(char []){1,1,1}, (char []){0,0,0}}, 3},//T  
    {(char *[]){(char []){0,0,1},(char []){1,1,1}, (char []){0,0,0}}, 3},//L    
    {(char *[]){(char []){1,0,0},(char []){1,1,1}, (char []){0,0,0}}, 3},//ML  
    {(char *[]){(char []){1,1},(char []){1,1}}, 2},//SQ
    {(char *[]){(char []){0,0,0,0}, (char []){1,1,1,1}, (char []){0,0,0,0}, (char []){0,0,0,0}}, 4} //R
};

//Fazer uma copia do tetramino
Tetramino CopiaTetramino(Tetramino tetramino){
    Tetramino novo_tetramino = tetramino;
    char **copiatetramino = tetramino.array;
    novo_tetramino.array = (char**)malloc(novo_tetramino.largura*sizeof(char*));
    for(int i = 0; i < novo_tetramino.largura;i++){
        novo_tetramino.array[i] = (char*)malloc(novo_tetramino.largura*sizeof(char));
        for(int j = 0; j< novo_tetramino.largura; j++){
            novo_tetramino.array[i][j] = copiatetramino[i][j];
        }
    }
    return novo_tetramino;
}

void LimparCopiaTetramino( Tetramino tetramino){
    for(int i = 0; i < tetramino.largura; i++){
        free(tetramino.array[i]);
    }
    free(tetramino.array);
}

//Verificação a posicao da forma copiada
int Checarposicao( Tetramino tetramino){
    char **array = tetramino.array;
    int i,j;
    for( i = 0; i < tetramino.largura;i++ ){
        for( j = 0; j < tetramino.largura; j++){
            if((tetramino.pos_y + j < 0 || tetramino.pos_y + j >= MAP_Y || tetramino.pos_x + i >= MAP_X )){
                if(array[i][j]){return FALSE;}
            }else if(map[tetramino.pos_x+i][tetramino.pos_y+j] && array[i][j]){return FALSE;}
        }
    }
    return TRUE;
}

//Novo tetramino aleatorio
void NovoTetramino(){
    Tetramino novo_tetramino = CopiaTetramino(TetraminoForma[rand()%7]);

    novo_tetramino.pos_y = (MAP_Y - novo_tetramino.largura)/2;
    novo_tetramino.pos_x = 0;
    LimparCopiaTetramino(tetramino_atual);
    tetramino_atual = novo_tetramino;
    //De houver colisão o jogo se encerra
    if(!Checarposicao(tetramino_atual)){
        GameOn = FALSE;
    }
}

void RodarTetramino(Tetramino tetramino){
    Tetramino tempo = CopiaTetramino(tetramino);
    int largura = tetramino.largura;
    for(int i = 0; i < largura; i++){
        for(int j =0, k = largura - 1 ; j < largura; j++,k--){
            tetramino.array[i][j] = tempo.array[k][i];
        }
    }
    LimparCopiaTetramino(tempo);
}

void FixarTetramino(){
    int i,j;
    for( i = 0; i < tetramino_atual.largura; i++){
        for( j = 0 ; j < tetramino_atual.largura; j++){
            if(tetramino_atual.array[i][j]){
                map[tetramino_atual.pos_x + i][tetramino_atual.pos_y + j] = tetramino_atual.array[i][j];
            }
        }
    }
}

//Checagem de linhas completas e aumento do tempo e pontuação
void ChegagemdePontos(){
    int i, j, soma, contagem=0;
    for(int i = 0; i<MAP_X;i++){
        soma = 0;
        for(int j = 0; j < MAP_Y; j++){
            soma += map[i][j];
        }
        if(soma == MAP_Y){
            contagem ++;
            int l,k;
            for( k = i; k >= 1; k--){
                for(l = 0 ; l <MAP_Y; l++){
                    map[k][l] = map[k - 1][l];
                }
            }for(l = 0; l <MAP_Y;l++){
                map[k][l] = 0;
            }
        }
    }
    timer-=1000;
    score += 10*contagem;
}

void CriacaoMapa(){
    char mapa[MAP_X][MAP_Y] = {0};
    for (int i = 0; i < tetramino_atual.largura; i++) {
        for (int j = 0; j < tetramino_atual.largura; j++) {
            if (tetramino_atual.array[i][j]) {
                mapa[tetramino_atual.pos_x + i][tetramino_atual.pos_y + j] = tetramino_atual.array[i][j];
            }
        }
    }
    clear();

    printw("\n Tetris IFB \n");
    printw("\n Pontuacao: %d\n", score);
    printw("|-------------------------|\n");

    for (int i = 0; i < MAP_X; i++) {
        printw("|");
        for (int j = 0; j < MAP_Y; j++) {
            printw("%c", (map[i][j] + mapa[i][j]) ? 'O' : ' ');
        }
        printw("|\n");
    }

    printw("|-------------------------|\n");
}

void LimparMapa(char mapa[MAP_X][MAP_Y]) {
    for (int i = 0; i < MAP_X; i++) {
        for (int j = 0; j < MAP_Y; j++) {
            mapa[i][j] = 0;
        }
    }
}

void MovimentacaoTetramino(int acao){
    Tetramino tempo = CopiaTetramino(tetramino_atual);
    switch(acao){
        case KEY_DOWN :
            tempo.pos_x++; // move para baixo
            if(Checarposicao(tempo)){
                tetramino_atual.pos_x++;
            }else{
                FixarTetramino();
                ChegagemdePontos();//verifica as linhas completas, depois de movimentar
                NovoTetramino();
            }
            break;
        case KEY_RIGHT :
            tempo.pos_y++; // move para direita
            if(Checarposicao(tempo)){
                tetramino_atual.pos_y++;
            }
            break;
        case KEY_LEFT:
            tempo.pos_y--; //move para esquerda
            if(Checarposicao(tempo)){
                tetramino_atual.pos_y--;
            }
            break;
            case KEY_UP :
            RodarTetramino(tempo);//roda o tetramino
            if(Checarposicao(tempo)){
                RodarTetramino(tetramino_atual);
            }
            break;
    }
    LimparCopiaTetramino(tempo);
    CriacaoMapa();
}

/*int main(){
    srand(time(0)); // Inicializa o time
    score = 0 ;
    int preciona;
    initscr();
    noecho();
    struct timeval before, after;
    gettimeofday(&before, NULL);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    NovoTetramino();
    CriacaoMapa();


    bool jogarNovamente = TRUE;
    while (jogarNovamente) { // loop externo para reiniciar o jogo

        jogarNovamente = FALSE; // seta para sair do loop externo se ocorrer outro "Game Over"

        while (GameOn) { // loop principal do jogo
            preciona = getch();
            if (preciona == 27) { // Verifica se o usuário pressionou ESC para sair do jogo
                 GameOn = FALSE;
                 printw("Deseja jogar novamente? (Sim-Enter/Nao-Esc)\n");
                 preciona = getch();
                 if (preciona == 10) {

                    //cria limpa jogo zera tudo e inicia um jogo novo

                 }else if (preciona == 27) {
                    GameOn = FALSE;
                    return 0;
                }
            } else if (preciona != ERR) {
                MovimentacaoTetramino(preciona);
            }
            gettimeofday(&after, NULL);
            if (((double)after.tv_sec*1000000 + (double)after.tv_usec) - ((double)before.tv_sec*1000000 + (double)before.tv_usec) > timer) {
                before = after;
                MovimentacaoTetramino(KEY_DOWN);
            }
        }

        printw("\nGame Over\n");
        LimparCopiaTetramino(tetramino_atual);
       
        printw("Deseja jogar novamente? (Sim-Enter/Nao-Esc)\n");
        while (TRUE) {
            preciona = getch();
            if (preciona == 10) {
                GameOn = TRUE;
                main();
                break;
             
            } else if (preciona == 27) {
                GameOn = FALSE;
                break;
            }
        }
    }

    endwin();
    return 0;
}*/




void jogo() {
    srand(time(0));
    score = 0;
    int preciona;
    initscr();
    noecho();
    struct timeval before, after;
    gettimeofday(&before, NULL);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    NovoTetramino();
    CriacaoMapa();

    while (GameOn) {
        preciona = getch();
        if (preciona == 27) {
            GameOn = FALSE;
            printw("Deseja jogar novamente? (Sim-Enter/Nao-Esc)\n");
            preciona = getch();
            if (preciona == 10) {
                // Limpar tudo e iniciar um jogo novo
                LimparMapa(map);
                NovoTetramino();
                score = 0;
                GameOn = true;
                main();
            } else if (preciona == 27) {
                GameOn = FALSE;
                break;
            }
        } else if (preciona != ERR) {
            MovimentacaoTetramino(preciona);
        }
        gettimeofday(&after, NULL);
        if (((double)after.tv_sec * 1000000 + (double)after.tv_usec) - ((double)before.tv_sec * 1000000 + (double)before.tv_usec) > timer) {
            before = after;
            MovimentacaoTetramino(KEY_DOWN);
        }
    }

    printw("\nGame Over\n");
    LimparCopiaTetramino(tetramino_atual);

    printw("Deseja jogar novamente? (Sim-Enter/Nao-Esc)\n");
    while (TRUE) {
        preciona = getch();
        if (preciona == 10) {
            // Reiniciar o jogo
            LimparMapa(map);
            NovoTetramino();
            score = 0;
            GameOn = true;
            break;
        } else if (preciona == 27) {
            GameOn = FALSE;
            break;
        }
    }

    endwin();
}

int main() {
    jogo();
    return 0;
}