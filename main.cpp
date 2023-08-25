#include <iostream>
using namespace std;

void print(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << "[" << arr[i] << "]";
    }
    cout << endl;
}

void Merge(int datos[], int inicio, int fin) {
    int size = fin - inicio + 1;
    int temp[size];
    int centro = (inicio + fin) / 2;
    int j = inicio;
    int k = centro + 1;
    for(int i = 0; i < size; i++) {
        if (j <= centro && k <= fin) {
            if (datos[j] < datos[k]) {
                temp[i] = datos[j++];
            }
            else {
                temp[i] = datos[k++];
            }
        }
        else {
            if (j <= centro) {
                temp[i] = datos[j++];
            }
            else {
                temp[i] = datos[k++];
            }
        }
    }
    for(int i = 0; i < size; i++) {
        datos[inicio + i] = temp[i];
    }
}

void MergeSort(int datos[], int inicio, int fin) {
    if (inicio < fin) {
        int centro = (inicio + fin) / 2;
        MergeSort(datos, inicio, centro);
        MergeSort(datos, centro + 1, fin);
        Merge(datos, inicio, fin);
    }
}

int main() {
    int datos[] = {5, 2, 9, 1, 7};
    int n = sizeof(datos) / sizeof(datos[0]);

    MergeSort(datos, 0, n - 1);
    print(datos, n);

    return 0;
}
