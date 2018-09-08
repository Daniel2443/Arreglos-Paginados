#include <iostream>
#include <fstream>

using namespace std;

class marco{
public:
    int size;
    int numPag;
    int array[256] = {0};

    void iniciarMarco(int numPag, int *array,int cant){
        size = cant;
        this->numPag = numPag;
        for(int i=0; i<cant; i++) {
            this->array[i] = *(array+i);
        }
    }

};

class PagedArray{
private:
    marco marcos[6];
    int totalPag = 0;
    int pagCargadas = 0;
    ifstream archivo;
    int posicionReemplazar = 0;


public:
    int numTotales = 0;

    void setArchivo(string dirArch){
        archivo.open(dirArch,ios::in);
        if(archivo.fail()){
            cout<<"El archivo no existe"<<endl;
        }else{
            //algun metodo de lectura que cuente la cantidad de posiciones
            //que tiene el archivo osea cantidad de enteros y lo guarde en
            // numTotales para saber el tamaño del Arrglo d numeros en total
            // y no solo los que esten en memoria.
            numTotales;
            totalPag = numTotales/256;
        }
    }

    int operator [](int posicion){
        int num;
        int pagActual = posicion/256;
        if(posicion > numTotales){
            cout<<"La posicion solicitada no existe"<<endl;
        }else{
            if(pagCargadas > 0){
                for(int i = 0; i < pagCargadas; i++){
                   if(marcos[i].numPag == pagActual){
                       num = marcos[i].array[posicion-(256*pagActual)];
                       return num;
                   }else if(i==5){
                           //Aqui significa que estan las 6 pag en memoria asi que se realiza
                           //el reemplazo de pagina con el algoritmo de reemplazo FIFO.
                       if(posicionReemplazar<6){
                           //Primero se debe leer la seccion del archivo en la que se encuentra
                           //el numero solicitado meterla en el arrayAux para asignar ese array
                           //a un marco de pagina
                           int cantNumAux = 256;
                           int arrayAux[cantNumAux];
                           marcos[posicionReemplazar].iniciarMarco(pagActual, arrayAux, cantNumAux);
                           posicionReemplazar++;
                       }else{
                           posicionReemplazar = 0;
                           //Primero se debe leer la seccion del archivo en la que se encuentra
                           //el numero solicitado meterla en el arrayAux para asignar ese array
                           //a un marco de pagina
                           int cantNumAux = 256;
                           int arrayAux[cantNumAux];
                           marcos[posicionReemplazar].iniciarMarco(pagActual, arrayAux, cantNumAux);
                           posicionReemplazar++;
                       }
                   }
                }
                //Aqui significa que la pagina donde se encuentra la posicion que se busca
                //no esta en un marco y ademas hay espacio libre por lo que se lee el
                //archivo de alguna forma y se asigna a un array y se pasa al marco que se
                //crea
                int cantNumAux = 256;
                int arrayAux[cantNumAux];//Aqui se debe crear un array con los numeros de la pagina
                marco nuevo;
                nuevo.iniciarMarco(pagActual,arrayAux,cantNumAux);
                marcos[pagCargadas] = nuevo;
                num = nuevo.array[posicion-(256*pagActual)];
                return num;

            }else{
                //Aqui significa que no hay paginas cargadas en marcos por lo que se lee el
                //archivo de alguna forma y se asigna a un array y se pasa al marco que se
                //crea y lo mismo arriba
                int cantNumAux = 256;
                int arrayAux[cantNumAux];
                marco nuevo;
                nuevo.iniciarMarco(pagActual,arrayAux,cantNumAux);
                marcos[0] = nuevo;
                num = nuevo.array[posicion-(256*pagActual)];
                return num;
            }
        }
        return -1;
    }

};


int main() {
    PagedArray pagAr;
    pagAr.setArchivo("prueba.txt");

    int numPrueba;
    int arrayPrueba[] = {0,50,2,5,43,71,97,35};
    marco prueba;
    prueba.iniciarMarco(0,arrayPrueba,8);
    numPrueba = prueba.array[5];

    int a = pagAr[200];
    int b = pagAr.numTotales;
    cout<<"El numero a es: "<<a<<endl;
    cout<<"El tamaño del array es: "<<b<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"El numero de prueba que se encuentra en la posicion 5 del marco de prueba es: "<<numPrueba<<endl;

    return 0;
}