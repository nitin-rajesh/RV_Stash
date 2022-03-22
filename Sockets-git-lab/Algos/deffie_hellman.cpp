#include<iostream>
#include<math.h>
#include<time.h>
#include<unistd.h>
using namespace std;

class Encyrpter{

    long int g, a, n;

    long int publicKey;
    long int privateKey;


public:

    long generatePublicKey(){

        publicKey = (long) pow(g,a) % n;

        cout<<publicKey<<endl;

        return publicKey;
    }

    void calculatePrivateKey(long pubKey){

        privateKey = (long) pow(pubKey,a) % n;

        cout<<privateKey<<endl;

    }

    Encyrpter(int n, int g){
        this->n = n;
        this->g = g;
        srand(time(0));
        a = rand() % 13;
        cout<<"g: "<<g<<"\ta: "<<a<<"\tn: "<<n<<endl;
        sleep(1);

    }
};

int main(){
    Encyrpter alice(97,3);
    Encyrpter bob(97,3);

    long pubKey = alice.generatePublicKey();
    bob.calculatePrivateKey(pubKey);
    pubKey = bob.generatePublicKey();
    alice.calculatePrivateKey(pubKey);
}