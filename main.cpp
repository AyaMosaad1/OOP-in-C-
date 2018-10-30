#include <iostream>
#include<math.h>
using namespace std;

class dynmarr
{
private:
        float*p;
        int s;
public :
   /*dynamic array's constructior*/
dynmarr(){s=0; p = NULL ;}

void set_s(int i){ s = i; p = new float[s];}

int get_s(){return s;}

void set_arr (dynmarr a)
    {
        float e;
        for(int i = 0 ; i < s ; i++){
        cin >> e;
        a.set_elem(i,e);
        }
    }
void printarr (dynmarr a){
     p = a.get_p();
    for(int i = 0 ; i < s ; i++){cout<<p[i]<<endl;}
    }
    float* get_p(){ return &p[0]; }

float get_elem(int i)
{
    return p[i];
}
void set_elem (int i , float e){ p[i] = e ;}
void add (){ float sum ;
    for(int i =0 ; i < s ; i++){
    sum =sum+p[i];}
     cout<<sum<<endl;}

void find_ele (int ind){ cout<< p[ind]<<endl;}

void find_indx( float elex ){
    char n=0;
    for (int i=0 ; i < s ; i++)
    {
    if (p[i]==elex){cout<<"the element" <<" "<< elex <<" in :" << i <<endl;}
    else { n ++;}
    }
if (n==4){cout<<"NOT in this array"<<endl;}
}
/*find index of element and return it and if didn't  find the element , it is return -1*/
int find_ind_re ( float elex_re ){
    int n=0;
    for (int i=0 ; i < s ; i++)
    {
    if (p[i] == elex_re){return i;}
    else { n ++;}
    }
    if (n==4){return -1;}
}

/*remove one element and shifting array*/
void remove_ele (float useless_ele){
     int ind ;
     ind = find_ind_re (useless_ele);
     if (ind != (-1)){
     for(int j = (ind+1) ; j < s ;j++)
     {
         p [j-1] = p[j];
     }
      s=s-1;
        }
}

/*add new size with new element in the end of array*/
void newsize (int new_size )
 {
float*t=NULL;

if (new_size!=0)
{
   new_size= new_size+s;
    t = new float [new_size];

    for(int i = 0; i < s ;i++)
{
    t[i] = p[i];
}
 for(int i = s ; i < new_size ; i++){

    cin>>t[i];
}

  s = new_size;
  delete []p;
  p = t;
 }
}

/*add new element in the end of array*/
void append (float nwele) {
    float*t=NULL;
    t = new float [s+1];
    for(int i = 0 ; i < s ;i++)
{
    t[i] = p[i];
}
    s = s+1;
    delete []p;
    p = t;
    p[s-1]=nwele;
}
/*add new element in anyplce in array*/
void insert_ele (float ele , int place )
   {
       append(ele);
       for(int i=0 ; i < (s-1-place) ; i++)
       {
          p[s-i-1]=p[s-i-2];
       }
       p[place]=ele;
   }
 };

int main()
{
dynmarr a ;
a.set_s(4);
a.set_arr(a);
a.printarr(a);
/*CHOOSE ANY FUNCTION TO DO*/
/*a.add();

a.find_ele(2);

a.find_indx(5);

a.remove_ele(2);

cout<<"please enter your new element"<<endl;
a.newsize(2);

a.insert_ele(333,2);
*/

return 0;
}
