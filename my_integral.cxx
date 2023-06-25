#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>

int count;
float total, inBox;

float integral (float (*f)(float), float xmin, float xmax, float ymin, float ymax);
float f (float x);

int main(int argc, char *argv[]){
  if(argc == 1){
    float i = integral(f, -2, 2, 0, 4);
  
    std::cout<< "RESULT: " <<std::endl;
    std::cout<< i << std::endl;
    exit(0);
  }
  
  float xmin = std::stof(argv[1]);
  float xmax = std::stof(argv[2]);
  float ymin = std::stof(argv[3]);
  float ymax = std::stof(argv[4]);

  float res = integral(f, xmin, xmax, ymin, ymax);
  
  std::cout<< "RESULT: " <<std::endl;
  std::cout<< res << std::endl;
}

float f (float x){
  return exp(cos(x));
}

float integral (float (*f)(float), float xmin, float xmax, float ymin, float ymax){
  for (count=0; count < 1000000; count++){
    float u1 = (float)rand()/(float)RAND_MAX;
    float u2 = (float)rand()/(float)RAND_MAX;

    float xcoord = ((xmax - xmin)*u1) + xmin;
    float ycoord = ((ymax - ymin)*u2) + ymin;
    float val = f(xcoord);

    total++;

    if (val > ycoord){
      inBox++;
    }
  }

  float density = inBox/total;

  return (xmax - xmin)*(ymax - ymin)*density;
}