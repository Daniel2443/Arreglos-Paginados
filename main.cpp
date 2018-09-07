#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>     /* atoi */
using namespace std;
ifstream *indata;
int *ini;
//double rate = 5 * 1024 / 10.5;

void WriteFile(int size_) {
/* ESTO ES PARA SIMPLEMENTE HACER UN ARCHIVO RANDOM,
 * SE PODRIA USAR PARA GENERAR EL ARCHIVO FINAL
 *
 * */
    srand (time (nullptr));
    ofstream outdata;

    int size = 256;
    bool finish = false;
    //fstream data("archivo.txt");

    outdata.open ("archivo.txt");
    for (int i = 0; i < size_; ++i) {
        outdata<< rand ()<<",";
    }
}
void fillPages(){

    int ini = 0;
}
int *page2 = new int[256];
int *page3 = new int[256];
int *page4 = new int[256];
int *page5 = new int[256];
int *page6 = new int[256];
int *page1 = new int[256];
char *line = NULL;
void refill(){
    ofstream outdata;

    int size = 256;
    bool finish = false;
    //fstream data("archivo.txt");

    outdata.open ("archivo5.txt");
    for (int i = 0; i < 256 ; ++i) {
        outdata<< page1[i]<<endl;
    }
    cout << "entré en pagina 2"<<endl;
    for (int i = 0; i < 256 ; ++i) {
        outdata<< page2[i]<<endl;
    }   cout << "entré en pagina 3"<<endl;
    for (int i = 0; i < 256 ; ++i) {
        outdata<< page3[i]<<endl;
    }   cout << "entré en pagina 4"<<endl;
    for (int i = 0; i < 256 ; ++i) {
        outdata<< page4[i]<<endl;
    }     cout << "entré en pagina 5"<<endl;
    for (int i = 0; i < 256 ; ++i) {
        outdata<< page5[i]<<endl;
    }
    cout << "entré en pagina 6"<<endl;
    for (int i = 0; i < 256 ; ++i) {
        outdata<< page6[i]<<endl;
    }




};
void readFile(char* &linea) {
    const string aFile = "archivo1.txt";

    //ESTO LEE TODAS LAS LINEAS
    /*while (!f.eof()) {
        getline(f,line);

        //f.seekg (0, len);
        if (line.length() == 0|| line[0] == ';')
            cout << "IGNORE LINE\n";
        else
            cout << line << "\n";
    }*/

/*    ESTO ES PARA RELLENAR LAS PAGINAS, SI FUNCIONA. LO QUE PASA ES QUE LUEGO NO SE
    COMO HACER PARA GUARDAR EL PROGRESO, Y LUEGO PODER LEER LAS LINEAS QUE FALTAN*/

   FILE *fp = fopen ("archivo1.txt", "r");
    if (fp == NULL) {
        exit (EXIT_FAILURE);
    }

    size_t len = 0;
    int counter = 0;
    int ciclos = 0;
    while ((getline(&linea, &len, fp)) != -1) {
        int a;
        a = atoi (linea);
        if(a==0){
            break;
        }

            if (counter < 256 && ciclos==0) {
            page1[counter] = a;

        }else if(counter==256){
            page1[counter] = a;
            counter=0;
            ciclos++;

        }
        if (counter < 512 && ciclos==1) {
            page2[counter] = a;
        }else if(counter==256){
            page2[counter] = a;
            counter=0;
            ciclos++;

        }
        if (counter <= 768 && ciclos==2) {
            page3[counter] = a;
        }else if(counter==256){
            page3[counter] = a;
            counter=0;
            ciclos++;

        }
        if (counter <= 1024 && ciclos==3) {
            page4[counter] = a;
        }else if(counter==256){
            page4[counter] = a;
            counter=0;
            ciclos++;

        }
        if (counter <= 256 * 5 && ciclos==4) {
            page5[counter] = a;
        }else if(counter==256){
            page5[counter] = a;
            counter=0;
            ciclos++;

        }
        if (counter <= 256 * 6  && ciclos==5) {
            page6[counter] = a;
        }else if(counter==256){
            page6[counter] = a;
            counter=0;
            ciclos++;

        } else if(ciclos >= 6) {
            cout << "No more memory, please wait"<<endl;
            break;

        }
        //cout <<a <<endl;
        //page1[counter] = a;
        // using printf() in all tests for consistency
        //cout <<counter <<endl;
        counter++;
    }
    //cout <<"asd" <<endl;
    fclose(fp);
    //cout <<"asd1" <<endl;
    if (line){
      //  cout <<"asd2" <<endl;
        free (line);
        //cout <<"asd3" <<endl;
    }
    //cout <<"asd4" <<endl;
}
int main() {
    //WriteFile (356);
    readFile (line);
    //refill ();
    int page=0;

    for (int i = 0; i < 256 ; ++i) {
        cout<< page1[i]<<endl;

    }
    cout << "entré en pagina 2"<<endl;
    for (int i = 0; i < 256 ; ++i) {
        cout<< page2[i]<<endl;
    }   cout << "entré en pagina 3"<<endl;
    for (int i = 0; i < 256 ; ++i) {
        cout<< page3[i]<<endl;
    }   cout << "entré en pagina 4"<<endl;
    for (int i = 0; i < 256 ; ++i) {
        cout<< page4[i]<<endl;
    }     cout << "entré en pagina 5"<<endl;
    for (int i = 0; i < 256 ; ++i) {
        cout<< page5[i]<<endl;
    }
    cout << "entré en pagina 6"<<endl;
    for (int i = 0; i < 256 ; ++i) {
        cout<< page6[i]<<endl;
    }
    free(page1);

    readFile (line);
    cout << "Esta es la linea: "<<line<<endl;


    cout <<"hola";
    return 0;
}