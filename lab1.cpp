#include <iostream>
#include <cmath>
using  namespace  std;

int main(){
    int k,number;
    double x,i;
    cout<<"Enter k:";
    while(true){
        cin>>k;
        if(k<=1){
            cout<<"Error! k is equal or below 1.Enter k:";
        }
        else{
            break;
        }
    }
    cout<<"Enter number of digits after decimal point:";
    while(true){
        cin>>number;
        if(number<1){
            cout<<"Error!  Number of digits after decimal point should be more or equal to 1."
                  "Enter number of digits after decimal point:";
        }
        else{
            break;
        }
    }
    cout<<"Enter x:";
    while(true){
        cin>>x;
        if(x==0){
            cout<<"Error! x can't be 0.\nEnter x: ";
        }
        else{
            break;
        }
    }

    i = pow(10, -k);//вводим значение переменной эпсилон, для сравнения последнего числа в ряду
    double part=1;//задаём значение первого слагаемого в ряду
    double result = 1;//задаем результату начальное значение, равное первому слагаемому
    int n = 1;
    while(fabs(part)>=i){ //сравниваем с эпсилон
        part *=-x*x/((n+1)*(n+2));//каждое следующее слагаемое
        n+=2;
        result +=part;//считаем сумму
    }
    cout<<fixed;
    cout.precision(number);//вводим кол-во знаков после запятой
    cout <<"The result of a standard function is:"<< sin(x)/x<<endl;
    cout <<"The result of calculating the Taylor series is:"<< result<<endl;
}