#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define WIDTH 22 
#define HEIGHT 12 

char grid[HEIGHT][WIDTH];
int playerX, playerY;

void initializeGrid() {
    // Fill the grid with empty spaces
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = ' ';
        }
    }

    // Create walls around the edges
    for (int x = 0; x < WIDTH; x++) {
        grid[0][x] = '#';
        grid[HEIGHT-1][x] = '#';
    }
    for (int y = 0; y < HEIGHT; y++) {
        grid[y][0] = '#';
        grid[y][WIDTH-1] = '#';
    }

    // Place the player in the center
    playerX = WIDTH / 2;
    playerY = HEIGHT / 2;
    grid[playerY][playerX] = 'P';
}

void displayGrid() {
    system("cls");  // Clear the console
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", grid[y][x]);
        }
        printf("\n");
    }
}

void movePlayer(char direction) {
    int newX = playerX;
    int newY = playerY;

    switch (direction) {
        case 'w': newY--; break;
        case 's': newY++; break;
        case 'a': newX--; break;
        case 'd': newX++; break;
    }

    // Check if the new position is not a wall before moving
    if (grid[newY][newX] != '#') {
        grid[playerY][playerX] = ' ';
        playerX = newX;
        playerY = newY;
        grid[playerY][playerX] = 'P';
    }
}

int main() {
    char input;
    initializeGrid();

    while (1) {
        displayGrid();
        printf("Move (WASD) or Q to quit: ");
        input = getch();  // Get a single character input without pressing Enter
        if (input == 'q' || input == 'Q') break;
        movePlayer(input);
    }

    return 0;
}