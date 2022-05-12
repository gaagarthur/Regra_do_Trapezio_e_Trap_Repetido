#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>

using namespace std;

void regraTrapezio();
void polinomial();
void racional();
void exponencial();
void methodChoice();
void roots();
float derivative_and_error();
int menu();

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

int num_trap, decisao_main;
float a, b, c, a2, b2, c2, height, x1, x2, root_value[2], delta;

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
int main(){


    cout<<"\n\n |=====================================|\n |          Regra do Trapezio          |\n |         e Trapezio Repetido         |\n";
    cout<<" |=====================================|"<<endl;
    cout<<"\n    Funcoes Afim ou Quadratica | 1 |\n    Funcao Racional            | 2 |\n    Funcao Exponencial         | 3 |\n\n    ---> "; cin>>decisao_main;

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
    //cout<<"\n\n    Opcao Invalida!\n";
    menu();

    }

}
//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
void regraTrapezio(){

    float integral, sum_of_fx=0, x_values, real_integral_value, foreseen_erro, abs_error;

    cout<<"\n    Digite primeiro valor do intervalo: ";cin >> x1;
    cout<<"    Digite segundo  valor do intervalo: ";cin >> x2;
    height=x2-x1;

    cout<<"\n    Digite o valor real da integral: ";cin >> real_integral_value;
    

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
     if(x1>x2){
        x2=x1+x2;
        x1=x2-x1;
        x2=x2-x1;
        }

    if(num_trap==1){/* REGRA DO TRAPEZIO*/

        switch(decisao_main){

            case 1: /* Polinomial */
                integral = (((a*pow(x1,2))+(b*x1)+(c)) + ((a*pow(x2,2))+(b*x2)+(c))) * (height / 2);
                cout<<"\n    integral = "<<integral;
                //menu();

            break;

            case 2: /* Racional */
                integral = ((((a*pow(x1,2))+(b*x1)+(c))/((a2*pow(x1,2))+(b2*x1)+(c2)))+(((a*pow(x2,2))+(b*x2)+(c))/((a2*pow(x2,2))+(b2*x2)+(c2)))) * (height / 2);
                cout<<"\n    integral = "<<integral;
                //menu();

            break;

            case 3: /* Exponencial */
                integral = (((a*exp(b*x1))+c)+(((a*exp(b*x2))+c)))*(height/2);
                cout<<"\n    integral = "<<integral;
                //menu();

            break;

        }
        cout<<"\n    Integral = "<<integral;


        cout<<fixed<<"\n    Erro Previsto <= "<<foreseen_erro;

        abs_error=integral-real_integral_value;
        cout<<"\n    Erro Absoluto = "<<abs_error;      
                
        cout<<defaultfloat<<setprecision(3)<<"\n    Erro Relativo = "<<(abs_error/real_integral_value)*100<<"%";
        menu();

    }else{/* REGRA TRAPEZIO REPETIDO */
        

        switch(decisao_main){

            case 1: /* Polinomial */

                for(int i=1; i<num_trap; i++ ){
                   x_values = (i*(height/num_trap))+x1;
                   sum_of_fx = ((a*pow(x_values,2))+(b*x_values)+(c)) + sum_of_fx;
                }
                
                integral = ((2*sum_of_fx)+((a*pow(x1,2))+(b*x1)+(c)) + ((a*pow(x2,2))+(b*x2)+(c)))*((height/num_trap)/2);
                /*cout<<"\n    Integral = "<<integral;
                
                foreseen_erro = derivative_and_error();
                cout<<"\n    Erro Previsto <= "<<foreseen_erro;

                abs_error=integral-real_integral_value;
                cout<<"\n    Erro Absoluto = "<<abs_error;      
                
                cout<<setprecision(3)<<"\n    Erro Relativo = "<<(abs_error/real_integral_value)*100<<"%";
                menu();*/

            break;

            case 2: /* Racional */
                
                for(int i=1; i<num_trap; i++ ){
                   x_values = (i*(height/num_trap))+x1;
                   sum_of_fx = (((a*pow(x_values,2))+(b*x_values)+(c))/((a2*pow(x_values,2))+(b2*x_values)+(c2))) + sum_of_fx;
                }
                foreseen_erro = derivative_and_error();

                integral = ((2*sum_of_fx) + (((a*pow(x1,2))+(b*x1)+(c))/((a2*pow(x1,2))+(b2*x1)+(c2))) + (((a*pow(x2,2))+(b*x2)+(c))/((a2*pow(x2,2))+(b2*x2)+(c2)))) * ((height/num_trap)/2);
                /*cout<<"\n    Integral = "<<integral;

                cout<<"\n    Erro Previsto <= "<<foreseen_erro;

                abs_error=integral-real_integral_value;
                cout<<fixed<<"\n    Erro Absoluto = "<<abs_error;      
                
                cout<<defaultfloat<<setprecision(3)<<"\n    Erro Relativo = "<<(abs_error/real_integral_value)*100<<"%";
                menu();*/

            break;

            case 3: /* Exponencial */
                
                for(int i=1; i<num_trap; i++ ){
                   x_values = (i*(height/num_trap))+x1;
                   sum_of_fx = (((a*exp(b*x_values))+c)) + sum_of_fx;
                }
                foreseen_erro = derivative_and_error();

                integral = ((2*sum_of_fx)+  ((a*exp(b*x1))+c)+(((a*exp(b*x2))+c)))*((height/num_trap)/2);
                /*cout<<"\n    Integral = "<<integral;


                cout<<fixed<<"\n    Erro Previsto <= "<<foreseen_erro;

                abs_error=integral-real_integral_value;
                cout<<"\n    Erro Absoluto = "<<abs_error;      
                
                cout<<defaultfloat<<setprecision(3)<<"\n    Erro Relativo = "<<(abs_error/real_integral_value)*100<<"%";
                menu();*/

            break;

        }

            cout<<"\n    Integral = "<<integral;


            cout<<fixed<<"\n    Erro Previsto <= "<<foreseen_erro;

            abs_error=integral-real_integral_value;
            cout<<"\n    Erro Absoluto = "<<abs_error;      
                
            cout<<defaultfloat<<setprecision(3)<<"\n    Erro Relativo = "<<(abs_error/real_integral_value)*100<<"%";
            menu();

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
	cout<<" |      Para funcoes exponenciais     |\n\n    vamos usar:\n\n    f(x) = ('a' vezes 'e' elevado a ('b'vezes 'x')) mais 'c' "<<"\n    f(x) = (a*e^(bx))+c ";
	
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
float derivative_and_error(){

    float error_abs, error_study, deriv, x_for_max_fx, gx;

    switch(decisao_main){

            case 1://  for a!=0 --> f"(x)=  a*2       for a==0 ---> f"(x)= 0            

                if(a!=0){
                    error_study = (pow(x2-x1,3)/(12*pow(num_trap,2)))*(a*2);
                    return error_study;
                    
                }else{
                    error_study=0;
                    return error_study;               
                }
                
            break;


            case 2: //

                if((a!=0&&a2!=0) || (a==0&&a2!=0) || (a!=0&&a2==0)){
                    cout<<"\n    Este programa nao e capaz de realizar o calculo de f\"(x)";
                    cout<<"\n    Insira o valor de f\"(x) em que x resulte no maior |f(x)|\n\n    ---> ";cin>>deriv; //verify if is supposed to be the max fx or |fx|

                    if(deriv<0){
                        deriv=deriv*-1;
                    }

                    error_study = (pow(x2-x1,3)/(12*pow(num_trap,2)))*deriv;
                    return error_study;
                    
                }else{// a==0 && a2==0 (f'*g-g'*f)/()
                    cout<<"\n    Insira o valor de x que resulte no maior |f(x)| dentro do intervalo\n\n    ---> ";cin>>x_for_max_fx;

                    gx = (b2*x_for_max_fx)+c2; 
                    deriv = ((b*c2) - (b2*c)) / pow(gx,2); 

                    error_study = (pow(x2-x1,3)/(12*pow(num_trap,2)))*deriv;
                    return error_study;
                }

            break;


            case 3:

                if(a==0||b==0){
                    deriv =0;
                }else if(a!=0 && b!=0){
                    cout<<"\n    Insira o valor de x que resulte no maior |f(x)| dentro do intervalo\n\n    ---> ";cin>>x_for_max_fx;
                    deriv = (a*b*b)*exp(b*x_for_max_fx);
                }
                error_study = (pow(x2-x1,3)/(12*pow(num_trap,2)))*deriv;
                return error_study;

            break;

    }

}
//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
int menu(){

    char opera;
    cout<<"\n\n    Deseja realizar outra operacao?\n\n           |Sim = S|    |Nao = N|\n\n    ---> "; cin>>opera;

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

