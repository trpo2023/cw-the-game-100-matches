#ifndef game_common_h
#define game_common_H

typedef struct {
    int match;
    char* player_one;
    char* player_two;
    int current_player;
    int mode;
} CodeUnits;

void step(int take, CodeUnits* code_units);
int is_end(CodeUnits* code_units);
CodeUnits* creates_game(int mode, char* p1, char* p2);

#endif