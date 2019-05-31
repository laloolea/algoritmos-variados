#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

void evaluaPolinomio1();
void Sum(int n);
int RSum(int a[],int n);
void Add(int m,int n);
void Fibonacci(int n);
void Trasp(int n );
void Mult (int m,int n);
int main(){
  int as[10] ={5000,6000,7000,8000,11000,12000,15000,17000,18000,20000 };


  cout << "ALGORITMO SUMA:"<<endl<<endl;
  // Algoritmo suma 10 iteraciones
  for(int i = 0; i < 10;++i){
    Sum(as[i]);
  }
  cout <<endl<< "ALGORITMO RSUMA:"<<endl<<endl;

  //Algoritmo RSum 10 iteraciones
  for(int i = 0; i < 10;++i){
    int a [as[i]];
    for(int j = 0; j < as[i] ; ++j){
      a[j]= j ;
    }

    clock_t start, end;
  	double cpu_time_used;
    cout <<"Algoritmo RSuma con n= "<<as[i]<<" la suma es: "<<  RSum(a,as[i]);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout <<" y tarda: " << cpu_time_used<<endl;
  }

  int m=10;
  int n = 10;

  cout <<endl<< "ALGORITMO ADD:"<<endl<<endl;
  // Algoritmo Add 10 iteraciones
  for(int i = 1; i <= 10;++i){
    m=m+10*8;
    n=n+10*8;
    Add(m,n);
  }
  cout<< endl<<endl;

  cout <<endl<< "ALGORITMO FIBONACCI:"<<endl<<endl;
  int f=10;
  for(int i = 0 ; i < 10 ;++i){

    Fibonacci(f);
    f= f+3;
  }
  cout <<endl<< "ALGORITMO TRASP:"<<endl<<endl;
  // Algoritmo Add 10 iteraciones
  int k= 10;
  for(int i = 1; i <= 10;++i){

    Trasp(k);

    k=k+150;
  }
  cout<< endl<<endl;

  cout <<endl<< "ALGORITMO Mult:"<<endl<<endl;
  // Algoritmo Add 10 iteraciones
  int h=10,l=10;

  for(int i = 1; i <= 10;++i){
    h=h+10*8;
    l=l+10*8;
    Mult(h,l);
  }
  return 0;

}

void Sum(int n)
{
  int a [n];
  for(int i = 0; i < n ; ++i){
    a[i]= i;
  }
  clock_t start, end;
	double cpu_time_used;

  start = clock();
  int s=0;
  for (int i = 0; i <n ;++i){
    s= s+ a[i];

  }
  end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  cout << "Algoritmo Suma con n= "<<n<<" la suma es: "<< s <<" y tarda: " << cpu_time_used<<endl;

}
int RSum(int a[],int n)
{

  if(n<=0)return 0;
  else return RSum(a,n-1) + a[n];


}
void Add(int m,int n)
{
  int a[m][n], b[m][n], c[m][n];

  for(int i = 0 ; i < m ;++i){
    for(int j=0 ; j < n ;++j){
      a[i][j]=i;
      b[i][j]= j;
    }
  }


  clock_t start, end;
  double cpu_time_used;
  start = clock();
  for(int i = 0 ; i < m ;++i){
    for(int j=0 ; j < n ;++j){
      c[i][j]= a[i][j]+b[i][j];
    }
  }

  end = clock();
  cout <<"Algoritmo Add (suma de matrices) con m y n= "<<m;
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  cout <<" tarda: " << cpu_time_used<<endl;
}

void Fibonacci(int n)
{
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  if(n<=1) cout<< n;
  else{
    int fnm2=0, fnm1=1, fn=0;
    for(int i =2;i<=n;++i){
      fn=fnm1+fnm2;
      fnm2=fnm1;
      fnm1=fn;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<"El numero "<< n <<" de la sucesion de fibonacci es:" << fn <<" y tarda: " << cpu_time_used<<endl;;

  }
}

void Trasp(int n )
{
  int a[n][n];

//  int t [n][n];
  int t=0;
  for(int i=0;i<n;++i){
    a[i][i]=i;
  }
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  for(int i =0;i<n;++i){
    for(int j=i; j<n;++j){
      t=a[i][j];
      a[i][j]=a[j][i];
      a[j][i]=t;
    }
  }
  end = clock();
  cout <<"Algoritmo Trasp (transpuesta de matrices) con m y n= "<<n;

  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  cout <<" tarda: " << cpu_time_used<<endl;


}
void Mult (int m,int n)
{
  int a[m][n], b[m][n], c[m][m];
  for(int i = 0 ; i < m ;++i){
    for(int j=0 ; j < n ;++j){
      a[i][j]=i;
      b[i][j]=j;
      c[i][j]=0;
    }
  }

  clock_t start, end;
  double cpu_time_used;
    start = clock();
  for ( int i = 0 ; i < m ; i++ ) {
     for ( int j = 0 ; j < n ; j++ ) {
         c[ i ][ j ] = 0;
         for ( int k = 0 ; k < n ; k++ ) {
             c[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ];
         }
     }
 }

  end = clock();
  cout <<"Algoritmo Mult (multiplicacion de matrices) con m y n= "<<n;
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  cout <<" tarda: " << cpu_time_used<<endl;
}
