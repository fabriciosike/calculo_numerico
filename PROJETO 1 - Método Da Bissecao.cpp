/*
UNIVERSIDADE FEDERAL DA BAHIA - UFBA
DISCIPLINA: CALCULO NUMERICO - MAT174
PROFESSORA: RAFAELA SOUZA
ALUNOS: CRISTIAN ARAUJO E FABRICIO CIQUEIRA

PROJETO 01 - METODOD DA BISSECAO
*/

#include <iostream>  //BIBLIOTECA PARA ENTRADA E SAIDA DE DADOS
#include <cmath>	// BIBLIOTECA PARA FUNCOES MATEMATICAS
using namespace std; 

double funcao (double x){ 
	return (M_PI*pow((300/cos(x)),2)*0.8/(0.5*M_PI*14*14*(1+sin(x)-0.5*cos(x)))-1200); // EQUACAO PARA A CONCENTRACO GEOMETRICA DO FATOR C 
} 

//METODO DA BISSECAO
double bissecao(double a, double b, double epsilon){ 
    int cont = 0; //VARIAVEL PARA CONTADOR DE INTERAÇÕES
    double c, fc; //VARIAVEIS PARA RAIZ E FUNCAO PARA O VALOR DA RAIZ
    double error = fabs(b-a); //VARIAVEL PARA ERRO
    
    while(error>epsilon){  //LOOPING COM VERIFICACAO DA CONDICAO DE PARADA
        c = (a+b)/2; //CALCULA A RAIZ
        fc = funcao(c); //CALCULA O VALOR DA FUNCAO PARA RAIZ
		
        if(funcao(a)*fc < 0) b = c; //ATRIBUI UM NOVO VALOR PARA O FIM DA FAIXA DE VALORES
		 
        if(fc*funcao(b) < 0) a = c; //ATRIBUI UM NOVO VALOR PARA O INICIO DA FAIXA DE VALORES
        
        cont++; //INTERA O CONTADOR DE INTERAÇÕES
        error = fabs(b-a); // CALCULA O NOVO ERRO
    }
	
	cout<<"\nRaiz: "<<c<<endl; //IMPRIME A RAIZ MAIS PROXIMA
	cout<<"\nErro: "<<error<<endl; // IMPRIME O ERRO
	cout<<"\nNumero de iteracoes: "<<cont<<endl; // IMPRIME O NUMERO DE INTERAÇÕES
	
	return c;
} 

int main(){
	double a, b, e; //VARIAVEIS INICIAIS
	
	cout<<"**********************************METODO DA BISSECAO***************************************"<<endl; // MENU DO PROGRAMA
	cout<<"\nIncio do intervalo 'a':"<<endl;
	cin>>a; //PEGA O VALOR DO INICIO DO INTERVALO
	cout<<"\nFim do intervalo 'b':"<<endl;
	cin>>b; //PEGA O VALOR DO FIM DO INTERVALO
	cout<<"\nInforme o valor de epsilon:"<<endl;
	cin>>e; //PEGA O VALOR DO EPSILON

    if(a==b){ //VERIFICA SE EXISTE REALMENTE UMA FAIXA DE VALORES, E NÃO UM UNICO VALOR
        cout<<"\nOs valores de 'a' e 'b' sao iguais. Digite um novo valor para o fim do intervalo 'b':"<<endl; 
        cin>>b;
    }else{
		bissecao(a,b,e); //CHAMA O METODO NUMERICO
    }
	
	return 0;
}
