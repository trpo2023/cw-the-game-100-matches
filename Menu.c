#include "Menu.h"
#include "Name.h"
#include "Game.h"
#include <stdio.h>
#include <stdlib.h>

void start()
{
char graphic_mode[255] = {0};
int graphic_mode_int = 0;
printf("Добро пожаловать в игру 100 спичек.\n");
printf("Описание игры: это игра, целью которой является не дать противнику забрать последнюю спичку.\n Игроки по очереди берут из общей кучки спички, не превышая при этом количество, равное десяти \n Кто забрал последнюю спичку, тот и выиграл.\n");

name_read(graphic_mode);
graphic_mode_int = atoi(graphic_mode);

Game_start();
}
