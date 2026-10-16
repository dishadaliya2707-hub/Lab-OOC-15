#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Terminal-compatible non-blocking keypress check for Linux/macOS/Windows
#if defined(_WIN32)
    #include <conio.h>
    #include <windows.h>
    void sleepMs(int ms) { Sleep(ms); }
    char readInput() { return _kbhit() ? _getch() : 0; }
#else
    #include <unistd.h>
    #include <termios.h>
    #include <fcntl.h>
    void sleepMs(int ms) { usleep(ms * 1000); }
    char readInput() {
        struct termios oldt, newt;
        char ch = 0;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);
        return (ch != EOF) ? ch : 0;
    }
#endif

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

// Auxiliary structure for 2D position tracking
struct Point {
    int x, y;
};

// CLASS: Encapsulates all Snake game logic and data members
class SnakeGame {
private:
    const int width;
    const int height;
    Point head;
    Point fruit;
    std::vector<Point> tail; // Using std::vector instead of fixed raw array
    Direction dir;
    bool gameOver;
    int score;

    // STATIC MEMBER VARIABLE: Tracks total active games across all objects
    static int activeGamesCount;

    void generateFruit() {
        fruit.x = rand() % width;
        fruit.y = rand() % height;
    }

public:
    // DEFAULT CONSTRUCTOR: Initializes a standard 20x20 game board
    SnakeGame() : SnakeGame(20, 20) {}

    // PARAMETERIZED CONSTRUCTOR: Initializes custom board dimensions and sets starting state
    SnakeGame(int w, int h) : width(w), height(h), gameOver(false), dir(STOP), score(0) {
        head.x = width / 2;
        head.y = height / 2;
        generateFruit();
        activeGamesCount++; // Increments static counter when object is created
    }

    // DESTRUCTOR: Cleans up object instances
    ~SnakeGame() {
        activeGamesCount--;
    }

    // STATIC MEMBER FUNCTION: Accesses static variable without needing object reference
    static int getActiveGamesCount() {
        return activeGamesCount;
    }

    bool isGameOver() const { return gameOver; }

    void Draw() const {
        // Clear screen ANSI sequence (works across bash/zsh/cmd terminal)
        std::cout << "\033[H\033[J";

        for (int i = 0; i < width + 2; i++) std::cout << "#";
        std::cout << "\n";

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) std::cout << "#";

                if (i == head.y && j == head.x) {
                    std::cout << "O"; // Snake Head
                } else if (i == fruit.y && j == fruit.x) {
                    std::cout << "*"; // Fruit
                } else {
                    bool printTail = false;
                    for (const auto& segment : tail) {
                        if (segment.x == j && segment.y == i) {
                            std::cout << "o"; // Snake Body
                            printTail = true;
                            break;
                        }
                    }
                    if (!printTail) std::cout << " ";
                }

                if (j == width - 1) std::cout << "#";
            }
            std::cout << "\n";
        }

        for (int i = 0; i < width + 2; i++) std::cout << "#";
        std::cout << "\n";
        std::cout << "Score: " << score << " | Active Games: " << activeGamesCount << "\n";
        std::cout << "Controls: W (Up), A (Left), S (Down), D (Right), X (Quit)\n";
    }

    void ProcessInput() {
        char key = readInput();
        switch (key) {
            case 'a': if (dir != RIGHT) dir = LEFT; break;
            case 'd': if (dir != LEFT) dir = RIGHT; break;
            case 'w': if (dir != DOWN) dir = UP; break;
            case 's': if (dir != UP) dir = DOWN; break;
            case 'x': gameOver = true; break;
        }
    }

    void UpdateLogic() {
        if (dir == STOP) return;

        // Shift body segments forward
        if (!tail.empty()) {
            for (size_t i = tail.size() - 1; i > 0; --i) {
                tail[i] = tail[i - 1];
            }
            tail[0] = head;
        }

        // Move Head
        switch (dir) {
            case LEFT:  head.x--; break;
            case RIGHT: head.x++; break;
            case UP:    head.y--; break;
            case DOWN:  head.y++; break;
            default: break;
        }

        // Wall collisions
        if (head.x >= width || head.x < 0 || head.y >= height || head.y < 0) {
            gameOver = true;
        }

        // Self-collision with tail
        for (const auto& segment : tail) {
            if (segment.x == head.x && segment.y == head.y) {
                gameOver = true;
            }
        }

        // Fruit consumption
        if (head.x == fruit.x && head.y == fruit.y) {
            score += 10;
            tail.push_back({-1, -1});
            generateFruit();
        }
    }
};

// Initialize static member variable outside class definition
int SnakeGame::activeGamesCount = 0;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // OBJECT CREATION: Instantiating object 'game' using Parameterized Constructor
    SnakeGame game(20, 20);

    while (!game.isGameOver()) {
        game.Draw();
        game.ProcessInput();
        game.UpdateLogic();
        sleepMs(80);
    }

    std::cout << "\nGAME OVER! Final Score: " << game.isGameOver() << "\n";
    return 0;
}