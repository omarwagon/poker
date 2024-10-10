// poker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <random>
#include <algorithm>


int main()
{

    srand(time(0));
    int deck[52];
    int i;
    enum suit
    {
        spades, diamonds, clubs, hearts
    };
    enum value
    {
        two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8, nine = 9, ten = 10, jack, queen, king, ace
    };

    class card
    {
    public:
        suit suit_;
        value value_;

        card(suit s, value v) : suit_(s), value_(v) {}

        std::string toString() {
            std::string suit_names[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
            std::string value_names[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
            return value_names[static_cast<int>(value_)] + " of " + suit_names[static_cast<int>(suit_)];
        };

    };

    
    for (i = 0; i < 52; i++)
    {
        int s = i / 13; // suit
        int v = i % 13 + 2; // value
        deck[i] = (s << 4) | v; // store suit and value together
    }

    // Shuffle the deck
    for (i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        std::swap(deck[i], deck[j]);
    }

    // Deal cards to players
    const int numPlayers = 2;
    const int cardsPerHand = 5;
    std::vector<card> hands[numPlayers];

    for (i = 0; i < numPlayers; i++)
    {
        for (int j = 0; j < cardsPerHand; j++)
        {
            int cardValue = deck.back();
            deck[52]--;
            int suitValue = cardValue >> 4; // Extract suit
            int valueValue = (cardValue & 0x0F); // Extract value
            hands[i].emplace_back(static_cast<suit>(suitValue), static_cast<value>(valueValue));
            deck[52] = cardValue; // Remove card from deck
        }
    }

    // Display hands
    for (i = 0; i < numPlayers; i++)
    {
        std::cout << "Player " << (i + 1) << "'s hand:\n";
        for (const auto& card : hands[i]) {
            std::cout << card.toString() << "\n";
        }
        std::cout << std::endl;
    }

    return 0;
}
    




/*

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int deck[52];
    int i;
    string suitnames[4] = { "spades", "diamonds", "clubs", "hearts" };
    string ranknames[13] = { "ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king" };

    // create a new deck, with cards in order, but unique
    for (i = 0; i < 52; i++)
    {
        deck[i] = i;
    }

    // shuffle the deck:
    for (i = 0; i < 52; i++)
    {
        // generate a random index to swap with the card at index i.
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }


    // print all the cards
    for (i = 0; i < 52; i++)
    {
        int suitnumber = deck[i] / 13; // 0 - 3
        int rank = deck[i] % 13;
        cout << ranknames[rank] << " of " << suitnames[suitnumber] << "\n";
    }

    // Check first 5 cards for an ace
    cout << endl;
    for (i = 0; i < 5; i++)
    {
        int acerank = 0;
        int currentCardRank = deck[i] % 13;
        if (currentCardRank == acerank)
        {
            cout << "Got an ace!" << endl;
        }
    }

    // Get the rank of the first 5 cards
    int R[5]; // = {4, 7, 6, 3, 5}; // rank of the first 5 cards
    int S[5];
    for (i = 0; i < 5; i++)
    {
        R[i] = deck[i] % 13;
        S[i] = deck[i] / 13;
    }

    // Sort the R array
    bool swapped = false;
    do
    {
        // 1 pass of the bubble sort
        swapped = false;
        for (int i = 0; i < 4; i++)
        {
            if (R[i] > R[i + 1])
            {
                int temp = R[i];
                R[i] = R[i + 1];
                R[i + 1] = temp;
                swapped = true;
            }
        }
    } while (swapped == true);

    // print the sorted ranks and suits
    for (i = 0; i < 5; i++)
    {
        cout << ranknames[R[i]] << " of " << suitnames[S[i]] << "\n";
    }

    // Check for a straight:
    if (R[1] == R[0] + 1 && R[2] == R[1] + 1 && R[3] == R[2] + 1 && R[4] == R[3] + 1)
    {
        cout << "You got a straight! (you must have cheated)" << endl;
    }
    else
    {
        cout << "No straight" << endl;
    }

    // Check first 5 cards for any pair
    if (R[0] == R[1] || R[1] == R[2] || R[2] == R[3] || R[3] == R[4])
    {
        cout << "You got a pair!" << endl;
    }
    else
    {
        cout << "No pair" << endl;
    }

    // Check for a flush (all the same suit)
    if (S[0] == S[1] && S[1] == S[2] && S[2] == S[3] && S[3] == S[4])
    {
        cout << "You got a flush!" << endl;
    }
    else
    {
        cout << "No flush" << endl;
    }

    // Check for straight flush

    // Check for 4 of a kind

    // Check for full house
    system("pause");
    return 0;
}

*/