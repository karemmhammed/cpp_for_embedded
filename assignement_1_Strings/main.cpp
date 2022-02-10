#include <iostream>
#include <vector>
#include <map>

int image,movies,music,others;

using namespace std;

void clearr (void)
{
    image=0;
    movies=0;
    music=0;
    others=0;
}
void handleLine (string line  , map  < string , int > &m ){


    size_t foundDot = line.rfind(".");
    size_t foundSpace = line.rfind(" ");
    int last = foundSpace-foundDot ;



    string ext = line.substr(foundDot+1,last-1) ;
    string size = line.substr(foundSpace+1,line.size()-foundSpace-2);
    int sz = stoi(size);

    if(ext == "mp3" || ext == "aac" || ext == "flac")
        music+=sz;
    else if (ext == "jpg" || ext == "bmp" || ext == "gif")
        image+=sz;
    else if (ext == "mp4" || ext == "avi" || ext == "mkv")
        movies+=sz;
    else
        others+=sz;;


}

int main() {
    int j = 0;
    int i = 0 ;
    int tc ;
    cin>>tc;
    vector<int> sizes (tc);
    map  < string , int > m ;
    string line ;

    while(i<tc)
    {
        cin>>sizes[i++];
    }

    getline(cin,line);


    while(tc--){
        for(int i = 0 ; i < sizes[j] ; i++){
            getline(cin,line);
            handleLine(line , m);
        }
        j++;

        cout<<"music "<<music<<"b "<<"images "<<image<<"b "<<"movies "<<movies<<"b "<<"others "<<others<<"b\n ";
        clearr();

    }
}
