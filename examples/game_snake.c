/*
 * game_snake: Classic snake game, ported from PixelSnake by QuantumCoderrr.
 * https://github.com/QuantumCoderrr/PixelSnake
 *
 * A real game running on our SDL2 AmigaOS 3.x port.
 * Uses: SDL_Renderer (FillRect, DrawLine), input (arrow keys),
 *       timer (SDL_GetTicks, SDL_Delay).
 * No external assets -- all rendering via colored rectangles and
 * a built-in 5x3 pixel digit font.
 *
 * Controls: Arrow keys to move, P to pause, R to restart, ESC to quit.
 *
 * Original: MIT license, QuantumCoderrr/PixelSnake
 * amiport: adapted for AmigaOS 3.x / SDL2 port
 */

#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"

/* amiport: AmigaOS version string and stack */
static const char *verstag = "$VER: game_snake 1.0 (28.03.2026)";
long __stack = 32768;

#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 240
#define GRID_SIZE 10
#define GRID_WIDTH (WINDOW_WIDTH / GRID_SIZE)
#define GRID_HEIGHT (WINDOW_HEIGHT / GRID_SIZE)
#define MAX_FRAMES_IDLE 9000 /* auto-exit after ~3 min idle at 50fps */

/* Digit patterns for score display (5x3 pixel font) */
static const int DIGIT_WIDTH = 3;
static const int DIGIT_HEIGHT = 5;
static const int DIGITS[10][5][3] = {
    {{1,1,1},{1,0,1},{1,0,1},{1,0,1},{1,1,1}}, /* 0 */
    {{0,1,0},{1,1,0},{0,1,0},{0,1,0},{1,1,1}}, /* 1 */
    {{1,1,1},{0,0,1},{1,1,1},{1,0,0},{1,1,1}}, /* 2 */
    {{1,1,1},{0,0,1},{1,1,1},{0,0,1},{1,1,1}}, /* 3 */
    {{1,0,1},{1,0,1},{1,1,1},{0,0,1},{0,0,1}}, /* 4 */
    {{1,1,1},{1,0,0},{1,1,1},{0,0,1},{1,1,1}}, /* 5 */
    {{1,1,1},{1,0,0},{1,1,1},{1,0,1},{1,1,1}}, /* 6 */
    {{1,1,1},{0,0,1},{0,1,0},{1,0,0},{1,0,0}}, /* 7 */
    {{1,1,1},{1,0,1},{1,1,1},{1,0,1},{1,1,1}}, /* 8 */
    {{1,1,1},{1,0,1},{1,1,1},{0,0,1},{1,1,1}}  /* 9 */
};

typedef struct {
    int x, y;
} Point;

typedef struct Node {
    Point pos;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    Point dir;
    int length;
} Snake;

typedef struct {
    Snake snake;
    Point food;
    int score;
    int speed_x10;  /* amiport: integer speed * 10, avoids float */
    int move_timer_ms;
    int paused;
    int game_over;
} Game;

static void initSnake(Snake *snake)
{
    Node *node = (Node *)SDL_malloc(sizeof(Node));
    node->pos.x = GRID_WIDTH / 2;
    node->pos.y = GRID_HEIGHT / 2;
    node->next = NULL;
    snake->head = node;
    snake->tail = node;
    snake->dir.x = 1;
    snake->dir.y = 0;
    snake->length = 1;
}

static void freeSnake(Snake *snake)
{
    Node *current = snake->head;
    while (current) {
        Node *next = current->next;
        SDL_free(current);
        current = next;
    }
    snake->head = NULL;
    snake->tail = NULL;
    snake->length = 0;
}

static int pointEquals(Point a, Point b)
{
    return a.x == b.x && a.y == b.y;
}

static int isOnSnake(Snake *snake, Point p)
{
    Node *current = snake->head;
    while (current) {
        if (pointEquals(current->pos, p))
            return 1;
        current = current->next;
    }
    return 0;
}

/* amiport: simple LCG random to avoid libnix rand() seed issues */
static Uint32 rng_state;

static void rng_seed(Uint32 seed)
{
    rng_state = seed;
}

static int rng_next(int modulus)
{
    rng_state = rng_state * 1103515245 + 12345;
    return (int)((rng_state >> 16) % (Uint32)modulus);
}

static void placeFood(Game *game)
{
    Point p;
    do {
        p.x = rng_next(GRID_WIDTH);
        p.y = rng_next(GRID_HEIGHT);
    } while (isOnSnake(&game->snake, p));
    game->food = p;
}

static void resetGame(Game *game)
{
    if (game->snake.head != NULL) {
        freeSnake(&game->snake);
    }
    initSnake(&game->snake);
    placeFood(game);
    game->score = 0;
    game->speed_x10 = 50;  /* 5.0 moves/sec */
    game->move_timer_ms = 0;
    game->paused = 0;
    game->game_over = 0;
}

