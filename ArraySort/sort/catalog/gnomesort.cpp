#include "gnomesort.h"
#include <QList>

GnomeSort::GnomeSort()
{ // описание алгоритма
    this->title = "Гномья сортировка";
    this->shortDescription = "Алгоритм похож на сортировку вставками. Поддерживаем указатель на текущий элемент, если он больше предыдущего или он первый — смещаем указатель на позицию вправо, иначе меняем текущий и предыдущий элементы местами и смещаемся влево.";
    this->description = "Алгоритм находит первое место, где два соседних элемента стоят в неправильном порядке и меняет их местами. Он пользуется тем фактом, что обмен может породить новую пару, стоящую в неправильном порядке, только до или после переставленных элементов. Он не допускает, что элементы после текущей позиции отсортированы, таким образом, нужно только проверить позицию до переставленных элементов.";
    this->stepString = "O(n^2)";
    this->stepValue = "400"; // просто считаем эту фигню для 20 элементов. n^2 -> 20x20 = 400

    // шари алгоритма
    this->algoritm.append("Начинаем идти по массиву c нулевого элемента до n-1");
    this->algoritm.append("Если элемент i больше чем элемент i+1 меняем их местами");
    this->algoritm.append("Доходим до конца массива");
    this->algoritm.append("Повторяем действия n раз");

    this->source =
        "int i = 0;\n"
        "while (i < array.length()) {\n"
        "   if (i == 0 || array[i-1] <= array[i]) {\n"
        "      i++;\n"
        "   } else {\n"
        "       int tmp = array[i]; array[i] = array[i-1]; array[--i] = tmp;\n"
        "   }\n"
        "}";

    this->markers.append(SLOW_MARKER);
}
QList<QList<int>> GnomeSort::sort(QList<int> array) {
    QList<QList<int>> steps;
    // добавляем изначальное значение в шаги
    steps.append(cloneArray(array));
    int i = 0;
    while (i < array.length()) {
        if (i == 0 || array[i-1] <= array[i]) {
            i++;
        } else {
            int tmp = array[i]; array[i] = array[i-1]; array[--i] = tmp;
            //std::swap(array[i], array[i-1]);
        }
        steps.append(cloneArray(array));
    }
    return steps;
}
