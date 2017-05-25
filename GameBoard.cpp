//
//  GameBoard.cpp
//  FinalProject
//
//  Created by Timothy Guyon on 4/20/17.
//  Copyright © 2017 Timothy Guyon. All rights reserved.

#include "main.hpp"
#include "graphics.hpp"
//constructor and destructor
GameBoard:: GameBoard(){}
GameBoard:: ~GameBoard(){}


void GameBoard:: checkSet(int one, int two, int three) {
    cout << "checking cards " << one << ", " << two << " and " << three << endl;
    bool numSameOrDiff = false;
    bool shapeSameOrDiff = false;
    bool colorSameOrDiff = false;
    bool opacitySameOrDiff = false;
    
    int card1num = boardCards[one - 1 ].getNumber();
    color card1color= boardCards[one - 1 ].getColor();
    shape card1shape = boardCards[one - 1 ].getShape();
    opacity card1opacity = boardCards[one - 1 ].getOpacity();
    
    int card2num = boardCards[two - 1 ].getNumber();
    color card2color= boardCards[two - 1 ].getColor();
    shape card2shape = boardCards[two - 1 ].getShape();
    opacity card2opacity = boardCards[two - 1 ].getOpacity();
    
    int card3num = boardCards[three - 1 ].getNumber();
    color card3color= boardCards[three - 1 ].getColor();
    shape card3shape = boardCards[three - 1 ].getShape();
    opacity card3opacity = boardCards[three - 1 ].getOpacity();
    
    if(((card1num == card2num) && (card1num == card3num)) or ((card1num != card2num) && (card1num != card3num) && (card2num != card3num))){
        numSameOrDiff = true;
        cout << "numbers pass" << endl;
    }
    
    //check color with iterator
    int numRed = 0;
    if(card1color.red == 1){
        numRed +=1;
    }
    if(card2color.red == 1){
        numRed +=1;
    }
    if(card3color.red == 1){
        numRed +=1;
    }
    
    int numGreen = 0;
    if(card1color.green == 1){
        numGreen +=1;
    }
    if(card2color.green == 1){
        numGreen +=1;
    }
    if(card3color.green == 1){
        numGreen +=1;
    }
    
    int numBlue = 0;
    if(card1color.blue == 1){
        numBlue +=1;
    }
    if(card2color.blue == 1){
        numBlue +=1;
    }
    if(card3color.blue == 1){
        numBlue +=1;
    }
    
    if((numRed == 1 or numRed == 3) && (numGreen == 1 or numGreen == 3) && (numBlue == 1 or numBlue ==0)){
        colorSameOrDiff = true;
        cout << "colors pass" << endl;
    }
    
    if(((card1shape == card2shape) && (card1shape == card3shape)) or ((card1shape != card2shape) && (card1shape != card3shape) && (card2shape != card3shape))){
        shapeSameOrDiff = true;
        cout << "shapes pass" << endl;
    }
    if(((card1opacity == card2opacity) && (card1opacity == card3opacity)) or ((card1opacity != card2opacity) && (card1opacity != card3opacity) && (card2opacity != card3opacity))){
        opacitySameOrDiff = true;
        cout << "opacity pass" << endl;
    }
    
    if(numSameOrDiff && colorSameOrDiff && shapeSameOrDiff && opacitySameOrDiff){
        cout << "IT'S A SET BABY" << endl;
        updateScore();
    }
}
void GameBoard:: populateDeck() {
    color red = {1,0,0};
    color green = {0,1,0};
    color blue = {0,0,1};
    
    for (int i = 0; i < 81; i ++){
        Card mycard = Card();
        cards.push_back(mycard);
    }
    
    for (int i = 0; i < 81; i++){
        cards[i].setNumber((i % 3)+1);
        if( i < 27){
            cards[i].setColor(red);
            if( i < 9){
                cards[i].setShapeType(circle);
                if( i < 3){
                    cards[i].setShapeOpacity(empty);
                } else if(i < 6){
                    cards[i].setShapeOpacity(partial);
                } else {
                    cards[i].setShapeOpacity(full);
                }
            } else if(i < 18){
                cards[i].setShapeType(square);
                if( i < 12){
                    cards[i].setShapeOpacity(empty);
                } else if(i < 15){
                    cards[i].setShapeOpacity(partial);
                } else {
                    cards[i].setShapeOpacity(full);
                }
                
            } else {
                cards[i].setShapeType(triangle);
                if( i < 21){
                    cards[i].setShapeOpacity(empty);
                } else if(i < 24){
                    cards[i].setShapeOpacity(partial);
                } else {
                    cards[i].setShapeOpacity(full);
                }
                
            }
            
        } else if(i < 54){
            cards[i].setColor(green);
            if( i < 36){
                cards[i].setShapeType(circle);
                if( i < 30){
                    cards[i].setShapeOpacity(empty);
                } else if(i < 33){
                    cards[i].setShapeOpacity(partial);
                } else {
                    cards[i].setShapeOpacity(full);
                }
            } else if(i < 45){
                cards[i].setShapeType(square);
                if( i < 39){
                    cards[i].setShapeOpacity(empty);
                } else if(i < 42){
                    cards[i].setShapeOpacity(partial);
                } else {
                    cards[i].setShapeOpacity(full);
                }
                
            } else {
                cards[i].setShapeType(triangle);
                if( i < 48){
                    cards[i].setShapeOpacity(empty);
                } else if(i < 51){
                    cards[i].setShapeOpacity(partial);
                } else {
                    cards[i].setShapeOpacity(full);
                }
                
            }
        } else {
            cards[i].setColor(blue);
            if( i < 63){
                cards[i].setShapeType(circle);
                if( i < 57){
                    cards[i].setShapeOpacity(empty);
                } else if(i < 60){
                    cards[i].setShapeOpacity(partial);
                } else {
                    cards[i].setShapeOpacity(full);
                }
            } else if(i < 72){
                cards[i].setShapeType(square);
                if( i < 66){
                    cards[i].setShapeOpacity(empty);
                } else if(i < 69){
                    cards[i].setShapeOpacity(partial);
                } else {
                    cards[i].setShapeOpacity(full);
                }
                
            } else {
                cards[i].setShapeType(triangle);
                if( i < 75){
                    cards[i].setShapeOpacity(empty);
                } else if(i < 78){
                    cards[i].setShapeOpacity(partial);
                } else {
                    cards[i].setShapeOpacity(full);
                }
                
            }
            
            
        }
    }
}

