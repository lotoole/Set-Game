//
//  Card.hpp
//  FinalProject
//
//  Created by Timothy Guyon on 4/20/17.
//  Copyright © 2017 Timothy Guyon. All rights reserved.
//
//
//  card.hpp
//  Set
//
//  Created by Liam O'Toole on 4/18/17.
//  Copyright © 2017 Liam O'Toole. All rights reserved.
//

#ifndef card_hpp
#define card_hpp
#include "main.hpp"
using namespace std;
//structs and enums
struct color {
    double red;
    double green;
    double blue;
};
enum shape {circle, triangle, square};
enum opacity {empty, partial, full};
//Point 2d class
class Point2D {
public:
    Point2D();
    Point2D(int x_in, int y_in);
    
    int get_x() const;
    int get_y() const;
    
    void set_x(int x_in);
    void set_y(int y_in);
    void set_point(int x_in, int y_in);
    
    void move_point(int x_offset, int y_offset);
    
    // returns the distance between two points
    static double distance_between(int x1, int y1, int x2, int y2);
private:
    int x;
    int y;
};
//class shape
class Shape {
public:
    //default constructor and destructor
    Shape();
    ~Shape();
    /**
     * Requires: nothing
     * Modifies: nothing (canvas to be drawn on)
     * Effects: draws the shape on the canvas
     */
    virtual void draw(Point2D topLeft, color cardColor) const = 0;
protected:
    //fields
private:
    
    
};

//Circle class
class Circle : public Shape {
public:
    //constructor and destructor
    Circle();
    ~Circle();
    /**
     * Requires: nothing
     * Modifies: nothing (canvas to be drawn on)
     * Effects: Setter and getter for radius
     */
    int getRadius() const;
    void setRadius(int r);
    // override draw method from Shape
    virtual void draw(Point2D topLeft, color cardColor) const override;
protected:
    //fields
    int radius;
private:
};

class Triangle : public Shape {
public:
    Triangle();
    ~Triangle();
    /**
     * Requires: nothing
     * Modifies: nothing (canvas to be drawn on)
     * Effects: Setter and getter for height and with
     */
    int getHeight() const;
    int getWidth() const;
    void setWidth(int w);
    void setHeight(int h);
    // override draw method from Shape
    virtual void draw(Point2D centerPoint, color cardColor) const override;
private:
    //fields
    int triangleHeight;
    int triangleWidth;
};

//Rectangle Class
class Rectangle : public Shape {
public:
    Rectangle();
    ~Rectangle();
    /**
     * Requires: nothing
     * Modifies: nothing (canvas to be drawn on)
     * Effects: Setter and getter for height and with
     */
    int getHeight() const;
    int getWidth() const;
    void setWidth(int w);
    void setHeight(int h);
    // override draw method from Shape
    virtual void draw(Point2D topLeft, color cardColor) const override;
    void drawCardOutline(Point2D topLeft);
private:
    //fields
    int recHeight;
    int recWidth;
};






//card class, make it abstract
class Card {
public:
    //constructor and destructor
    Card();
    ~Card();
    
    //methods
    void setNumber(int n);
    void setColor(color c);
    void setShapeType(shape s);
    void setShapeOpacity(opacity f);
    
    int getNumber();
    color getColor();
    shape getShape();
    opacity getOpacity();
    
    
    
    friend ostream& operator << (ostream& outs, color c);
    friend ostream& operator << (ostream& outs, shape &s);
    friend ostream& operator << (ostream& outs, opacity &o);
    
    string getShapeString();
    string getOpacityString();
    string shapeToString(enum shape &s);
    string opacityToString(enum opacity &f);
    //do something for color
    string colorToString(color &c);
    string getColorString();
    
protected:
    color shapeColor;
    shape shapeType;
    opacity shapeOpacity;
private:
    //fields
    //    ptr Shape //abstract class
    //    unique_ptr<Shape> cardShape;
    
    //number of shapes
    int numShapes;
    color red = {1,0,0};
    color green = {0,1,0};
    color blue = {0,0,1};
};


#endif /* card_hpp */
