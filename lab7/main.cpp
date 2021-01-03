#include <iostream>
#include <math.h>
#include <string.h>
class shape{
protected:
    int dim1;
    int dim2;
    // new branch
public:
    shape(){dim1=dim2=0;}
    shape(int x);
    shape(int x,int y);
    virtual float getAera()=0;
    
};
shape::shape(int x){
    dim1=x;
    dim2=x;
}
shape::shape(int x,int y){
    dim1=x;
    dim2=y;
}
class circle:public shape{
protected:
    int aera;
public:
    circle(){}
    float getAera(){
        aera = (3.14*dim1*dim2);
        return aera;
    };
    circle(int x);
};
circle::circle(int x):shape(x){}
class rectangle:public shape{
protected:
    int aera;
public:
    
    rectangle(){}
    float getAera(){
        aera = (1.0*dim1*dim2);
        return aera;
    };
    rectangle(int x,int y);
    int getX(){
        return dim1;
    }
};
rectangle::rectangle(int x,int y):shape(x,y){}

class triangle:public shape{
protected:
    int aera;
public:
    
    triangle(){}
    float getAera(){
        aera = 0.5*dim1*dim2;
        return aera;
    };
    triangle(int x,int y);
};
triangle::triangle(int x,int y):shape(x,y){}


class square:public rectangle{
protected:
    int aera;
public:
    
    square(){}
    square(int x);
    square(int x,int y);
};
square::square(int x,int y):rectangle(x,y){}
square::square(int x):rectangle(x,x){}



class geoshape{
    shape** ptr;
    int size ;
public:
    geoshape(shape *p1[],int Size){
        ptr = p1;
        size=Size;
        
    }
    float totalAera (){
        float sum = 0.0;
        for (int i=0;i<size;i++){
            sum += ptr[i]->getAera();
        }
        return sum;
    }
    
};




int main(int argc, const char * argv[]) {
    circle c(7);
    rectangle r(20,5);
    triangle t(20,10);
    square s(6);
    rectangle r1(10,6);
    square s2(9);
    
    shape *array[6];
    
    array[0]=&c;
    array[1]=&r;
    array[2]=&t;
    array[3]=&s;
    array[4]=&r1;
    array[5]=&s2;
    
    geoshape total(array,6);
    
    std::cout<<"total area = "<<total.totalAera()<<std::endl;
    return 0;
}
