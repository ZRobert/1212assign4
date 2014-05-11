/*************************************************
Program: calculatingPi.cpp
Author: Robert Payne
Lab section: L15
Date: 3-30-2012
Purpose:  This program uses the Monte Carlo Method
          to calculate Pi. For visualization
          purposes, the domain and range of the
          area of the square that the circle is
          inscribed is domain: [0,2] and range:
          [0,2]. The circle is a unit cirle with
          with the center at (1,1), meaning it
          would intersect the square at (0,1),
          (1,0), (1,2), and (2,1). The program
          runs a loop generating random points
          and checks them to see if they fall
          within the circle using this inequality:

            1 > (1-x)^2 + (1-y)^2

          If the random point is within the circle,
          it is counted and stored as m; and n
          represents the number of random points
          generated and tested. Pi is then
          calculated using this formula:

            pi = (4*m)/n
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    //variables
    float calculatedPi;  //stores the calculated pi
    float randomX;      //placeholder for x coordinate
    float randomY;      //placeholder for y coordinate
    int i;              //for loop counter
    int m = 0;          //count for points inside the circle
    float n;            //total number of points generated


    srand(time(0));     //seeds the random generator
    cout<< "Press enter to calculate pi!";  //prompts user to press enter
    cin.get();  //waits for user to press enter
    cout<< "Please wait...\n";
    //for loop that generates the data needed to do the calculations for pi
    for(i = 0; i < 50000000; i++)
    {

        randomX = ((float)rand()/(float)RAND_MAX)*2; //value between 0 and 2
        randomY = ((float)rand()/(float)RAND_MAX)*2; //value between 0 and 2

        if(((pow((1.0-randomX),2))+pow((1.0-randomY),2))< 1.0)
            m++; //counter for points that fall inside the circle
    }

    //calculation for pi
    n = i;
    calculatedPi = (4.0*m)/n;

    //outputs the approximation for pi
    cout<<"Pi is approximately: " <<calculatedPi <<endl;

    return 0;
}
