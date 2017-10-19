#include <iostream>
#include <stdlib.h>
struct movie_s{char title[50];
int year;};
using namespace std;
void printmovie(movie_s movie);
int main()
{   char buffer[50];
    movie_s mine[5];
    movie_s *p;
    p=mine;
    cout<<"what movie did you see?\n";
    for(int i=0;i<5;i++)
    {
        cin.getline(mine[i].title,50);
    }
    cout<<"which year was the movie produced ";
     for(int i=0;i<5;i++)
    {
        cin.getline(buffer,50);
        mine[i].year=atoi(buffer);

    }
for(int i=0;i<5;i++)
   {
        printmovie(mine[i]);
   }
    return 0;
}
void printmovie(movie_s movie)
{
    cout<<movie.title;
    cout<<movie.year;
}
