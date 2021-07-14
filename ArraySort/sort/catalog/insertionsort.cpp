#include "insertionsort.h"
#include <QList>

InsertionSort::InsertionSort()
{
    // описание алгоритма
    this->title = "Сортировка вставками";
    this->shortDescription = "При сортировке вставками массив постепенно перебирается слева направо. При этом каждый последующий элемент размещается так, чтобы он оказался между ближайшими элементами с минимальным и максимальным значением.";
    this->description = "Создадим массив, в котором после завершения алгоритма будет лежать ответ. Будем поочередно вставлять элементы из исходного массива так, чтобы элементы в массиве-ответе всегда были отсортированы. Асимптотика в среднем и худшем случае – O(n2), в лучшем – O(n). Реализовывать алгоритм удобнее по-другому (создавать новый массив и реально что-то вставлять в него относительно сложно): просто сделаем так, чтобы отсортирован был некоторый префикс исходного массива, вместо вставки будем менять текущий элемент с предыдущим, пока они стоят в неправильном порядке.";


    this->stepString = "O(n^2)";
    this->stepValue = "400"; // просто считаем эту фигню для 20 элементов. n^2 -> 20x20 = 400

    // шари алгоритма
    this->algoritm.append("Начинаем идти по массиву c нулевого элемента до n-1");
    this->algoritm.append("Если элемент i больше чем элемент i+1 меняем их местами");
    this->algoritm.append("Доходим до конца массива");
    this->algoritm.append("Повторяем действия n раз");

    // код алгоритма
    this->source =
            "for (int i = 0; i < array.size(); i++) {\n"
            "   for (int j = 0; j < array.size() - i - 1; j++) {\n"
            "       if (array[j+1] < array[j]) {\n"
            "           std::swap(array[j], array[j + 1]);\n"
            "       }\n"
            "   }\n"
            "}";
}

QList<QList<int>> InsertionSort::sort(QList<int> array) {
    QList<QList<int>> steps;
    // добавляем изначальное значение в шаги
    steps.append(cloneArray(array));
    for (size_t i = 1; i < array.size(); ++i) {
       int x = array[i];
       size_t j = i;
       while (j > 0 && array[j - 1] > x) {
         array[j] = array[j - 1];
         --j;
          steps.append(cloneArray(array));
       }
       array[j] = x;
        steps.append(cloneArray(array));
     }
    return steps;
}
