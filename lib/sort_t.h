/* 
 * @file   sort_t.h
 * @author Tomás González Martín
 * @brief  Práctica #05: Ordenación
 *
 * Created on 16 de Abril de 2018, 05:49
 */
#pragma once
#include "dni_t.h"

#ifndef SORT_T_H
#define SORT_T_H

template <class T>
class sort_t{
public:
    sort_t(void);
    sort_t(int sz);
    sort_t(const sort_t& Sort);
    ~sort_t();
    
    
    int insertionSort(vector<T> vector, bool show);
    int bubbleSort(vector<T> vector, bool show);
        int baja(vector<T>& vector, bool show, int i, int size);
    int heapSort(vector<T> vector, bool show);
        int mainQuickSort(vector<T>& vector, bool show, int start, int end);
    int quickSort(vector<T> vector, bool show);
        int alphaShellSort(vector<T>& vector, bool show, int jump);
    int shellSort(vector<T> vector, bool show);
    
    
    
    vector<T> getVector(void);
    
private:
    
    void resize(void);    
    int sz_;
    vector<T> vector_;
};


template<class T>
sort_t<T>::sort_t(void){
    sz_ = 20;
    resize();
}

template<class T>
sort_t<T>::sort_t(int sz):
sz_(sz)
{
    resize();
}

template<class T>
sort_t<T>::sort_t(const sort_t& Sort):
sz_(Sort.sz_),
vector_(Sort.vector_)
{}

template<class T>
sort_t<T>::~sort_t(void){
    sz_ = -1;
    vector_.clear();
}

template<class T>
vector<T> sort_t<T>::getVector(void){
    return vector_;
}

/*template<class T>
void sort_t<T>::resize(void){
    //srand (time(NULL));
    for (int i = 0; i < sz_; i++)
        vector_.push_back(rand() % 99 + 1);
}*/

template<class T>
void sort_t<T>::resize(void){
    srand (time(NULL));
    
    for (int i = 0; i < sz_; i++){
        dni_t dni;
        vector_.push_back(dni);
    }
        
}


/***************************************************************************/
/*******************************InsertionSort*******************************/
/***************************************************************************/
template<class T>
int sort_t<T>::insertionSort(vector<T> vector, bool show){
    int count = 0;
    
    if (show){
        cout << "Estado inicial del vector" << endl;
        cout << "size = " << sz_ << endl;
        cout << "v =";
        for (int i = 0; i < vector.size(); i++)
            cout << " " << vector[i];
        cout << endl;
    }
    
    for (int i = 1; i < vector.size(); i++){
        for (int j = 0; j < i; j++){
            if ( ++count && vector[j] >= vector[i]){
                
                if (show){
                    cin.ignore();
                    cout << "Insertar en :";
                    for (int k = 0; k < vector.size(); k++){
                        if (k == j || k == i)
                            cout << " |" << vector[k] << "|";
                        else
                            cout << " " << vector[k];
                    }
                }
                
                //Se intercambian los valores
                vector.insert(vector.begin()+j, vector[i]);
                vector.erase(vector.begin()+i+1);
                
                
                if (show){
                    cin.ignore();
                    cout << "Siguiente   :";
                    for (int k = 0; k < vector.size(); k++){
                        if (k == i+1)
                            cout << " |" << vector[k] << "|";
                        else
                            cout << " " << vector[k];
                    }
                    cout << endl;
                }
                
            }
        }
        
    }
    if (show){
        cout << endl;
        cout << endl;
        cout << "\t\tVector ordenado:";
        for (int k = 0; k < vector.size(); k++)
            cout << " " << vector[k];

        cout << endl;
        cin.ignore();
    }
    
    return count;
    

}






/***************************************************************************/
/*********************************BubbleSort********************************/
/***************************************************************************/
template<class T>
int sort_t<T>::bubbleSort(vector<T> vector, bool show){
    int count = 0;
    
    if (show){
        cout << "Estado inicial del vector" << endl;
        cout << "size = " << sz_ << endl;
        cout << "v =";
        for (int i = 0; i < vector.size(); i++)
            cout << " " << vector[i];
        cout << endl;
    }
    
    for (int i = 1; i < vector.size(); i++){
        for (int j = vector.size()-1; j >=i; j--){
            if (++count && vector[j] < vector[j-1]){
                
                if (show){
                    cin.ignore();
                    cout << "Cambiar con:";
                    for (int k = 0; k < vector.size(); k++){
                        if (k == j || k == j-1)
                            cout << " |" << vector[k] << "|";
                        else
                            cout << " " << vector[k];
                    }
                    cout << endl;
                }
                
                //Se intercambian los valores
                T aux = vector[j-1];
                vector[j-1] = vector[j];
                vector[j] = aux;
                
                
            }
        }
        
    }
    if(show){
        cout << endl;
        cout << endl;
        cout << "\t\tVector ordenado:";
        for (int k = 0; k < vector.size(); k++)
            cout << " " << vector[k];

        cout << endl;

        cin.ignore();
    }
    
    return count;
    
}




