#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

void participantes();

vector<string> obtenerDatos(std::string linea);

int main(int argc, char** argv) {
    cout << "DENTRO DEL MAIN" << endl;
    ifstream entrada("products_taller.csv", ios::in);   //ver si esta el archivo
    ifstream entrada2("trx_taller.csv", ios::in); //ingreso archivo 2
    ofstream salida("productos.csv");
    
    if(!entrada){
        cout<< "archivo no encontrado" << endl;
    }
    else{
        cout << "<<<<<<<<<<<<<  ARCHIVO ENCONTRADO  >>>>>>>>>>>>" << endl;
        
        for (std::string linea; getline(entrada, linea);) {
            vector<string> datos = obtenerDatos(linea);
            if (datos.size() >= 2) {
                string barcode = datos.at(0);
                string name = datos.at(1);
                string volume = datos.at(2);
                
                int cantidad=0;
                if(entrada2){
                    for (std::string linea2;getline(entrada2,linea2);)
                    {
                        vector<string> datos2 = obtenerDatos(linea2);
                        if (datos.size() >= 2)
                        {
                            string barcode2 = datos2.at(0);
                            if(barcode == barcode2){
                                int valor = atoi(datos2.at(1).c_str());
                                cantidad = cantidad + valor;
                                cout << "canti" << endl;
                                cout << cantidad << endl;

                            }
                        }
                        datos2.clear();   
                    }
                    

                }
                string quantity = to_string(cantidad);
                std::string fila;
                fila = barcode + ";" + name + ";" + volume + ";" + quantity;
                salida << fila << std::endl;
                }
            datos.clear();
        }
    }
            
    return 0;
}

vector<string> obtenerDatos(std::string linea) {
    vector<string> arreglo;
    std::stringstream ss(linea);
    std::string item;

    while (std::getline(ss, item, ';')) {
        string valor = item;
        arreglo.push_back(valor);
    }
    return arreglo;
}

void participantes() {
    std::cout << std::endl << "=== Taller 2 ===" << std::endl;
    std::cout << std::endl << "Javier Gallegos" << std::endl;
    std::cout << std::endl << "Rodrigo Estay" << std::endl;
    std::cout << std::endl << "Janira Navarro" << std::endl;
}
