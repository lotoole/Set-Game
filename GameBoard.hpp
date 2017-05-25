//
//  GameBoard.hpp
//  FinalProject
//
//  Created by Timothy Guyon on 4/20/17.
//  Copyright © 2017 Timothy Guyon. All rights reserved.
//

//
//  functions.hpp
//  Set
//
//  Created by Liam O'Toole on 4/13/17.
//  Copyright © 2017 Liam O'Toole. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp
#include "main.hpp"

class GameBoard {
public:
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: constructor and destrucotr
     */
    GameBoard();
    ~GameBoard();
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: checks for a set of cards, will call updateBoard if there is a set
     */
    void checkSet(int one, int two, int three);
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: populate with parameterless constructors which will then be looped through and have the fields set
     */
    void populateDeck();
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: shuffles the deck
     */
    void shuffleDeck();
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: populates the gameBoard with cards
     */
    void populateBoardCards();
    /**
     * Requires: coordinates
     * Modifies: nothing
     * Effects: checks to see if click is in card bounds and adds to vector to be checked if set
     */
    void selectCards(Point2D click);
    /**
     * Requires: index of targeted element
     * Modifies: nothing
     * Effects: checks to see if click is in card bounds and adds to vector to be checked if set
     */
    string getVectorItemShape(int i);
    string getVectorItemOpacity(int i);
    string getVectorItemColor(int i);
    
    
    shape getBoardItemShape(int i);
    string getBoardItemOpacity(int i);
    string getBoardItemColor(int i);
    int getBoardNumberOfShapes(int i);
    int getCardNumberOfShapes(int i);
    //draw card
    void cardDraw(int cardNumber, Point2D topLeft);
    //file I/O
    string loadSave();
    void save(string userName, int score);
    //user score information
    int getUserScore();
    string getUserName();
    void setUserName();
    //game over methods
    void gameOver();
    
    Card returnBoardCard(int i);
    
    //drawButtons to check set and end game
    void drawButtons();
protected:
    //holds the 81 cards in the deck
    vector<Card> cards;
private:
    //holds the 9 cards that are on the board
    vector<Card> boardCards;
    //holds cards that have been selected to check
    vector<Card> chosen;
    //fields for user and score
    int userScore = 0;
    string userName;
    //update score
    void updateScore();
    
    
};

#endif /* functions_hpp */
