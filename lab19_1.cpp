#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string fname,vector<string> &iname,vector<int> &iscores,vector<char> &igrades){
    ifstream data("name_score.txt");
    string smass;
    int sor,p1,p2,p3;
    char na[100];
    char form[] = "%[^:]: %d %d %d";
    while (getline(data,smass))
    {
        sscanf(smass.c_str(),form,na,&p1,&p2,&p3);
        sor = p1+p2+p3;
        iname.push_back(na);
        iscores.push_back(sor);
        igrades.push_back(score2grade(sor));
    }
    data.close();
}

void getCommand(string &command, string &key){
    string text;
    char a[100];
    char b[100];
    char format[] = "%s %[^\n]";
    cout << "Please input your command: ";
    getline(cin,text);
    sscanf(text.c_str(),format,&a,&b);
    command = a;
    key = b;
}

void searchName(vector<string> nname,vector<int> nscores,vector<char> ngrades,string nkey){
    bool fin = false;
    cout << "---------------------------------"<<'\n';
    for (unsigned int i = 0; i < nname.size(); i++)
    {
        
        if (nkey == toUpperStr(nname[i]))
        { 
            cout << nname[i] << "'s score = " << nscores[i] << '\n';
            cout << nname[i] << "'s grade = " << ngrades[i]<<'\n';      
            fin = true;
        }
        
    }
    if (!fin)
    {
        cout << "Cannot found."<<'\n';
    }
    cout << "---------------------------------"<<'\n';
}

void searchGrade(vector<string> gname,vector<int> gscores,vector<char> ggrades,string gkey){
     bool fig = false;
     cout << "---------------------------------"<<'\n';
    for (unsigned int i = 0; i < gname.size(); i++)
    { 
        if (gkey[0]  == ggrades[i])
        {
            cout << gname[i] << " (" << gscores[i]<<")"<<'\n';
            fig = true;
        }
        
    }
    if (!fig)
    {
        cout << "Cannot found."<<'\n';
    }
    cout << "---------------------------------"<<'\n';
}



int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
