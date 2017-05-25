//
//  Card.cpp
//  FinalProject
//
//  Created by Timothy Guyon on 4/20/17.
//  Copyright © 2017 Timothy Guyon. All rights reserved.
//

//
//  card.cpp
//  Set
//
//  Created by Liam O'Toole on 4/18/17.
//  Copyright © 2017 Liam O'Toole. All rights reserved.
//

#include "main.hpp"
#include "graphics.hpp"
//card methods
Card:: Card(){}
Card:: ~Card(){}

void Card:: setShapeType(shape s){
    shapeType = s;
}

void Card:: setNumber(int n){
    numShapes = n;
}
void Card:: setShapeOpacity(opacity f){
    shapeOpacity = f;
}

void Card:: setColor(color c){
    shapeColor = c;
}

shape Card:: getShape(){
    return shapeType;
}
string Card:: getOpacityString() {
    return opacityToString(shapeOpacity);
}
string Card:: getShapeString(){
    return shapeToString(shapeType);
}
string Card:: getColorString() {
    return colorToString(shapeColor);
}
int Card:: getNumber(){
    return numShapes;
}
color Card:: getColor(){
    return shapeColor;
}
opacity Card:: getOpacity(){
    return shapeOpacity;
}

ostream& operator << (ostream& outs, shape &s){
    switch(s){
        case circle: outs << "circle";
        case triangle: outs << "triangle";
        case square: outs << "square";
    }
    return outs;
}

ostream& operator << (ostream& outs, opacity &f){
    switch(f){
        case circle: outs << "circle";
        case triangle: outs << "triangle";
        case square: outs << "square";
    }
    return outs;
}

ostream& operator << (ostream& outs, color c){
    if(c.red == 1 && c.green == 0 && c.blue == 0){
        outs << "red";
    } else if (c.red == 0 && c.green == 1 && c.blue == 0){
        outs << "green";
    } else if (c.red == 0 && c.green == 0 && c.blue == 1){
        outs << "blue";
    }
    return outs;
}


string Card::shapeToString(enum shape &s){
    switch(s){
        case circle: return "circle";
        case triangle: return "triangle";
        case square: return "square";
            
    }
}
string Card::opacityToString(enum opacity &f){
    switch(f){
        case empty: return "empty";
        case partial: return "partial";
        case full: return "full";
            
    }
}
string Card:: colorToString(color &c) {
    string returnValue;
    if(c.red == 0 && c.green == 1 & c.blue == 0) {
        returnValue = "green";
    }
    if(c.red == 1 && c.green == 0 && c.blue == 0) {
        returnValue = "red";
    }
    if(c.red == 0 && c.green == 0 && c.blue == 1) {
        returnValue = "blue";
    }
    return returnValue;
}



//shape methods
Shape:: Shape() {};
Shape:: ~Shape(){};


//circle
Circle:: Circle(){};
Circle:: ~Circle(){};
//setter and getter for radius
int Circle::getRadius() const {
    return radius;
}
void Circle:: setRadius(int r) {
    radius = r;
}
//override draw
void Circle::draw(Point2D centerPoint, color cardColor) const {
    glBegin(GL_TRIANGLE_FAN);
    // set fill color
    glColor3f(cardColor.red, cardColor.green, cardColor.blue);
    // draw center point
    glVertex2i(centerPoint.get_x(), centerPoint.get_y());
    // draw outside points
    double radius = 43.30127 / 2;
    for (int i = 0; i <= 360; ++i) {
        glVertex2i(centerPoint.get_x() + radius * cos(i * M_PI / 180.0), centerPoint.get_y() + radius * sin(i * M_PI / 180.0));
    }
    glEnd();
}


//triangle
Triangle:: Triangle(){};
Triangle:: ~Triangle(){};
//setter and getters for height and width
int Triangle:: getHeight() const {
    return triangleHeight;
}
int Triangle:: getWidth() const {
    return triangleWidth;
}
void Triangle:: setWidth(int w) {
    triangleWidth = w;
}
void Triangle:: setHeight(int h) {
    triangleHeight = h;
}
//override draw
void Triangle::draw(Point2D centerPoint, color cardColor) const {
   	glBegin(GL_TRIANGLES); //Begin triangle coordinates
    //Triangle
        glColor3f(cardColor.red,cardColor.green,cardColor.blue);
    glVertex2f(centerPoint.get_x(), centerPoint.get_y() - 43.30127 / 2);
    glVertex2f(centerPoint.get_x() - 25, centerPoint.get_y() + 43.30127 / 2);
    glVertex2f(centerPoint.get_x() + 25, centerPoint.get_y() + 43.30127 / 2);
    glEnd(); //End triangle coordinates
}


//rectangle
Rectangle:: Rectangle(){};
Rectangle:: ~Rectangle(){};
//setter and getters for height and width
int Rectangle:: getHeight() const {
    return recHeight;
}
int Rectangle:: getWidth() const {
    return recWidth;
}
void Rectangle:: setWidth(int w) {
    recWidth = w;
}
void Rectangle:: setHeight(int h) {
    recHeight = h;
}
//override draw of a rectangle
void Rectangle::draw(Point2D centerPoint, color cardColor) const {
    glBegin(GL_QUADS);
    glColor3f(cardColor.red, cardColor.green, cardColor.blue);
    //top left
    glVertex2i(centerPoint.get_x() - 25, centerPoint.get_y()-25);
    //top right
    glVertex2i(centerPoint.get_x() + 25, centerPoint.get_y() - 25);
    //bottom right
    glVertex2i(centerPoint.get_x() +25, centerPoint.get_y() +25);
    //bottom left
    glVertex2i(centerPoint.get_x() - 25, centerPoint.get_y() + 25);
    glEnd();
}
//override draw of a rectangle
void Rectangle::drawCardOutline(Point2D topLeft) {
    glBegin(GL_QUADS);
    //top left
    glColor3f(255,255,255);

    glVertex2i(topLeft.get_x(), topLeft.get_y());
    //top right
    glVertex2i(topLeft.get_x() + 150, topLeft.get_y());
    //bottom right
    glVertex2i(topLeft.get_x() + 150, topLeft.get_y() + 200);
    //bottom left
    glVertex2i(topLeft.get_x(), topLeft.get_y() + 200);
    glEnd();
}


//point 2d methods
Point2D::Point2D() : x(0), y(0) {
}

Point2D::Point2D(int x_in, int y_in) : x(x_in), y(y_in) {
}

int Point2D::get_x() const {
    return x;
}

int Point2D::get_y() const {
    return y;
}

void Point2D::set_x(int x_in) {
    x = x_in;
}

void Point2D::set_y(int y_in) {
    y = y_in;
}

void Point2D::set_point(int x_in, int y_in) {
    x = x_in;
    y = y_in;
}

void Point2D::move_point(int x_offset, int y_offset) {
    x += x_offset;
    y += y_offset;
}

double Point2D::distance_between(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
