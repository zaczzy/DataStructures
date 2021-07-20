#include <vector>
#include <algorithm>
#include <random>
#include <stdexcept>
#include <optional>
enum Suit {
    Club,
    Diamond,
    Heart,
    Spade
};


class Card {
    private:
    bool available = true;
    protected:
    int faceValue;
    Suit suit;
    public:
    Card(int c, Suit s) {
        faceValue = c;
        suit = s;
    }
    virtual int value() = 0;
    Suit getSuit() {return suit;}
    bool isAvailable() {return available;}
    void markUnavailale() {available = false;}
    void markAvailable() {available = true;}
};


class BlackJackCard : public Card {
    public:
    BlackJackCard(int c, Suit s) : Card(c, s) {}
    int value() {
        if (isAce()) return 1;
        else if (isFaceCard()) return 10;
        else return faceValue;
    }
    
    bool isAce() {return faceValue == 1;}
    int minValue() {
        if (isAce()) return 1;
        else return value();
    }
    int maxValue() {
        if (isAce()) return 11;
        else return value();
    }
    bool isFaceCard() {
        return faceValue >= 11 && faceValue <=13;
    }
};

template <typename T, typename std::enable_if<std::is_base_of<Card, T>::value>::type* = nullptr>
class Hand {
    protected:
    std::vector<T> cards;
    public:
    int score() {
        int score = 0;
        for (T card: cards) {
            score += card.value();
        }
        return score;
    }
    void addCard(T card) {
        cards.push_back(card);
    }
};


class BlackJackHand : public Hand<BlackJackCard> {
    public: 
    /* return the highest possible value that is lower than 21 or lowest score over 21*/
    int score () {
        std::vector<int> scores = possibleScores();
    }
    private:
    std::vector<int> possibleScores() {
        std::vector<int> possible {0};
        for (BlackJackCard& card : cards) {
            int maxValue = card.maxValue();
            int minValue = card.minValue();
            std::vector<int> copy;
            copy.reserve(possible.size());
            if (maxValue != minValue) {
                copy = possible;
                for (auto it = copy.begin(); it !=copy.end(); it++) {
                    *it += maxValue;
                }
            }
            for (auto it = possible.begin(); it!=possible.end(); it++) {
                *it += minValue;
            }
            if (maxValue != minValue) {
                possible.insert(possible.end(), copy.begin(), copy.end());
            }
        }
        return possible;
    }
};

template<typename T, typename std::enable_if<std::is_base_of<Card, T>::value>::type* = nullptr>
class Deck {
    private:
    std::vector<T> cards;
    int dealtIndex = 0;
    void setDeckOfCards (std::vector<T> &cards) {
        this->cards = cards;
    }
    void shuffle() {
        auto rng = std::default_random_engine {};
        std::shuffle(cards.begin(), cards.end(), rng);
    }
    int remainingCards() {
        return cards.size() - dealtIndex;
    }
    std::vector<T> dealHand(int number) {
        std::vector<T> hand;
        int count;
        for (count = 0; count < number; count++) {
            if (dealtIndex == cards.size()) break;
            hand.push_back(cards[dealtIndex]);
            dealtIndex++;
        }
//        optional syntax
        if (count == 0) return std::nullopt;
//        return by value with move semantics
        return hand;
    }

    std::optional<T> dealCard() {
        if (dealtIndex == cards.size())
            return std::nullopt;
        return std::optional<T>{cards[++dealtIndex]};

    }

};

int main() {
    return 0;
}