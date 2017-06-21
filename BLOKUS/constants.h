#pragma once
#include <unistd.h>
#include <cstring>
enum BLOCKCOLOR{ BLUE, RED, GREEN, YELLOW, GRAY };
enum DIRECTION{ UP, DOWN, RIGHT, LEFT };

static const char* const my_strcat(const char* const str1,  const char* const str2){
    char* ret = new char[strlen(str1) + strlen(str2) + 1];
    strcpy(ret, str1);
    strcat(ret, str2);
    return ret;
}

const int MAX_X = 20;
const int MAX_Y = 20;
const char* const PIX_PATH = strcat(getcwd(NULL, 256), "/data");
const char* const PIX_BLUE = my_strcat(PIX_PATH, "/blue/blue.png");
const char* const PIX_BLUE_T = my_strcat(PIX_PATH, "/blue/blue_t.png");
const char* const PIX_BLUE_BLUE = my_strcat(PIX_PATH, "/blue/blue_blue.png");
const char* const PIX_BLUE_RED = my_strcat(PIX_PATH, "/blue/blue_red.png");
const char* const PIX_BLUE_GREEN = my_strcat(PIX_PATH, "/blue/blue_green.png");
const char* const PIX_BLUE_YELLOW = my_strcat(PIX_PATH, "/blue/blue_yellow.png");
const char* const PIX_RED = my_strcat(PIX_PATH, "/red/red.png");
const char* const PIX_RED_T = my_strcat(PIX_PATH, "/red/red_t.png");
const char* const PIX_RED_BLUE = my_strcat(PIX_PATH, "/red/red_blue.png");
const char* const PIX_RED_RED = my_strcat(PIX_PATH, "/red/red_red.png");
const char* const PIX_RED_GREEN = my_strcat(PIX_PATH, "/red/red_green.png");
const char* const PIX_RED_YELLOW = my_strcat(PIX_PATH, "/red/red_yellow.png");
const char* const PIX_GREEN = my_strcat(PIX_PATH, "/green/green.png");
const char* const PIX_GREEN_T = my_strcat(PIX_PATH, "/green/green_t.png");
const char* const PIX_GREEN_BLUE = my_strcat(PIX_PATH, "/green/green_blue.png");
const char* const PIX_GREEN_RED = my_strcat(PIX_PATH, "/green/green_red.png");
const char* const PIX_GREEN_GREEN = my_strcat(PIX_PATH, "/green/green_green.png");
const char* const PIX_GREEN_YELLOW = my_strcat(PIX_PATH, "/green/green_yellow.png");
const char* const PIX_YELLOW = my_strcat(PIX_PATH, "/yellow/yellow.png");
const char* const PIX_YELLOW_T = my_strcat(PIX_PATH, "/yellow/yellow_t.png");
const char* const PIX_YELLOW_BLUE = my_strcat(PIX_PATH, "/yellow/yellow_blue.png");
const char* const PIX_YELLOW_RED = my_strcat(PIX_PATH, "/yellow/yellow_red.png");
const char* const PIX_YELLOW_GREEN = my_strcat(PIX_PATH, "/yellow/yellow_green.png");
const char* const PIX_YELLOW_YELLOW = my_strcat(PIX_PATH, "/yellow/yellow_yellow.png");
const char* const PIX_GRAY = my_strcat(PIX_PATH , "/gray.png");

const int BLOCKSIZE = 21;
extern int turn;
