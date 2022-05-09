#include<iostream>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

using namespace std;

void polinomial();
void racional();
void exponencial();
void regraTrapezio();
//float derivative();
void methodChoice();
void roots();
int menu();

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

int num_trap, decisao_main;
float a, b, c, a2, b2, c2, height, x1, x2, root_value[2], delta;

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
int main(){

// 1 funcoes afim ou quadratica | 2 funcao racional | 3 funcao exponencial


    cout<<"\n    Funcoes afim ou Quadratica | 1 |\n    Funcao Racional            | 2 |\n    Funcao Exponencial         | 3 |\n\n    ---> "; cin>>decisao_main;

    switch(decisao_main){

    case 1:
        polinomial();
        break;

    case 2:
        racional();
        break;

    case 3:
        exponencial();
        break;

    default: 
    cout<<"\n\n    Opcao invalida!\n";
    menu();
    break;

    }

}
//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
void regraTrapezio(){

    float integral, sum_of_fx=0, x_values;

    cout<<"\n    Digite primeiro valor do intervalo: ";cin >> x1;
    cout<<"    Digite segundo  valor do intervalo: ";cin >> x2;
    height=x2-x1;

    if(decisao_main==2){
        roots();

        if(a!=0 && delta>=0){
            if(root_value[0]!=root_value[1]){

                if(((root_value[0]>=x1&&root_value[0]<=x2)||(root_value[0]>=x2&&root_value[0]<=x1))||((root_value[1]>=x1&&root_value[1]<=x2)||(root_value[1]>=x2&&root_value[1]<=x1))){ 
                    /* checking if there's a asymptote located inside of the interval*/
                    cout<<"\n    Esta funcao apresenta uma assintota dentro do intervalo fornecido\n    Este programa nao esta preparado para fazer tal calculo\n";
                    menu();
                }
            }else if((root_value[0]==root_value[1])&&((root_value[0]>=x1&&root_value[0]<=x2)||(root_value[0]>=x2&&root_value[0]<=x1))){               

                    cout<<"\n    Esta funcao apresenta uma assintota dentro do intervalo fornecido\n    Este programa nao esta preparado para fazer tal calculo\n";
                    menu();
                
            }
        }else if((a==0)&&((root_value[0]>=x1&&root_value[0]<=x2)||(root_value[0]>=x2&&root_value[0]<=x1))){
            cout<<"\n    Esta funcao apresenta uma assintota dentro do intervalo fornecido\n    Este programa nao esta preparado para fazer tal calculo\n";
            menu();
        }
    }


    if(x1==x2){
        cout<<"\n    Os valores entrados resultam em uma integral = 0";
        menu();
    }
    if(height<0){
        height=height*(-1);
    }

    if(num_trap==1){

        switch(decisao_main){

            case 1: /* Polinomial */
                integral = (((a*pow(x1,2))+(b*x1)+(c)) + ((a*pow(x2,2))+(b*x2)+(c))) * (height / 2);
                cout<<"    integral = "<<integral;
                menu();

            break;

            case 2: /* Racional */
                integral = ((((a*pow(x1,2))+(b*x1)+(c))/((a2*pow(x1,2))+(b2*x1)+(c2)))+(((a*pow(x2,2))+(b*x2)+(c))/((a2*pow(x2,2))+(b2*x2)+(c2)))) * (height / 2);
                cout<<"    integral = "<<integral;
                menu();

            break;

            case 3: /* Exponencial f(x) = (a*e^(bx))+c */
                integral = (((a*exp(b*x1))+c)+(((a*exp(b*x2))+c)))*(height/2);
                cout<<"    integral = "<<integral;
                menu();

            break;


        }
    }else{/* ESPACO PARA TRAPEZIO REPETIDO */
        
        if(x1>x2){
            x2=x1+x2;
            x1=x2-x1;
            x2=x2-x1;
            }

        switch(decisao_main){

            case 1: /* Polinomial */

                for(int i=1; i<num_trap; i++ ){
                   x_values = (i*(height/num_trap))+x1;
                   sum_of_fx = ((a*pow(x_values,2))+(b*x_values)+(c)) + sum_of_fx;
                }

                integral = ((2*sum_of_fx)+((a*pow(x1,2))+(b*x1)+(c)) + ((a*pow(x2,2))+(b*x2)+(c)))*((height/num_trap)/2);
                cout<<"    integral = "<<integral;
                menu();

            break;

            case 2: /* Racional */
                

            break;

            case 3: /* Exponencial f(x) = (a*e^(bx))+c */
                

            break;







        }


    }


}

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
void polinomial(){



    cout<<"\n\n |=====================================|\n |      Para funcoes  polinomiais      |\n |    Para 1 grau  comece com a = 0    |"<<endl<<endl;

    cout<<"    Digite valor de a: ";cin >> a;
    cout<<"    Digite valor de b: ";cin >> b;
    cout<<"    Digite valor de c: ";cin >> c;

    if(a==0&&b==0&&c==0){
        cout<<"\n    Os valores entrados resultam em uma integral = 0";
        menu();
    }

    methodChoice();

}
//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
void racional(){

    cout<<"\n\n |=======================================|\n |Para funcoes racionais ate segundo grau|\n |    Para 1  grau  comece com  a = 0    |"<<endl<<endl;

	cout<<"\n    Dividendo:\n\n";
    cout<<"    Digite valor de a: ";cin >> a;
    cout<<"    Digite valor de b: ";cin >> b;
    cout<<"    Digite valor de c: ";cin >> c;
    
    if(a==0&&b==0&&c==0){
        cout<<"\n    Os valores entrados resultam em uma integral = 0";
        menu();
    }

    cout<<"\n\n    Divisor:\n\n";
    cout<<"    Digite valor de a: ";cin >> a2;
    cout<<"    Digite valor de b: ";cin >> b2;
    cout<<"    Digite valor de c: ";cin >> c2;
    
    if(a2==0&&b2==0&&c2==0){
    	cout<<"    \n\nA funcao tem 0 como denominador e resulta em uma indeterminacao matematica\n";
    	menu();
	}

    methodChoice();

}
//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
void exponencial(){

    cout<<"\n\n |====================================|\n";
	cout<<" |      Para funcoes exponenciais      |\n\n    vamos usar:\n\n    f(x) = ('a' vezes 'e' elevado a ('b'vezes 'x')) mais 'c' "<<"\n    f(x) = (a*e^(bx))+c ";
	
	cout<<"\n\n    Digite valor de a: ";cin >> a;
    cout<<"    Digite valor de b: ";cin >> b;
    cout<<"    Digite valor de c: ";cin >> c;

    if(a==0&&c==0){
        cout<<"\n    Os valores entrados resultam em uma integral = 0";
        menu();
    }
    methodChoice();
}
//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

