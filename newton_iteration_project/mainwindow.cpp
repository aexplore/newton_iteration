#include "mainwindow.h"
#include "ui_mainwindow.h"

vector<double> MainWindow::get_coe(){
    vector<double> coes;
    QString str_coe=ui->lineEdit->text();
    int first_pos=str_coe.indexOf(",");
    double first_coe=str_coe.mid(0,first_pos).toDouble();
    coes.push_back(first_coe);
    int last_pos=str_coe.lastIndexOf(",");
    double last_coe=str_coe.mid(last_pos+1,str_coe.size()-1-last_pos).toDouble();

    int coe_nums=str_coe.count(",");
    int pos_0=str_coe.indexOf(",");
    for(int i=0;i<coe_nums-1;++i){

        int pos_1=pos_0+1;
        while(str_coe[pos_1]!=","){
            pos_1++;
        }
        QString coe=str_coe.mid(pos_0+1,pos_1-pos_0-1);
        coes.push_back(coe.toDouble());
        pos_0=pos_1;


    }

     coes.push_back(last_coe);
//     for(int i=0;i<coes.size();++i){
//         qDebug()<<coes[i];
//     }
     return coes;
}

vector<double> MainWindow::get_index(){
    vector<double> index;
    QString str_coe=ui->lineEdit_2->text();
    int first_pos=str_coe.indexOf(",");
    double first_coe=str_coe.mid(0,first_pos).toDouble();
    index.push_back(first_coe);
    int last_pos=str_coe.lastIndexOf(",");
    double last_coe=str_coe.mid(last_pos+1,str_coe.size()-1-last_pos).toDouble();

    int coe_nums=str_coe.count(",");
    int pos_0=str_coe.indexOf(",");
    for(int i=0;i<coe_nums-1;++i){

        int pos_1=pos_0+1;
        while(str_coe[pos_1]!=","){
            pos_1++;
        }
        QString coe=str_coe.mid(pos_0+1,pos_1-pos_0-1);
        index.push_back(coe.toDouble());
        pos_0=pos_1;


    }

     index.push_back(last_coe);
//     for(int i=0;i<index.size();++i){
//         qDebug()<<index[i];
//     }
     return index;
}

double MainWindow::get_value(){
    QString str=ui->lineEdit_3->text();
    double value=str.toDouble();
    return value;
}

double MainWindow::get_precision(){
    QString str=ui->lineEdit_4->text();
    double precision=str.toDouble();
    return precision;
}

double MainWindow::iter_exp(double value){
    vector<double> coe=get_coe();
    vector<double> index=get_index();

    double exp_value=0;
    for(int i=0;i<coe.size();++i){
        exp_value=exp_value+coe[i]*pow(value,index[i]);
    }

    double deriva_value=0;
    for(int i=0;i<coe.size();++i){
        deriva_value=deriva_value+coe[i]*index[i]*pow(value,index[i]-1);
    }

    return value-exp_value/deriva_value;
}

double MainWindow::newton(){
    double precision=get_precision();
    double init_value=get_value();

    int count=0;

    double pre = init_value;
    double x = iter_exp(init_value);

    while (abs(x - pre) > precision)
    {
        //cout <<"The result of the"<<" "<<count<<" "<<"iteration is"<<" "<<pre << endl;
        pre = x;
        x = iter_exp(x);
        if (count++ > 50)
        {
//           cout << "Iteration failed" << endl;
           return -1;
        }
    }
//      cout << "the number of iterations is:" << count << endl;
    return x;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    get_coe();
//    get_index();
    ui->label_6->setText(QString::number(newton(),10,10));
}
