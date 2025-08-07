#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Hidden {};

class Component {
public:
    virtual ~Component() {}
    virtual bool hasFocus() const = 0;
};

class Container : public Component {
public:
    virtual ~Container() {}
    virtual bool hasFocus() const = 0;
    virtual void setHeight(double) = 0;
    virtual void setWidth(double) = 0;
};

class Window : public Component {
public:
    virtual ~Window() {}
    virtual bool hasFocus() const = 0;
    virtual void hide() = 0;
};

class Frame : public Window {
public:
    virtual ~Frame() {}
    virtual bool hasFocus() const = 0;
    virtual bool hasMenu() const = 0;
    virtual void setTitle(const string&) = 0;
};

int main(){
    return 0;
}

void fun(const Component& c, vector<const Window*>& v){
    Frame* f = dynamic_cast<Frame*>(const_cast<Component*>(&c));
    if(f && f->hasMenu()){
        f->setTitle("menu");
        v.push_back(f);
    }
    Window* w = dynamic_cast<Window*>(const_cast<Component*>(&c));
    if(w && w->hasFocus()){
        try{
            w->hide();
        }
        catch(const Hidden&){}
    }
    Container* ct = dynamic_cast<Container*>(const_cast<Component*>(&c));
    if(ct && ct->hasFocus()){
        ct->setHeight(3.0);
        ct->setWidth(3.0);
    }
}