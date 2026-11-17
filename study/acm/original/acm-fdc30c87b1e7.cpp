#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

// 游戏区域大小
const int WIDTH = 20;
const int HEIGHT = 20;

// 方向枚举
enum Direction {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

// 位置结构体
struct Position {
    int x, y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}
};

class SnakeGame {
private:
    vector<Position> snake;  // 蛇的身体
    Position food;           // 食物位置
    Direction dir;           // 当前方向
    bool gameOver;           // 游戏结束标志
    int score;               // 分数

public:
    SnakeGame() {
        Init();
    }

    void Init() {
        gameOver = false;
        dir = STOP;
        score = 0;
        
        // 初始化蛇的位置（在中间）
        snake.clear();
        snake.push_back(Position(WIDTH / 2, HEIGHT / 2));
        
        // 生成第一个食物
        GenerateFood();
    }

    void GenerateFood() {
        bool onSnake;
        do {
            onSnake = false;
            food.x = rand() % WIDTH;
            food.y = rand() % HEIGHT;
            
            // 确保食物不在蛇身上
            for (const auto& segment : snake) {
                if (segment.x == food.x && segment.y == food.y) {
                    onSnake = true;
                    break;
                }
            }
        } while (onSnake);
    }

    void Draw() {
        // 清屏
        system("cls");
        
        // 绘制上边界
        for (int i = 0; i < WIDTH + 2; i++)
            cout << "#";
        cout << endl;

        // 绘制游戏区域
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                // 绘制左边界
                if (j == 0)
                    cout << "#";
                
                // 检查当前位置是否有蛇的身体
                bool isSnake = false;
                for (int k = 0; k < snake.size(); k++) {
                    if (snake[k].x == j && snake[k].y == i) {
                        if (k == 0)  // 蛇头
                            cout << "O";
                        else         // 蛇身
                            cout << "o";
                        isSnake = true;
                        break;
                    }
                }
                
                // 检查是否有食物
                if (!isSnake) {
                    if (food.x == j && food.y == i)
                        cout << "F";
                    else
                        cout << " ";
                }
                
                // 绘制右边界
                if (j == WIDTH - 1)
                    cout << "#";
            }
            cout << endl;
        }

        // 绘制下边界
        for (int i = 0; i < WIDTH + 2; i++)
            cout << "#";
        cout << endl;

        // 显示分数
        cout << "Score: " << score << endl;
    }

    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
                case 'a':
                case 'A':
                    if (dir != RIGHT) dir = LEFT;
                    break;
                case 'd':
                case 'D':
                    if (dir != LEFT) dir = RIGHT;
                    break;
                case 'w':
                case 'W':
                    if (dir != DOWN) dir = UP;
                    break;
                case 's':
                case 'S':
                    if (dir != UP) dir = DOWN;
                    break;
                case 'x':
                case 'X':
                    gameOver = true;
                    break;
            }
        }
    }

    void Logic() {
        if (dir == STOP) return;

        // 保存蛇尾位置（用于增长）
        Position prevTail = snake.back();

        // 移动蛇身（从尾部向头部）
        for (int i = snake.size() - 1; i > 0; i--) {
            snake[i] = snake[i - 1];
        }

        // 移动蛇头
        switch (dir) {
            case LEFT:
                snake[0].x--;
                break;
            case RIGHT:
                snake[0].x++;
                break;
            case UP:
                snake[0].y--;
                break;
            case DOWN:
                snake[0].y++;
                break;
        }

        // 检查是否撞墙
        if (snake[0].x >= WIDTH || snake[0].x < 0 || 
            snake[0].y >= HEIGHT || snake[0].y < 0) {
            gameOver = true;
        }

        // 检查是否撞到自己
        for (int i = 1; i < snake.size(); i++) {
            if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
                gameOver = true;
                break;
            }
        }

        // 检查是否吃到食物
        if (snake[0].x == food.x && snake[0].y == food.y) {
            score += 10;
            // 增长蛇身
            snake.push_back(prevTail);
            GenerateFood();
        }
    }

    void Run() {
        srand(time(0));  // 初始化随机数种子
        
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            
            // 控制游戏速度
            Sleep(100);


            
        }
        
        // 游戏结束
        system("cls");
        cout << "Game Over!" << endl;
        cout << "Final Score: " << score << endl;
        cout << "Press any key to exit...";
        _getch();
    }
};

int main() {
    cout << "Welcome to Snake Game!" << endl;
    cout << "Controls:" << endl;
    cout << "W - Up" << endl;
    cout << "S - Down" << endl;
    cout << "A - Left" << endl;
    cout << "D - Right" << endl;
    cout << "X - Exit" << endl;
    cout << "Press any key to start...";
    _getch();
    
    SnakeGame game;
    game.Run();
    
    return 0;
}