// Worker.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include<string>
using namespace std;

class Worker{
private:
	string name;
	int age;
	string sex;
	float pay_per_hour;
	double hours;
public:	
	Worker(){};
	Worker(string n,int a,string s,float p,double h){name=n;age=a;sex=s;pay_per_hour=p;hours=h;};
	virtual void Compute_pay(){};
	friend ostream &operator<<(ostream& os,Worker &worker);
	friend istream& operator>>(istream& is,Worker& worker);
	void Setpay_per_hour(){cout<<"请输入薪资等级：";cin>>pay_per_hour;};
	float Getpay_per_hour(){return pay_per_hour;};
	double GetHours(){return hours;};

	string getname(){return name;}
	int getage(){return age;}
	string getsex(){return sex;}
};

ostream& operator<<(ostream &os,Worker &worker){
	os<<worker.name<<"\t";
	os<<worker.age<<"\t";
	os<<worker.sex<<"\t";
	os<<worker.pay_per_hour<<"\t";
	os<<worker.hours<<"\t";
	return os;
}
istream& operator>>(istream& is,Worker& worker){
		cout<<"输入姓名，年龄，性别，薪金等级,实际工作数"<<endl;
		is>>worker.name>>worker.age>>worker.sex>>worker.pay_per_hour>>worker.hours;
		return is;
}

class HourlyWorker:public Worker{
public:
	HourlyWorker();
	HourlyWorker(string n,int a,string s,float p,double h):Worker(n,a,s,p,h){};
	void Compute_pay(){
		float pay;
		if (GetHours()<40){
			pay=GetHours()*Getpay_per_hour();cout<<"周薪为："<<pay<<endl;}
		else
		{pay=Getpay_per_hour()*40+1.5*Getpay_per_hour()*(GetHours()-40);cout<<"周薪为："<<pay<<endl;}
		};
	//return pay;
	};
HourlyWorker::HourlyWorker():Worker(){}

class SalariedWorker:public Worker{
public:
	SalariedWorker();
	SalariedWorker(string n,int a,string s,float p,double h):Worker(n,a,s,p,h){};
	void Compute_pay(){
		float pay;
		if (GetHours()>=35){
			pay=Getpay_per_hour()*40;cout<<"周薪为："<<pay<<endl;}
		else
		{pay=Getpay_per_hour()*GetHours()+0.5*Getpay_per_hour()*(35-GetHours());cout<<"周薪为："<<pay<<endl;}
		//return pay;
	};
};
SalariedWorker::SalariedWorker():Worker(){}

void main(){
	Worker *w[5];
	for (int i=0;i<5;i++){
		int m;
		cout<<"请输入薪资等级(10,20,30,40,50):";
		cin>>m;
		switch(m){
			case 10:{cout<<"HourlyWorker 10"<<"\t";cout<<endl;HourlyWorker worker;cin>>worker;
				w[i]=new HourlyWorker(worker.getname(),worker.getage(),worker.getsex(),worker.Getpay_per_hour(),worker.GetHours());
				cout<<worker;worker.Compute_pay();
					}break;
			case 20:{cout<<"HourlyWorker 20"<<"\t";cout<<endl;HourlyWorker worker;cin>>worker;
				w[i]=new HourlyWorker(worker.getname(),worker.getage(),worker.getsex(),worker.Getpay_per_hour(),worker.GetHours());
				cout<<worker;worker.Compute_pay();}break;
			case 30:{cout<<"SalariedWorker 30"<<"\t";cout<<endl;SalariedWorker worker;cin>>worker;
				w[i]=new SalariedWorker(worker.getname(),worker.getage(),worker.getsex(),worker.Getpay_per_hour(),worker.GetHours());
				cout<<worker;worker.Compute_pay();}break;
			case 40:{cout<<"HourlyWorker 40"<<"\t";cout<<endl;HourlyWorker worker;cin>>worker;
				w[i]=new HourlyWorker(worker.getname(),worker.getage(),worker.getsex(),worker.Getpay_per_hour(),worker.GetHours());
				cout<<worker;worker.Compute_pay();}break;
			case 50:{cout<<"SalariedWorker 50"<<"\t";cout<<endl;SalariedWorker worker;cin>>worker;
				w[i]=new SalariedWorker(worker.getname(),worker.getage(),worker.getsex(),worker.Getpay_per_hour(),worker.GetHours());
				cout<<worker;worker.Compute_pay();}
		};
	}
}
