#include <stdio.h>
using namespace std;
typedef struct pilha{
    int topo = - 1; //Variavel que irá receber o topo, sendo que essa variavel possuí o valor -1 quando não há nada no topo
    int indice[100]; //Variavel que irá receber os elementos da pilha
}pilha;
int tamanho = 0; // Variavel para verificar o tamanho atual da pilha
int peek(pilha *p)
{
    if (p->topo == -1) //verifica se o topo está vazio 
    {
        return -1;
    }
    else
    {
        return p->indice[p->topo]; // retorna o indice do topo caso não esteja vazio
    }
}
int push(pilha *p, int valor) // Os parametros são o ponteiro que aponta para a struct pilha e o valor a ser adicionado
{
    if (tamanho == 100) //verifica se a pihla está cheia
    {
        return -1;
    }
    else{
        p->indice[tamanho] = valor; //O ponteiro que aponta para o indice(variavel que contem a estrutura) recebe na posição do tamanho o valor
        p->topo = tamanho; // O topo recebe o indice atual
        tamanho = tamanho + 1; // o tamanho aumenta
        return valor;// Retorna o valor adicionado
    }
}
int pop(pilha * p) //Função para remover o topo da pilha, recebe como parametro a pilha
{
    if (p->topo == -1) // Verifica se a pilha está vazia
    {
        printf("Pilha vazia! \n");
        return -1;
    }
    else{
        int valor_removido = p->indice[p->topo]; // essa variavel recebe o valor a ser removido
        p->indice[p->topo] =  -1; // Aqui usamos o -1 como um espaço vazio para a variavel, estamos simplesmente deletando o valor
        tamanho = tamanho -1; // decrementando o tamanho
        p->topo = p->topo -1; // fazenodo o topo receber o topo anterior
        return valor_removido; //retornando o valor removido
    }
}
int imprimePilha(pilha * p) // variavel para imprimir a pilha
{
    if(p->topo == -1) // verifica se a pilha está vazia
    {
        printf("Pilha vazia!! \n");
        return -1;
    }
    else{
        for(int i = 0 ; i <=p->topo; i++) // essa repetição funciona da seguinte forma, a variavel i, ira percorrer ate o o ponteiro que a ponta para o topo que é a mesma coisa que pensar o tamanho da pilha
        {
            printf("%d\n", p->indice[i]);
        }
    }
}
int main()
{
    pilha * minha_pilha;
    int navegador = 0;
    int adicionar = 0;
    while (true)
   {   
        printf("Bem vindo a sua pilha! Para visualizar a sua pilha digite '1', para inserir um valor em sua pilha digite '2', para remover o topo de sua pilha digite '3' e para sair digite '4'\n");
        scanf("%d", &navegador);
        while (navegador != 1 && navegador != 2 && navegador != 3 && navegador != 4)
        {
            printf("Você não informou uma opção válida! Tente novamente \n");
            scanf("%d", &navegador);
        }
        if (navegador == 1)
        {
            if(minha_pilha->indice[tamanho] == -1)
            {
                printf("A sua pilha está vazia! \n");
            }
            else{
            printf("Você optou por visualizar a pilha!\n ");
            imprimePilha(minha_pilha);
            }
        }
        if (navegador == 2)
        {
            printf("Você optou por inserir! Por favor insira o numero abaixo: \n");
            scanf("%d", &adicionar);
            push(minha_pilha, adicionar);
        }
        if (navegador == 3)
        {
            printf("Você optou por remover o topo! Removendo\n ");
            pop(minha_pilha);
            imprimePilha(minha_pilha);  
        }
        if (navegador == 4)
        {   printf("Você optou por sair da pilha! \n");
            break;
        }
   }    
}
