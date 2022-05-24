#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double iter_exp(double x)
{
      double orig_exp = x-4+2*pow(x,(double)1/3);
      double derivative = 1+2/3*pow(1/x,(double)2/3);
      return x-(orig_exp / derivative);
}

void newton(double x0, double e)
{
    int count=0;

    double pre = x0;
    double x = iter_exp(x0);

    while (abs(x - pre) > e)
    {
        cout <<"The result of the"<<" "<<count<<" "<<"iteration is"<<" "<<pre << endl;
        pre = x;
        x = iter_exp(x);
        if (count++ > 50)
        {
           cout << "Iteration failed" << endl;
           return ;
        }
    }
      cout << "the number of iterations is:" << count << endl;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    double x0, e;
    cout << "please input the value of x0:"<<"\n";
    cin >> x0;
    cout << "Please enter a tolerance:"<<"\n";
    cin >> e;
    newton(x0, e);

    return a.exec();
}
