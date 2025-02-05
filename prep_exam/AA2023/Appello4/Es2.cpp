#include <iostream>
#include <vector>

using namespace std;

class File{
    private:
        double size;
        bool vis;
    public:
        File(double s = 0, bool v = false): size(s <= 0? 0 : s), vis(v){} 
        virtual ~File(){}
        double getSize() const{
            return size;
        }
        bool getVis() const{
            return vis;
        }
};

class Photo: public File{
    private:
        bool lossy;
    public:
        Photo(double s = 0, bool v = false, bool l = false): File(s,v), lossy(l){}
        bool getLossy() const{
            return lossy;
        }
};

class Video: public File{
    private:
        double fps;
    public:
        Video(double s = 0, bool v = false, double f = 0): File(s,v), fps(f <= 0 ? 0 : f){}
        double getFps() const{
            return fps;
        }
};

class PaODrive{
    private:
        vector<const File*> files;
        double max_mb;
    public:
        PaODrive(int m = 0): max_mb(m){}

        double uploadFile(const File& f){
            if(f.getSize() > max_mb)
                return -1.0;
            else{
                files.push_back(&f);
                return max_mb -= f.getSize();
            }
        }

        vector<const File*> copy(double d){
            vector<const File*> copia;
            for(auto it = files.begin(); it != files.end(); ++it ){
                if(const Video* v = dynamic_cast<const Video*>(*it))
                    if(v->getVis() && v->getFps() >= d)
                        copia.push_back(v);
                if(const Photo* p = dynamic_cast<const Photo*>(*it))
                    if(!(p->getLossy()) && p->getSize() < 2.0)
                        copia.push_back(p);
            }
            return copia;
        }
};

int main() {
    PaODrive cloud(10);  // Creiamo un cloud con 10 MB di memoria disponibile
    
    File f1(2, true);
    Photo p1(1.5, false, false); // Foto senza perdita di dati, < 2MB
    Photo p2(3, true, true); // Foto con perdita di dati
    Video v1(4, true, 30.0); // Video pubblico con 30 fps
    Video v2(5, true, 20.0); // Video pubblico con 20 fps
    Video v3(6, false, 25.0); // Video privato, non deve essere copiato

    cout << "Memoria disponibile dopo f1: " << cloud.uploadFile(f1) << " MB\n";
    cout << "Memoria disponibile dopo p1: " << cloud.uploadFile(p1) << " MB\n";
    cout << "Memoria disponibile dopo p2: " << cloud.uploadFile(p2) << " MB\n";
    cout << "Memoria disponibile dopo v1: " << cloud.uploadFile(v1) << " MB\n";
    cout << "Memoria disponibile dopo v2: " << cloud.uploadFile(v2) << " MB\n";
    cout << "Memoria disponibile dopo v3: " << cloud.uploadFile(v3) << " MB\n";

    vector<const File*> copia = cloud.copy(25.0);
    cout << "\nFile copiati (" << copia.size() << "):\n";
    for (const auto& file : copia) {
        const Video* vid = dynamic_cast<const Video*>(file);
        if (vid) cout << "- Video con " << vid->getFps() << " FPS\n";
        const Photo* pho = dynamic_cast<const Photo*>(file);
        if (pho) cout << "- Foto " << (pho->getLossy() ? "lossy" : "non lossy") << "\n";
    }

    return 0;
}