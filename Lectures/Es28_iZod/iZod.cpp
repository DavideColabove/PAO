#include<iostream>
#include<string>
#include<vector>

using namespace std;

class FileAudio{
    private:
        std::string titolo;
        double MB;
    public:
        virtual FileAudio* clone() const =0;
        virtual bool qualita() const =0;
        virtual ~FileAudio(){}
        double getSize() const { return MB;}
        virtual bool operator==(const FileAudio& f) const {
            return typeid(*this)==typeid(f) && titolo == f.titolo && MB == f.MB;
        }
};

class Mp3: public FileAudio{
    private:
        static unsigned int sogliaQualita;
        unsigned int bitrate; // in Kbit/s
    public:
        Mp3* clone() const { return new Mp3 (*this);}
        bool qualita() const { return bitrate >= sogliaQualita;}
        unsigned int getBitrate() const { return bitrate;}
        virtual bool operator==(const FileAudio& f) const{
            return FileAudio::operator==(f) && bitrate==static_cast<const Mp3*>(f).bitrate;
        }
};
unsiged int Mp3::sogliaQualita = 192;

class WAV: public FileAudio{
    private:
        unsigned int frequenza; // in kHz
        bool lossless; // true se é senza perdita
        static unsigned int sogliaQualita;
    public:
        WAV* clone() const { return new WAV (*this);}
        bool qualita() const { return frequenza >= sogliaQualita;}
        bool isLossLess() const { return lossless;}
        virtual bool operator==(const FileAudio& f) const{
            return FileAudio::operator==(f) && frequenza==static_cast<const WAV&>(f).frequenza && lossless==static_cast<const WAV&>(f).lossless;
        }
};
unsiged int WAV::sogliaQualita = 96;

class iZod{
    private:
        class Brano{
            public:
                FileAudio* ptr; // puntatore superpolimorfo
                // convertitore FileAudio* => Brano
                Brano(FileAudio* p): ptr(p->clone()) {}
                // deep memory
                Brano(const Brano& b): ptr(b.ptr->clone())  {}
                Brano& operator=(const Brano& b){
                    if(this != &b){ // evita il problema x = x
                        delete ptr;  // distruzione polimorfa (FONDAMENTALE marcatura del distruttore FileAudio)
                        ptr = b.ptr->clone();
                    }
                    return *this;
                }
                ~Brano(){ delete ptr; }
        };
        std::vector<Brano> brani;
    public:
        std::vector<Mp3> mp3(double dim, unsigned int br) const{
            std::vector<Mp3> v;
            for(std::vector<Brano>::const_iterator cit = brani.begin(); cit != brani.end(); ++cit){
                if(dynamic_cast<Mp3*>(cit->ptr) && (cit->ptr)->getSize() > dim && static_cast<Mp3*>(cit->ptr)->getBitrate() > br){
                    v.push_back(*static_cast<Mp3*>(cit->ptr));
                }
            }
            return v;
        }
        std::vector<FileAudio*> braniQual() const{
            std::vector<FileAudio*> v;
            for(std::vector<Brano>::const_iterator cit = brani.begin(); cit != brani.end(); ++cit){
                if((cit->ptr)->qualita() && (!dynamic_cast<WAV*>(cit->ptr)) || static_cast<WAV*>(cit->ptr)->isLossLess()){
                    v.push_back(cit->ptr); 
                }
            }
            return v;
        }
        void insert(Mp3* m){
            bool found = false;
            for(auto it = brani.begin(); !found && it != brani.end(); it++){
                found = *(it->ptr)==*m;
            }
            if(!found){
                brani.push_back(m);
            }
        }
};