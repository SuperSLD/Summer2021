#include "bubblesort.h"
#include <QList>

BubbleSort::BubbleSort() {
    // описание алгоритма
    this->title = "Сортировка пузырьком";
    this->shortDescription = "Самая обычная сортировка пузырьком, которой учат в школе.";
    this->description = "Будем идти по массиву слева направо. Если текущий элемент больше следующего, меняем их местами. Делаем так, пока массив не будет отсортирован. Заметим, что после первой итерации самый большой элемент будет находиться в конце массива, на правильном месте. После двух итераций на правильном месте будут стоять два наибольших элемента, и так далее. Очевидно, не более чем после n итераций массив будет отсортирован. Таким образом, асимптотика в худшем и среднем случае – O(n2), в лучшем случае – O(n).";
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
            "           // меняем элементы местами\n"
            "           std::swap(array[j], array[j + 1]);\n"
            "       }\n"
            "   }\n"
            "}";
}

/**
 * @brief BubbleSort::sort
 *
 * Реализация сортировки методом пузырька.
 *
 * @param array изначальный массив.
 * @return шари решения.
 */
QList<QList<int>> BubbleSort::sort(QList<int> array) {
    QList<QList<int>> steps;
    // добавляем изначальное значение в шаги
    steps.append(cloneArray(array));
    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < array.size() - i - 1; j++) {
            if (array[j+1] < array[j]) {
                std::swap(array[j], array[j + 1]);
            }
            // в конце итерации запоминаем изменения
            steps.append(cloneArray(array));
        }
    }
    return steps;
}
