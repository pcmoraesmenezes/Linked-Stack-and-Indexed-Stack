#include <iostream> // incluindo a biblioteca iostream
using namespace std; // permite que não seja necessario o uso do std::
typedef struct no // criando uma struct com nome no
{
    int dado; // variavel que armazenar o valor
    no * prox; // no que aponta para a proxima struct
}no;// nome da struct
typedef struct pilha{ // nome da struct
    int topo; // variavel que armazena quantos elementos tem na lista
    no * inicio; // variavel do tipo no que aponta apra o inicio da pilha
}pilha; // nome da struct
void inicializar(pilha * p) // função que inicializa a pilha ligada
{
    p->inicio = NULL; // a lista está vazia então o ponteiro que aponta para o inicio da pilha não contém nada
    p->topo = -1;// topo está vazio pois não há nenhum elemento
}
void empilhar(pilha * p, int valor) // função de inserção de elementos na pilha, recebe como parametro um ponteiro do tipo pilha e um valor inteiro a ser adicionado    
{
    no * novo = new no; // alocando espaço na memoria
    novo->dado = valor; // o novo espaço na memoria que foi alocado e do tipo no e nessa linha, o novo no apontado para dado recebe o valor a ser adicionado
    novo->prox = p->inicio; // o ponteiro proximo aponta para o proximo elemento então nessa linha estamos fazendo o novo apontar para o proximo elemento do inicio da pilha    
    p->inicio = novo; // Nessa linha, o ponteiro "inicio" da estrutura "pilha" é atualizado para apontar para o novo nó criado. Isso é feito para que o novo nó seja o primeiro elemento da pilha, ou seja, o elemento no topo da pilha. 
    p->topo++; // o topo é incrementado
}
int desempilhar(pilha *p) // função de remoção de um elemento, que é o topo
{
    if (p->topo == -1) // verifica se o topo está vazio
    {
        printf("A lista está vazia ! \n"); //imprime uma mensagem para o usuario caso o topo esteja vazio
        return -1; // retorna -1
    }
    int valor = p->inicio->dado; // a variavel valor recebe o elemento que está sendo removido
    no * remover = p->inicio; // criando uma struct do tipo no e ela recebe o ponteiro que aponta para o inicio
    p->inicio = p->inicio->prox; // o ponteiro p do tipo pilha recebe o ponteiro p apontado para a struct inicio que é uma struct que aponta para o proximo
    free(remover); // liberando espaço na memoria
    p->topo--; // decrementando o tamanho da pilha
    return valor; // retorna o valor removido
}
void imprimePilha(pilha * p) // função que imprime a pilha, recebe como parametro a pilha
{
    no* atual = p->inicio;  // criando uma variavel atual do tipo no que recebe o ponteiro p do tipo pilha que aponta para o inicio
    printf("Pilha: "); // mensagem para o usuario
    while(atual!=NULL) // enquanto o proximo elemento não for nulo
    {
        printf("%d ", atual->dado); // printando os elementos
        atual = atual->prox; // fazendo o ponteiro "andar"
    }
    printf("\n"); // quebra de linha
}
int main() // função principal
{
    pilha * minha_pilha; // criando uma variavel do tipo pilha
    inicializar(minha_pilha); // inicializando essa variavel
    int navegador = 0; // essa variavel será responsavel por guiar o usuario na interface
    int adicionar = 0; // variavel responsavel por receber o numero que o usuario gostaria de inserir na pilha
    while (true) // essa condição faz com que o laço de repetição seja sempre verdade
   { 
        printf("Bem vindo a sua pilha! Para visualizar a sua pilha digite '1', para inserir um valor em sua pilha digite '2', para remover o topo de sua pilha digite '3' e para sair digite '4'\n"); // mensagem para o usuario
        scanf("%d", &navegador); // está recebendo do usuario um numero para ação
        while (navegador != 1 && navegador != 2 && navegador != 3 && navegador != 4) // verifica se o usuario digitou algo além do que esperado
        {
            printf("Você não informou uma opção válida! Tente novamente \n"); // informa que ele não digitou uma opção válida das que foram ofertadas
            scanf("%d", &navegador);// recebe do usuario outra opção
        }
        if (navegador == 1) // verifica se ele escolheu a opção 1
        {
            if(minha_pilha->topo == -1) // verifica se a pilha está vazia
            {
                printf("Pilha vazia ! \n"); // retorna uma mensagem
            }
            else{ // senao
            printf("Você optou por visualizar a pilha!\n "); // retorna uma mensagem
            imprimePilha(minha_pilha); // imprime a pilha na tela
            }
        }
        if (navegador == 2) // verifica se ele optou pela opção 2
        {
            printf("Você optou por inserir! Por favor insira o numero abaixo: \n"); // retorna uma mensagem
            scanf("%d", &adicionar); // recebe do usuario um numero a ser adicionado
            empilhar(minha_pilha, adicionar); // chamando a função que adiciona elementos na pilha
        }
        if (navegador == 3) // verifica se o usuario optou pela opção 3
        {
            if(minha_pilha->topo == -1) // verifica se a pilha está vazia
            {
                printf("Pilha vazia! \n"); // retorna uma mensagem
            }
            else // senao
            {
              printf("Você optou por remover o topo! Removendo %d\n ", minha_pilha->inicio->dado); // imprime uma mensagem na tela
              desempilhar(minha_pilha); // chama a função que remove o topo da pilha
              imprimePilha(minha_pilha);  // imprime a pilha na tela
            }
        }
        if (navegador == 4) // verifica se o usuario optou pela opção 4
        {   printf("Você optou por sair da pilha! \n"); // retorna uma mensagem
            break; // quebra o laço de repetição
        }
}
}