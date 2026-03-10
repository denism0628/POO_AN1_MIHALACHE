#include "Canvas.h"
#include <iostream>
#include<cmath>

Canvas::Canvas(int width,int height){
    this->width=width;
    this->height=height;

    m=new char *[height];
    for(int i=0;i<height;i++)
       m[i]=new char [width];
    
    Clear();
}

Canvas::~Canvas(){
    for(int i=0;i<height;i++)
       delete[] m[i];
    
    delete[] m;
}

void Canvas::Print(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++)
            std::cout<<m[i][j]<<" ";
    std::cout<<'\n';
    }
}

void Canvas::Clear(){
    for(int i=0;i<height;i++)
       for(int j=0;j<width;j++)
           m[i][j]=' ';
}

void Canvas::SetPoint(int x,int y,char ch){
    if(x>=0 && x<=width && y>=0 && y<=height)
       m[x][y]=ch; 
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx=std::abs(x2-x1);
    int sx=x1 < x2 ? 1 : -1;
    int dy=-std::abs(y2-y1);
    int sy=y1 < y2 ? 1 : -1;
    int err=dx+dy, e2; 

    while (true) {
        SetPoint(x1,y1,ch);
        if(x1==x2 && y1==y2) break;
        e2=2*err;
        if(e2 >= dy) { err += dy; x1 += sx; } 
        if(e2 <= dx) { err += dx; y1 += sy; } 
    }
}

void Canvas::DrawRect(int left,int top,int right,int bottom,char ch){
    DrawLine(left,top,right,top,ch);
    DrawLine(left,bottom,right,bottom,ch);
    DrawLine(left,top,left,bottom,ch);
    DrawLine(right,top,right,bottom,ch);
}

void Canvas::FillRect(int left,int top,int right,int bottom,char ch){
    for(int y=top;y<=bottom;y++)
       for(int x=left;x<=right;x++)
            SetPoint(x,y,ch);
}

void Canvas::DrawCircle(int x,int y,int ray,char ch){
    int xc=0;
    int yc=ray;
    int d=3-2*ray;
    while(yc>=xc){
        SetPoint(x + xc, y + yc, ch);
        SetPoint(x - xc, y + yc, ch);
        SetPoint(x + xc, y - yc, ch);
        SetPoint(x - xc, y - yc, ch);
        SetPoint(x + yc, y + xc, ch);
        SetPoint(x - yc, y + xc, ch);
        SetPoint(x + yc, y - xc, ch);
        SetPoint(x - yc, y - xc, ch);

        xc++;
        if(d>0){
            yc--;
            d=d+4*(xc-yc)+10;
        }
        else
            d=d+4*xc+6;
    }
}

void Canvas::FillCircle(int x,int y,int ray,char ch){
    for(int i=y-ray;i<=y+ray;i++)
      for(int j=x-ray;j<=x+ray;j++)
          if((j-x)*(j-x)+(i-y)*(i-y)<=ray*ray)
             SetPoint(j,i,ch);
}

