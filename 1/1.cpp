#include <iostream>
using namespace std;

class E {
public:
    int id;
    string n;
    string g;
private:
    int s;
public:
    void set(int a, string b, string c, int d){
        id=a;
        n=b;
        g=c;
        s=d;
    }
    void upd(int x){
        s=x;
    }
    void show(){
        cout<<id<<" "<<n<<" "<<g<<" "<<s<<endl;
    }
};

int main(){
    E e[10];
    int i,a,d;
    string b,c;

    for(i=0;i<10;i++){
        cin>>a>>b>>c>>d;
        e[i].set(a,b,c,d);
    }

    for(i=0;i<10;i++){
        cin>>d;
        e[i].upd(d);
    }

    for(i=0;i<10;i++){
        e[i].show();
    }
}
