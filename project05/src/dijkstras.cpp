// dijsktras.cpp

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <list>
#include <climits>
#include <set>

using namespace std;

// Prototypes
void dijkstra(const std::vector<std::vector<char>> &,
              std::map<char, int> &,
              const std::pair<int, int> &,
              const std::pair<int, int> &);

typedef pair<int, char> Tile;           // Type Tile. Cost is first because comparison operates on first element in pair

// Main Execution

int main(int argc, char *argv[]) {
    int tileTypes = 0;                   // Number of tile variations
    map<char, int> tiles;                  // list to store tile type and cost
    int mapRows = 0, mapCols = 0;       // # map rows and columns
    vector< vector<char> > map;         // 2D vector to store map of costs
    vector<int> temp;
    int startRow = 0, startCol = 0;     // Runner start row and column
    int endRow = 0, endCol = 0;         // Runner end row and column
    int tileCost;
    char tile, tileChar;
    Tile tempTile;

    // Capture input:
    cin >> tileTypes;
    for(int i = 0; i < tileTypes; i++){
        cin >> tile >> tileCost;
        tiles[tile] = tileCost;
    }

    cin >> mapRows >> mapCols;
    map.resize(mapRows);
    for(size_t i = 0; i < mapCols; ++i) {
        map[i].resize(mapCols);
    }
    for(size_t i = 0; i < mapRows; ++i) {
        for(size_t j = 0; j < mapCols; ++j) {
            char tile;
            std::cin >> tile;
            map[i][j] = tile;
        }
    }

    cin >> startRow >> startCol >> endRow >> endCol;

    std::pair<int, int> start = std::make_pair(startRow, startCol);
    std::pair<int, int> end = std::make_pair(endRow, endCol);

    dijkstra(map, tiles, start, end);


    return 0;
}

// Dijkstra
void dijkstra(const std::vector<std::vector<char>> &map,
              std::map<char, int> &tiles,
              const std::pair<int, int> &start,
              const std::pair<int, int> &end) {

    std::set<std::pair<int, int>> q; // Unvisited Vertices
    std::vector<std::vector<int>> cost; // Cost
    std::vector<std::vector<std::pair<int, int>>> prev; // Prev Element in Path

    // Manage Memory
    cost.resize(map.size());
    prev.resize(map.size());

    for(size_t i = 0; i < map.size(); ++i) {
        cost[i].resize(map.size());
        prev[i].resize(map.size());
    }

    // For each vertex in Graph
    for(size_t i = 0; i < map.size(); ++i) {
        for(size_t j = 0; j < map.size(); ++j) {

            cost[i][j] = INT_MAX; // Unknown distance from source to [i][j] - set to infinity

            std::pair<int, int> undef = std::make_pair(-1, -1);
            prev[i][j] = undef; // Previous node in optimal path from source - set to undefined

            q.insert(std::make_pair(i, j)); // All nodes initially in q
        }
    }

    cost[std::get<0>(end)][std::get<1>(end)] = 0; // Distance from source to source - 0

    while(!q.empty()) {

        // u <- vertex in Q with min dist[u]
        std::pair<int, int> u;
        int uDist = INT_MAX;
        for(size_t i = 0; i < map.size(); ++i) {
            for(size_t j = 0; j < map.size(); ++j) {
                if(cost[i][j] < uDist && q.count(std::make_pair(i,j))) {
                    uDist = cost[i][j];
                    u = std::make_pair(i, j);
                }
            }
        }

        // If Shortest Path is the Target (Start)
        if(u == start) {
            break;
        }

        q.erase(u);

        std::pair<int, int> v; // Neighbor

        // Up
        v = std::make_pair(std::get<0>(u) + 1, std::get<1>(u));
        if(q.count(v)) {
            char tile = map[std::get<0>(v)][std::get<1>(v)];
            int alt = cost[std::get<0>(u)][std::get<1>(u)] + tiles[tile];
            if(alt < cost[std::get<0>(v)][std::get<1>(v)]) {
                cost[std::get<0>(v)][std::get<1>(v)] = alt;
                prev[std::get<0>(v)][std::get<1>(v)] = u;
            }
        }

        // Down
        v = std::make_pair(std::get<0>(u) - 1, std::get<1>(u));
        if(q.count(v)) {
            char tile = map[std::get<0>(v)][std::get<1>(v)];
            int alt = cost[std::get<0>(u)][std::get<1>(u)] + tiles[tile];
            if(alt < cost[std::get<0>(v)][std::get<1>(v)]) {
                cost[std::get<0>(v)][std::get<1>(v)] = alt;
                prev[std::get<0>(v)][std::get<1>(v)] = u;
            }
        }

        // Left
        v = std::make_pair(std::get<0>(u), std::get<1>(u) - 1);
        if(q.count(v)) {
            char tile = map[std::get<0>(v)][std::get<1>(v)];
            int alt = cost[std::get<0>(u)][std::get<1>(u)] + tiles[tile];
            if(alt < cost[std::get<0>(v)][std::get<1>(v)]) {
                cost[std::get<0>(v)][std::get<1>(v)] = alt;
                prev[std::get<0>(v)][std::get<1>(v)] = u;
            }
        }

        // Right
        v = std::make_pair(std::get<0>(u), std::get<1>(u) + 1);
        if(q.count(v)) {
            char tile = map[std::get<0>(v)][std::get<1>(v)];
            int alt = cost[std::get<0>(u)][std::get<1>(u)] + tiles[tile];
            if(alt < cost[std::get<0>(v)][std::get<1>(v)]) {
                cost[std::get<0>(v)][std::get<1>(v)] = alt;
                prev[std::get<0>(v)][std::get<1>(v)] = u;
            }
        }

    }


    // Find Shortest Path
    std::list<std::pair<int, int>> s; // Sequence
    std::pair<int, int> u = start; // Target
    while(prev[std::get<0>(u)][std::get<1>(u)] != std::make_pair(-1, -1)) {
        s.push_back(u);
        u = prev[std::get<0>(u)][std::get<1>(u)];
    }
    s.push_back(u);

    // Output
    std::cout << cost[std::get<0>(start)][std::get<1>(start)] << std::endl; // Cost

    for(auto it = s.begin(); it != s.end(); ++it) { // Path Sequence
        std::cout << std::get<0>(*it) << " " << std::get<1>(*it) << std::endl;
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
