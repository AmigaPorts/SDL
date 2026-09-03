/*
 * game_2048: The 2048 sliding tile puzzle, implemented in SDL2.
 *
 * A real game running on our SDL2 AmigaOS 3.x port.
 * Uses: video (SDL_FillRect), input (arrow keys), timer (animation).
 * No external assets -- all rendering via colored rectangles and
 * the SDL_test bitmap font (from libSDL2_test.a).
 *
 * Controls: Arrow keys to slide tiles, ESC to quit, R to restart.
 *
 * Build: Linked with -lSDL2_test for SDLTest_DrawCharacter font.
 */

#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
#include "SDL_test_font.h"

static const char *verstag = "$VER: game_2048 0.1 (28.03.2026)";
long __stack = 65536;

#define GRID 4
#define WIN_W 400
#define WIN_H 480
#define TILE_SIZE 80
#define TILE_GAP 10
#define BOARD_X 30
#define BOARD_Y 100
#define MAX_FRAMES_IDLE 9000 /* auto-exit after 3 min idle at 50fps */

static int board[GRID][GRID];
static int score;
static int best;
static int game_over;
static int game_won;

/* Tile colors (value -> R,G,B) */
static void tile_color(int val, Uint8 *r, Uint8 *g, Uint8 *b)
{
    switch (val) {
    case 0:    *r=205; *g=193; *b=180; return;
    case 2:    *r=238; *g=228; *b=218; return;
    case 4:    *r=237; *g=224; *b=200; return;
    case 8:    *r=242; *g=177; *b=121; return;
    case 16:   *r=245; *g=149; *b=99;  return;
    case 32:   *r=246; *g=124; *b=95;  return;
    case 64:   *r=246; *g=94;  *b=59;  return;
    case 128:  *r=237; *g=207; *b=114; return;
    case 256:  *r=237; *g=204; *b=97;  return;
    case 512:  *r=237; *g=200; *b=80;  return;
    case 1024: *r=237; *g=197; *b=63;  return;
    case 2048: *r=237; *g=194; *b=46;  return;
    default:   *r=60;  *g=58;  *b=50;  return;
    }
}

static void text_color(int val, Uint8 *r, Uint8 *g, Uint8 *b)
{
    if (val <= 4) { *r=119; *g=110; *b=101; }
    else          { *r=249; *g=246; *b=242; }
}

static void add_random_tile(void)
{
    int empty[GRID * GRID][2];
    int count = 0;
    int r, c, idx;
    for (r = 0; r < GRID; r++)
        for (c = 0; c < GRID; c++)
            if (board[r][c] == 0) {
                empty[count][0] = r;
                empty[count][1] = c;
                count++;
            }
    if (count == 0) return;
    idx = rand() % count;
    board[empty[idx][0]][empty[idx][1]] = (rand() % 10 < 9) ? 2 : 4;
}

static void init_game(void)
{
    int r, c;
    for (r = 0; r < GRID; r++)
        for (c = 0; c < GRID; c++)
            board[r][c] = 0;
    score = 0;
    game_over = 0;
    game_won = 0;
    srand((unsigned)SDL_GetTicks());
    add_random_tile();
    add_random_tile();
}

/* Slide and merge one row to the left. Returns 1 if anything moved. */
static int slide_row(int row[GRID])
{
    int moved = 0;
    int i, j, target;
    /* Remove gaps */
    target = 0;
    for (i = 0; i < GRID; i++) {
        if (row[i] != 0) {
            if (i != target) { row[target] = row[i]; row[i] = 0; moved = 1; }
            target++;
        }
    }
    /* Merge adjacent equal */
    for (i = 0; i < GRID - 1; i++) {
        if (row[i] != 0 && row[i] == row[i + 1]) {
            row[i] *= 2;
            score += row[i];
            if (row[i] == 2048) game_won = 1;
            for (j = i + 1; j < GRID - 1; j++) row[j] = row[j + 1];
            row[GRID - 1] = 0;
            moved = 1;
        }
    }
    return moved;
}

static int move_left(void)
{
    int moved = 0, r;
    for (r = 0; r < GRID; r++) moved |= slide_row(board[r]);
    return moved;
}

static int move_right(void)
{
    int moved = 0, r, c;
    int temp[GRID];
    for (r = 0; r < GRID; r++) {
        for (c = 0; c < GRID; c++) temp[c] = board[r][GRID - 1 - c];
        moved |= slide_row(temp);
        for (c = 0; c < GRID; c++) board[r][GRID - 1 - c] = temp[c];
    }
    return moved;
}

