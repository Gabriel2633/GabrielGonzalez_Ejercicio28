#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


void pinocho(int Nx, int Nt, double Dx, double Dt, double kappa, double sph, double rho,string filename);    

int main()
{
pinocho(101, 3000, 0.03, 0.9, 210.0, 900.0, 2700.0, "pinocho.dat");   
    return 0;
}

void pinocho(int Nx, int Nt, double Dx, double Dt, double kappa, double sph, double rho,string filename)    
{
    ofstream outfile;
    outfile.open(filename);
    double T[Nx][2];
    double TPL[Nx][31];
    
    for(int i=1;i<(Nx-1);i++)
    {
        T[i][0]=100.0;
    }
    T[0][0]=0.0;
    T[0][1]=0.0;
    T[Nx-1][0]=0.0;
    T[Nx-1][1]=0.0;
    
    double cons= kappa/(sph*rho)*Dt/(Dx*Dx);
    
    int m = 1;
    
    for(int t=1;t<(Nx-1);t++)
    {
        for(int ix=1;ix<(Nx-1);ix++)
    {
        T[ix][1]=T[ix][0]+cons*(T[ix+1][0]+T[ix-1][0]-2.0*T[ix][0]);
        
    }
        if(t%300 == 0 || t==1)
        {
            for(int ix=1;ix<Nx-1;ix++)
            {
                if(ix%2==0)
                {
                    TPL[ix][m]=T[ix][1];
                }
            }
            m=m+1;
        }
        
        for(int ix=1;ix<(Nx-1);ix++)
        {
        T[ix][0]=T[ix][1];
        }
    }
    
    for(int i=0;i<Nx;i++)
  {

      outfile << T[0][i] << endl;

  }
    outfile.close();
}












