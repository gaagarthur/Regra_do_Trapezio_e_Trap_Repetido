#include<iostream>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

using namespace std;

void polinomial();
void racional();
//void exponencial();
void regraTrapezio();
//float derivative();
void methodChoice();
void roots();
int menu();

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

int num_trap, decisao_main;
float a, b, c, a2, b2, c2, height, x1, x2, root_value[2];

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


        break;

    default: 
    
    break;

    }


    return 0;
}
//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
void regraTrapezio(){

    float integral;

    cout<<"\n    Digite primeiro valor do intervalo: ";cin >> x1;
    cout<<"    Digite segundo  valor do intervalo: ";cin >> x2;
    height=x2-x1;

   /* if(decisao_main==2){
    roots();

    if(root_value[0])

    }
*/

    if(x1==x2){
        cout<<"\n    Os valores entrados resultam em uma integral = 0";
        menu();
    }

        if(height<0){
            height=height*(-1);
        }

    if(num_trap==1){

        switch(decisao_main){

            case 1:
                integral = (((a*pow(x1,2))+(b*x1)+(c)) + ((a*pow(x2,2))+(b*x2)+(c))) * (height / 2);
                cout<<"    integral = "<<integral;
                menu();

            break;

            case 2:



            break;




        }
    }else{









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

    cout<<"\n\n |=====================================|\n |Para funcoes racionais ate segundo grau|\n |    Para 1  grau  comece com  a = 0    |"<<endl<<endl;

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

void methodChoice(){

    char method[2];

    cout<<"\n    Qual metodo Voce quer usar?\n\n    |    Trapezio     | = T\n    |Trapezio Repetido| = TR \n\n    ---> "; cin>>method[2];

    method[2] = toupper(method[2]);

    switch(method[2]){

        case 'T':

            num_trap=1;

            regraTrapezio();

            break;

        case 'TR':

            cout<<"    Digite numero de trapezeis: ";cin >> num_trap;

            while(num_trap<=0){
                
                cout<<"    Numero de trapezeis invalido (escolha um numero > 0)\n";

                cout<<"    Digite numero de trapezeis: ";cin >> num_trap;

            }

            regraTrapezio();

            break;

        default:

            cout<<"    opcao nao valiva";
            methodChoice();
    }

}
//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
void roots(){

if(a2!=0){
    root_value[0] = ((0-b2) - sqrt(pow(b2,2)-(4*a2*c2)))/(2*a2);
    root_value[1] = ((0-b2) + sqrt(pow(b2,2)-(4*a2*c2)))/(2*a2);

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

