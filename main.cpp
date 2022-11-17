#include "triangle.h"
#include "departArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
  if (argc != 2) {
     cout << "Use: ./Demo 1  "<< "=> test tri "
	  << "./Demo 2 "<< "=> test Array" 
	  << "please check your input parameters!" << endl;
     return -1;
   }
     
  if (1 == atoi(argv[1])) {
     cout << "Is a point in a triangle" << endl;
     pNode* triA = new pNode{1.0,0.0};
     pNode* triB = new pNode{3.0,0.0};
     pNode* triC = new pNode{0.0,3.0};
     pNode* triX = new pNode{2.0,1.0};

     cout << "please input your 1th point of triangle" << endl;
     cin >> triA->x >> triA->y;
     cout << "please input your 2th point of triangle" << endl;
     cin >> triB->x >> triB->y;
     cout << "please input your 3th point of triangle" << endl;
     cin >> triC->x >> triC->y;
     cout << "please input your check point" << endl;
     cin >> triX->x >> triX->y;


     Triangle* pTri = new Triangle();
     pTri->InitTriangle(triA, triB, triC);
     bool flag = pTri->IsInSide(triX);
     if (flag)
        cout << "yes, this point is inside the triangle!" << endl;
     else 
        cout << "No, this point is not inside the triangle!" << endl;


     
     delete triA;
     delete triB;
     delete triC;
     delete triX;
  }

  if (2 == atoi(argv[1])) {
      DepartArray* dpAry = new DepartArray();
      vector<int> num_vec = {1,5,11,5};
      int num_in;
      char ch_in;
      cout << "please input numbers, end by any letter:";
      num_vec.clear();
      while (cin >> num_in) {
	  cout << "num_in:" << num_in << endl;
          num_vec.push_back(num_in);
      }
      for(auto& i:num_vec)
	 cout << i << endl;
      
      bool flag = dpAry->IsDepartToArray(num_vec);      
      if (flag) 
	 cout << "yes, depart array successful!" << endl;
      else
	 cout << "no, depart array failed!" << endl;

      delete dpAry;
  }

}
