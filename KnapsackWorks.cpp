#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

 
int max(int a, int b) { return (a > b)? a : b; }
//From two integers returns the greater


int main() {
    string l;
    int i = 0, c, no, line;
    //declaration of variables
    
    std::vector<int>value;
    std::vector<int>weight;
    //declaration of two arrays : about the value and weight of the item
    
    std::cout<<"give the name of the file :";
    std::cin >> l; 
    //input of the name of the file
    
    std::ifstream myfile(l);
    //there is a search about the file with the name of the input : exp(l="problem_10_50_1_2_5.in")
    
    if (myfile.is_open())
    {
        while (myfile >> line)
        {
            if (i == 0) {
                
                //the variable no is the number of items 
                no = line; 
                
                //if the first number is 0 this means the number of items equals 0
                if (no==0)
                {
                    myfile.close();break; 
                    //we close the file and we (break) the loop  
                } 
            }
            
            else if (i == (no * 3) + 1) {c = line;}
            //the last number of the text is the weight of the sack
            //explanation:if the items are no=10 (10) * 3(number,value,weight)=30
            
            else {
                  //if (i % 3 == 1) { number of current item=line;}
                  if (i % 3 == 2) {value.push_back(line);}
                  //to find the value we search for the second number
                  else if(i%3!=1){weight.push_back(line);} 
                  //and for the weights the third 
            }
            i++;
        }
        myfile.close();
        //we are closing the current file
         
         for (int i = 0; i < value.size(); i++) { cout << i+1 << " - " << value[i] << " - " << weight[i] << endl; }
         //we transfered the numbers into two vectors 
         //example: 1 42 32
         //         2 42 42
         //         3 18 6 
        
         int kp[no + 1][c + 1];
         //declaring the 2d array for the knapsack solution
         
         for (int i = 0; i <= no; i++) {
            for (int w = 0; w <= c; w++){
                if (i == 0 || w == 0){ kp[i][w]=0;}
              //for 0 items or 0 weight we cant have something better than 0
                else if (weight[i - 1] <= w){kp[i][w]=max(value[i - 1] + kp[i - 1][w - weight[i - 1]], kp[i - 1][w]);}
              //if the condition is meet,  
              //if the previous max < value 
              //max <-- value
                else{kp[i][w]=kp[i - 1][w];}
              //or else the previous max => max
            }  
        }
        cout << kp[no][c]<<endl; 
        //the best solution to our problem is this
        
    }
    else cout << "Unable to open file"; 
   //if the file does not exist
    
    return 0;
}
