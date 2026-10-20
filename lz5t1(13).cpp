#include <iostream>
#include <string>

using namespace std;

// Структура Price, що представляє товар
struct Price {
    string productName;
    string manufacturer;
    double cost;
    int size[5]; // Масив з п'яти розмірів
};

int main() {
    const int numPrices = 8;
    Price prices[numPrices];

    // Введення даних в масив товарів за допомогою вказівників на структуру
    for (int i = 0; i < numPrices; i++) {
        Price* ptr = &prices[i]; // Вказівник на структуру Price

        cout << "Введіть дані для товару " << i + 1 << ":" << endl;
        cout << "Назва товару: ";
        cin >> ptr->productName;
        cout << "Назва фірми-виробника: ";
        cin >> ptr->manufacturer;
        cout << "Вартість товару: ";
        cin >> ptr->cost;
        cout << "Розміри (5 значень через пробіл): ";
        for (int j = 0; j < 5; j++) {
            cin >> ptr->size[j];
        }
    }

    // Впорядкування записів у масиві за спаданням вартості
    for (int i = 0; i < numPrices - 1; i++) {
        for (int j = i + 1; j < numPrices; j++) {
            if (prices[i].cost < prices[j].cost) {
                // Обмін елементів місцями за допомогою вказівників
                Price temp = prices[i];
                prices[i] = prices[j];
                prices[j] = temp;
            }
        }
    }

   // Виведення впорядкованого списку товарів
 cout << "Список товарів після сортування за спаданням вартості:" << endl;
    for (int i = 0; i < numPrices; i++) {
        cout << "Назва: " << prices[i].productName << ", Фірма: " << prices[i].manufacturer << ", Ціна: " << prices[i].cost << " грн, Розміри: " << prices[i].size[0] << ", " << prices[i].size[1] << ", " << prices[i].size[2] << ", " << prices[i].size[3] << ", " << prices[i].size[4] << endl;
    }

    // Введення даних для пошуку (згідно з умовою завдання 13)
    string searchName;
    int searchSize;
    cout << "Введіть назву товару: ";
    cin >> searchName;
    cout << "Введіть розмір: ";
    cin >> searchSize;

    // Виведення даних про товар, назва і розмір якого вводиться з клавіатури
cout << "Виведення даних про товар:" << endl;
bool found = false;
    for (int i = 0; i < numPrices; i++) {
        // Перевіряємо, чи є потрібний розмір у масиві розмірів конкретного товару
        bool hasSize = false;
        for (int j = 0; j < 5; j++) {
            if (prices[i].size[j] == searchSize) {
                hasSize = true;
            }
        }

        if (prices[i].productName == searchName && hasSize) {
            cout << "Назва: " << prices[i].productName << ", Фірма: " << prices[i].manufacturer << ", Вартість: " << prices[i].cost << " грн" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Такого товару немає." << endl;
    }

    return 0;
}