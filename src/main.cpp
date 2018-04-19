/* 
 * @file   main.cpp
 * @author Tomás González Martín
 * @brief  Práctica #05: Ordenación
 *
 * Created on 16 de Abril de 2018, 05:49
 */

#include "../lib/stadistical_t.h"
#define MAX_SIZE 20

//Método que sirve para los valores del vector que se creará
sort_t<dni_t> newSort(void){
    
    int v_size = MAX_SIZE;
    
    do{
    cout << "Indique el tamaño del vector (máximo 20, mínimo 1)" << endl;
    cin >> v_size;
    }while (v_size <= 0);
    
    if (v_size > MAX_SIZE)
        v_size = MAX_SIZE;
    
    sort_t<dni_t> sortAlgorithm(v_size); 
    
    return sortAlgorithm;
}


//Contiene la traza para cada uno de los algoritmos
void howTheyWorks(void){
    
    sort_t<dni_t> sortAlgorithm = newSort();
    
    int option = -1;
    
    while (option != 6){
        cout << "¿Qué algoritmo desea probar?" << endl;
        cout << "0. Inserción" << endl;
        cout << "1. Burbuja" << endl;
        cout << "2. HeapSort" << endl;
        cout << "3. QuickSort" << endl;
        cout << "4. ShellSort" << endl;
        cout << "5. Quiero cambiar el tamaño" << endl;
        cout << "6. Ninguno, prefiero irme" << endl;
        cin >> option;
        
            switch(option){
                case 0: sortAlgorithm.insertionSort(sortAlgorithm.getVector(), 1);break;
                case 1: sortAlgorithm.bubbleSort(sortAlgorithm.getVector(), 1);break;
                case 2: sortAlgorithm.heapSort(sortAlgorithm.getVector(), 1);break;
                case 3: sortAlgorithm.quickSort(sortAlgorithm.getVector(), 1);break;
                case 4: sortAlgorithm.shellSort(sortAlgorithm.getVector(), 1);break;
                case 5: sortAlgorithm = newSort();break;
                case 6: cout << "Volviendo al menú principal" << endl;break;
                default: cerr << "Esa opción no existe. Por favor, elija otra" << endl;
            }
    }
    
}


//Muestra las estadísticas dadas para cada algoritmo dados los mismos vectores a ordenar
void stadistics(void){
    
    int num_test = -1;
    int v_size = -1;
    while (num_test < 0){
        cout << "Indique el número total de pruebas" << endl;
        cin >> num_test;
        
        if (num_test < 0)
            cout << "Debe indicar un número positivo..." << endl;
    }
    
    while (v_size < 0){
        cout << "Indique el tamaño de las pruebas" << endl;
        cin >> v_size;
        
        if (v_size < 0)
            cout << "Debe indicar un número positivo..." << endl;
    }
    
    stadistical_t<dni_t> stadistical(num_test, v_size);
    stadistical.writeStadistical(cout);
    
}



void manualHowTheyWorks(void){
    
    int option = -1;
    

    vector<dni_t> v_dni;
    int DNI = 1;
    int character;
    string tochar;
    string name;
    string surname;
    
    dni_t dni;
    
    
    cout << "Rellene los siguientes datos" << endl;
    for (int i = 0; i < 3; i++){
        do{
            cout << "dni [" << i+1 << "] :";
            cin >> DNI;
            if (DNI < 0 || DNI > 99999999)
                cout << "DNI debe estar entre 0 y 99999999" << endl;
        }while (DNI < 0 || DNI > 99999999);
        dni_t dni;
        dni.setDni(DNI);
        
        cout << "Letra [" << i+1 << "] :";
        cin >> character;
        dni.setCharacter(character);
        /*cout << "Nombre [" << i+1 << "] :";
        cin >> name;
        dni.setName(name);
        cout << "Apellido [" << i+1 << "] :";
        cin >> surname;
        dni.setSurname(surname);*/
        cout << "llega" << endl;
        v_dni.push_back(dni);
        
            
    }
        
    
    sort_t<dni_t> sortAlgorithm;
    
    
    while (option != 6){
        cout << "¿Qué algoritmo desea probar?" << endl;
        cout << "0. Inserción" << endl;
        cout << "1. Burbuja" << endl;
        cout << "2. HeapSort" << endl;
        cout << "3. QuickSort" << endl;
        cout << "4. ShellSort" << endl;
        cout << "5. Quiero cambiar el tamaño" << endl;
        cout << "6. Ninguno, prefiero irme" << endl;
        cin >> option;
        
        
        
            switch(option){
                case 0: sortAlgorithm.insertionSort(v_dni, 1);break;
                case 1: sortAlgorithm.bubbleSort(v_dni, 1);break;
                case 2: sortAlgorithm.heapSort(v_dni, 1);break;
                case 3: sortAlgorithm.quickSort(v_dni, 1);break;
                case 4: sortAlgorithm.shellSort(v_dni, 1);break;
                case 5: sortAlgorithm = newSort();break;
                case 6: cout << "Volviendo al menú principal" << endl;break;
                default: cerr << "Esa opción no existe. Por favor, elija otra" << endl;
            }
    }
    
}


int main (void){
    
    int option = -1;
    
    while (option != 2){
        cout << "Práctica #05: Ordenación       -       AyEDA       -       Tomás González Martín" << endl;
        cout << "Elija el programa deseado:" << endl;
        cout << "0. Modo Demostración" << endl;
        cout << "1. Modo Estadística" << endl;
        cout << "2. Demostración manual (out of service)" << endl;
        cout << "3. Salir del programa" << endl;
        cin >> option;
        
            system("clear");
            switch(option){
                case 0: howTheyWorks();break;
                case 1: stadistics();break;
                case 2: manualHowTheyWorks();break;
                case 3: cout << "*****Saliendo*****" << endl;break;
                default: cerr << "Esa opción no existe. Por favor, elija otra" << endl;
            }
    }
    
    
    
    return 0;
    
}