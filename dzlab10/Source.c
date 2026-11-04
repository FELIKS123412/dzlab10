#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#define M_PI 3.14159265358979323846
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void main()
{
    setlocale(LC_ALL, "RUS");

    int choice;
    int go = 1;

    do {
        printf("\n================ M E N U ================\n");
        printf("1. Рассчитать площадь сектора\n");
        printf("2. Вывести определение фигуры\n");
        printf("3. Нарисовать фигуру\n");
        printf("4. Сравнить два сектора по площади\n");
        printf("5. Выход\n");
        printf("Выберите пункт меню (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода!\n");
            break;
        }

        switch (choice)
        {
        case 1:
        {
            double r;
            printf("Введите радиус сектора: ");
            scanf("%lf", &r);
            if (r < 0) {
                printf("Радиус не может быть отрицательным.\n");
            }
            else {
                double area = 0.125 * M_PI * r * r;
                printf("Площадь сектора круга (45 градусов): %.2f\n", area);
            }
            break;
        }
        case 2:
        {
            printf("\n--- Определение фигуры ---\n");
            printf("Сектор круга — это часть круга, ограниченная дугой окружности\n");
            printf("и двумя радиусами (в данном случае: осью Y и прямой y = x,\n");
            printf("что составляет угол 45 градусов или пи/4 радиан).\n");
            break;
        }
        case 3:
        {
            char fill;
            char contr;
            int a;

            printf("Введите символ для контура фигуры: ");
            scanf(" %c", &contr);

            printf("Введите символ для внутренней закраски: ");
            scanf(" %c", &fill);

            printf("Введите размер фигуры (радиус): ");
            scanf("%d", &a);

            if (a < 2)
            {
                printf("Ошибка: размер должен быть не меньше 2.\n");
            }
            else
            {
                printf("\n");
                for (int y = a; y >= -1; y--)
                {
                    for (int x = -1; x <= a; x++)
                    {
                        if (x == 0 && y >= 0 && y < a)
                        {
                            printf("| ");
                        }
                        else if (x == 0 && y == a)
                        {
                            printf("^ ");
                        }
                        else if (y == 0 && x > 0 && x < a)
                        {
                            printf("--");
                        }
                        else if (y == 0 && x == a)
                        {
                            printf("> ");
                        }
                        else if (x == 0 && y == 0)
                        {
                            printf("+ ");
                        }
                        else
                        {
                            if (x >= 0 && y >= 0)
                            {
                                int r2 = x * x + y * y;
                                int a2 = a * a;

                                int acr = (abs(r2 - a2) <= a);
                                int diagonal = (x == y);
                                int bound = (x == 0 && y <= a);

                                if ((acr || diagonal || bound) && y >= x)
                                {
                                    printf("%c ", contr);
                                    continue;
                                }

                                if (r2 < a2 && y > x)
                                {
                                    printf("%c ", fill);
                                    continue;
                                }
                            }

                            printf("  ");
                        }
                    }
                    printf("\n");
                }
            }
            break;
        }
        case 4:
        {
            double r1, r2;
            printf("--- Первый сектор ---\n");
            printf("Введите радиус: ");
            scanf("%lf", &r1);

            printf("--- Второй сектор ---\n");
            printf("Введите радиус: ");
            scanf("%lf", &r2);

            if (r1 < 0 || r2 < 0) {
                printf("Радиус не может быть отрицательным.\n");
                break;
            }

            double area1 = 0.125 * M_PI * r1 * r1;
            double area2 = 0.125 * M_PI * r2 * r2;

            printf("Площадь 1-го сектора: %.2f\n", area1);
            printf("Площадь 2-го сектора: %.2f\n", area2);

            if (area1 > area2) {
                printf("Первый сектор больше по площади.\n");
            }
            else if (area2 > area1) {
                printf("Второй сектор больше по площади.\n");
            }
            else {
                printf("Площади секторов равны.\n");
            }
            break;
        }
        case 5:
        {
            printf("Выход из программы...\n");
            go = 0;
            break;
        }
        default:
        {
            printf("Неверный выбор! Пожалуйста, выберите от 1 до 5.\n");
        }
        }

    } while (go != 0);
}