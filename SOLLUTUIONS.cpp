//F
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int getdelta(int number){
	number = abs(number);
	int first2digits, last2digits;
	
	first2digits = number%10 + 10*((number/10)%10);
	while(number > 99){
		number  = number /10;
		
	}
	last2digits = number%10 + 10*((number/10)%10);

	return first2digits - last2digits;
}
int main(){
	int count = 0;
	int a, b;
	int chislo;
	cin >> a >> b;
	
	
	for (int i = a; i <= b; i++){
		
		if(getdelta(i) != 0 and i%getdelta(i) == 0){
				
			 chislo = i;
			 count++;
		}
	}
	
	if(count != 0) cout << count << " " << chislo;
	else cout << "0" << " " << "0";
	
}



//A
#include <vector>
#include <iostream>
#include <math.h>
//Найдите все натуральные числа, принадлежащие отрезку [a; b], которые представляют собой произведение трёх различных простых делителей, оканчивающихся на одну и ту же цифру. В ответе запишите количество таких чисел и такое из них, для которого разность наибольшего и наименьшего простых делителей максимальна. Если чисел с максимальной разницей наибольшего и наименьшего простых делителей несколько, то вывести наименьшее из них. В случае, если подходящих чисел нет, вывести два нуля через пробел



using namespace std;

void show(vector<int> a){
  for  (int i = 0; i < a.size(); i++){
    
    cout << a[i] << " ";

  }
  cout << endl;
}

bool pr(int a){
  for(int j=2;j<int(sqrt(a))+1;j++){
    if(a%j==0)
      return false;
  }
return true;
}
 
 //485617


int main(){
int a,b;
 
cin>>a>>b;
int c=0,max=0,cmax=0;
for(int i=a;i<=b;i++){
  vector<int> a={};
  int d = 2;
  while( d<=int(sqrt(i)+1)){
    if(i%d==0 && pr(d))
      a.push_back(d);
    d++;
  }
  if (a.size()==3 && a[0]%10==a[1]%10 and a[1]%10==a[2]%10 && i==a[0]*a[1]*a[2])
    {
      c++;
      if ((a[2]-a[0])>max){
        max=abs(a[2]-a[0]);
        cmax = i;
      }
    }
} 
 
    

 cout<<c<<' '<<cmax;


}


//C
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
 


using namespace std;

vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}
 
 //485617


int main(){
int a,b;

ifstream file("input.txt"); // открыли файл для чтения

string s;
file >> s;
string al="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char maxl='A';
int max =0;
for(int i=0;i<27;i++){
  string c = "";
  c=c+al[i];
  vector<string> sp;
  sp =  split(s,c); 
  
  for(int j=0;j<sp.size();j++){
    if(sp[j].length()!=s.length())
      if(sp[j].length()>max){
        max = sp[j].length();
        maxl=al[i];
      }
  }
  }
cout<<maxl<< ' '<<max;

}



//D
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void show(vector<string> a ){
    for (int k =0; k < a.size(); k++){
       
        cout << a[k] << endl;
    } 
    cout << endl; 
    cout << endl;
}
void  f1(string value, int digits, vector<string> *save, int m)
{
	
	
    if (digits == 0)
    {
		int count = 0;
		for (int i =0; i < value.length(); i++){
			if(value[i] == '0' or value[i] == '2') count++;
		}
		if (count >= m) (*save).push_back(value);
        
        return;
    }
    
    
	
	
	
	f1(value + "0", digits-1,save, m);
	f1(value + "1", digits-1,save, m);
	f1(value + "2", digits-1,save, m);
	f1(value + "3", digits-1,save, m);

    
}



int main()
{
    vector<string> save;
    int m;
    int n;
    int k;
    cin >> n >> m >> k;
    f1("", n, &save, m);
    
    string temp = save[k-1];
    //show(save);
    if (k < save.size()){
		cout << save.size() << " ";
    for (int  i = 0; i < temp.size(); i++){ 
		if (temp[i] == '0') cout << "A";
		if (temp[i] == '1') cout << "F";
		if (temp[i] == '2') cout << "I";
		if (temp[i] == '3') cout << "N";
		
		
	}
	
	
}
else cout << "ERROR";
}




#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
void show(vector<int> a){

  for  (int i = 0; i < a.size(); i++){
    
    cout << a[i] << " ";

  }
  cout << endl;
}

int MAX = 99999999;

void floyd(vector<vector<int> > A, int N, int current){
       vector<vector<int> > d(N, vector<int>(N, 0));
    vector<vector<int> > next_v(N, vector<int>(N, 0));
    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
        {
            d[i][j] = A[i][j];
            if (d[i][j] == 0 && i != j)
                d[i][j] = MAX;
          
            
        }
    //i - промежуточная вершина, u, v - вершины между которыми ищется расстояние
    for (int i=0; i<N; ++i)
      for (int u=0; u<N; ++u)
      for (int v=0; v<N; ++v)
        if (d[u][i] + d[i][v] < d[u][v]){
            d[u][v] = d[u][i] + d[i][v];
      
        
    }
	if(d[0][current-1] != MAX)
		cout << d[0][current-1];
	else cout << "-1";
    
  

    
}

//Превращаем в список смежности
//Удаляем ребра, у кторых вес больше допустимого
//Применяем алгоритм дейкстры
//Выводим время

int main(){
	int N; int M; int current; int to; int from; int time; int weight;
	cin >> N;
	cin >> current;
	cin >> M;
	
	vector< vector<int> > A(N, vector<int>(N, 0));
  vector< vector<int> > weigths(M, vector<int>(3, 0));
  for(int i=0;i<M;i++){
    cin>>from>>to>> time >> weight;
    
    A[from-1][to-1] = time;
    A[to-1][from-1] = time;
    weigths[i][0] = from;
    weigths[i][1] = to;
    weigths[i][2] = weight;
	
 }
	int m, n;
	cin >> m >> n;
	int gruz = m+n;
	//cout << "GRUZ" << gruz;
	
	//for(int i=0; i < N; i++) show(A[i]);
	for(int i=0; i < M; i++){
		
		if (weigths[i][2] < gruz){
			
			A[weigths[i][0]-1][weigths[i][1]-1] = 0;
			A[weigths[i][1]-1][weigths[i][0]-1] = 0;
		}
		
		
	}
	//cout << endl;
	//for(int i=0; i < N; i++) show(A[i]);
	
	
	floyd(A, N, current);
	
	
	
	
}



