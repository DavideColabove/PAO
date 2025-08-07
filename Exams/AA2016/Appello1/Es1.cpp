#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

class GalloFile{
    private:
        double MB;
    public:
        GalloFile(double m = 0): MB(m) {}
        GalloFile(const GalloFile& gf): MB(gf.MB){}
        virtual GalloFile* clone() const = 0;
        virtual bool highQuality() const = 0;
        virtual ~GalloFile() {}
        double getMB() const{
            return MB;
        }
};

class Foto: public GalloFile{
    private:
        unsigned int ISO;
        bool flash;
    public:
        Foto(double m =0, unsigned int i = 0, bool f = false): GalloFile(m), ISO(i), flash(f){}
        Foto(const Foto& f): GalloFile(f), ISO(f.ISO), flash(f.flash){}
        Foto* clone() const override{
            return new Foto(*this);
        }
        bool highQuality() const{
            return ISO >= 500;
        }
        unsigned int getISO() const{
            return ISO;
        }
        bool getFlash() const{
            return flash;
        }
};

class Video: public GalloFile{
    private:
        unsigned int sec;
        bool FHD;
    public:
        Video(double m = 0, unsigned int s = 0, bool f=false): GalloFile(m), sec(s), FHD(f){}
        Video(const Video& v): GalloFile(v), sec(v.sec), FHD(v.FHD){}
        Video* clone() const override{
            return new Video(*this);
        }
        bool highQuality() const override{
            return FHD;
        }
        unsigned int getSec() const{
            return sec;
        }
};

class Gallo{
    private:
        vector<GalloFile*> files;
    public:
        vector<GalloFile*> selectHQ(){
            vector<GalloFile*> res;
            for(auto it = files.begin(); it != files.end(); ++it){
                Foto* f = dynamic_cast<Foto*>(*it);
                Video* v = dynamic_cast<Video*>(*it);
                if(f && f->highQuality() && f->getFlash())
                    res.push_back(f->clone());
                if(v && v->highQuality())
                    res.push_back(v->clone());
            }
            return res;
        }
        void removeNonFoto(double s){
            bool removed = false;
            for(auto it = files.begin(); it != files.end();){
                if(!(dynamic_cast<Foto*>(*it)) && (*it)->getMB() > s){
                    it = files.erase(it);
                    removed = true;
                }
                else{
                    ++it;
                }
            }
            if(!removed)
                throw logic_error("NoRemove");
        }
        const GalloFile* insert(const GalloFile* pf){
            const Video* cv = dynamic_cast<const Video*>(pf);
            if(!cv || cv->getSec() < 60){
                GalloFile* newFile = pf->clone();
                files.push_back(newFile);
                return newFile;
            }
            return nullptr;
        }
};