#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int main(){

    // abrir ficheiro input

    ifstream input;
    input.open("input.txt");
    if(!input){cout << "Erro ao abrir ficheiro"<< endl; return 0 ;}


    //variaveis
    vector<int> seeds; 
    int mapeamento[3];
    string aux;
    int number;

    //leitura de seeds para vetor
    getline(input,aux, ':');
    getline(input,aux);

    stringstream seedFinder(aux);


    while(seedFinder >> number){
        seeds.push_back(number);
        cout << number << " " ;
    }

    // alocacao de um vetor Tupla para guardar Par (semente, soil,fertilizer,water ,light ,temperature ,humidity ,location)

    int numeroSeeds = seeds.size();

    int** mapeamentoCompletoTuple = new int*[numeroSeeds];

    for (int i = 0; i < numeroSeeds; ++i) {
        mapeamentoCompletoTuple[i] = new int[8];
    }

    cout << endl;

    // mapeamento seed to soil

    getline(input,aux);
    getline(input,aux); // avanca duas linhas;

    getline(input,aux); //linha de pesquisa ( loop goes here)
    stringstream mapFinder(aux);

    int i = 0;
    while(mapFinder >> number){
        mapeamento[i] = number;
        cout << mapeamento[i] << " ";
        i++;
    }

    // logica seed to soil

    for(int a = 0 ; a < numeroSeeds ; a++ ){

        
    }



    




    

    return 0;
}