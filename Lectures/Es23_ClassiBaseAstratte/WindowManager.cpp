class Shape{
    ...
    virtual void draw(Position){...}
};

class Window: public Shape{
    ...
    void draw(Position){...}
};

class Icon: public Shape{
    ...
    void draw(Position){...}
};

class PopUp: public Shape{
    ...
    void draw(Position){...}
};

class DesktopManager{
    ...
    void show(const Shape& s){
        ...
        Position p = computePosition();
        s.draw(p);
        ...
    }
};