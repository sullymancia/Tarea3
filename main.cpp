#include "Test.h"
#include <iostream>
using namespace std;

//Padre = (Izquierda - 1) / 2 ->impar
//Padre = (derecha - 2) / 2 - > Par


//Reemplazo
vector<int> replace(vector<int> min_heap, int replaced_value, int replacement{
    int index = search_replaced_value(min_heap, replaced_value);

        min_heap[index] = replacement;

            return heapify(min_heap, index);
}

//Swap
vector<int> swap(vector<int> min_heap, int current_index, int padre_posi){
     int temp = 0;

    temp = min_heap[current_index];

        min_heap[current_index] = min_heap[padre_posi];

            min_heap[padre_posi] = temp;

    return min_heap;
}

int get_smallest_children_index(vector<int> min_heap, int index){
    int right_index = index*2 + 2;
    int left_index = index*2 + 1;
    int right_son = min_heap[right_index];
    int left_son = min_heap[left_index];

    return right_son > left_son ? left_index : right_index;
}

//Ir a la posicion del padre
int get_padre_posi(int current_index){
    int direction = current_index % 2;
    int padre_posi = 0;

    return direction != 0 ? (current_index - 1) / 2 : (current_index - 2) / 2;
}

// Buscar valor reemplazado
int search_replaced_value(vector<int> min_heap, int replaced_value){
    for(int i = 0; i < min_heap.size(); i++)
    {
        if(min_heap[i] == replaced_value)
            return i;
    }

    return -1;
}

//Si es Menor que el padre
bool less_than_father(vector<int> min_heap, int index){
    int direction = index % 2;

    if(direction == 0 && min_heap[index] < min_heap[(index - 2) / 2])
        return true;

    else

    if(direction != 0 && min_heap[index] < min_heap[(index - 1) / 2])
        return true;

    return false;
}

bool is_leaf(vector<int> min_heap, int index){
    int left = index*2 + 1;
    if(left > min_heap.size() - 1)
        return true;

    return false;
}

//Balanceo o nuevo ordenamiento de los monticulos
vector<int> heapify(vector<int> min_heap, int index){
    if(index > 0){

        if(less_than_father(min_heap, index)){
            int padre_posi = get_padre_posi(index);
            return heapify(swap(min_heap, index, padre_posi), padre_posi);
        }

        else{
            if(is_leaf(min_heap, index)) return min_heap;

            int child_index = get_smallest_children_index(min_heap, index);
            if(min_heap[child_index] < min_heap[index])
                return heapify(swap(min_heap, index, child_index), child_index);

            return min_heap;
        }
    }

    else
    {
        if(is_leaf(min_heap, index)) return min_heap;

        int child_index = get_smallest_children_index(min_heap, index);
        if(min_heap[child_index] < min_heap[index])
            return heapify(swap(min_heap, index, child_index), child_index);

        return min_heap;
    }
}

int main ()
{
    test();
    return 0;
}
