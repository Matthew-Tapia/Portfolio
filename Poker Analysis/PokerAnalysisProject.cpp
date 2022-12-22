//
// Created by Matthew Tapia on 12/9/22.
//

#include "PokerAnalysisProject.h"

PokerAnalysisProject::PokerAnalysisProject() : Application({2560, 1600, 32}, "Poker Analysis"){
    srand(time(NULL));

    setBackgroundColor(Constants::POKER_ANALYSIS_BACKGROUND_COLOR);
    //GAME LOGIC
    const int NUM_OF_RUNS = 1000000;
    int scoreCounter[10] = {0, 0, 0, 0, 0, 0, 0, 0,0,0};

    for(int i = 0; i < NUM_OF_RUNS; i++){
        Deck deck;
        CardHand cardHand;

        for(int j = 0; j < 5; j++){
            cardHand.addCard(deck.dealCard());
        }

        cardHand.sortByRank();
        PokerScore currentPokerScore = CardHandScorer::scoreHandPoker(cardHand);

        for(PokerScore::ScoresEnum j = PokerScore::ScoresEnum(0); j != PokerScore::ScoresEnum::END_SCORE; j = (PokerScore::ScoresEnum)(j+1)){
            if(currentPokerScore == j){
                scoreCounter[j]++;
            }
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            EXAMPLE_CARDS[i][j].setSize(getWidth()/32, getHeight()/12);
            EXAMPLE_CARDS[i][j].setPosition((getWidth()/32) + (3*getWidth()/64)*j, getHeight()/16 + (getHeight()/5)*i);
        }
    }

    for(int i = 5; i < 10; i++){
        for(int j = 0; j < 5; j++){
            EXAMPLE_CARDS[i][j].setSize(getWidth()/32, getHeight()/12);
            EXAMPLE_CARDS[i][j].setPosition((17*getWidth()/32) + (3*getWidth()/64)*j, getHeight()/16 + (getHeight()/5)*(i-5));
        }
    }

    for(int i = 0; i < 10; i++){
        int gcd = 1;

        for (int j = 1; j <= scoreCounter[i]; ++j) {
            if (NUM_OF_RUNS % j == 0 && scoreCounter[i] % j ==0) {
                gcd = j;
            }
        }

        probabilities[i].setString(std::to_string(scoreCounter[i]/gcd) + " : " + std::to_string(NUM_OF_RUNS/gcd));
        probabilities[i].setCharacterSize(getWidth()/45);
    }

    for(int i = 0; i < 5; i++){
        probabilities[i].setPosition(19*getWidth()/64, getHeight()/12 + (getHeight()/5)*i);
    }

    for(int i = 5; i < 10; i++){
        probabilities[i].setPosition(51*getWidth()/64, getHeight()/12 + (getHeight()/5)*(i-5));
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 5; j++){
            addComponent(EXAMPLE_CARDS[i][j]);
        }
        addComponent(probabilities[i]);
    }
}
