#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Tamaño máximo de la pila

double stack[MAX]; // Pila para los números
int top = -1;      // Índice del tope de la pila

// Función para agregar un número a la pila
void push(double num)
{
    if (top < MAX - 1)
    {
        stack[++top] = num;
    }
    else
    {
        printf("Error: Pila llena\n");
    }
}

// Función para sacar un número de la pila
double pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    else
    {
        printf("Error: Pila vacía\n");
        return 0;
    }
}

// Función para mostrar la pila
void mostrarPila()
{
    printf("Pila: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%.2f ", stack[i]);
    }
    printf("\n");
}

int main()
{
    char input[20];

    printf("Calculadora RPN (escribe 'q' para salir)\n");

    while (1)
    {
        printf("> ");
        scanf("%s", input);

        // Si el usuario escribe 'q', salir
        if (input[0] == 'q')
        {
            break;
        }

        // Si es un número, convertir y agregar a la pila
        if (sscanf(input, "%lf", &stack[top + 1]) == 1)
        {
            push(stack[top + 1]);
        }
        // Operaciones básicas
        else if (input[0] == '+' && top > 0)
        {
            push(pop() + pop());
        }
        else if (input[0] == '-' && top > 0)
        {
            double b = pop(), a = pop();
            push(a - b);
        }
        else if (input[0] == '*' && top > 0)
        {
            push(pop() * pop());
        }
        else if (input[0] == '/' && top > 0)
        {
            double b = pop();
            if (b != 0)
            {
                double a = pop();
                push(a / b);
            }
            else
            {
                printf("Error: División por cero\n");
                push(b);
            }
        }
        else
        {
            printf("Entrada inválida\n");
        }

        // Mostrar la pila después de cada operación
        mostrarPila();
    }

    printf("Saliendo...\n");
    return 0;
}
