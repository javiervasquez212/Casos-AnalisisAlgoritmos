#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;


//----------------------------------------------------------------------------------------- Compare the Triplets


int Compare1(int pArray1[], int pArray2[], int pArrayRespuesta[2]){
    for (int i = 0; i < 3; i++)
    {
        if(pArray1[i]>pArray2[i]){ 

            pArrayRespuesta[0]++;
        }
        else{
            pArrayRespuesta[1]++;
        }
    }
    cout << "Resultado: "<< pArrayRespuesta[0] << " , "<< pArrayRespuesta[1] << endl;
    pArrayRespuesta[0] = 0;
    pArrayRespuesta[1]= 0;
}

// El segundo algoritmo es mucho más eficiente ya que no requiere de ciclos, lo cual hace que el rendimiento
// sea mucho mejor

int Compare2(int pArray1[], int pArray2[], int pArrayRespuesta[2]){

    if(pArray1[0]!= pArray2[0]){
        int numero=(pArray1[0]-pArray2[0])/abs(pArray1[0]-pArray2[0]); //+1 si ana es mayor
        pArrayRespuesta[0]+=numero+1;                   //-1 si bob es mayor
        pArrayRespuesta[1]+=numero-1;                   //se hace 0
        }
    if(pArray1[1]!=pArray2[1]){
        int numero=(pArray1[1]-pArray2[1])/abs(pArray1[1]-pArray2[1]);
        pArrayRespuesta[0]+=numero+1;        //para tener múltiplos de dos
        pArrayRespuesta[1]+=numero-1;
        }
    if(pArray1[2]!=pArray2[2]){
        int numero=(pArray1[2]-pArray2[2])/abs(pArray1[2]-pArray2[2]);
        pArrayRespuesta[0]+=numero+1;
        pArrayRespuesta[1]+=numero-1;
        }
    pArrayRespuesta[0]=pArrayRespuesta[0]/2;      //divide entre 2 para obtener el resultado
    pArrayRespuesta[1]=abs(pArrayRespuesta[1]/2);
    cout << "Resultado: "<< pArrayRespuesta[0] << " , "<< pArrayRespuesta[1] << endl;
}

//----------------------------------------------------------------------------------------- Time Conversion

string timeConversion1(string formatAP) {
	string format24h = formatAP.substr(2, 6); //:mm:ss
	int hrs = stoi(formatAP.substr(0,2)); //hh

	if(hrs==12){
		if(formatAP[8]=='A')
			hrs = 0; //Medianoche 00:mm:ss
	}else if(formatAP[8]=='P'){
		hrs += 12; //Horas de la tarde (13-23)
	}

	format24h = (hrs<10) ? "0"+to_string(hrs)+format24h : to_string(hrs)+format24h;

	return format24h;
}

// El segundo algoritmo es más eficiente ya que requiere de menos comparaciones para realizar el mismo proceso

string timeConversion2(string formatAP) {
	string format24h = formatAP.substr(2, 6); //:mm:ss
	int hrs = stoi(formatAP.substr(0,2)); //hh
	int factor = ((hrs%12)/hrs); //Para PM: =0 si hrs=12 | =1 en otro caso
	
	if(formatAP[8]=='A')
        factor--; //Para AM: =-1 si hrs=12 | =0 en otro caso 
	
    hrs += (12 * factor);

	format24h = (hrs<10) ? "0"+to_string(hrs)+format24h : to_string(hrs)+format24h;
	
	return format24h;
}

//----------------------------------------------------------------------------------------- Minion Game

void the_minion_game(string palabra){

    int puntaje[2]={0,0};

    for(int contador=0;contador<palabra.length();contador++){
        puntaje[0]+=((palabra[contador]=='A'||palabra[contador]=='E'||palabra[contador]=='I'||palabra[contador]=='O'||palabra[contador]=='U')?
                        palabra.length()-contador:0);
        puntaje[1]+=((palabra[contador]!='A'&&palabra[contador]!='E'&&palabra[contador]!='I'&&palabra[contador]!='O'&&palabra[contador]!='U')?
                        palabra.length()-contador:0);
    }

    if(puntaje[0]>puntaje[1]){
        cout<<"Jugador a: "<<puntaje[0]<<endl;
    }
    else if(puntaje[0]<puntaje[1]){
        cout<<"Jugador b: "<<puntaje[1]<<endl;
    }
    else{
        cout<<"Draw"<<endl;
    }
}

//----------------------------------------------------------------------------------------- Pairs

int pairs_with_pointers(int k, vector<int> arr) {
    
    // Ordenar el array(ascendente)
    sort(arr.begin(), arr.end());
    
    // {Pointer 2, NULL, Pointer1}
    int pointers[] = {1, 0, 0};
    int result = 0;
    int valueDif = 0;
    
    while (pointers[0] < arr.size()) {
        
        valueDif = arr[pointers[0]] - arr[pointers[2]];
        
        // Si es lo que busco, aumento pointer2
        if (valueDif == k) {
            result++;
            pointers[0]++;
            continue;
        }
        
        // Mueve el puntero necesario dependiendo si es mayor o menor
        pointers[ ((valueDif - k)/abs(valueDif - k)) + 1 ]++;
    }
    
    return result;
}


int main(){


    // Variables Compare the Triplets
    int result[]={0,0};

    int a[]= {20,28,50};
    int b[]= {50,60,70};

    int c[]= {20,28,50};
    int d[]= {10,60,50};

    // Variables Pairs

    vector<int> arr1 = {1, 3, 5, 8, 6, 4, 2};
    vector<int> arr2 = {1, 5, 3, 4, 2};

    //Time Conversion

    cout << "\n----------------Time Conversion----------------\n" << endl;

    cout << timeConversion1("12:41:15AM") << endl;
	cout << timeConversion2("08:41:15PM") << endl;

    // Pairs

    cout << "\n----------------Pairs----------------\n" << endl;

    cout << "Resultado: " << pairs_with_pointers(2, arr1) << endl;
    cout << "Resultado: " << pairs_with_pointers(2, arr2) << endl;

    // The Minion Game

    cout << "\n----------------Minion----------------\n" << endl;

    string palabra1="BANANA", palabra2="ARIAL", palabra3="POO";

    the_minion_game(palabra1);
    the_minion_game(palabra2);

    // Compare the Triplets

    cout << "\n----------------Compare----------------\n" << endl;


    Compare1(a,b,result);

    Compare2(c,d,result);

    return 0;
}

//Link repositorio https://github.com/javiervasquez212/Casos-AnalisisAlgoritmos

// 
