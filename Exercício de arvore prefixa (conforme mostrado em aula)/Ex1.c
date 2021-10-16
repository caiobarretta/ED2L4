#include<stdio.h>
#include<stdlib.h>

typedef struct Tnode *link;

struct Tnode {
 char token;
 link l, r;
};

char *a;
int i;

 // A fun��o parse atua sobre a express�o prefixa a[i..].
 // Os operadores s�o '+' e '*', cada vari�vel tem
 // um s� caracter, e n�o h� espa�os entre os caracteres.
 // A fun��o transforma a express�o em uma �rvore bin�ria
 // e devolve a raiz da �rvore.
 
link parse();

imprime_arvore(link x, char lado);

//1. �Inspirando-se� no exemplo acima, escreva uma fun��o que receba uma
//express�o aritm�tica e construa a correspondente �rvore. Suponha que a 
//express�o s� envolve os operadores '+','-','*', e '/' e operandos 
//que consistem em uma s� letra. 


 int main(){
 	
 	//Ler na ordem raiz-esquerda-direita, teremos a express�o em nota��o prefixa
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
 
