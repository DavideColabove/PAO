#include<iostream>
#include<list>

using namespace std;

class File{
    private:
        int MB;
        bool accessibile;
    public:
        File(int m = 0, bool a = false): MB(m), accessibile(a){}
        virtual ~File(){} 
        virtual File* clone() const = 0;
        bool isAccessibile() const{
            return accessibile;
        }
        int getMB() const{
            return MB;
        }
};

class Audio: public File{
    private:
        bool lossy;
    public:
        Audio(int m = 0, bool a = false, bool l = false): File(m,a), lossy(l){}
        virtual Audio* clone() const = 0;
        virtual ~Audio(){} 
        bool isLossy() const{
            return lossy;
        }
};

class Mp3: public Audio{
    public:
        Mp3(int m = 0, bool a = false, bool l = true): Audio(m,a,true){}
        virtual Mp3* clone() const{
            return new Mp3(*this);
        }
        virtual ~Mp3(){}
};

class Video: public File{
    private:
        unsigned int fps;
    public:
        Video(int m=0, bool a = false, int f = 1): File(m,a), fps(f > 0? f : 1){}
        virtual ~Video(){}
        unsigned int getFps() const{
            return fps;
        }
        virtual Video* clone() const{
            return new Video(*this);
        }
};

class QoogleDrive{
    private:
        list<const File*> dir;
        int MAX_MB;
    public:
        QoogleDrive(int mmb): MAX_MB(mmb >= 0? mmb : 0){}
        ~QoogleDrive() {
            for (list<const File*>::const_iterator it = dir.begin(); it != dir.end(); ++it)
                delete *it;
        }
        Audio* uploadFile(File& f){
            const Audio* q = dynamic_cast<const Audio*>(&f);
            if(q){
                if(q->isAccessibile() && (MAX_MB - q->getMB()) >= 0){
                    Audio* up = q->clone();
                    dir.push_back(up);
                    MAX_MB -= q->getMB();
                    return up;
                }
            }
            throw EXC();
        }
        list<Audio*> audioCopy(){
            list<Audio*> res;
            Audio* copy = nullptr;
            for(auto cit = dir.begin(); cit != dir.end(); ++cit){
                Audio* copy = dynamic_cast<Audio*>(const_cast<File*>(*cit));
                if(copy && (!(copy->isLossy()) || dynamic_cast<Mp3*>(copy)))
                    res.push_back(copy->clone());
            }
            return res;
        }
        Video* minVideo(unsigned int fr) {
            if (dir.empty()) 
                throw EXC();
            Video* minVideo = nullptr;
            for (const File* f : dir) {
                Video* v = dynamic_cast<Video*>(const_cast<File*>(f));
                if (v && v->getFps() > fr) {
                    if (!minVideo || v->getMB() < minVideo->getMB()) {
                        minVideo = v;
                    }
                }
            }
            if (!minVideo) 
                throw EXC();
            return minVideo->clone();
        }
}

