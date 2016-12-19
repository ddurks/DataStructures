#include <iostream>
#include <random>
#include <map>

using namespace std;
int N = 100;

int main(int argc, char *argv[]) {

    cout << 6 << endl;
    cout << "f 3\ng 1\nG 2\nh 4\nm 7\nr 5" << endl;
    cout << N << " " << N << endl;

    map<int, char> options;

    options[0] = 'f';
    options[1] = 'g';
    options[2] = 'G';
    options[3] = 'h';
    options[4] = 'm';
    options[5] = 'r';

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 5); // define the range

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << options[distr(eng)] << " ";
        }
        cout << endl;
    }
    cout << "0 0\n" << N-1 << " " << N-1 << endl;
}
