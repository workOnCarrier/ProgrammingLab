
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <iostream>

using namespace std;
namespace fs = boost::filesystem;

vector<string>  getSoList();
int main (){
    getSoList();
    return 0;
}
bool fileNameIsPlugin ( string &fileName ){
    string::size_type pos = fileName.find(".so");
    if( string::npos != pos ){
        // potentially a valid library
        if ( fileName.length() == pos + 3 ){
        // check if the files has format .so
            cout << "potentially valid .SO library " << fileName << endl;
        }else{
        // check if the files has format .so.#*
            cout << "potentially valid .SO.## library " << fileName << endl;
        }
    }
    return true;
}
vector<string>  getSoList(){
    vector<string> soList;
    fs::path full_path ( fs::initial_path<fs::path>() );
    cout << " path being looked out for :" << full_path.filename() << endl;
    if ( !fs::exists(full_path) ){
#pragma message ( "TBD::PluginManager::IdentifyPlugins  --- throw exception for non obtainable full path" )
    }
    if ( fs::is_directory(full_path) ){
        fs::directory_iterator endIter;
        for ( fs::directory_iterator dirIter(full_path); dirIter != endIter; ++dirIter ){
            try{
                if ( fs::is_directory ( dirIter->status() ) ){
                    continue;
                }else if ( fs::is_regular_file ( dirIter->status() ) ){
                    // interesting
                    // checking if it is an so / dll 
                    string fileName = dirIter->path().string();
                    if ( true == fileNameIsPlugin ( fileName ) ){
                        soList.push_back ( fileName );
                    }
                }
                else{
                    // could by symbolic link / device /etc... not interested in this version
                }
            }catch( const std::exception &e ){

                throw;
            }
        }
    }
    return soList;
}