/***************************************************************************/
/**********************************HeapSort*********************************/
/***************************************************************************/
template<class T>
int sort_t<T>::baja(vector<T>& vector, bool show, int i, int size){
    T aux;
    int count = 0;
    
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (show){
        cin.ignore();
        cout << "Padre e hijos:";
        for (int k = 0; k < vector.size(); k++){
            if (k == l || k == r || k == largest)
                cout << " |" << vector[k] << "|";
            else
                cout << " " << vector[k];
        }
        cout << endl;
    }
    
    if(++count && l < size && vector[l] > vector[largest])
        largest = l;
    if(++count && r < size && vector[r] > vector[largest])
        largest = r;
    if(++count && largest != i){
        aux = vector[i];
        vector[i] = vector[largest];
        vector[largest] = aux;
        baja(vector, show, largest, size);
    }
    
        
   return count;
}


template<class T>
int sort_t<T>::heapSort(vector<T> vector, bool show){
    int count = 0;
    int x = 0;
    T aux;
    
    if (show){
        cout << "Estado inicial del vector" << endl;
        cout << "size = " << sz_ << endl;
        cout << "v =";
        for (int i = 0; i < vector.size(); i++)
            cout << " " << vector[i];
        cout << endl;
    }
    

    for(int i=vector.size()/2; i>=0; i--){
        count += baja(vector, show, i, vector.size());
    }
    
    for(int i = sz_-1; i>=0; i--){
        aux = vector[0];
        vector[0] = vector[i];
        vector[i] = aux;
        count+= baja(vector,show, 0, i);
    }
    
    
    
    if(show){
        cout << endl;
        cout << endl;
        cout << "\t\tVector ordenado:";
        for (int k = 0; k < vector.size(); k++)
            cout << " " << vector[k];

        cout << endl;

        cin.ignore();
    }
    
    return count;
    
}




/***************************************************************************/
/*********************************QuickSort*********************************/
/***************************************************************************/

template<class T>
int sort_t<T>::mainQuickSort(vector<T>& vector, bool show, int start, int end){
    int pivot = (end+start)/2;
    int count = 0;
    
    int i = start;
    int j = end;
    while ( i <= j ){
               
        while (++count && vector[i] < vector[pivot]) i++;
        while (++count && vector[j] > vector[pivot]) j--;
        if (show){
            cin.ignore();
            cout << "Antes:";
            for (int k = 0; k < vector.size(); k++){
                if (k == j || k == i || k == pivot)
                    cout << " |" << vector[k] << "|";
                else
                    cout << " " << vector[k];
            }
            cout << endl;
        }
        if (i <= j){
            T aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
            if (show){
                cout << "Ahora:";
                for (int k = 0; k < vector.size(); k++){
                    if (k == j || k == i || k == pivot)
                        cout << " |" << vector[k] << "|";
                    else
                        cout << " " << vector[k];
                }
                cout << endl << endl;
            }
            
            i++;
            j--;
        }
        
    }
    
    
    if (start < j)  count += mainQuickSort(vector, show, start, j);
    if (end > i)    count += mainQuickSort(vector, show, i, end);
    
    return count;
}

template<class T>
int sort_t<T>::quickSort(vector<T> vector, bool show){
    int count = 0;
    if (show){
        cout << "Estado inicial del vector" << endl;
        cout << "size = " << vector.size() << endl;
        cout << "v =";
        for (int i = 0; i < vector.size(); i++)
            cout << " " << vector[i];
        cout << endl;
    }
    
    count += mainQuickSort(vector, show, 0, vector.size());

    if(show){
        cout << endl;
        cout << endl;
        cout << "\t\tVector ordenado:";
        for (int k = 0; k < vector.size(); k++)
            cout << " " << vector[k];

        cout << endl;

        cin.ignore();
    }
    
    
    return count;
}




/***************************************************************************/
/*********************************ShellSort*********************************/
/***************************************************************************/

template<class T>
int sort_t<T>::alphaShellSort(vector<T>& vector, bool show, int jump){
    int count = 0;
    
    T aux;
    int i_aux;
    
    
    for (int i = jump; i < vector.size(); i++){
        
        
        
        aux = vector[i];
        i_aux = i;
        while (++count && (i_aux>=0) && (aux < vector[i_aux-jump])){
            
            
            vector[i_aux] = vector[i_aux - jump];
            i_aux = i_aux - jump;
            
            
        }
        if (i_aux >= 0 || i_aux < vector.size())
            vector[i_aux] = aux;
        
        if (show && jump){
            cin.ignore();
            cout << "[" << jump << "]:";
            for (int k = 0; k < vector.size(); k++){
                    cout << " " << vector[k];
            }
            cout << endl;
            
            }
        
    }
    
    return count;
    
}



template<class T>
int sort_t<T>::shellSort(vector<T> vector, bool show){
    int count = 0;
    

    if (show){
        cout << "Estado inicial del vector" << endl;
        cout << "size = " << sz_ << endl;
        cout << "v =";
        for (int i = 0; i < vector.size(); i++)
            cout << " " << vector[i];
        cout << endl;
    }
    
    
    int jump = vector.size();
    while (jump >= 1){
        jump = jump/2;
        count += alphaShellSort(vector, show, jump);
    }
    
    if(show){
        cout << endl;
        cout << endl;
        cout << "\t\tVector ordenado:";
        for (int k = 0; k < vector.size(); k++)
            cout << " " << vector[k];

        cout << endl;

        cin.ignore();
    }
    
    return count;
}

    
    
    
#endif /* SORT_T_H */

