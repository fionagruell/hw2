#include <iostream>
#include <fstream>

using namespace std;

int main(void){
	double x0 = 0.5;
	double x;
	ofstream out ("output.dat");//creates file to store data in 
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	double v[Nend - Nskip]; // Array to store the data in 
	cout << "Berechnung der Daten" << endl;

	for(double r=0; r <= 4; r += 0.001){
	   x=x0;
	   for(int i=1; i <= Nskip; i++)
		   x = r*x*(1-x);
	   for(int i=Nskip+1; i <= Nend; i++){
	   		   x = r*x*(1-x);
	   		   v[i-(Nskip+1)]=x; // Vektor bei festem r von Step 100 bis 200
   	   }
	
   	   cout << "Schreiben der Daten in Datei bei r="<<r << endl;
	for(int i=Nskip+1; i<=Nend ; i++)   {
   	   out << r << "\t =r"<<"\t v["<< i-(Nskip)<<"]\t = \t"<< v[i-Nskip-1]<< endl; //Ausgabe in Datei bei festem r
	}
	}

out.close();
cout <<"Schreiben beendet"<< endl;
	return 0;
}
