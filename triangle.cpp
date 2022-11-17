/*
判断一个点是否在一个三角形内
*/
#include "triangle.h"
#include <iostream>

using namespace std;

Triangle::Triangle() {
   pNode* tri_a = new pNode{0.0,0.0};
   pNode* tri_b = new pNode{0.0,0.0};
   pNode* tri_c = new pNode{0.0,0.0};
   
   cout << "Triangle constructor" << endl;
}

Triangle::~Triangle(){
   delete tri_a;
   delete tri_b;
   delete tri_c;
   cout << "~ Triangle destructor" << endl;
}


bool Triangle::InitTriangle(pNode* triA, pNode* triB, pNode* triC) {
   if(triA == nullptr || triB == nullptr || triC == nullptr){
      cout << "please check triangle is init!!" << endl;
      return false;
   }
   
   cout << "Inittriangle" <<endl;
   tri_a = triA;
   tri_a = triA;
   tri_b = triB;
   tri_b = triB;
   tri_c = triC;
   tri_c = triC;
   cout << tri_c->x << tri_c->y << endl;
   return true;
}

void Triangle::ReversePot(){
    cout << "ReversePot" << endl;
    if(tri_a == nullptr || tri_b == nullptr || tri_c == nullptr){
       cout << "please check triangle is init!!" << endl;
       return ;
    }
    double tmpRes = (tri_c->x-tri_a->x)*(tri_b->y-tri_a->y) - (tri_c->y-tri_a->y)*(tri_b->x-tri_a->x);
    cout << "tmpres" << tmpRes << endl;
    if (tmpRes >= 0){
       double tmpx = tri_b->x;
       double tmpy = tri_b->y;
       tri_b->x = tri_c->x;
       tri_b->y = tri_c->y;
       tri_c->x = tmpx;
       tri_c->y = tmpy;
    }
}

double Triangle::CalcCrossPdt(pNode* potA, pNode* potB, pNode* potX){
    cout << "calccrosspdt" << endl;
    double tmp = (potB->x - potA->x)*(potX->y - potA->y) - (potB->y - potA->y)*(potX->x - potA->x);
    cout << "tmp:" << tmp << endl;
    return (potB->x - potA->x)*(potX->y - potA->y) - (potB->y - potA->y)*(potX->x - potA->x) ;
}

bool Triangle::IsInSide(pNode* dst){
   cout << "isinside" << endl;
   ReversePot();
   if(CalcCrossPdt(tri_a, tri_b, dst) < 0)
	  return false; 
   if(CalcCrossPdt(tri_b, tri_c, dst) < 0)
	  return false; 
   if(CalcCrossPdt(tri_c, tri_a, dst) < 0)
	  return false; 
   return true;
}

