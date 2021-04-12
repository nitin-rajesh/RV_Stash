package com.company;

public class Combinations {
    int numberOfCombinations;
    public int bruteForceSumCombi(int n){
        int sum = 0;
        for(int i = 0; i <= 9; i++){
            for(int j = 0; j <= i; j++){
                for(int k = 0; k <= j; k++){
                    for(int l = 0; l <= k; l++){
                        if(i + j + k + l == n){
                            System.out.println(i + " " + j + " " + k + " " + l);
                            sum++;
                        }
                    }
                }
            }
        }
        numberOfCombinations = sum;
        return sum;
    }

    Combinations(int n){
        if(n >= 36){
            System.out.println("Out of bounds");
        }
        else
            numberOfCombinations = bruteForceSumCombi(n);
    }
    int getNumberOfCombinations(){
        return numberOfCombinations;
    }

}
