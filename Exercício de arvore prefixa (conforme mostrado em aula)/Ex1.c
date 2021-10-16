#include<stdio.h>
#include<stdlib.h>

typedef struct Tnode *link;

struct Tnode {
 char token;
 link l, r;
};

char *a;
int i;

 // A função parse atua sobre a expressão prefixa a[i..].
 // Os operadores são '+' e '*', cada variável tem
 // um só caracter, e não há espaços entre os caracteres.
 // A função transforma a expressão em uma árvore binária
 // e devolve a raiz da árvore.
 
link parse();

imprime_arvore(link x, char lado);

//1. “Inspirando-se” no exemplo acima, escreva uma função que receba uma
//expressão aritmética e construa a correspondente árvore. Suponha que a 
//expressão só envolve os operadores '+','-','*', e '/' e operandos 
//que consistem em uma só letra. 


 int main(){
 	
 	//Ler na ordem raiz-esquerda-direita, teremos a expressão em notação prefixa
 	int tArvore = 5;
 	a = malloc(sizeof(char)*tArvore);
 	a[0] = '+';
 	a[1] = '1';
 	a[2] = '-';
 	a[3] = '3';
 	a[4] = '4';
	link x = parse();
	printf("Arvore:\n");
	imprime_arvore(x, ' ');
 }
 
 
  link parse() {
	char t;
	link x;
	t = a[i++];
	x = malloc(sizeof *x);
	x->token = t;
	if (t == '+' || t == '-' || t == '*' || t == '/') {
		x->l = parse();
		x->r = parse();
	}
	else {
	 	x->l = NULL;
	 	x->r = NULL;
	}
	 return x;
}


imprime_arvore(link x, char lado)
{
	if(x->token != NULL){
		printf("%c%c\n", lado, x->token);
		
		if(x->l != NULL && x->r != NULL){
			imprime_arvore(x->l, 'E');
			imprime_arvore(x->r, 'D');
		}
		else if(x->l != NULL){
			imprime_arvore(x->l, 'E');
		}
		else if(x->r != NULL){
			imprime_arvore(x->r, 'D');
		}
	}
}
 
