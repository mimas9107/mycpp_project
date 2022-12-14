#include <iostream>
#include <fstream>
#include <vector>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

int main(int argc, char* argv[])
{
    int cnt_lines=0;
    if(argc == 1) { return 0L;}
    string filename(argv[argc-1]);
    
    vector<string> lines;
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    ///* Read file into line *///
    cnt_lines =1;
    while (getline(input_file, line)){
        
        lines.push_back(line);
        cout << cnt_lines << " " << line << endl;
        cnt_lines++;
    }



    ///* Print out the lines *///
    ///* for (const auto &i : lines)*///
    ///*    cout << i << endl; *///

    input_file.close();
    return EXIT_SUCCESS;
}
