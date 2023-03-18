import random

number_list = [i for i in range(1,21)]

random_num = number_list[random.randint(1, 19)]
guess = 0
max_guesses = 3

running = True
while running and guess < max_guesses:
    user_num = input(f'Choose a number between 1 - 20 (You have {max_guesses - guess} guesses left): ')
    print(' ')

    if user_num == 'exit':
        break
   
    if int(user_num) == int(random_num):
        print('correct!\n')
        break

    elif user_num != random_num:
        if guess != 2:
            if int(user_num) > int(random_num):
                print('guess again, Aim lower\n')

            if int(user_num) < int(random_num):
                print('guess again, aim higher\n')
        else:
            print('HEHEHEHE. Ran out of guesses.') 
            break

        guess += 1