static void addHead(Snake *snake, Point newPos)
{
    Node *node = (Node *)SDL_malloc(sizeof(Node));
    node->pos = newPos;
    node->next = snake->head;
    snake->head = node;
    if (snake->length == 0)
        snake->tail = node;
    snake->length++;
}

static void removeTail(Snake *snake)
{
    Node *current;
    if (!snake->head)
        return;
    if (snake->head == snake->tail) {
        SDL_free(snake->tail);
        snake->head = snake->tail = NULL;
        snake->length = 0;
        return;
    }
    current = snake->head;
    while (current->next != snake->tail) {
        current = current->next;
    }
    SDL_free(snake->tail);
    snake->tail = current;
    snake->tail->next = NULL;
    snake->length--;
}

static int handleInput(Game *game, SDL_Event *e)
{
    if (e->type == SDL_QUIT)
        return 1;

    if (e->type == SDL_KEYDOWN) {
        SDL_Keycode sym = e->key.keysym.sym;

        /* amiport: ESC to quit */
        if (sym == SDLK_ESCAPE)
            return 1;

        if (game->game_over && sym == SDLK_r) {
            resetGame(game);
            return 0;
        }
        switch (sym) {
            case SDLK_UP:
                if (game->snake.dir.y != 1) {
                    game->snake.dir.x = 0;
                    game->snake.dir.y = -1;
                }
                break;
            case SDLK_DOWN:
                if (game->snake.dir.y != -1) {
                    game->snake.dir.x = 0;
                    game->snake.dir.y = 1;
                }
                break;
            case SDLK_LEFT:
                if (game->snake.dir.x != 1) {
                    game->snake.dir.x = -1;
                    game->snake.dir.y = 0;
                }
                break;
            case SDLK_RIGHT:
                if (game->snake.dir.x != -1) {
                    game->snake.dir.x = 1;
                    game->snake.dir.y = 0;
                }
                break;
            case SDLK_p:
                game->paused = !game->paused;
                break;
            default:
                break;
        }
    }
    return 0;
}

static void updateGame(Game *game, Uint32 delta_ms)
{
    int interval_ms;
    Point newHead;

    if (game->paused || game->game_over)
        return;

    game->move_timer_ms += (int)delta_ms;

    /* amiport: integer arithmetic for move interval
     * interval = 1000 / (speed_x10 / 10) = 10000 / speed_x10 */
    interval_ms = 10000 / game->speed_x10;

    if (game->move_timer_ms >= interval_ms) {
        game->move_timer_ms -= interval_ms;

        newHead.x = game->snake.head->pos.x + game->snake.dir.x;
        newHead.y = game->snake.head->pos.y + game->snake.dir.y;

        /* Wall or self collision -> game over */
        if (newHead.x < 0 || newHead.x >= GRID_WIDTH ||
            newHead.y < 0 || newHead.y >= GRID_HEIGHT ||
            isOnSnake(&game->snake, newHead)) {
            game->game_over = 1;
            return;
        }

        addHead(&game->snake, newHead);

        if (pointEquals(newHead, game->food)) {
            game->score++;
            /* Speed up every 5 points */
            if (game->score % 5 == 0)
                game->speed_x10 += 10; /* +1.0 moves/sec */
            placeFood(game);
        } else {
            removeTail(&game->snake);
        }
    }
}

static void drawPixel(SDL_Renderer *r, int x, int y)
{
    SDL_Rect p;
    p.x = x;
    p.y = y;
    p.w = 2;
    p.h = 2;
    SDL_RenderFillRect(r, &p);
}

static void drawDigit(SDL_Renderer *r, int digit, int x, int y)
{
    int i, j;
    if (digit < 0 || digit > 9)
        return;
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    for (i = 0; i < DIGIT_HEIGHT; i++)
        for (j = 0; j < DIGIT_WIDTH; j++)
            if (DIGITS[digit][i][j])
                drawPixel(r, x + j * 3, y + i * 3);
}

static void drawNumber(SDL_Renderer *r, int num, int x, int y)
{
    int digits[10];
    int len = 0;
    int i;

    if (num == 0) {
        drawDigit(r, 0, x, y);
        return;
    }
    while (num > 0) {
        digits[len++] = num % 10;
        num /= 10;
    }
    for (i = len - 1; i >= 0; i--) {
        drawDigit(r, digits[i], x + (len - 1 - i) * 12, y);
    }
}

/* Draw "SCORE:" label as simple lines, then the number */
static void drawScore(SDL_Renderer *r, int score)
{
    /* amiport: draw "SCORE:" as individual character boxes */
    static const char *label = "SCORE:";
    int x = 10;
    int i;

    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    for (i = 0; label[i]; i++) {
        SDL_RenderDrawLine(r, x, 5, x + 6, 5);
        x += 10;
    }
    drawNumber(r, score, x, 3);
}

