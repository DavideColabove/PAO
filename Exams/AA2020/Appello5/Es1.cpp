template<class T1, class T2>
bool Fun(T1* ptr, T2& ref) const {
    return (typeid(T1) == typeid(T2)) 
        && (typeid(*ptr) == typeid(ref))
        && (dynamic_cast<Abs*>(ptr));
}