static int move_up(void)
{
    int moved = 0, r, c;
    int temp[GRID];
    for (c = 0; c < GRID; c++) {
        for (r = 0; r < GRID; r++) temp[r] = board[r][c];
        moved |= slide_row(temp);
        for (r = 0; r < GRID; r++) board[r][c] = temp[r];
    }
    return moved;
}

static int move_down(void)
{
    int moved = 0, r, c;
    int temp[GRID];
    for (c = 0; c < GRID; c++) {
        for (r = 0; r < GRID; r++) temp[r] = board[GRID - 1 - r][c];
        moved |= slide_row(temp);
        for (r = 0; r < GRID; r++) board[GRID - 1 - r][c] = temp[r];
    }
    return moved;
}

static int can_move(void)
{
    int r, c;
    for (r = 0; r < GRID; r++)
        for (c = 0; c < GRID; c++) {
            if (board[r][c] == 0) return 1;
            if (c < GRID - 1 && board[r][c] == board[r][c + 1]) return 1;
            if (r < GRID - 1 && board[r][c] == board[r + 1][c]) return 1;
        }
    return 0;
}

static void draw_text(SDL_Renderer *ren, int x, int y, const char *text,
                       Uint8 r, Uint8 g, Uint8 b)
{
    int i;
    for (i = 0; text[i]; i++) {
        SDLTest_DrawCharacter(ren, x + i * 8, y, text[i]);
    }
    /* SDLTest_DrawCharacter uses the current draw color set before calling,
     * but it sets its own. We just accept the default white. */
    (void)r; (void)g; (void)b;
}

