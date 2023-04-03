#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>        // std::abs

/*
 * IMDBPP is a class that represents Movies that might
 * be in a IMDB database. A IMDBPP has the following 
 * properties: title, director, budget, rating, boxoffice,
 * and genres. 
 * (See the enum Genres for the available genress.)
 */

using namespace std;

enum Genres{
    ACTION,
    ADVENTURE,
    COMEDY,
    THRILLER,
    WESTERN,
    OTHER
};

template<typename T>
bool isEqual(std::vector<T> first, std::vector<T> second)
{
    if (first.size() != second.size()) {
        return false;
    }
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());
    return first == second;
}

string enumToString(Genres genres)
{
    switch (genres)
    {
    case ACTION:
        return "ACTION";
    case ADVENTURE:
        return "ADVENTURE";
    case COMEDY:
        return "COMEDY";
    case THRILLER:
        return "THRILLER";
    case WESTERN:
        return "WESTERN";
    case OTHER:
        return "OTHER";
    }
    return "";
}

class IMBDPP{

private:
    string title;
    string director;
    double rating;
    double budget;
    double boxoffice;
    Genres genres;

public:
    // Constructors
    IMBDPP(){}

    IMBDPP(string title, string director, double rating, double budget, double boxoffice, Genres genres){
        this->title = title;
        this->director = director;
        this->rating = rating;
        this->budget = budget;
        this->boxoffice = boxoffice;
        this->genres = genres;
    }

    // Getters
    string getTitle() const {return title;}
    string getDirector() const {return director;}
    double getRating() const {return rating;}
    double getBudget() const {return budget;}
    double getBoxOffice() const {return boxoffice;}
    Genres getGenres() const {return genres;}

    // Setters
    void setTitle(string title) {this->title = title;}
    void setDirector(string director) {this->director = director;}
    void setRating(double rating) {this->rating = rating;}
    void setBudget(double budget) {this->budget = budget;}
    void setBoxOffice(double boxoffice) {this->boxoffice = boxoffice;}
    void setGenres(Genres genres) {this->genres = genres;}

    // Instance Methods
    bool equals(const IMBDPP &otherMovie)  const {
        return (*this) == otherMovie;

    }
    bool operator == (const IMBDPP &rhs) const {
        return this->getTitle() == rhs.getTitle() &&
               this->getDirector() == rhs.getDirector() &&
               this->getBudget() == rhs.getBudget() &&
               this->getGenres() == rhs.getGenres();
    }
    bool operator<(const IMBDPP& rhs) const {
        return this->getTitle() < rhs.getTitle() &&
               this->getDirector() < rhs.getDirector() &&
               this->getRating() < rhs.getRating() &&
               this->getBudget() < rhs.getBudget() &&
               this->getBoxOffice() < rhs.getBoxOffice() &&
               this->getGenres() < rhs.getGenres();
    }

    void printAttr(){
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << "IMBD object: ";
        cout << "Title: "; 
        cout << title;
        cout << "Rating: "; 
        cout << rating;
        cout << ", Director: ";
        cout << director;
        cout << ", Budget: ";
        cout << budget;
        cout << ", Box Office: ";
        cout << boxoffice;
        cout << ", Genres: ";
        cout << enumToString(genres);
        cout << endl;
    }

    // Methods Declared

};

int main(int argc, char const *argv[])
{
    IMBDPP m1("Movie1", "director1", 9.5, 43.98, 103.36, ACTION);
    IMBDPP m2("Movie2", "director1", 8.1, 41.48, 256.36, ADVENTURE);
    IMBDPP m3("Movie3", "director2", 5.2, 145.86, 45.36, ADVENTURE);
    IMBDPP m4("Movie4", "director3", 7.5, 32.99, 65.7, THRILLER);
    IMBDPP m5("Movie5", "director4", 8.3, 125.25, 163.3, WESTERN);
    IMBDPP m6("Movie6", "director5", 3.5, 527.88, 527.88, COMEDY);
    IMBDPP m7("Movie7", "director5", 6.5, 74.58, 574.58, COMEDY);
    IMBDPP m8("Movie8", "director6", 9.3, 11.96, 811.96, WESTERN);
    IMBDPP m9("Movie9", "director7", 4.5, 45.58, 5.73, OTHER);
    IMBDPP m10("Movie10", "director1", 5.6, 61.84, 85.64, OTHER);

    vector<IMBDPP> movieList1 = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10};
    vector<IMBDPP> movieList2 = {m1, m4, m5, m6, m7, m10};
    vector<IMBDPP> movieList3 = {m3, m4, m8, m9, m10};
    vector<IMBDPP> movieList4 = {m1, m2, m3, m4, m7, m7, m9};
    vector<IMBDPP> movieList5 = {m1, m9, m10};
    vector<IMBDPP> emptyList = {};

    exit(0);
}
