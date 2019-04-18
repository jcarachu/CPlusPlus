#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
/*
DECK OF CARDS:
    Design the data structure for a generic deck of cards.
    Explain how you would subclass data structures to implement
    blackjack.

    - Assume that the deck is a standard 52 card set.
*/

enum Suit { Club = 0, Diamond = 1, Heart = 2, Spade =3};

class Card
{
    private:
        int value;
        Suit suit;
        string suit_string;
        bool status;
    public:
        Card(int, Suit); 
        Suit getSuit() { return suit; }
        string getSuitString() {return suit_string; }
        int getValue() { return value; }
        void setStatus(bool cond) { this->status = cond; }
        bool getStatus () { return status; }
        
};

Card :: Card(int value, Suit suit)
{
    this->value = value;
    this->suit = suit;
    this->status = true;

    switch (this->suit)
    {
        case Club: 
            suit_string = "CLUB";
            break;
        case Diamond:
            suit_string = "DIAMOND";
            break;
        case Heart:
            suit_string = "HEART";
            break;
        case Spade:
            suit_string = "SPADE";
            break;
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class Deck
{
    private:
        vector<Card> deck;
    public:
        Deck ();
        void shuffle();
        void printDeck();
        Card dealCard();
};

Deck :: Deck()
{
    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            deck.push_back(Card(i, (Suit) j));
        }
    }
}

void Deck :: shuffle()
{
    srand((unsigned) time (NULL));
    map<int,int> card_address;

    for (int i = 0; i < deck.size()/2 ; i++)
    {
        // remember for srand.
        // Create random unique numbers locations!

        int random = rand() % (deck.size() - i) + i;

        while(card_address.count(random) != 0)
        {
            random = rand() % (deck.size());
        };

        card_address.insert(pair<int,int> (random,random));
        Card temp_card = deck[i];
        deck[i] = deck[random];
        deck[random] = temp_card;
        
    }
}

void Deck :: printDeck()
{
    for(int i = 0; i < deck.size(); i++)
    {
        printf("Card %d\n",i+1);
        printf("  $$$ %d %s\n",deck[i].getValue()+1, deck[i].getSuitString().c_str());

    }
}

Card Deck :: dealCard()
{
    Card topCard = Card (-1,Spade);
    if (deck.size() > 0) 
    {
        topCard = deck[0];
    }

    return topCard;
}


int main()
{
    Deck* tempDeck = new Deck();
    tempDeck->shuffle();
    tempDeck->printDeck();
    return 0;
}


