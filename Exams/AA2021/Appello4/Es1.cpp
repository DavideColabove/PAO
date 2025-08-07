class A{
    public:
        virtual ~A(){}
};

class B: virtual public A{
    public:
        virtual void b() = 0;
};

class C: public B{
    public:
        void c() const{}
};

class D: virtual public A{
    protected:
        D(){}
};

class E: public C, public D{
    E& operator=(const E& e){
        C::operator=(e);
        D::operator=(e);
        return *this;
    }
}   