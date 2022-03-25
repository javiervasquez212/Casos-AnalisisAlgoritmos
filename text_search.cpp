#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;

# define NO_OF_CHARS 256

//Boyer Moore Algorithm for Pattern Searching

void badCharHeuristic( string str, int size,
                        int badchar[NO_OF_CHARS]) //Crea y ordena el array de badChar
{
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void search( string txt, string pat) // Busca la palabra y hace los switch necesarios
{
    int x = 0;
    int m = pat.size();
    int n = txt.size();
    int badchar[NO_OF_CHARS];
 
    badCharHeuristic(pat, m, badchar);
 
    int s = 0; 
    while(s <= (n - m))
    {
        int j = m - 1;
        while(j >= 0 && pat[j] == txt[s + j])
            j--;
        if (j < 0)
        {
            x++;
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;
        }
        else
            s += max(1, j - badchar[txt[s + j]]);
    }

    cout << "La palabra " << pat << " se repite: " << x << " veces " << endl;
    
}
string readFileIntoString2(const string& path) { // Función para leer archivo/pasar texto a String
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}
int main(){

    string filename("Texto.txt");
    string txt;
    txt = readFileIntoString2(filename);
    
    //Pruebas

    string palabra1 = "death";
    search(txt, palabra1);

    string palabra2 = "a";
    search(txt, palabra2);

    string palabra3 = "you";
    search(txt, palabra3);

    string palabra4 = "Quiet led own";
    search(txt, palabra4);

    exit(EXIT_SUCCESS);


    return 0;
}
  