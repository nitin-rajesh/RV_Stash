#include<iostream>
#include<vector>
using namespace std;

class Hamming{

public:

    static vector<int> generateHamming(vector<int> ipArray){
        
        vector<int> hamming;
        vector<int> indices;

        //init hamming vector
        int i = 1;
        for(vector<int>::iterator p = ipArray.begin(); 
            p != ipArray.end(); i++){
            if(isPowerOf2(i)){
                hamming.push_back(-1);
                indices.push_back(i);
            }
            else{
                hamming.push_back(*p++);
            }
        }

        //add hamming bits
        for(vector<int>::iterator p = indices.begin(); p != indices.end(); p++){
            int sum = 0;
            for(int j = *p; j <= hamming.size(); j += (*p) * 2){
                //cout<<j<<'\t';
                for(int i = 0; i < *p; i++){
                    if(!isPowerOf2(j + i))
                        sum += hamming[j + i - 1];
                }
            }

            sum %= 2;
            //cout<<sum<<endl;
            hamming[*p - 1] = sum;
        } 

        return hamming;
    }

    static vector<int> removeHammingBits(vector<int> hamming){
        vector<int> array;
        for(int i = 1; i <= hamming.size(); i++){
            if(!isPowerOf2(i)){
                cout<<hamming[i - 1]<<'\t';
                array.push_back(hamming[i - 1]);
            }
        }
        cout<<endl;
        return array;
    }

    static vector<int> getHammingBits(vector<int> hamming){
        int i = 0, index;
        vector<int> array;

        while((index = twoPower(i)) < hamming.size()){
            array.push_back(hamming[index - 1]);
            cout<<hamming[index - 1]<<'.';
            i++;
        }

        cout<<endl;

        return array;
    }

    static int verifyHamming(vector<int> hamming){
        int i = 0;

        vector<int> hammingBits = getHammingBits(hamming);

        vector<int> indices;

        vector<int> temp = generateHamming(removeHammingBits(hamming));

        vector<int> calciBits = getHammingBits(temp);

        for(int i = 0; i < calciBits.size(); i++){
            cout<<calciBits[i];
        }

        cout<<endl;

        for(int i = 0; i < calciBits.size(); i++){
            calciBits[i] = !calciBits[i] && hammingBits[i];
            cout<<calciBits[i];

        }

        cout<<endl;

        return binaryToDecimal(calciBits);
        
    }

    static int binaryToDecimal(vector<int> array){

        int val = 0;

        for(int i = 0; i < array.size(); i++){
            val += array[i]*twoPower(i);
        }

        //cout<<val<<endl;

        return val;

    }

    static bool isPowerOf2(int val){
        while(val % 2 == 0){
            val /= 2;
        }
        if(val == 1)
            return true;

        return false;
    }

    static int twoPower(int x){
        if(x < 0)
            return 0;
        if( x == 0)
            return 1;
        return twoPower(x-1) + twoPower(x-1);
    }
};


int main(int argc, const char *argv[]){
    Hamming test;
    int a[] =  {0,1,1,0,1,1,1,0};
    vector<int> sample(a,a + sizeof(a)/sizeof(a[0]));
    vector<int> hamming = Hamming::generateHamming(sample);
    for(int i = 0; i < hamming.size(); i++){
        cout<<hamming[i]<<'\t';
    }

    cout<<endl;

    int b[] = {1,1,0,0,1,1,0,1,1,1,1,0};

    vector<int> testCode(b,b + sizeof(b)/sizeof(b[0]));

    int index = Hamming::verifyHamming(testCode);

    if(index == 0)
        cout<<"No error"<<endl;
    else
        cout<<"Error at "<<index<<endl;

}

