#include<iostream>
#include<math.h>
using namespace std;


class RSA{

    long int p, q, e, n, phi, d;
    
    long int publicKey;
    long int privateKey;

    char message[128];
    int cipher[128];

public:

    long cascadedMod(int base, int expo, int mod){
        if(expo <=  0)
            return 1;
        return (base*cascadedMod(base,expo - 1, mod))%mod;
    }

    void findPrivateKey(){
        int k = 0;
        cout<<"Here";
        do{
            d = (++k*phi + 1)/e;
            cout<<d<<'\n';
        }while((k*phi + 1)%e);
    }

    int* encrypt(char message[]){
        int i;
        for(i = 0; message[i] != '\0'; i++){
            cipher[i] = cascadedMod(message[i],e,n);
            cout<<(int)message[i]<<">>"<<cipher[i]<<endl;
        }
        cipher[i] = '\0';
        return cipher;
    }

    char* decrypt(int cipher[]){
        int i;
        for(i = 0; cipher[i] != '\0'; i++){
            message[i] = cascadedMod(cipher[i],d,n);
            cout<<(int)message[i]<<"<<"<<cipher[i]<<endl;

        }
        message[i] = '\0';
        return message;

    }

    RSA(long p, long q, long e){
        this->p = p;
        this->q = q;
        this->e = e;

        n = p * q;
        phi = (p-1) * (q-1);


    }

};

int main(){

    RSA test(53,59,3);

    char plaintext[] = "Hello";

    int* cipher = test.encrypt(plaintext);

    test.findPrivateKey();

    cout<<test.decrypt(cipher)<<endl;


}