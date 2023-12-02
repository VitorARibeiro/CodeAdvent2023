#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){

    ifstream input;
    input.open("input_trechebut.txt");

    if (!input){
        cout<<"Impossivel abrir ficheiro"<<endl;
    }
    else{
        cout << "Ficheiro lido com sucesso"<<endl;
    }

    //loop
    string stringAux;
    int soma = 0;
    
    while(getline(input,stringAux)){

        size_t firstPos = stringAux.find_first_of("0123456789");
        size_t lastPos = stringAux.find_last_of("0123456789");

        char finalchar[3];

        finalchar[0] = stringAux[firstPos];
        finalchar[1] = stringAux[lastPos];
        finalchar[2] = '\0';

        soma += atoi(finalchar);

        //cout << atoi(finalchar);

    }

    cout << soma;





   
    


    






    



    return 0;
}


