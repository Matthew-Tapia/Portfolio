//
// Created by Matthew Tapia on 12/9/22.
//

#ifndef PORTFOLIO_POKERANALYSISPROJECT_H
#define PORTFOLIO_POKERANALYSISPROJECT_H

#include "../SFML Tools/Application.h"
#include <string>
#include "CardHandScorer.h"
#include "DrawableCard.h"
#include "ProbabilityText.h"
#include "MathTools.h"

class PokerAnalysisProject : public Application{
private:
    DrawableCard EXAMPLE_CARDS[10][5] = {{DrawableCard(CLUBS, ACE), DrawableCard(CLUBS, TEN), DrawableCard(CLUBS, JACK), DrawableCard(CLUBS, QUEEN), DrawableCard(CLUBS, KING) },
                                         {DrawableCard(HEARTS, THREE), DrawableCard(HEARTS, FOUR), DrawableCard(HEARTS, FIVE), DrawableCard(HEARTS, SIX), DrawableCard(HEARTS, SEVEN) },
                                         {DrawableCard(DIAMONDS, TWO), DrawableCard(HEARTS, NINE), DrawableCard(CLUBS, NINE), DrawableCard(DIAMONDS, NINE), DrawableCard(SPADES, NINE) },
                                         {DrawableCard(HEARTS, ACE), DrawableCard(DIAMONDS, ACE), DrawableCard(CLUBS, FIVE), DrawableCard(DIAMONDS, FIVE), DrawableCard(SPADES, FIVE) },
                                         {DrawableCard(DIAMONDS, THREE), DrawableCard(DIAMONDS, SEVEN), DrawableCard(DIAMONDS, TEN), DrawableCard(DIAMONDS, QUEEN), DrawableCard(DIAMONDS, KING) },
                                         {DrawableCard(HEARTS, THREE), DrawableCard(CLUBS, FOUR), DrawableCard(CLUBS, FIVE), DrawableCard(DIAMONDS, SIX), DrawableCard(SPADES, SEVEN) },
                                         {DrawableCard(DIAMONDS, THREE), DrawableCard(HEARTS, EIGHT), DrawableCard(CLUBS, EIGHT), DrawableCard(DIAMONDS, EIGHT), DrawableCard(SPADES, JACK) },
                                         {DrawableCard(DIAMONDS, ACE), DrawableCard(HEARTS, ACE), DrawableCard(CLUBS, NINE), DrawableCard(DIAMONDS, NINE), DrawableCard(SPADES, TEN) },
                                         {DrawableCard(DIAMONDS, ACE), DrawableCard(SPADES, THREE), DrawableCard(CLUBS, NINE), DrawableCard(DIAMONDS, NINE), DrawableCard(HEARTS, QUEEN) },
                                         {DrawableCard(CLUBS, FOUR), DrawableCard(CLUBS, SIX), DrawableCard(HEARTS, SEVEN), DrawableCard(DIAMONDS, JACK), DrawableCard(HEARTS, KING) }};

    ProbabilityText probabilities[10];

public:
    PokerAnalysisProject();
};


#endif //PORTFOLIO_POKERANALYSISPROJECT_H
