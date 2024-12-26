#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// Декларація функцій
void task_geom33(); // Завдання 1: Аналіз точок у геометричній фігурі
void task_14();     // Завдання 2: Обчислення суми ряду
void task_3();      // Завдання 3: Дослідження ряду на збіжність

// Функція для обчислення факторіала
long long factorial(int num) {
    if (num == 0 || num == 1) return 1;
    long long result = 1;
    for (int i = 2; i <= num; i++) {
        result *= i;
    }
    return result;
}

int main() {
    cout << "Task number: "; // Запит номера завдання
    int menu;
    cin >> menu;

    // Перемикання між завданнями
    switch (menu) {
        case 1: task_geom33(); break; // Завдання 1
        case 2: task_14(); break;    // Завдання 2
        case 3: task_3(); break;     // Завдання 3
        default: 
            cout << "Wrong task! (Only 1,2,3)" << endl; // Некоректний ввід
    }
    system("pause"); // Пауза перед завершенням програми
    return 0;
}

// Реалізація завдання 1: Перевірка точок у фігурі
void task_geom33() {
    float x, y, r; // Координати точки та радіус
    int n, count_in = 0; // Кількість точок та лічильник точок у фігурі

    cout << "Parameters r: "; // Введення радіуса
    cin >> r;
    if (!cin) { // Перевірка на коректність вводу
        cout << "Must be numeric!" << endl;
        cin.clear(); // Очищення потоку вводу
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Number of points n: "; // Введення кількості точок
    cin >> n;
    if (!cin || n <= 0) { // Перевірка коректності
        cout << "Must be a positive integer!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Цикл для перевірки кожної точки
    for (int i = 0; i < n; i++) {
        cout << "Point x, y: "; // Введення координат точки
        cin >> x >> y;
        if (!cin) { // Перевірка коректності
            cout << "Must be numeric!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Умови потрапляння точки в задані області
        if (x > 0 && y > r / sqrt(2) && x < r * sqrt(2) && y < r + r / sqrt(2))
            count_in++;
        else if (x > 0 && y < 0 && x < sqrt(2) * r && y > -r)
            count_in++;
    }

    cout << "Count points in region: " << count_in << endl; // Результат
}

// Реалізація завдання 2: Обчислення суми ряду
void task_14() {
    double x; // Вхідне число x
    int n;    // Натуральне число n
    cout << "Введіть значення x: ";
    cin >> x;
    cout << "Введіть значення n: ";
    cin >> n;

    double sum = 0; // Ініціалізація суми
    // Обчислення суми ряду
    for (int i = 1; i <= n; i++) {
        double term = pow(x, 2 * i - 1) / factorial(i + 2); // Член ряду
        sum += term;
    }
    cout << "Сума ряду: " << sum << endl;

    // Виведення окремих елементів ряду
    cout << "Елементи: ";
    if (n % 2 == 0) { // Парне n - кожен третій елемент
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) {
                double term = pow(x, 2 * i - 1) / factorial(i + 2);
                cout << term << " ";
            }
        }
    } else { // Непарне n - кожен четвертий елемент
        for (int i = 1; i <= n; i++) {
            if (i % 4 == 0) {
                double term = pow(x, 2 * i - 1) / factorial(i + 2);
                cout << term << " ";
            }
        }
    }
    cout << endl;
}

// Реалізація завдання 3: Дослідження ряду на збіжність
void task_3() {
    double x, epsilon, g; // Вхідні параметри
    cout << "Введіть значення x: ";
    cin >> x;
    cout << "Введіть значення epsilon (e): ";
    cin >> epsilon;
    cout << "Введіть значення g: ";
    cin >> g;

    // Перевірка коректності параметрів
    if (epsilon <= 0 || epsilon >= 1 || g <= 1) {
        cout << "Некоректні значення epsilon або g." << endl;
        return;
    }

    double sum = 0; // Ініціалізація суми
    double term;    // Поточний член ряду
    int n = 1;      // Лічильник ітерацій

    // Цикл обчислення ряду
    while (true) {
        term = (pow(x, n - 1) + 3 * n) / factorial(2 * n - 1); // Член ряду
        if (fabs(term) < epsilon) { // Перевірка на збіжність
            cout << "Ряд збігається. Сума: " << sum << endl;
            break;
        }
        if (fabs(term) > g) { // Перевірка на розбіжність
            cout << "Ряд розбігається. Переривання обчислень." << endl;
            break;
        }

        sum += term; // Додавання члена до суми
        n++;         // Перехід до наступного члена
    }
}

