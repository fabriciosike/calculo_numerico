/*
UNIVERSIDADE FEDERAL DA BAHIA - UFBA
DISCIPLINA: CALCULO NUMERICO - MAT174
PROFESSORA: RAFAELA SOUZA
ALUNOS: CRISTIAN ARAUJO E FABRICIO CIQUEIRA

PROJETO 01 - METODOD DAS CORDAS  
*/ 

#include <iostream>  //BIBLIOTECA PARA ENTRADA E SAIDA DE DADOS
#include <cmath>	// BIBLIOTECA PARA FUNCOES MATEMATICAS
using namespace std;

double funcao (double x){ 
	return (M_PI*pow((300/cos(x)),2)*0.8/(0.5*M_PI*14*14*(1+sin(x)-0.5*cos(x)))-1200); // EQUACAO PARA A CONCENTRACO GEOMETRICA DO FATOR C 
}

// METODO DAS CORDAS
double cordas(double a, double b, double e1, double e2){
	double erro, f_a, f_b, c, f_c; //VARIAVEIS PARA RAIZ, FUNCAO PARA CADA VALOR E ERRO
	int cont = 0; //VARIAVEL PARA CONTADOR DE INTERAÇÕES
	
	f_a=funcao(a); //CALCULANDO O VALOR DA FUNCAO PARA O INICIO DA FAIXA
    f_b=funcao(b); //CALCULANDO O VALOR DA FUNCAO PARA O FIM DA FAIXA
    c=(a*f_b - b*f_a)/(f_b-f_a); //CALCULANDO VALOR DA RAIZ
    f_c=funcao(c); //CALCULANDO O VALOR DA FUNCAO PARA A RAIZ
    erro=fabs(b-a); // CALCULANDO ERRO 
    
	while(erro>e1 || fabs(f_c)>e2){ //LOOPING COM VERIFICACAO DAS CONDICOES DE PARADA
		cont++; //INCREMENTANDO CONTADOR
        a=b; //TROCANDO O INCIO DA FAIXA
        b=c; //TROCANDO O FIM DA FAIXA
        f_a=funcao(a); //CALCULANDO O VALOR DA FUNCAO PARA O INICIO DA FAIXA
    	f_b=funcao(b); //CALCULANDO O VALOR DA FUNCAO PARA O FIM DA FAIXA
        c=(a*f_b - b*f_a)/(f_b - f_a); //CALCULANDO VALOR DA RAIZ
        f_c=funcao(c); //CALCULANDO O VALOR DA FUNCAO PARA A RAIZ
    	erro=fabs(b-a); // CALCULANDO ERRO 
    }
    
	cout<<"\nRaiz: "<<c<<endl; //IMPRIME A RAIZ MAIS PROXIMA
	cout<<"\nErro: "<<erro <<endl; // IMPRIME O ERRO
	cout<<"\nNumero de iteracoes: "<<cont<<endl; // IMPRIME O NUMERO DE INTERAÇÕES
	
	return c;
}

int main(){
	double a, b, e1, e2; //VARIAVEIS INICIAIS
	
	cout<<"**********************************METODO DAS CORDAS***************************************"<<endl; // MENU DO PROGRAMA
	cout<<"\nIncio do intervalo 'a':"<<endl;
	cin>>a; //PEGA O VALOR DO INICIO DO INTERVALO
	cout<<"\nFim do intervalo 'b':"<<endl;
	cin>>b; //PEGA O VALOR DO FIM DO INTERVALO
	cout<<"\nInforme o valor de epsilon 1:"<<endl;
	cin>>e1; //PEGA O VALOR DO EPSILON 1
	cout<<"\nInforme o valor de epsilon 2:"<<endl;
	cin>>e2; //PEGA O VALOR DO EPSILON 2

    if(a==b){ //VERIFICA SE EXISTE REALMENTE UMA FAIXA DE VALORES, E NÃO UM UNICO VALOR
        cout<<"\nOs valores de 'a' e 'b' sao iguais. Digite um novo valor para o fim do intervalo 'b':"<<endl;
        cin>>b;
    }else{
		cordas(a, b, e1, e2); //CHAMA O METODO NUMERICO
    }

}

