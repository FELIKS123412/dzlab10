#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#define M_PI 3.14159265358979323846
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

double area_sector(double r);
void print_definition(void);
void draw_sector(int draw_r, char contr, char fill);
double compare_sectors(double s1, double s2);

void main() {
    setlocale(LC_ALL, "RUS");

    int vibor;
    int draw_r;
    double r, s;
    double r1, r2, s1, s2, diff;
    char fill, contr;

    do {
        printf("\nМеню операций для сектора круга:\n");
        printf("1 - Рассчитать площадь фигуры\n");
        printf("2 - Вывести определение фигуры\n");
        printf("3 - Нарисовать фигуру\n");
        printf("4 - Сравнить два сектора по площади\n");
        printf("0 - Выход\n");
        printf("Выберите операцию: ");

        if (scanf("%d", &vibor) ) {
            printf("Ошибка ввода!\n");
            
        }

        switch (vibor) {
        case 1:
            printf("Введите радиус сектора: ");
            scanf("%lf", &r);
            if (r < 0) {
                printf("Радиус не может быть отрицательным.\n");
            }
            else {
                s = area_sector(r);
                printf("Площадь сектора круга (45 градусов): %.2f\n", s);
            }
            break;

        case 2:
            print_definition();
            break;

        case 3:
            printf("Введите символ для контура фигуры: ");
            scanf(" %c", &contr);

            printf("Введите символ для внутренней закраски: ");
            scanf(" %c", &fill);

            printf("Введите размер фигуры (радиус): ");
            scanf("%d", &draw_r);

            if (draw_r < 2) {
                printf("Ошибка: размер должен быть не меньше 2.\n");
            }
            else {
                draw_sector(draw_r, contr, fill);
            }
            break;

        case 4:
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

            s1 = area_sector(r1);
            s2 = area_sector(r2);
            diff = compare_sectors(s1, s2);

            printf("Площадь 1-го сектора: %.2f\n", s1);
            printf("Площадь 2-го сектора: %.2f\n", s2);

            if (diff > 0) {
                printf("Первый сектор больше второго на %.2f\n", diff);
            }
            else if (diff < 0) {
                printf("Второй сектор больше первого на %.2f\n", -diff);
            }
            else {
                printf("Площади секторов равны.\n");
            }
            break;

        case 0:
            printf("Завершение программы.\n");
            break;

        default:
            printf("Неверный пункт меню, попробуйте снова.\n");
            break;
        }

    } while (vibor != 0);
}

double area_sector(double r) {
    return 0.125 * M_PI * r * r;
}

void print_definition(void) {
    printf("\n--- Определение фигуры ---\n");
    printf("Сектор круга — это часть круга, ограниченная дугой окружности\n");
    printf("и двумя радиусами (в данном случае: осью Y и прямой y = x,\n");
    printf("что составляет угол 45 градусов или пи/4 радиан).\n");
}

void draw_sector(int draw_r, char contr, char fill) {
    printf("\n");
    for (int y = draw_r; y >= -1; y--) {
        for (int x = -1; x <= draw_r; x++) {
            if (x == 0 && y >= 0 && y < draw_r) {
                printf("| ");
            }
            else if (x == 0 && y == draw_r) {
                printf("^ ");
            }
            else if (y == 0 && x > 0 && x < draw_r) {
                printf("--");
            }
            else if (y == 0 && x == draw_r) {
                printf("> ");
            }
            else if (x == 0 && y == 0) {
                printf("+ ");
            }
            else {
                if (x >= 0 && y >= 0) {
                    int r2 = x * x + y * y;
                    int a2 = draw_r * draw_r;

                    int acr = (abs(r2 - a2) <= draw_r);
                    int diagonal = (x == y);
                    int bound = (x == 0 && y <= draw_r);

                    if ((acr || diagonal || bound) && y >= x) {
                        printf("%c ", contr);
                        continue;
                    }

                    if (r2 < a2 && y > x) {
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

double compare_sectors(double s1, double s2) {
    return s1 - s2;
}