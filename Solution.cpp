#include <iostream>
#include <fstream>
#include <string>
#include <forward_list>
#include <functional>
using namespace std;

struct Vertex{int i,v, w;
  Vertex(int i,int v,int w)
  :i(i),v(v),w(w){}
 } ;

ostream& operator<<(ostream& stream,const Vertex& vertices){stream<<vertices.i<<" , "<<vertices.v<<" , "<<vertices.w;return stream;}


int main(){
  //string l;
  int i=0,c,no,x,y,z,line;
  
  std::forward_list<Vertex>vertices;
  //std::cout<<"give the name of the file :";
  //std::cin >> l;

  std::ifstream myfile("Untitled-1.txt");//(l)
  if (myfile.is_open())
  {
   while (myfile >> line)
    {
        if(i==0){no=line;/*cout << no <<endl;*/}
        else if(i==(no*3)+1){c=line;/*cout << c <<endl;*/}
        else{  
              if(i%3==1){x=line;}
              else if(i%3==2){  y=line;/*A[b][0]=line;cout<<A[b][0]<<" , ";*/}
              else {z=line; vertices.emplace_front(x,y,z);  }
            }
        i++;
    }
    for(Vertex& v:vertices){cout<<v.i<<" - "<<v.v<<" - "<<v.w<<endl;}

  myfile.close(); }
  else cout << "Unable to open file";
  
  //vertices.sort();
  for(Vertex& v:vertices){cout<<v.i<<" - "<<v.v<<" - "<<v.w<<endl;}

  vertices.clear();
  return 0;
}
