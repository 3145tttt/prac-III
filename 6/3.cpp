#include <iostream>
#include <map>
#include <string>
#include <set>
#include <iomanip>

class Date {
private:
    int year, month, day;
    std::string date_str;
public:
    Date(std::string s){
        date_str = s;
        auto it1 = s.find('/'), it2 = s.find('/', it1 + 1);
        year = std::stol(s.substr(0, it1));
        month = std::stol(s.substr(it1 + 1, it2 - it1 - 1));
        day = std::stol(s.substr(it2 + 1));
    }

    friend bool operator<(const Date& left, const Date& other);

    void print() const {
        std::cout << year << "/" 
            << std::setfill('0') << std::setw(2) << month << "/" 
            << std::setfill('0') << std::setw(2) << day;
    }
};

bool operator<(const Date& left, const Date& other){
        if(left.year != other.year){
            return left.year < other.year;
        }
        if(left.month != other.month){
            return left.month < other.month;
        }
        return left.day < other.day;
    }

int main(){
    std::set<Date> dates;
    std::set<std::string> pupils;
    std::map<std::pair<std::string, Date>, int> marks;

    std::string surname, date;
    int mark;
    while(std::cin >> surname >> date >> mark){
        pupils.emplace(surname);
        dates.emplace(date);
        Date t = date;
        marks[std::make_pair(surname, t)] = mark;
    }

    std::cout << ".";
    for(auto x: dates){
        std::cout << " ";
        x.print();
    }
    std::cout << std::endl;
    
    for(auto p: pupils){
        std::cout << p;
        for(auto d: dates){
            auto it = marks.find(std::make_pair(p, d));
            std::cout << " ";
            if(it != marks.end()){
                std::cout << it->second;
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}