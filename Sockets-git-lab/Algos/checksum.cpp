#include<iostream>
using namespace std;



int nibbleCount(int checksum){
    int len = 0;
    while(checksum){
        len++;
        checksum/=16;
    }

    return len;
}

int delimGen(int nibbles){
    int delim = 0;
    for(int i = 0; i < nibbles; i++){
        delim *= 16;
        delim += 0xF;
    }
    return delim;
}

int placeValue(int nibbles){
    if(nibbles <= 0)
        return 1;
    return 16 * placeValue(nibbles - 1);
}

int generateCheckSum(int header, int nibbles){
    int sum = 0;
    int checksumSize = placeValue(nibbles);
    int delim = delimGen(nibbles);

    while(header){ 

        printf("%x\n",header);
        sum += header % checksumSize;
        header /= checksumSize;
    }
        
    printf("%x\n",delim);
    printf("%x\n",sum);
    printf("%x\n", sum >> (nibbles * 4));

    
    while(sum >> (nibbles * 4)){
        sum = (sum & delim) + (sum>>checksumSize);

        //printf("%x\n",sum);
    }
    
    sum = ~sum;

    return sum;
}

int addChecksumToHeader(int header, int checksum){
    return (checksum * nibbleCount(header) * 16) + header;
}



bool validateCheckSum(int header, int checksum){

    int val = generateCheckSum(header, nibbleCount(checksum));
    
    if(~(~val + checksum) == 0)
        return true;
    else
        return false;
    
}

int main(){

    int header1 = 0x1AB8378;
    int header2 = 0x1AB8378;

    int checksum = generateCheckSum(header1, 4);
    int result = addChecksumToHeader(header1,checksum);
    int sample = addChecksumToHeader(header2,checksum);

    printf("Computed checksum at sender %x\n",result);
    printf("Computed checksum at sender %x\n",sample);



    if(validateCheckSum(header2,checksum))
        cout<<"No error"<<endl;
    else
        cout<<"Found error"<<endl;

    

}