import random

def guess_number_game():
    secret_number = random.randint(1, 100)
    max_attempts = 10
    attempts = 0

    print("Я загадал число от 1 до 100. Попробуйте угадать его за 10 попыток!")

    while attempts < max_attempts:
        try:
            guess = int(input(f"Попытка {attempts + 1}: Введите ваше предположение: "))
        except ValueError:
            print("Ошибка: введите целое число.")
            continue

        if guess < 1 or guess > 100:
            print("Пожалуйста, введите число от 1 до 100.")
            continue

        attempts += 1

        if guess == secret_number:
            print(f"Поздравляю! Вы угадали число {secret_number} с {attempts}-й попытки.")
            break
        elif guess < secret_number:
            print("Слишком маленькое число.")
        else:
            print("Слишком большое число.")

    else:
        print(f"К сожалению, вы не угадали число. Было загадано: {secret_number}")

if __name__ == "__main__":
    guess_number_game()