void GameBoard:: populateBoardCards() {
    for(int i=0; i< 9; i++){
        boardCards.push_back(cards[i]);
    }
}

void GameBoard:: shuffleDeck(){
    srand(time(NULL));
    for(int i = 0; i < 81; i++){
        int index = rand() % 81;
        
        int tempNum = cards[i].getNumber();
        color tempColor = cards[i].getColor();
        opacity tempOpacity = cards[i].getOpacity();
        shape tempShape = cards[i].getShape();
        
        int swapNum = cards[index].getNumber();
        color swapColor = cards[index].getColor();
        opacity swapOpacity = cards[index].getOpacity();
        shape swapShape = cards[index].getShape();
        
        cards[i].setNumber(swapNum);
        cards[i].setShapeOpacity(swapOpacity);
        cards[i].setShapeType(swapShape);
        cards[i].setColor(swapColor);
        
        cards[index].setNumber(tempNum);
        cards[index].setShapeOpacity(tempOpacity);
        cards[index].setShapeType(tempShape);
        cards[index].setColor(tempColor);
        
        
        
    }
    
}

string GameBoard:: getVectorItemShape(int i){
    return cards[i].getShapeString();
}
string GameBoard:: getVectorItemOpacity(int i) {
    return cards[i].getOpacityString();
}
string GameBoard:: getVectorItemColor(int i) {
    return cards[i].getColorString();
}
int GameBoard:: getBoardNumberOfShapes(int i) {
    return boardCards[i].getNumber();
}

shape GameBoard:: getBoardItemShape(int i){
    return boardCards[i].getShape();
}
string GameBoard:: getBoardItemOpacity(int i) {
    return boardCards[i].getOpacityString();
}
string GameBoard:: getBoardItemColor(int i) {
    return boardCards[i].getColorString();
}
int GameBoard:: getCardNumberOfShapes(int i) {
    return cards[i].getNumber();
}
void GameBoard:: cardDraw(int cardNumber, Point2D topLeft) {
    int num = boardCards[cardNumber].getNumber();
    color colr = boardCards[cardNumber].getColor();
    shape shapeType = boardCards[cardNumber].getShape();
    opacity opcty = boardCards[cardNumber].getOpacity();
    Rectangle cardRectangle = Rectangle();
    cardRectangle.drawCardOutline(topLeft);
    //triangle
    if(shapeType == triangle){
        if(num == 1){
            Triangle cardTriangle = Triangle();
            Point2D card1Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+100);
            cardTriangle.draw(card1Point, colr);
        }
        if(num ==2) {
            Triangle cardTriangle = Triangle();
            Point2D card1Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+50);
            Point2D card2Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+150);
            cardTriangle.draw(card1Point, colr);
            cardTriangle.draw(card2Point, colr);
            
        }
        if(num == 3) {
            Triangle cardTriangle = Triangle();
            Point2D card1Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+33);
            Point2D card2Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+99);
            Point2D card3Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+165);
            cardTriangle.draw(card1Point, colr);
            cardTriangle.draw(card2Point, colr);
            cardTriangle.draw(card3Point, colr);
        }
    }
    //circle
    if(shapeType == circle){
        if(num == 1){
            Circle cardCircle = Circle();
            Point2D card1Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+100);
            cardCircle.draw(card1Point, colr);
        }
        if(num ==2) {
            Circle cardCircle = Circle();
            Point2D card1Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+50);
            Point2D card2Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+150);
            cardCircle.draw(card1Point, colr);
            cardCircle.draw(card2Point, colr);
            
        }
        if(num == 3) {
            Circle cardCircle = Circle();
            Point2D card1Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+33);
            Point2D card2Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+99);
            Point2D card3Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+165);
            cardCircle.draw(card1Point, colr);
            cardCircle.draw(card2Point, colr);
            cardCircle.draw(card3Point, colr);
        }
    }
    //square
    if(shapeType == square){
        if(num == 1){
            Rectangle cardRectangle = Rectangle();
            Point2D card1Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+100);
            cardRectangle.draw(card1Point, colr);
        }
        if(num ==2) {
            Rectangle cardRectangle = Rectangle();
            Point2D card1Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+50);
            Point2D card2Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+150);
            cardRectangle.draw(card1Point, colr);
            cardRectangle.draw(card2Point, colr);
            
        }
        if(num == 3) {
            Rectangle cardRectangle = Rectangle();
            Point2D card1Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+33);
            Point2D card2Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+99);
            Point2D card3Point = Point2D(topLeft.get_x()+75, topLeft.get_y()+165);
            cardRectangle.draw(card1Point, colr);
            cardRectangle.draw(card2Point, colr);
            cardRectangle.draw(card3Point, colr);
        }
    }
    
}
Card GameBoard:: returnBoardCard(int i){
    return boardCards[i];
}

