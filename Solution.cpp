#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

struct Item {
    int i, v, w;
    Item(int i, int v, int w) {this->i = i; this->v = v;this->w = w;}
};

ostream& operator<<(ostream& stream, const Item& items) 
{ stream << items.i << " , " << items.v << " , " << items.w; return stream; }
 
int max(int a, int b) { return (a > b)? a : b; }


int main() {
    //string l;
    int i = 0, c{}, no{}, x, y, z, line;
    std::vector<Item>items;
    //std::cout<<"give the name of the file :";
    //std::cin >> l;

    std::ifstream myfile("arxeio.txt");//(l)
    if (myfile.is_open())
    {
        while (myfile >> line)
        {
            if (i == 0) {
                no = line; 
                if (no==0)
                {
                    break;
                } 
                items.reserve(no);/*cout << no <<endl;*/
            }
            else if (i == (no * 3) + 1) { c = line;/*cout << c <<endl;*/ }
            else {
                if (i % 3 == 1) { x = line; }
                else if (i % 3 == 2) { y = line;/*A[b][0]=line;cout<<A[b][0]<<" , ";*/ }
                else { z = line; items.emplace_back(x, y, z); }
                //vec.push_back(MyStruct(4, 1.2, "test"));
            }
            i++;
        }
        for (int i = 0; i < items.size(); i++) { cout << items[i].i << " - " << items[i].v << " - " << items[i].w << endl; }
        
        //knapsack
        std::vector< std::vector<Item>>kp;
       //int K[no + 1][c + 1];
        for (int i = 0; i < no; i++) {

            for (int w = 0; w <= c; w++)
            {
                if (i == 0 || w == 0)
                    kp[i][w].w = 0;
                else if (items[i - 1].w <= w)
                    kp[i][w].w = max(items[i - 1].v + kp[i - 1][w].w - items[i - 1].w, kp[i - 1][w].w);
                else
                    kp[i][w].w = kp[i - 1][w].w;
            }
        }

        cout << kp[no][c].v;

            myfile.close();
        
    }
    else cout << "Unable to open file";

    items.clear();
    return 0;
}