void methodChoice(){

    char method;

    cout<<"\n    Qual metodo Voce quer usar?\n\n    |    Trapezio     | = T\n    |Trapezio Repetido| = R \n\n    ---> "; cin>>method;

    method = toupper(method);

    switch(method){

        case 'T':

            num_trap=1;
            cout<<"\n    Voce escolheu metodo do Trapezio\n";
            regraTrapezio();

            break;

        case 'R':

            cout<<"\n    Voce escolheu metodo do Trapezio Repetido\n";
            cout<<"\n    Digite numero de trapezeis: ";cin >> num_trap;

            while(num_trap<=0){
                
                cout<<"\n    Numero de trapezeis invalido (escolha um numero > 0)\n";

                cout<<"\n    Digite numero de trapezeis: ";cin >> num_trap;

            }

            regraTrapezio();

            break;

        default:

            cout<<"\n    opcao nao valiva";
            methodChoice();
    }

}
//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
void roots(){

    if(a2!=0){
        delta= pow(b2,2)-(4*a2*c2);
        if(delta>=0){
            root_value[0] = ((0-b2) - sqrt(delta))/(2*a2);
            root_value[1] = ((0-b2) + sqrt(delta))/(2*a2);
        }
    }else{
        root_value[0] = (0-c2)/b2;
    }

}
//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
int menu(){

    char opera;
    cout<<"\n    Deseja realizar outra operacao?\n\n           |Sim = S|    |Nao = N|"; cin>>opera;

    opera=toupper(opera);
    switch(opera){
        case 'S':

            main();
            break;
        
        case 'N':

            return 0;
            break;

        default:
            cout<<"\n    Escolha uma das opcoes\n";
            menu();
    }

}

