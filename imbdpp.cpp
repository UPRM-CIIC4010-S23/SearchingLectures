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

    // Tester Methods (DO NOT REMOVE)
    static string enumToString(Genres genres){
        switch(genres){
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
    static void printFirst6Movies(vector<IMBDPP> v){
        if(v.size() >= 1) v.at(0).printAttr();
        if(v.size() >= 2) v.at(1).printAttr();
        if(v.size() >= 3) v.at(2).printAttr();
        if(v.size() >= 4) v.at(3).printAttr();
        if(v.size() >= 5) v.at(4).printAttr();
        if(v.size() >= 6) v.at(5).printAttr();
    }

    // Methods Declared

};