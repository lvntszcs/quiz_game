#include<iostream>
#include<fstream>
#include<locale>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define QUESTION_NUM 3

using namespace std;

int correctAnswers=0;

int questions[QUESTION_NUM];

struct datatype{
    string id;
    string question;
    string a;
    string b;
    string c;
    string d;
    string solution;
};
datatype a[400];
int db=-1;

void input()
{
    cout<<"Which file do you want to load? ";
    string filename;
    cin>>filename;
    ifstream fin(filename);
    string x;
    fin>>x;

    while(!fin.eof()){
            db++;
            a[db].id=x;
            getline(fin, a[db].id, '\n');
            getline(fin, a[db].question, '\n');
            getline(fin, a[db].a, '\n');
            getline(fin, a[db].b, '\n');
            getline(fin, a[db].c, '\n');
            getline(fin, a[db].d, '\n');
            fin>>x;
            a[db].solution=x;
            fin>>x;
        }
    cout<<db+1<<" questions loaded."<<endl<<endl;

    fin.close();
    system("pause");
    system("cls");
}

void clearConsole()
{
    system("cls");
    cout<<"Score: "<<correctAnswers<<"/"<<QUESTION_NUM<<endl;
}

void quiz()
{
    for(int i=0;i<QUESTION_NUM;i++)
        questions[i]=-1;

    cout<<"Score: "<<correctAnswers<<"/"<<QUESTION_NUM<<" db="<<db<<endl;
    for(int i=0; i<QUESTION_NUM;i++)
    {
        int randomnum=-1;

        bool done=false;
        while(!done)
        {
            randomnum = rand() % (db+1);
            cout<<randomnum<<endl;
            bool found = false;
            for(int j=0;j<QUESTION_NUM;j++)
            {
                if(questions[j]==randomnum)
                {
                    found=true;
                    break;
                }
            }
            if(found==false){
                questions[i]=randomnum;
                done=true;
            }
        }

        string answer="";

        while((answer !="a" && answer !="b") && (answer !="c" && answer !="d") ){
                clearConsole();
                cout<<i+1<<"/"<<QUESTION_NUM<<": "<<a[randomnum].question<<endl<<a[randomnum].a<<endl<<a[randomnum].b<<endl<<a[randomnum].c<<endl<<a[randomnum].d<<endl;
                cout<<endl;
                cout<<"Answer: ";

                cin>>answer;
        };


        if(answer==a[randomnum].solution) {
            cout<<"Correct answer!"<<endl;
            correctAnswers++;
        }
        else {
            cout<<"Incorrect answer!"<<endl;
            cout<<"The correct answer is: "<<a[randomnum].solution<<endl;
        }

        system("pause");
        clearConsole();
    }
    system("pause");
    system("cls");
}

void result()
{
    cout<<"Result: "<<(double)correctAnswers*100.0/(double)QUESTION_NUM<<"%"<<endl;

    cout<<"Asked questions: "<<endl;
    for(int i=0;i<QUESTION_NUM;i++)
    {
        cout<<questions[i]+1<<endl;
    }
}

int main(){

    setlocale(LC_ALL, "");
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);

    srand (time(NULL));

    input();
    if(QUESTION_NUM>db+1)
    {
        cout<<"Can't ask more questions than the number of questions provided in the text file."<<endl;
        system("pause");
        return -1;
    }

    quiz();
    result();

    return 0;
}
