#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

const int SIZE1 = 20;
const int WIDTH = 40;
const int HEIGHT = 30;

enum Direction { UP, DOWN, LEFT, RIGHT };

struct Point {
    int x;
    int y;
};

struct Snake {
    Point body[WIDTH * HEIGHT];
    int length;
    Direction direction;
};

struct Food {
    Point position;
    bool isVisible;
};

bool IsInSnake(int x, int y, const Snake& snake); 

void DrawSnake(const Snake& snake) {
    setfillcolor(GREEN);
    for (int i = 0; i < snake.length; i++) {
        fillrectangle(snake.body[i].x * SIZE1, snake.body[i].y * SIZE1,
                      (snake.body[i].x + 1) * SIZE1, (snake.body[i].y + 1) * SIZE1);
    }
}

void DrawFood(const Food& food) {
    if (food.isVisible) {
        setfillcolor(RED);
        fillrectangle(food.position.x * SIZE1, food.position.y * SIZE1,
                      (food.position.x + 1) * SIZE1, (food.position.y + 1) * SIZE1);
    }
}

void GenerateFood(Food& food, const Snake& snake) {
    int x, y;
    do {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
    } while (getpixel(x * SIZE1, y * SIZE1) != BLACK || IsInSnake(x, y, snake));
    food.position.x = x;
    food.position.y = y;
    food.isVisible = true;
}

bool IsInSnake(int x, int y, const Snake& snake) {
    for (int i = 0; i < snake.length; i++) {
        if (snake.body[i].x == x && snake.body[i].y == y) {
            return true;
        }
    }
    return false;
}

void UpdateSnake(Snake& snake) {
    for (int i = snake.length - 1; i > 0; i--) {
        snake.body[i] = snake.body[i - 1];
    }
    switch (snake.direction) {
        case UP:
            snake.body[0].y--;
            break;
        case DOWN:
            snake.body[0].y++;
            break;
        case LEFT:
            snake.body[0].x--;
            break;
        case RIGHT:
            snake.body[0].x++;
            break;
    }
    if (snake.body[0].x < 0) {
        snake.body[0].x = WIDTH - 1;
    } else if (snake.body[0].x >= WIDTH) {
        snake.body[0].x = 0;
    }
    if (snake.body[0].y < 0) {
        snake.body[0].y = HEIGHT - 1;
    } else if (snake.body[0].y >= HEIGHT) {
        snake.body[0].y = 0;
    }
}

bool IsSnakeSelfIntersecting(const Snake& snake) {
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
            return true;
        }
    }
    return false;
}

bool IsSnakeEatingFood(const Snake& snake, const Food& food) {
    return snake.body[0].x == food.position.x && snake.body[0].y == food.position.y;
}

void InitializeSnake(Snake& snake) {
    snake.length = 1;
    snake.direction = RIGHT;
    snake.body[0].x = WIDTH / 2;
    snake.body[0].y = HEIGHT / 2;
}

void HandleInput(Snake& snake) {
    if (kbhit()) {
        char ch = getch();
        switch (ch) {
            case 'w':
                if (snake.direction != DOWN) {
                    snake.direction = UP;
                }
                break;
            case 's':
                if (snake.direction != UP) {
                    snake.direction = DOWN;
                }
                break;
            case 'a':
                if (snake.direction != RIGHT) {
                    snake.direction = LEFT;
                }
                break;
            case 'd':
                if (snake.direction != LEFT) {
                    snake.direction = RIGHT;
                }
                break;
            case 'x':
                exit(0);
        }
    }
}

bool IsGameOver(const Snake& snake) {
    return IsSnakeSelfIntersecting(snake);
}

void GameOver() {
    clearrectangle(0, 0, WIDTH * SIZE1, HEIGHT * SIZE1);
    settextcolor(RED);
    settextstyle(50, 0, _T("Arial"));
    outtextxy(WIDTH / 4 * SIZE1, HEIGHT / 2 * SIZE1, _T("Game Over"));
    Sleep(3000);
}

int main() {
    initgraph(WIDTH * SIZE1, HEIGHT * SIZE1);
    srand(static_cast<unsigned int>(time(NULL)));

    Snake snake;
    InitializeSnake(snake);

    Food food;
    GenerateFood(food, snake);

    while (true) {
        clearrectangle(0, 0, WIDTH * SIZE1, HEIGHT * SIZE1);

        UpdateSnake(snake);
        DrawSnake(snake);
        DrawFood(food);

        if (IsSnakeEatingFood(snake, food)) {
            snake.length++;
            GenerateFood(food, snake);
        }

        if (IsGameOver(snake)) {
            GameOver();
            InitializeSnake(snake);
            GenerateFood(food, snake);
        }

        HandleInput(snake);

        Sleep(200);
    }

    closegraph();

    return 0;
}
