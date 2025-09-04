import math

def get_positive_integer():
    while True:
        user_input = input("Введите положительное целое число: ")
        if not user_input.isdigit():
            print("Ошибка: введено не число или нецелое число. Попробуйте снова.")
            continue
        number = int(user_input)
        if number <= 0:
            print("Ошибка: число должно быть положительным. Попробуйте снова.")
            continue
        return number

def factorial(n):
    # Используем оптимизированную функцию из библиотеки math
    return math.factorial(n)

def main():
    n = get_positive_integer()
    result = factorial(n)
    print(f"Факториал числа {n} равен {result}")

if __name__ == "__main__":
    main()