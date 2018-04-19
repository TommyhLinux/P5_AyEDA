/* 
 * @file   statistical_t.h
 * @author Tomás González Martín
 * @brief  Práctica #05: Ordenación
 *
 * Created on 16 de Abril de 2018, 05:49
 */
#pragma once

#include "sort_t.h"
#include <iomanip>
#include <climits>

#ifndef STADISTICAL_T_H
#define STADISTICAL_T_H

enum to_sort {InsertionSort, BubbleSort, HeapSort, QuickSort, ShellSort};

template<class T>
class stadistical_t{
public:
    stadistical_t(int number_of_tests, int size);
    ~stadistical_t(void);
    
    int getMax(int xSort);
    int getMin(int xSort);
    float getAvg(int xSort);
    
    ostream& writeStadistical(ostream& os);
    
private:
    
    vector<sort_t<T> > testbench_sort_;
    
};

template<class T>
stadistical_t<T>::stadistical_t(int number_of_tests, int size){
        
    //Se crean vectores de tamaño aleatorio
    for (int i = 0; i < number_of_tests; i++){
        sort_t<T> sort(size);
        testbench_sort_.push_back(sort);
    }
    
}

template<class T>
stadistical_t<T>::~stadistical_t(void){
    
    testbench_sort_.clear();
    
}

template<class T>
int stadistical_t<T>::getMax(int xSort){
    
    int max = INT_MIN;
    int cost = -1;
    
    for (int i = 0; i < testbench_sort_.size(); i++){
        //calculamos cada uno de los costes
        switch (xSort){
            case InsertionSort:     cost = testbench_sort_[i].insertionSort(testbench_sort_[i].getVector(), false);break;
            case BubbleSort:        cost = testbench_sort_[i].bubbleSort(testbench_sort_[i].getVector(), false);break;
            case HeapSort:          cost = testbench_sort_[i].heapSort(testbench_sort_[i].getVector(), false);break;
            case QuickSort:         cost = testbench_sort_[i].quickSort(testbench_sort_[i].getVector(), false);break;
            case ShellSort:         cost = testbench_sort_[i].shellSort(testbench_sort_[i].getVector(), false);break;
            default:                cost = 0;
            
        }
        if (cost >= max)
            max = cost;
        cost = 0;
    }
    
    return max;
}

template<class T>
int stadistical_t<T>::getMin(int xSort){
    
    int min= INT_MAX;
    int cost = -1;
    
    for (int i = 0; i < testbench_sort_.size(); i++){
        //calculamos cada uno de los costes
        switch (xSort){
            case InsertionSort:     cost = testbench_sort_[i].insertionSort(testbench_sort_[i].getVector(), false);break;
            case BubbleSort:        cost = testbench_sort_[i].bubbleSort(testbench_sort_[i].getVector(), false);break;
            case HeapSort:          cost = testbench_sort_[i].heapSort(testbench_sort_[i].getVector(), false);break;
            case QuickSort:         cost = testbench_sort_[i].quickSort(testbench_sort_[i].getVector(), false);break;
            case ShellSort:         cost = testbench_sort_[i].shellSort(testbench_sort_[i].getVector(), false);break;
            default:                cost = 0;
        }
        if (cost <= min)
            min = cost;
        cost = 0;
    }

    return min;
    
}

template<class T>
float stadistical_t<T>::getAvg(int xSort){
    
    int add = 0;
    
    for (int i = 0; i < testbench_sort_.size(); i++)
        switch (xSort){
            case InsertionSort:     add += testbench_sort_[i].insertionSort(testbench_sort_[i].getVector(), false);break;
            case BubbleSort:        add += testbench_sort_[i].bubbleSort(testbench_sort_[i].getVector(), false);break;
            case HeapSort:          add += testbench_sort_[i].heapSort(testbench_sort_[i].getVector(), false);break;
            case QuickSort:         add += testbench_sort_[i].quickSort(testbench_sort_[i].getVector(), false);break;
            case ShellSort:         add += testbench_sort_[i].shellSort(testbench_sort_[i].getVector(), false);break;
            default:                add += 0;   
        }

    
    return add/testbench_sort_.size();        
}


template<class T>
ostream& stadistical_t<T>::writeStadistical(ostream& os){

    os.precision(2);
    os << endl;
    os << setw(21) << "Número de comparaciones" << endl << endl;
    os << setw(21) << "Mínimo" << setw(10) <<  "Medio" << setw(10) <<  "Máximo" << endl;
    os << "Inserción" << setw(10) << fixed << getMin(InsertionSort) << setw(11) <<  getAvg(InsertionSort) << setw(9) <<  getMax(InsertionSort) << endl;
    os << "Burbuja" << setw(12) <<  getMin(BubbleSort) << setw(11) <<  getAvg(BubbleSort) << setw(9) <<  getMax(BubbleSort) << endl;
    os << "HeapSort" << setw(11) <<  getMin(HeapSort) << setw(11) <<  getAvg(HeapSort) << setw(9) <<  getMax(HeapSort) << endl;
    os << "QuickSort" << setw(10) <<  getMin(QuickSort) << setw(11) <<  getAvg(QuickSort) << setw(9) <<  getMax(QuickSort) << endl;
    os << "ShellSort" << setw(10) <<  getMin(ShellSort) << setw(11) <<  getAvg(ShellSort) << setw(9) <<  getMax(ShellSort) << endl;
    os << endl << "\t\t\t*********" << endl << endl << endl;    
    
    cin.ignore();
    
    return os;
    
}

#endif /* STADISTICAL_T_H */
