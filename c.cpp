#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


void pinocho(int Nx, int Nt, double Dx, double Dt, double kappa, double sph, double rho,string filename);    

int main()
{
pinocho(201, 200, 0.01, 0.5, 200.0, 900.0, 2700.0, "pinocho.dat");   
    return 0;
}

void pinocho(int Nx, int Nt, double Dx, double Dt, double kappa, double sph, double rho,string filename)    
{
    ofstream outfile;
    outfile.open(filename);
    double T[2][Nx];
    
    for(int i=0;i<(Nx);i++)
    {
        T[0][i]=300.0;
        T[1][i]=300.0;
    }
    for(int i=80;i<120;i++)
    {
        T[0][i]=500.0;
        T[1][i]=500.0;
    }
    
    
    double cons= kappa/(sph*rho)*Dt/(Dx*Dx);
    
    
    for(int t=1;t<(Nt-1);t++)
    {
        for(int ix=1;ix<(Nx-1);ix++)
    {
        T[1][ix]=T[0][ix]+cons*(T[0][ix+1]+T[0][ix-1]-2.0*T[0][ix]);
        
    }
        
        for(int ix=1;ix<(Nx-1);ix++)
        {
        T[0][ix]=T[1][ix];
        }
        
        for(int i=0;i<Nx;i++)
  {
       outfile << T[0][i] << " ";
       
  }
        outfile << "\n";
    }
    
   
    outfile.close();
}












