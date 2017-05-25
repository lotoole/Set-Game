//
//  main.cpp
//  FinalProject
//
//  Created by Timothy Guyon on 4/20/17.
//  Copyright © 2017 Timothy Guyon. All rights reserved.
//

//
//  main.cpp
//  Set
//
//  Created by Liam O'Toole, Timmy Guyon and Liv on 4/13/17.
//  Copyright © 2017 Liam O'Toole. All rights reserved.
//
#include "GameBoard.hpp"
#include "graphics.hpp"
#include "Card.hpp"
using namespace std;
#include <GLUT/glut.h>
GLdouble width, height;
int wd;

void init() {
    width = 490;
    height = 805;
}

///* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
    glColor3f(0.0f, 0.0f, 1.0f);
}

///* Handler for window-repaint event. Call back when the window first appears and
// whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    GameBoard mainBoard = GameBoard();
    mainBoard.populateDeck();
    mainBoard.shuffleDeck();
    mainBoard.populateBoardCards();
    vector<Point2D> cardLocations   {Point2D(10, 100), Point2D(170, 100), Point2D(330, 100),
                                    Point2D(10, 310), Point2D(170, 310), Point2D(330, 310),
                                    Point2D(10, 520), Point2D(170, 520), Point2D(330, 520)};
    for (int i = 0; i < 9; i++){
        mainBoard.cardDraw(i, cardLocations[i]);
    }
    mainBoard.drawButtons();
    

    glFlush();  // Render now
}

//// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    if (key == 'G') {
        glColor3f(0.0f, 1.0f, 0.0f);
    }

    if (key == 'R') {
        glColor3f(1.0f, 0.0f, 0.0f);
    }

    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:

            break;
        case GLUT_KEY_RIGHT:

            break;
        case GLUT_KEY_UP:

            break;
    }

    glutPostRedisplay();

    return;
}

void cursor(int x, int y) {
    //r.set_top_left(x, y);

    glutPostRedisplay();
}

//// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
//// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {


    glutPostRedisplay();
}

void timer(int extra) {

    glutTimerFunc(30, timer, 0);
    glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
        init();
    
        glutInit(&argc, argv);          // Initialize GLUT
    
        glutInitDisplayMode(GLUT_RGBA);
    
        glutInitWindowSize((int)width, (int)height);
        glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
        /* create the window and store the handle to it */
        wd = glutCreateWindow("Set!" /* title */ );
    
        // Register callback handler for window re-paint event
        glutDisplayFunc(display);
    
        // Our own OpenGL initialization
        initGL();
    
        // register keyboard press event processing function
        // works for numbers, letters, spacebar, etc.
        glutKeyboardFunc(kbd);
    
        // register special event: function keys, arrows, etc.
        glutSpecialFunc(kbdS);
    
        // handles mouse movement
        glutPassiveMotionFunc(cursor);
    
        // handles mouse click
        glutMouseFunc(mouse);
    
        // handles timer
        glutTimerFunc(0, timer, 0);
    
        // Enter the event-processing loop
        glutMainLoop();
    
    
    
    
    
    
    
    
    
//    cout << "Below we will print out all 81 cards to show that our deck has the 81 different cards in set. It will print all of the specific information for each card:" << endl;
//    cout << "---------------------" << endl;
//    for (int i = 0; i < 81 ; i++){
//        string cardShape = mainBoard.getVectorItemShape(i);
//        string cardOpacity = mainBoard.getVectorItemOpacity(i);
//        string cardColor = mainBoard.getVectorItemColor(i);
//        cout << "Card #" << i+1 << " " << cardShape << " " << cardOpacity << " " << cardColor << " " << mainBoard.getCardNumberOfShapes(i) << endl;
//    }
//    mainBoard.populateBoardCards();
//    cout << "\n";
//    cout << "Below is printing out the 9 cards that are being pushed from the deck onto the actual game board and the cards information" << endl;
//    int count = 0;
//    for(int j=0; j<9;j++) {
//        cout << "Card #" << count + 1 << " " << mainBoard.getBoardItemColor(j)<< " " << mainBoard.getBoardItemOpacity(j) << " " << mainBoard.getBoardItemShape(j) << " " << mainBoard.getBoardNumberOfShapes(j) << endl;
//        count++;
//    }
//    string input1 = "";
//    string input2 = "";
//    string input3 = "";
//    do{
//    cout << "first card: ";
//    getline(cin, input1);
//    cout << "second card: ";
//    getline(cin, input2);
//    cout << "third card: ";
//    getline(cin, input3);
//    int card1check = atoi(input1.c_str());
//    int card2check = atoi(input2.c_str());
//    int card3check = atoi(input3.c_str());
//    
//
//    mainBoard.checkSet(card1check, card2check, card3check);
//    }while(input1 != "end");
//
//    mainBoard.gameOver();
    
    
    
    return 0;
}
