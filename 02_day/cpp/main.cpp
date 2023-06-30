#include <iostream>
using namespace std;

class A{
	int a;
	int b;
public:
	A(int a,int b):a(a),b(b){
		cout<<"构造器"<< endl;
	}
	~A(){
		cout<<"析构器"<< endl;
	}
};

int main(){
	A* p = new A(1,2);
	delete p;
}