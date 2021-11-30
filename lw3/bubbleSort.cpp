#include <iostream>
#include <ctime>

using namespace std;

// bubbleSort - сортировка пузырьком
void bubbleSort(int arr[], int size)
{   
    // первым циклом мы проходим по всем индексам массива
    for (int step = 0; step < size-1; ++step){
        // вторым циклом мы проходима по всем индексам
        // которые идут после того, до которого мы дошли
        // предыдущим циклом
        for (int i = step+1; i < size; ++i){
            // проверяем соседние элементы
            // если более левый элемент
            // больше правого
            // то они меняются местами
            if (arr[i] < arr[step]){
                int temp = arr[i];
                arr[i] = arr[step];
                arr[step] = temp;
            }
        }
    }
}

// printArray - вывод массива в консоль
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// findElement - линейный поиск элементы
int findElement(int array[], int n, int el) {
    for (int i = 0; i < n; i++) {
        if (array[i] == el) {
            return i;
        }
    }
    return -1;
}

int findBinary(int arr[], int n, int key){
    bool flag = false;
    int l = 0; // левая граница
    int r = n-1; // правая граница
    int mid;
 
    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2; // находим индекс посередине границ
        if (arr[mid] == key) { // проверяем значение серединного индекса
            flag = true; 
        }
        if (arr[mid] > key) { // находим, какую часть надо отбросить
            r = mid - 1; 
        } else {
            l = mid + 1;
        }
    }
    
    if (flag) {
        return mid;
    }
    return -1;
}

int main()
{   
    srand(time(0));

    // инициализируем массив
    int array [1000] = {};
    
    // в цикле наполняем массив случайными числами
    for (int i = 0; i < 1000; i++) {
        array[i] = rand() % 4000 - 2000;
    }
    
    // находим длину массиву
    int n = sizeof(array)/sizeof(array[0]);
    
    // инициализируем переменную ключа (элемент, который мы будем искать в массиве)
    int key;

    // иницилизируем переменную, где мы будем хранить результаты поиска
    int result;
    
    // вызываем фунцию пузырьковой сортировки
    bubbleSort(array, n);
    // printArray(array, n);
    
    // генерируем случайное значение, которое будем искать
    // и выводим его в консоль
    key = rand() % 4000 - 2000;
    cout << "Key for linear search is: " << key << endl;

    // инициализируем переменную где мы храним время начала работы цикла
    int start_time = clock();
    for (int i = 0; i < 1000000; i++)
    {
        result = findElement(array, n, key);
    }
    int end_time = clock();

    // выводим результат в консоль
    cout << "Result: " << result << endl;
    // количество полученных тиков делим на количество процессорным тиков в секунду
    // и получаем время выполняния цикла в секундах, сразу выводя его в консоль
    cout << "Executio n time: " << (double(end_time - start_time)) / CLOCKS_PER_SEC << endl;
    
    // выполняем те же операции для бинарного поиска
    key = rand() % 4000 - 2000;
    cout << "Key for binary search is: " << key << endl;

    start_time = clock();
    for (int i = 0; i < 1000000; i++)
    {
    result = findBinary(array, n, key);
    }
    end_time = clock();

    cout << "Result: " << result << endl;
    cout << "Execution time: " << (double(end_time - start_time)) / CLOCKS_PER_SEC << endl;
}