void GameBoard:: drawButtons(){
    Rectangle checkSetButton = Rectangle();
    Rectangle endGameButton = Rectangle();
    //draw the check set button
    Point2D checkSetButtonTopLeft = Point2D(10, 730);
    glBegin(GL_QUADS);
    glColor3f(0,255,0);
    //topleft
    glVertex2i(checkSetButtonTopLeft.get_x(), checkSetButtonTopLeft.get_y());
    //top right
    glVertex2i(checkSetButtonTopLeft.get_x()+310, checkSetButtonTopLeft.get_y());
    //bottom right
    glVertex2i(checkSetButtonTopLeft.get_x()+310, checkSetButtonTopLeft.get_y()+65);
    //bottom left
    glVertex2i(checkSetButtonTopLeft.get_x(), checkSetButtonTopLeft.get_y()+65);
    glEnd();
    //draw label for check set
    string message = "Check For Set";
    glColor3f(1,0,0);
    glRasterPos2i(checkSetButtonTopLeft.get_x()+75, checkSetButtonTopLeft.get_y()+40);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    //draw the end game button
    Point2D endGameButtonTopLeft = Point2D(330, 730);
    glBegin(GL_QUADS);
    glColor3f(0,255,0);
    //topleft
    glVertex2i(endGameButtonTopLeft.get_x(), endGameButtonTopLeft.get_y());
    //top right
    glVertex2i(endGameButtonTopLeft.get_x()+150, endGameButtonTopLeft.get_y());
    //bottom right
    glVertex2i(endGameButtonTopLeft.get_x()+150, endGameButtonTopLeft.get_y()+65);
    //bottom left
    glVertex2i(endGameButtonTopLeft.get_x(), endGameButtonTopLeft.get_y()+65);
    glEnd();
    //draw label for end game
    string message2 = "End Game";
    glColor3f(1,0,0);
    glRasterPos2i(endGameButtonTopLeft.get_x()+25, endGameButtonTopLeft.get_y()+40);
    for (int i = 0; i < message2.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message2[i]);
    }
}

void GameBoard:: selectCards(Point2D click){
    //loop through vector of cards on board to see if click is within the bounds of any card
    //if so, log the index of the card that the click hit
    //then push the vector element at that index into the chosen vector
    
    //chosen.push_back(selectedCard);
}
//score information
//call this method when checkSet is true
void GameBoard:: updateScore() {
    userScore += 30;
}
int GameBoard:: getUserScore() {
    return userScore;
}
string GameBoard:: getUserName() {
    return userName;
}
void GameBoard:: setUserName() {
    cout << "Please enter a Username!" << endl;
    getline(cin, userName);
}
//file IO
void GameBoard:: save(string userName, int score) {
    ofstream file("userData.txt", ios::app);
    if (file.is_open()) {
        file << userName << endl;
        file << score << endl;
        
    }
    else {
        cout << "File Not Found" << endl;
    }
    
}


string GameBoard:: loadSave() {
    vector<string> data;
    string found;
    string search;
    ifstream file;
    string line;
    
    cout << "enter a name to Search : ";
    cin >> search;
    file.open("userData.txt");
    
    if (file) {
        while (!file.eof()) {
            getline(file, line);
            data.push_back(line);
        }
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == search) {
                
                found = data[i] + " " + data[i + 1];
                
            }
            if (i == data.size() && data[i] != search) {
                cout << "Sorry! data not found" << endl;
            }
            
        }
    }
    
    
    
    
    
    return found;
}
void GameBoard:: gameOver() {
    //when the game ends, we will call save
    save(getUserName(), getUserScore());
}
