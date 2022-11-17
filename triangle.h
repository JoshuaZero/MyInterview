/*
判断一个点是否在一个三角形内
*/

#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

class pNode{
public:
  double x;
  double y;
};

class Triangle {
public:
   Triangle();
   ~Triangle();
   bool InitTriangle(pNode* triA, pNode* triB, pNode* triC);
   bool IsInSide(pNode* dst);

private:
   double  CalcCrossPdt(pNode* potA, pNode* potB, pNode* potX); 
   void ReversePot();

private:
   pNode* tri_a;
   pNode* tri_b;
   pNode* tri_c;
};


#endif //_TRIANGLE_H_
