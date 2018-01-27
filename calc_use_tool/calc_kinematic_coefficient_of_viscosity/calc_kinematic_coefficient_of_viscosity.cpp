#include <iostream>
#include <cmath>

using namespace std;

//below is my initial figure
const double d = 1.9936e-3;
const double D = 62.38e-3;
const double t = 12.81;
const double m = 0.03278e-3;
const double p = 0.9555;
const double s = 262.6e-3;
const double g = 9.794;
const double pi = 3.142;

const double ud = 0.004e-3;
const double uD = 0.06e-3;
const double us = 0.1e-3;
const double ut = 0.09;
const double up = 0.0005;
const double um = 0.0002e-3;

int main(int argc, char *argv[])
{
    double dd = -(g*D*t/18/s)*((6*m*(D+4.8*d)/(pi*d*d*(D+2.4*d)*(D+2.4*d)))-p*(2*D*d+2.4*d*d)/(D+2.4*d)*(D+2.4*d));
    double DD = (g*t*2.4*d)/(18*s*(D+2.4*d)*(D+2.4*d))*(6*m/pi/d-p*d*d);
    double ss = -(g*t*D)/(18*s*s*(D+2.4*d))*(6*m/pi/d-p*d*d);
    double tt = (g*t*D)/(18*s*(D+2.4*d))*(6*m/pi/d-p*d*d);
    double pp =  -(g*t*D*d*d)/(18*s*(D+2.4*d));
    double mm = (g*t*D)/(18*s*(D+2.4*d))*(6/pi/d);

    double un = sqrt(pow(dd*ud, 2)+pow(DD*uD, 2)+pow(ss*us, 2)+pow(tt*ut, 2)+pow(pp*up, 2)+pow(mm*um, 2));
    cout << pow(dd*ud, 2) << endl;
    cout << pow(DD*uD, 2) << endl;
    cout << pow(ss*us, 2) << endl;
    cout << pow(tt*ut, 2) << endl;
    cout << pow(pp*up, 2) << endl;
    cout << pow(mm*um, 2) << endl;
    cout << un << endl;

    return 0;
}

