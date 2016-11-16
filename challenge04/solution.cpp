// Challenge 04: Card Rank
// Read in a series of cards and players, display them from highest card holder to lowest

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Card{
    string name, suit;
    int rank;
};

bool compareCards(const Card &a, const Card &b){
    if(a.rank == b.rank){
        return a.suit > b.suit;
    }
    else{
        return a.rank > b.rank;
    }
}
// Main Execution
int main(int argc, char *argv[]) {
    string line;
    int numCards;
    string name, rank, suit;
    Card temp;
    vector<Card> cards;
    while(!cin.eof()){
        cin >> numCards;
        if( numCards <= 0 ) break;
        for(int i = 0; i < numCards; i++){
            cin >> name;
            cin >> rank;
            cin >> suit;

            temp.name = name;
            if(rank == "J") temp.rank = 11;
            else if(rank == "Q") temp.rank = 12;
            else if(rank == "K") temp.rank = 13;
            else if(rank == "A") temp.rank = 14;
            else temp.rank = stoi(rank);
            temp.suit = suit;
            cards.push_back(temp);
        }
        sort(cards.begin(), cards.end(), compareCards);
        for(int i = 0; i < numCards; i++){
            if( i == numCards - 1 ){
                cout << cards[i].name;
            }
            else{
                cout << cards[i].name << ", ";
            }
        }
        cout << endl;
        cards.clear();
    }
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
