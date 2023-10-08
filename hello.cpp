#include "bits/stdc++.h"
using namespace std;
class G{
    public:
        void gprint(){
            cout<<"g"<<endl;
        }
};
class P: public G{
    public:
        void pprint(){
            cout<<"p"<<endl;
            gprint();
        }
};
class Child: public P{
    public:
        void cprint(){
            cout<<"c"<<endl;
            pprint();
        }
};
int main(){
    Child c; 
    c.cprint();
}