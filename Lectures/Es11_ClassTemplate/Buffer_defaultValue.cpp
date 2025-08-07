template <class Tipo = int, unsigned int size = 1024>   //tutti quelli alla destra dovranno avere valori di default
class Buffer {
    //...
};

int main(){
    Buffer<> ib;            //Buffer<int,1024>
    Buffer<string> sb;      //Buffer<string,1024>
    Buffer<string,500> sbs; //Buffer<string,500>
}