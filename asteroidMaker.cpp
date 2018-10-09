/*
PURPOSE: The purpose of this code was to create 10 small.in files to be ran on the Mercury6 N-Body Simulator.

*/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
//send cycles, name, a, e, I, g, n, M
void Finisher(ofstream&,int&, int, double, double, double, double, double, double, int);
int main()
{
/*
  Asteroidal = Keplerian orbital elements, in an `asteroidal' format.
               i.e.  a e I g n M, where
                a = semi-major axis (in AU)
                ^ Range from 70 to 200
                e = eccentricity
                ^ Range from 0 to .1
                I = inclination (degrees)
                ^ Range from 0 to 10 degrees
                g = argument of pericentre (degrees) 0 to 360
                n = longitude of the ascending node (degrees) 0 ti 360
                M = mean anomaly (degrees) 0 to 360
*/
  int name = 1;
  double a, e, I, g, n, M;
  int z; //, z2, z3;
  int cycles = 1000;
  ofstream outfile;
  srand(unsigned(time(NULL)));

//a=(double)rand()/(RAND_MAX)+0+(rand()%4);
  z = 0;//z2 = z3 = 0;
  outfile.open("small1.in");
  Finisher(outfile,name, cycles, a, e, I, g, n, M, z);
  outfile.close();
  outfile.open("small2.in");
  Finisher(outfile,name, cycles, a, e, I, g, n, M, z);
  outfile.close();
  outfile.open("small3.in");
  Finisher(outfile,name, cycles, a, e, I, g, n, M, z);
  outfile.close();
  outfile.open("small4.in");
  Finisher(outfile,name, cycles, a, e, I, g, n, M, z);
  outfile.close();
  outfile.open("small5.in");
  Finisher(outfile,name, cycles, a, e, I, g, n, M, z);
  outfile.close();
  outfile.open("small6.in");
  Finisher(outfile,name, cycles, a, e, I, g, n, M, z);
  outfile.close();
  outfile.open("small7.in");
  Finisher(outfile,name, cycles, a, e, I, g, n, M, z);
  outfile.close();
  outfile.open("small8.in");
  Finisher(outfile,name, cycles, a, e, I, g, n, M, z);
  outfile.close();
  outfile.open("small9.in");
  Finisher(outfile,name, cycles, a, e, I, g, n, M, z);
  outfile.close();
  outfile.open("small10.in");
  Finisher(outfile,name, cycles, a, e, I, g, n, M, z);
  outfile.close();




  //Make 1000 asteroids with the following format:
  //make a plot of a and e and a and I
/*
Cartesian = for xyz coordinates and velocities. Distances should be
            in AU and velocities in AU per day (1 day = 86400 seconds).

and an example of these are as follows:

APOLLO   ep=2450400.5
1.4710345 .5600245  6.35621 285.63908  35.92313  15.77656 0 0 0
JASON    Ep=2450400.5
2.2157309 .7644575  4.84834 336.49610 169.94137 293.37226 0 0 0
KHUFU    ep=2450600.5
0.9894948 .4685310  9.91298  54.85927 152.64772  66.69818 0 0 0
MINOS    ep=2450400.5
1.1513383 .4127106  3.93863 239.50170 344.85893   8.93445 0 0 0
ORPHEUS  ep=2450400.5
1.2091305 .3226805  2.68180 301.55128 189.79654  28.31467 0 0 0
TOUTATIS EP=2450600.5
2.5119660 .6335854  0.46976 274.82273 128.20968  50.00728 0 0 0

*/



  return 0;
}

void Finisher(ofstream& outfile, int& num, int cycles, double a, double e, double I, double g, double n, double M, int z )
{
  outfile << ")O+_06 Small-body initial data  (WARNING: Do not delete this line!!)" << endl;
  outfile <<") Lines beginning with `)' are ignored." << endl;
  outfile <<")----------------------------------------------------------------------" << endl;
  outfile << " style (Cartesian, Asteroidal, Cometary) = Ast" << endl;
  outfile << ")---------------------------------------------------------------------"  << endl;
  while(cycles != 0)
{
  a=(double)rand()/(RAND_MAX)+70+(rand()%120);
//cout << "a "<< a << endl;
//if(e > 0.1)
  e = ((double)rand())/(RAND_MAX)/10;
//cout << "e " << e << endl;
  I=(double)rand()/(RAND_MAX)+0+(rand()%10);
//cout << "I " << I << endl;
  g=(double)rand()/(RAND_MAX)+0+(rand()%360);
//cout << "g " << g << endl;
  n=(double)rand()/(RAND_MAX)+0+(rand()%360);
//cout << "n " << n << endl;
  M=(double)rand()/(RAND_MAX)+0+(rand()%360);
//cout << "M " << M << endl;
  outfile << "A" << num << "  ep = 2450400.5"<< endl;
  num++;
  outfile << a << " " << e << " " << I << " " << g << " " << n
  << " " << M << " " << z << " " << z << " " << z<< endl;
  cycles--;
}

}