static void draw_board(SDL_Renderer *ren)
{
    int r, c, x, y;
    SDL_Rect rect;
    Uint8 tr, tg, tb;
    char buf[32];

    /* Background */
    SDL_SetRenderDrawColor(ren, 250, 248, 239, 255);
    SDL_RenderClear(ren);

    /* Score bar */
    SDL_SetRenderDrawColor(ren, 187, 173, 160, 255);
    rect.x = BOARD_X; rect.y = 10; rect.w = 150; rect.h = 50;
    SDL_RenderFillRect(ren, &rect);
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    SDL_snprintf(buf, sizeof(buf), "SCORE: %d", score);
    draw_text(ren, BOARD_X + 10, 20, buf, 255, 255, 255);
    SDL_snprintf(buf, sizeof(buf), "BEST:  %d", best);
    draw_text(ren, BOARD_X + 10, 40, buf, 255, 255, 255);

    /* Title */
    SDL_SetRenderDrawColor(ren, 119, 110, 101, 255);
    draw_text(ren, BOARD_X + 200, 20, "2048", 119, 110, 101);
    draw_text(ren, BOARD_X + 200, 40, "SDL2/AmigaOS3", 119, 110, 101);

    /* Board background */
    SDL_SetRenderDrawColor(ren, 187, 173, 160, 255);
    rect.x = BOARD_X - TILE_GAP;
    rect.y = BOARD_Y - TILE_GAP;
    rect.w = GRID * (TILE_SIZE + TILE_GAP) + TILE_GAP;
    rect.h = GRID * (TILE_SIZE + TILE_GAP) + TILE_GAP;
    SDL_RenderFillRect(ren, &rect);

    /* Tiles */
    for (r = 0; r < GRID; r++) {
        for (c = 0; c < GRID; c++) {
            x = BOARD_X + c * (TILE_SIZE + TILE_GAP);
            y = BOARD_Y + r * (TILE_SIZE + TILE_GAP);

            tile_color(board[r][c], &tr, &tg, &tb);
            SDL_SetRenderDrawColor(ren, tr, tg, tb, 255);
            rect.x = x; rect.y = y;
            rect.w = TILE_SIZE; rect.h = TILE_SIZE;
            SDL_RenderFillRect(ren, &rect);

            if (board[r][c] != 0) {
                text_color(board[r][c], &tr, &tg, &tb);
                SDL_SetRenderDrawColor(ren, tr, tg, tb, 255);
                SDL_snprintf(buf, sizeof(buf), "%d", board[r][c]);
                /* Center text in tile */
                {
                    int tw = (int)SDL_strlen(buf) * 8;
                    draw_text(ren, x + (TILE_SIZE - tw) / 2,
                              y + (TILE_SIZE - 8) / 2, buf, tr, tg, tb);
                }
            }
        }
    }

    /* Game over / won overlay */
    if (game_over) {
        SDL_SetRenderDrawColor(ren, 238, 228, 218, 180);
        rect.x = BOARD_X - TILE_GAP;
        rect.y = BOARD_Y - TILE_GAP;
        rect.w = GRID * (TILE_SIZE + TILE_GAP) + TILE_GAP;
        rect.h = GRID * (TILE_SIZE + TILE_GAP) + TILE_GAP;
        SDL_RenderFillRect(ren, &rect);
        SDL_SetRenderDrawColor(ren, 119, 110, 101, 255);
        draw_text(ren, BOARD_X + 100, BOARD_Y + 150, "GAME OVER!", 119, 110, 101);
        draw_text(ren, BOARD_X + 90, BOARD_Y + 170, "R=Restart ESC=Quit", 119, 110, 101);
    }
    if (game_won && !game_over) {
        SDL_SetRenderDrawColor(ren, 237, 194, 46, 180);
        rect.x = BOARD_X - TILE_GAP;
        rect.y = BOARD_Y - TILE_GAP;
        rect.w = GRID * (TILE_SIZE + TILE_GAP) + TILE_GAP;
        rect.h = GRID * (TILE_SIZE + TILE_GAP) + TILE_GAP;
        SDL_RenderFillRect(ren, &rect);
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        draw_text(ren, BOARD_X + 120, BOARD_Y + 150, "YOU WIN!", 255, 255, 255);
        draw_text(ren, BOARD_X + 80, BOARD_Y + 170, "Keep playing or ESC", 255, 255, 255);
    }

    SDL_RenderPresent(ren);
}

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;
    int running = 1;
    int idle_frames = 0;
    int moved;
    int rc;

    (void)argc; (void)argv; (void)verstag;

    printf("game_2048: SDL2 2048 for AmigaOS 3.x\n");
    printf("Controls: Arrow keys, R=restart, ESC=quit\n");
    fflush(stdout);

    rc = SDL_Init(SDL_INIT_VIDEO);
    if (rc != 0) {
        printf("FAIL: SDL_Init(VIDEO): %s\n", SDL_GetError());
        return 10;
    }

    window = SDL_CreateWindow(
        "2048 - SDL2/AmigaOS3",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIN_W, WIN_H, 0
    );
    if (!window) {
        printf("FAIL: SDL_CreateWindow: %s\n", SDL_GetError());
        SDL_Quit();
        return 10;
    }

    printf("Creating renderer...\n"); fflush(stdout);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer) {
        printf("FAIL: SDL_CreateRenderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 10;
    }
    printf("Renderer created OK\n"); fflush(stdout);

    init_game();
    printf("Game initialized, drawing board...\n"); fflush(stdout);
    draw_board(renderer);
    printf("First draw complete\n"); fflush(stdout);

    while (running && idle_frames < MAX_FRAMES_IDLE) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
                break;
            }
            if (event.type == SDL_KEYDOWN) {
                idle_frames = 0;
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_ESCAPE:
                    running = 0;
                    break;
                case SDL_SCANCODE_R:
                    init_game();
                    draw_board(renderer);
                    break;
                case SDL_SCANCODE_LEFT:
                    moved = move_left();
                    if (moved) { add_random_tile(); draw_board(renderer); }
                    if (!can_move()) game_over = 1;
                    if (game_over) draw_board(renderer);
                    break;
                case SDL_SCANCODE_RIGHT:
                    moved = move_right();
                    if (moved) { add_random_tile(); draw_board(renderer); }
                    if (!can_move()) game_over = 1;
                    if (game_over) draw_board(renderer);
                    break;
                case SDL_SCANCODE_UP:
                    moved = move_up();
                    if (moved) { add_random_tile(); draw_board(renderer); }
                    if (!can_move()) game_over = 1;
                    if (game_over) draw_board(renderer);
                    break;
                case SDL_SCANCODE_DOWN:
                    moved = move_down();
                    if (moved) { add_random_tile(); draw_board(renderer); }
                    if (!can_move()) game_over = 1;
                    if (game_over) draw_board(renderer);
                    break;
                default:
                    break;
                }
                if (score > best) best = score;
            }
        }
        SDL_Delay(20);
        idle_frames++;
    }

    printf("Final score: %d (best: %d)\n", score, best);
    fflush(stdout);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    printf("PASS: 2048 exited cleanly\n");
    return 0;
}
