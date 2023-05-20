#include "Menu.h"
#include "Name.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void winner(CodeUnits* code_units)
{
    if (code_units->current_player == 1) {
        printf("Игра окончена. Победитель: %s\n", code_units->player_one);
        return;
    } else {
        printf("Игра окончена. Победитель: %s\n", code_units->player_two);
        return;
    }
}

int take(CodeUnits* code_units)
{
    int take = 0;
    char num[255] = {0};
    int max = code_units->match > 10 ? 10 : code_units->match;
    if (code_units->current_player == 1) {
        printf("Ход игрока: %s\n", code_units->player_one);
    } else {
        printf("Ход игрока: %s\n", code_units->player_two);
    }
    printf("Спичек в куче: %d, Введите сколько спичек вы хотите забрать от "
           "1 до %d: ",
           code_units->match,
           max);
    name_read(num);
    take = atoi(num);
    while (take < 1 || take == 0 || take > max) {
        printf("\nНекорректный ввод, повторите попытку: ");
        name_read(num);
        take = atoi(num);
    }
    return take;
}

void Game_start()
{
    int mode = 0;
    char mode_char[255] = {0};
    char player_one[255] = {0};
    char player_two[255] = {0};
    char bot_name_ez[] = "ИИ-легкий";
    char bot_name_hard[] = "ИИ-нормальный";
    printf("Выберите режим игры. Введите цифру от 1 до 2\n");
    printf("1.уровень сложности-легкий\n 2.уровень сложности-нормальный\n");
    name_read(mode_char);
    mode = atoi(mode_char);
    while (mode < 1 || mode > 2 || mode == 0) {
        printf("\nНекорректный ввод, повторите попытку: ");
        name_read(mode_char);
        mode = atoi(mode_char);
    }
    
    if (mode == 1) {
        printf("Вы выбрали уровень сложности-легкий\n");
        printf("Введите имя игрока(не более 254 символов): ");
       name_read(player_one);
        strcpy(player_two, bot_name_ez);
    }
    if (mode == 2) {
        printf("Вы выбрали уровень сложности-нормальный\n");
        printf("Введите имя игрока(не более 254 символов): ");
        name_read(player_one);
        strcpy(player_two, bot_name_hard);
    }
    printf("\nИгра началась\n");
    CodeUnits* game = creates_game(mode, player_one, player_two);
    while (!is_end(game)) {
        int t = take(game);
        step(t, game);
    }
    winner(game);
}