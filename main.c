#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <float.h>

const int SQEQ_INF = -1;

#define M 3

int SqEquationTest (double* a, double* b, double* c, int s){

  if (s==0) {*a=1; *b=1; *c=1;}
  else {
      if (s==1) {
          *a=2; *b=2; *c=0;
      }
      if (s==2) {
          *a=0; *b=0; *c=0;
      };
      if (s==3){
          *a=1; *b=4; *c=4;
      };
      if (s==4){};
}

return 0;
};


int iszero(double q){
  if (fabs(q) < DBL_EPSILON) return 1;
          else return 0;
};


int SqEquation(double* x1, double* x2, int i) {
 double a=0, b=0, c=0;

 assert(x1 != x2);
 assert(x1);
 assert(x2);

 printf("Program is made to solve square equation a*x*x + b*x + c =0.  \n");

 SqEquationTest(&a, &b, &c, i);
 printf("Got in: (%lg*x*x)+(%lg*x)+%lg=0 \n", a, b, c);

 if (iszero(a)) {
     if (iszero(b))
        if (iszero(c)) return SQEQ_INF;
        else return 0;
     else
         if (iszero(c)) {
             *x1= 0;
             return 1;
         }
         else {
             *x1= -c/b;
             return 1;
         }
 };

 double d=b*b-4*a*c;
 if (d>0) {
     *x1= (-b + sqrt(d)) / (2*a);
     *x2= (-b - sqrt(d)) / (2*a);
     return 2;
 }
 else{
    if (iszero(d)) {
         *x1= -b/ (2*a);
         return 1;
    }
    else {
        return 0;
    }
 }
};


int output(int NRoots, double x1, double x2){
  if (NRoots==0) printf("no roots. \n\n");
  else
      if (NRoots==1) printf("one root, x= %lg. \n\n", x1);
      else
          if (NRoots==2) printf("two roots, x1= %lg, x2= %lg. \n\n", x1, x2);
          else printf("endless number of roots. \n\n");
  return 0;

};


int main(void)
{
    double x1=0, x2=0;
    int i=0;

    for(i=0; i<=M; i++){
      int NRoots=SqEquation(&x1, &x2, i);
      output(NRoots, x1, x2);
    }
    return 0;
}