/* Draw a centered message as simple line placeholders */
static void drawMessage(SDL_Renderer *r, const char *msg)
{
    int len = 0;
    int x, i;

    while (msg[len])
        len++;
    x = (WINDOW_WIDTH - len * 10) / 2;
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    for (i = 0; i < len; i++) {
        SDL_RenderDrawLine(r, x + i * 10, WINDOW_HEIGHT / 2,
                           x + i * 10 + 6, WINDOW_HEIGHT / 2);
    }
}

static void render(Game *game, SDL_Renderer *r)
{
    SDL_Rect rect;
    Node *curr;
    int i;
    Uint8 green;

    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
    SDL_RenderClear(r);

    /* Draw food (red) */
    SDL_SetRenderDrawColor(r, 255, 80, 80, 255);
    rect.x = game->food.x * GRID_SIZE + 2;
    rect.y = game->food.y * GRID_SIZE + 2;
    rect.w = GRID_SIZE - 4;
    rect.h = GRID_SIZE - 4;
    SDL_RenderFillRect(r, &rect);

    /* Draw snake (green gradient, bright head to dark tail) */
    curr = game->snake.head;
    i = 0;
    while (curr) {
        if (game->snake.length > 1) {
            green = (Uint8)(255 - i * (200 / game->snake.length));
        } else {
            green = 255;
        }
        SDL_SetRenderDrawColor(r, 0, green, 0, 255);
        rect.x = curr->pos.x * GRID_SIZE;
        rect.y = curr->pos.y * GRID_SIZE;
        rect.w = GRID_SIZE;
        rect.h = GRID_SIZE;
        SDL_RenderFillRect(r, &rect);
        curr = curr->next;
        i++;
    }

    /* HUD */
    drawScore(r, game->score);
    if (game->paused)
        drawMessage(r, "PAUSED");
    else if (game->game_over)
        drawMessage(r, "GAME OVER - R TO RESTART");

    SDL_RenderPresent(r);
}

int main(int argc, char *argv[])
{
    SDL_Window *w;
    SDL_Renderer *r;
    Game game;
    Uint32 last, now, delta, frame_time;
    int quit = 0;
    int idle_frames = 0;

    (void)argc;
    (void)argv;

    SDL_Log("game_snake: starting");

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return 10; /* amiport: RETURN_ERROR */
    }

    /* amiport: fullscreen at native RTG resolution.
     * SDL2 logical size handles the scaling from 320x240 game coords. */
    w = SDL_CreateWindow("Snake",
                         SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                         640, 480,
                         SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
    if (!w) {
        SDL_Log("Window failed: %s", SDL_GetError());
        SDL_Quit();
        return 10;
    }

    /* amiport: request software renderer (no accelerated on AmigaOS3) */
    r = SDL_CreateRenderer(w, -1, SDL_RENDERER_SOFTWARE);
    if (!r) {
        SDL_Log("Renderer failed: %s", SDL_GetError());
        SDL_DestroyWindow(w);
        SDL_Quit();
        return 10;
    }

    /* amiport: logical size -- game renders at 320x240, SDL2 scales to fill screen */
    SDL_RenderSetLogicalSize(r, WINDOW_WIDTH, WINDOW_HEIGHT);

    /* amiport: seed RNG from SDL_GetTicks (no time() dependency) */
    rng_seed(SDL_GetTicks());

    SDL_memset(&game, 0, sizeof(game));
    resetGame(&game);
    last = SDL_GetTicks();

    SDL_Log("game_snake: entering main loop (ticks=%lu)", (unsigned long)last);

    while (!quit) {
        SDL_Event e;
        int had_input = 0;

        while (SDL_PollEvent(&e)) {
            if (handleInput(&game, &e)) {
                quit = 1;
            }
            if (e.type == SDL_KEYDOWN)
                had_input = 1;
        }

        now = SDL_GetTicks();
        delta = now - last;
        last = now;

        updateGame(&game, delta);
        render(&game, r);

        /* amiport: auto-exit for automated testing */
        if (had_input) {
            idle_frames = 0;
        } else {
            idle_frames++;
            if (idle_frames >= MAX_FRAMES_IDLE) {
                SDL_Log("game_snake: auto-exit after idle timeout");
                quit = 1;
            }
        }

        /* ~60 fps cap */
        frame_time = SDL_GetTicks() - now;
        if (frame_time < 16)
            SDL_Delay(16 - frame_time);
    }

    SDL_Log("game_snake: cleanup");
    freeSnake(&game.snake);
    SDL_DestroyRenderer(r);
    SDL_DestroyWindow(w);
    SDL_Quit();

    return 0;
}
