#include "quicksort.h"
#include <QList>
#include <iostream>


QuickSort::QuickSort(){
    // описание алгоритма
    this->title = "Быстрая сортировка";
    this->shortDescription = "Быстрая сортировка представляет собой усовершенствованный метод сортировки, основанный на принципе обмена. Пузырьковая сортировка является самой неэффективной из всех алгоритмов прямой сортировки. Однако усовершенствованный алгоритм является лучшим из известных методом сортировки массивов. Он обладает столь блестящими характеристиками, что его изобретатель Ч. Хоар назвал его быстрой сортировкой.";
    this->description = "Этот алгоритм состоит из трёх шагов. Сначала из массива нужно выбрать один элемент — его обычно называют опорным. Затем другие элементы в массиве перераспределяют так, чтобы элементы меньше опорного оказались до него, а большие или равные — после. А дальше рекурсивно применяют первые два шага к подмассивам справа и слева от опорного значения. \n Быструю сортировку изобрели в 1960 году для машинного перевода: тогда словари хранились на магнитных лентах, а сортировка слов обрабатываемого текста позволяла получить переводы за один прогон ленты, без перемотки назад.";
    this->stepString = "O(n log n)";
    this->stepValue = "26"; // просто считаем эту фигню для 20 элементов. n^log n -> 20^1,3 = 26

    // шари алгоритма
    this->algoritm.append("1. Выбрать элемент из массива. Назовём его опорным.");
    this->algoritm.append("2. Разбиение: перераспределение элементов в массиве таким образом, что элементы, меньшие опорного, помещаются перед ним, а большие или равные - после.");
    this->algoritm.append("3. Рекурсивно применить первые два шага к двум подмассивам слева и справа от опорного элемента. Рекурсия не применяется к массиву, в котором только один элемент или отсутствуют элементы.");

    this->source =
      "int pivot;\n"
      "int l_hold = left;\n"
      "int r_hold = right;\n"
      "pivot = numbers[left];\n"
      "while (left < right) {\n"
      "    while ((numbers[right] >= pivot) && (left < right)) {\n"
      "        right--;\n"
      "    }\n"
      "    if (left != right) {\n"
      "        numbers[left] = numbers[right];\n"
      "        left++;\n"
      "    }\n"
      "    while ((numbers[left] <= pivot) && (left < right)) {\n"
      "         left++;\n"
      "    }\n"
      "    if (left != right) {\n"
      "        numbers[right] = numbers[left];\n"
      "        right--;\n"
      "    }\n"
      "    steps->append(cloneArray(fullMass, steps->first().size()));\n"
      "}\n"
      "numbers[left] = pivot;\n"
      "steps->append(cloneArray(fullMass, steps->first().size()));\n"
      "pivot = left;\n"
      "left = l_hold;\n"
      "right = r_hold;\n"
      "if (left < pivot)\n"
      "    qsortRecursive(steps, fullMass, numbers, left, pivot - 1)\n;"
      "if (right > pivot)\n"
      "    qsortRecursive(steps, fullMass, numbers, pivot + 1, right);";

    this->nominations.append(COOL_NOMINATION);
    this->nominations.append(FAST_NOMINATION);
    this->nominations.append(RECURSION_NOMINATION);

}

QList<QList<int>> QuickSort::sort(QList<int> array) {
    QList<QList<int>> steps;
    // добавляем изначальное значение в шаги
    steps.append(cloneArray(array));
    int mas[array.size()];
    qDebug("start sort");
    for (int i = 0; i < array.size(); i++) {
        mas[i] = array[i];
    }
    qsortRecursive(&steps, mas, mas, 0, array.size() - 1);
    return steps;
}

void QuickSort::qsortRecursive(QList<QList<int>> *steps, int *fullMass, int *numbers, int left, int right) {
      int pivot;
      int l_hold = left;
      int r_hold = right;
      pivot = numbers[left];
      while (left < right) {
            while ((numbers[right] >= pivot) && (left < right)) {
                right--;
            }
            if (left != right) {
                numbers[left] = numbers[right];
                left++;
            }
            while ((numbers[left] <= pivot) && (left < right)) {
                left++;
            }
            if (left != right) {
                numbers[right] = numbers[left];
                right--;
            }
            steps->append(cloneArray(fullMass, steps->first().size()));
      }
      numbers[left] = pivot;
      steps->append(cloneArray(fullMass, steps->first().size()));
      pivot = left;
      left = l_hold;
      right = r_hold;
      if (left < pivot)
            qsortRecursive(steps, fullMass, numbers, left, pivot - 1);
      if (right > pivot)
            qsortRecursive(steps, fullMass, numbers, pivot + 1, right);
}
