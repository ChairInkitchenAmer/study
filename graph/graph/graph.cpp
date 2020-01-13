// graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <SDL.h>
#include <time.h>

using namespace std;

int const WIDTH = 800;
int const HEIGHT = 800;

int cellWidth = 0;
int cellHeight = 0;

struct node {
    int f;
    int g;
    int h;

    int x, y;

    int rColor = 255;
    int gColor = 255;
    int bColor = 255;
    bool wall = false;

    vector<node*> neighbors;
    node* previous = nullptr;

    node(int f, int g, int h, int x, int y) : f(f), g(g), h(h), x(x), y(y) {
        float  t = ((double)rand() / (RAND_MAX));
        if (t<.3f) {
            wall = true;
            rColor = 0;
            gColor = 0;
            bColor = 0;
        }
    }
    
    node() : f(0), g(0), h(0), x(0), y(0){}
    
    bool operator==( const node& t2)  {
        return this->x == t2.x && this->y == t2.y;
    }

    void addNeighbor(node* neighbor) {
        neighbors.push_back(neighbor);
    }
};

void addNeighborsToNode(vector<vector<node*>>& grid, int y, int x) {
    int gridWidth = grid[0].size() - 1;
    int gridHeight = grid.size() - 1;

    if (y < gridHeight) {
        grid[y][x]->addNeighbor(grid[y + 1][x]);
    }
    if (y > 0) {
        grid[y][x]->addNeighbor(grid[y - 1][x]);
    }
    if (x < gridWidth) {
        grid[y][x]->addNeighbor(grid[y][x + 1]);
    }
    if (x > 0) {
        grid[y][x]->addNeighbor(grid[y][x - 1]);
    }

    if (x > 0 && y > 0) {
        grid[y][x]->addNeighbor(grid[y - 1][x - 1]);
    }

    if (x < gridWidth && y > 0) {
        grid[y][x]->addNeighbor(grid[y - 1][x + 1]);
    }

    if (y < gridHeight && x < gridWidth) {
        grid[y][x]->addNeighbor(grid[y + 1][x + 1]);
    }

    if (y < gridHeight && x > 0) {
        grid[y][x]->addNeighbor(grid[y + 1][x - 1]);
    }
}
 
int heuristic(node *a, node *b) {
    int x = abs(a->x - b->x);
    int y = abs(a->y - b->y);

    return sqrt(x * x + y * y);
    
    //manhattan distance
    //return abs(a->x - b->x) + abs(a->y - b->y);
}


void putPixel(SDL_Surface* surface, int x, int y, int r, int g, int b) {
    if (x < 0 || x >= surface->w || y<0 || y>= surface->h) {
        return;
    }

    Uint8* pixel =  (Uint8*)surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel;

    if (!pixel) {
        cout << "pixel is not correct";
    }


    pixel[0] = b;
    pixel[1] = g; ;
    pixel[2] = r;
}

int main(int arc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Awwww crap";
        exit(-1);
    }

    srand(time(NULL));
    SDL_Window* window = SDL_CreateWindow("Graphy graph", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Surface* surface = SDL_GetWindowSurface(window);

    if (SDL_GL_LoadLibrary(NULL) < 0) {
        std::cout << "failed to init gl";
        return -1;
    }

    bool isPlaying = true;
    int size = 50;
    cellHeight = surface->h / size;
    cellWidth = surface->w / size;

    vector<vector<node*>> array;
    vector<node*> openSet;
    vector<node*> closedSet;
    vector<node*> path;

    //generate nodes
    for (int i = 0; i < size; i++) {
        vector<node*> vec;
        for (int j = 0; j < size; j++) {
            vec.push_back(new node(0, 0, 0, i, j));
        }

        array.push_back(vec);
    }

    //add node neighbors
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            addNeighborsToNode(array, i, j);
        }
    }

    //set start and end nodes
    node* start = array[0][0];
    node* end = array[size-1][size-1];
    start->wall = false;
    end->wall = false;

    //add start to openSet
    openSet.push_back(start);
    start->rColor = 0;
    start->gColor = 255;
    start->bColor = 0;

    bool isDone = false;
    while (isPlaying) {
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                isPlaying = false;
            }
        }

        node* current = nullptr;
        if (openSet.size() > 0 && !isDone) {
            int winner = 0;
            for (int i = 0; i < openSet.size(); i++) {
                if (openSet[i]->f < openSet[winner]->f) {
                    winner = i;
                }
            }

            current = openSet[winner];
            
            if (current == end) {
                isDone = true;

                //need to figure out this part

            } else {
                path.clear();
            }
            
            closedSet.push_back(current);
            openSet.erase(openSet.begin() + winner);
            
            //move current to closed set, set to green
            if (!current->wall) {
                current->rColor = 0;
                current->bColor = 0;
                current->gColor = 255;
            }


            for (node* n : current->neighbors) {
                if (find(closedSet.begin(), closedSet.end(), n) == closedSet.end() && !n->wall) {
                    int tempg = current->g + 1;

                    bool validPath = false;
                    if (find(openSet.begin(), openSet.end(), n) != openSet.end()) {
                        if (tempg < n->g) {
                            n->g = tempg;
                            validPath = true;
                        }
                    } else {
                        n->g = tempg;
                        validPath = true;
                      
                        if (!n->wall) {
                            n->rColor = 255;
                            n->gColor = 0;
                            n->bColor = 0;
                        }

                        openSet.push_back(n);
                    }

                    if (validPath) {
                        n->h = heuristic(n, end);
                        n->f = n->g + n->h;
                        n->previous = current;

                        if (!current->wall) {
                            current->rColor = 0;
                            current->gColor = 255;
                            current->bColor = 0;
                        }
                    }
                }
            }
            //keep going
        } else {
            //no solution
        }
        
        //draw grid and blocks
        for (int i = 0; i < array.size(); i++) {
            for (int j = 0; j < array[i].size(); j++) {
                node* curr = array[i][j];
                //draw box
                for (int by = 0; by <= cellHeight; by++) {
                    for (int bx = 0; bx <= cellWidth; bx++) {
                        if (bx == 1 || by == 1 || bx == cellWidth - 1 || by == cellHeight - 1) {
                            putPixel(surface, (j * cellWidth) + bx, (i * cellHeight) + by, 0, 0, 0);
                        } else {
                            putPixel(surface, (j * cellWidth) + bx, (i * cellHeight) + by, curr->rColor , curr->gColor, curr->bColor);
                        }
                    }
                }
            }
        }

        
        if (!isDone) {
            //create path
            node* temp = current;
            if (temp != nullptr) {
                path.push_back(temp);
                while (temp != nullptr) {
                    if (temp->previous != nullptr) {
                        path.push_back(temp->previous);
                    }
                    temp = temp->previous;
                }
            }
        }

        //draw path
        for (auto node : path) {
            for (int by = 0; by <= cellHeight; by++) {
                for (int bx = 0; bx <= cellWidth; bx++) {
                    
                    putPixel(surface, (node->y * cellWidth) + bx, (node->x * cellHeight) + by, 0, 0, node->wall ? 0 : 255);
                }
            }
        }
        
        ///clear 
        SDL_UpdateWindowSurface(window);
    }

    
        
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            node* n = array[j][i];
            delete(n);
        }
    }

   SDL_FreeSurface(surface);
   SDL_DestroyWindow(window);
   SDL_Quit();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
